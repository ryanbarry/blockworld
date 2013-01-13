#include <cstdio>
#include <cstring>

#include "shader.hpp"
#include "texture.hpp"
#include "renderable.hpp"
#include <glm/gtc/matrix_transform.hpp>

Renderable::Renderable() {
	glGenVertexArrays(1, &vertexArrayId);
    glBindVertexArray(vertexArrayId);
    glGenBuffers(1, &bufferId);
    translation = glm::mat4(1.0);
    scale = glm::mat4(1.0);
    transform = glm::mat4(1.0);
	vertices = NULL;
	vertexCount = 0;
	enableTexture = false;
}

Renderable::~Renderable() {
    glDeleteBuffers(1, &bufferId);
    glDeleteVertexArrays(1, &vertexArrayId);
}

void Renderable::specifyVertices(const float v[], const float n[], const float t[], int count) {
    if(vertices == NULL) {
    	vertices = new float[8*count]; // 8 attributes per vertex (x,y,z,nx,ny,nz,u,v)
		vertexCount = count;
	} else if (count != vertexCount) {
		delete vertices;
		vertices = new float[3*3*count];
		vertexCount = count;
	}
	
	for(int i = 0; i < count; i++) {
		int dst0 = i*8, dst1 = dst0+1, dst2 = dst1+1, dst3 = dst2+1, dst4 = dst3+1, dst5 = dst4+1, dst6 = dst5+1, dst7 = dst6+1;
		int vt0 = i*3, vt1 = vt0+1, vt2 = vt1+1;
        int uv0 = i*2, uv1 = uv0+1;
        vertices[dst0] = v[vt0];		// x
		vertices[dst1] = v[vt1];		// y
		vertices[dst2] = v[vt2];		// z
		if(n != NULL) {
			vertices[dst3] = n[vt0];	// nx
			vertices[dst4] = n[vt1];	// ny
			vertices[dst5] = n[vt2];	// nz
		}
		if(t != NULL) {
			vertices[dst6] = t[uv0];	// u
			vertices[dst7] = t[uv1];	// v
		}
	}
	
	updateBuffer();
}

void Renderable::useTexture(const char *filename) {
	if((texId = loadTextureFromFile(filename)) != -1) {
        shaderTexId = shader->getUniformLocation("textureSampler");
        UVAttributeId = shader->getAttributeLocation("vertexUV");
        enableTexture = true;
    } else {
        printf("unable to load texture '%s'\n", filename);
    }
}

void Renderable::updateBuffer() {
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertexCount*8, vertices, GL_STATIC_DRAW);
}

void Renderable::translateX(float tx) {
    translation[3][0] += tx;
    transform = translation * scale;
}

void Renderable::translateY(float ty) {
    translation[3][1] += ty;
    transform = translation * scale;
}

void Renderable::translateZ(float tz) {
    translation[3][2] += tz;
    transform = translation * scale;
}

void Renderable::scaleX(float tx) {
    scale[0][0] += tx;
    transform = translation * scale;
}

void Renderable::scaleY(float ty) {
    scale[1][1] += ty;
    transform = translation * scale;
}

void Renderable::scaleZ(float tz) {
    scale[2][2] += tz;
    transform = translation * scale;
}

void Renderable::specifyShaderProgram(ShaderProgram *shader) {
	this->shader = shader;
    shaderMVP = this->shader->getUniformLocation("MVP");
	positionAttributeId = this->shader->getAttributeLocation("vertexPosition_modelspace");
}

void Renderable::render(glm::mat4& ViewProjection) {
    glm::mat4 MVP = ViewProjection * transform;

	shader->use();
    shader->uniformValueMat4(shaderMVP, &MVP[0][0]);
	
	if(enableTexture) {
        glActiveTexture(GL_TEXTURE0);
		// Bind our texture in Texture Unit 0
		glBindTexture(GL_TEXTURE_2D, texId);
		// Set our "myTextureSampler" sampler to user Texture Unit 0
		shader->uniformValueInt(shaderTexId, 0);
	}
	
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	
    // 1rst attribute: vertex positions
    glEnableVertexAttribArray(positionAttributeId);
    glVertexAttribPointer(
            positionAttributeId,// attribute id
            3,				// size
            GL_FLOAT,		// type
            GL_FALSE,		// normalized?
            8*sizeof(float),// stride
            (void*)0		// array buffer offset
    );
	
	if(enableTexture) {
		// 2nd attribute: UVs
		glEnableVertexAttribArray(UVAttributeId);
		glVertexAttribPointer(
		        UVAttributeId,// attribute id
		        2,			// size : U+V => 2
		        GL_FLOAT,	// type
		        GL_FALSE,	// normalized?
		        8*sizeof(float),// stride
		        (void*)(6*sizeof(float))	// array buffer offset
		);
	}

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
	
    glDisableVertexAttribArray(positionAttributeId);
    glDisableVertexAttribArray(UVAttributeId);
}