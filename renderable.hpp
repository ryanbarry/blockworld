#pragma once

#include "shaderprogram.hpp"
#include <glm/glm.hpp>

class Renderable {	
public:
	Renderable();
	virtual ~Renderable();
	void specifyVertices(const float v[], const float n[], const float t[], int count);
	void useTexture(const char *filename);
	void translateX(float tx);
	void translateY(float ty);
	void translateZ(float tz);
	void scaleX(float tx);
	void scaleY(float ty);
	void scaleZ(float tz);
	virtual void specifyShaderProgram(ShaderProgram *shader);
	virtual void render(glm::mat4& ViewProjection);

protected:
	GLuint vertexArrayId;
	GLuint bufferId;
	GLuint shaderProgramId;
	GLuint shaderTexId;
	GLuint positionAttributeId, UVAttributeId;
	int vertexCount, texId;
	ShaderProgram *shader;
	glm::mat4 translation, scale, transform;
	int shaderMVP;
	float *vertices;
	bool enableTexture;
	
	void updateBuffer();
};
