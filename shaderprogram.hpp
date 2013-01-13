#pragma once

#include <GL/glew.h>

class ShaderProgram {
private:
	GLuint vtxId, frgId, prgId;
	bool vtxLoaded, frgLoaded, programLinked;
	
	char* readFile(const char *filename);
	bool compileShader(GLuint id, char *source);
	void printShaderInfoLog(GLuint id, const char *name);
	bool linkProgram();
	
public:
	ShaderProgram();
	~ShaderProgram();
	void loadVertexShaderSource(const char *filename);
	void loadFragmentShaderSource(const char *filename);
	int getAttributeLocation(const char *name);
	int getUniformLocation(const char *name);
	void uniformValueMat4(int id, const float *value);
	void uniformValueInt(int id, int value);
	bool isUsable();
	void use();
};