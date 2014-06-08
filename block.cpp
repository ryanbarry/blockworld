#include "block.hpp"

const float Block::vertexCoordinates[] = {
// front face
	// bottom tri
	-0.5f, -0.5f, 0.5f,
	0.5f, -0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,
	// top tri
	-0.5f, 0.5f, 0.5f,
	0.5f, -0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
// right face
	// bottom tri
	0.5f, -0.5f, 0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, 0.5f, 0.5f,
	// top tri
	0.5f, 0.5f, 0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, 0.5f, -0.5f,
// rear face
	// bottom tri
	-0.5f, -0.5f, -0.5f,
	-0.5f, 0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	// top tri
	0.5f, -0.5f, -0.5f,
	-0.5f, 0.5f, -0.5f,
	0.5f, 0.5f, -0.5f,
// top face
	// rear tri
	0.5f, 0.5f, -0.5f,
	-0.5f, 0.5f, -0.5f,
	0.5f, 0.5f, 0.5f,
	// front tri
	0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f, -0.5f,
	-0.5f, 0.5f, 0.5f,
// left face
	// top tri
	-0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f, -0.5f,
	-0.5f, -0.5f, 0.5f,
	// bottom tri
	-0.5f, -0.5f, 0.5f,
	-0.5f, 0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
// bottom face
	// rear tri
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, 0.5f,
	// front tri
	-0.5f, -0.5f, 0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, 0.5f
};
const float Block::vertexNormals[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f
};
const float Block::vertexTextureCoordinates[] = {
// front face
	.0625f, 1.0f-.0625f,
	.125f, 1.0f-.0625f,
	.0625f, 1.0f,
	.0625f, 1.0f,
	.125f, 1.0f-.0625f,
	.125f, 1.0f,
// right face
	.0625f, 1.0f-.0625f,
	.125f, 1.0f-.0625f,
	.0625f, 1.0f,
	.0625f, 1.0f,
	.125f, 1.0f-.0625f,
	.125f, 1.0f,
// rear face
	.125f, 1.0f-.0625f,
	.125f, 1.0f,
	.0625f, 1.0f-.0625f,
	.0625f, 1.0f-.0625f,
	.125f, 1.0f,
	.0625f, 1.0f,
// top face
	.18359375f, 1.0f,
	.12890625f, 1.0f,
	.18359375f, 1.0f-.0625f,
	.18359375f, 1.0f-.0625f,
	.12890625f, 1.0f,
	.12890625f, 1.0f-.0625f,
// left face
	.125f, 1.0f,
	.0625f, 1.0f,
	.125f, 1.0f-.0625f,
	.125f, 1.0f-.0625f,
	.0625f, 1.0f,
	.0625f, 1.0f-.0625f,
// bottom face
	.0625f, 1.0f-.0625f,
	.125f, 1.0f-.0625f,
	.0625f, 1.0f,
	.0625f, 1.0f,
	.125f, 1.0f-.0625f,
	.125f, 1.0f
};

Block::Block() {
	shader = new ShaderProgram();
	shader->loadVertexShaderSource("basic.vert");
	shader->loadFragmentShaderSource("basic.frag");
	
	renderable = new Renderable();
	renderable->specifyVertices(vertexCoordinates, vertexNormals, vertexTextureCoordinates, sizeof(vertexCoordinates)/sizeof(float)/3);
	renderable->specifyShaderProgram(shader);
	renderable->useTexture("tilemap.tga");
}

Block::Block(const Block& original) {
	shader = original.shader;
	renderable = new Renderable(*(original.renderable));
}

Block::~Block() {
	delete renderable;
	delete shader;
}

Renderable* Block::getRenderable() {
	return renderable;
}

void Block::translate(float x, float y, float z) {
	if(x != 0.0f) renderable->translateX(x);
	if(y != 0.0f) renderable->translateY(y);
	if(z != 0.0f) renderable->translateZ(z);
}

std::vector<glm::vec3>* Block::generateVertexCoordinates(std::vector<glm::vec3>* points, float x, float y, float z) {
	int start = points->size();
	
	// front face
	(*points)[start+0]  = glm::vec3(-0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+1]  = glm::vec3(0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+2]  = glm::vec3(-0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+3]  = glm::vec3(-0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+4]  = glm::vec3(0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+5]  = glm::vec3(0.5f+x, 0.5f+y, 0.5f+z);
	
	// right face
	(*points)[start+6]  = glm::vec3(0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+7]  = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+8]  = glm::vec3(0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+9]  = glm::vec3(0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+10] = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+11] = glm::vec3(0.5f+x, 0.5f+y, -0.5f+z);
	
	// rear face
	(*points)[start+12] = glm::vec3(-0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+13] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+14] = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+15] = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+16] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+17] = glm::vec3(0.5f+x, 0.5f+y, -0.5f+z);
	
	// top face
	(*points)[start+18] = glm::vec3(0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+19] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+20] = glm::vec3(0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+21] = glm::vec3(0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+22] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+23] = glm::vec3(-0.5f+x, 0.5f+y, 0.5f+z);
	
	// left face
	(*points)[start+24] = glm::vec3(-0.5f+x, 0.5f+y, 0.5f+z);
	(*points)[start+25] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+26] = glm::vec3(-0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+27] = glm::vec3(-0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+28] = glm::vec3(-0.5f+x, 0.5f+y, -0.5f+z);
	(*points)[start+29] = glm::vec3(-0.5f+x, -0.5f+y, -0.5f+z);
	
	// bottom face
	(*points)[start+
		30] = glm::vec3(-0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+
		31] = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+
		32] = glm::vec3(-0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+
		33] = glm::vec3(-0.5f+x, -0.5f+y, 0.5f+z);
	(*points)[start+
		34] = glm::vec3(0.5f+x, -0.5f+y, -0.5f+z);
	(*points)[start+
		35] = glm::vec3(0.5f+x, -0.5f+y, 0.5f+z);
	
}
