#include <string>
#include <iostream>
#include <fstream>

#include "shaderprogram.hpp"

ShaderProgram::ShaderProgram() {
	vtxId = glCreateShader(GL_VERTEX_SHADER);
	frgId = glCreateShader(GL_FRAGMENT_SHADER);
	prgId = glCreateProgram();
	vtxLoaded = frgLoaded = programLinked = false;
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(prgId);
    glDeleteShader(vtxId);
    glDeleteShader(frgId);
}

void ShaderProgram::loadVertexShaderSource(const char *filename) {
	char *source;
	if((source = readFile(filename)) == NULL) {
		return;
	} else if(compileShader(vtxId, source)) {
		glAttachShader(prgId, vtxId);
		vtxLoaded = true;
		delete source;
	} else {
		printShaderInfoLog(vtxId, filename);
	}
	
	if(vtxLoaded && frgLoaded) {
		programLinked = linkProgram();
	}
}

void ShaderProgram::loadFragmentShaderSource(const char *filename) {
	char *source;
	if((source = readFile(filename)) == NULL) {
		return;
	} else if(compileShader(frgId, source)) {
		glAttachShader(prgId, frgId);
		frgLoaded = true;
		delete source;
	} else {
		printShaderInfoLog(frgId, filename);
	}
	
	if(vtxLoaded && frgLoaded) {
		programLinked = linkProgram();
	}
}

int ShaderProgram::getAttributeLocation(const char *name) {
	if(this->isUsable())
		return (int)glGetAttribLocation(prgId, name);
	else
		return -1;
}

int ShaderProgram::getUniformLocation(const char *name) {
	if(this->isUsable())
		return (int)glGetUniformLocation(prgId, name);
	else
		return -1;
}

void ShaderProgram::uniformValueMat4(int id, const float *value) {
	glUniformMatrix4fv(id, 1, GL_FALSE, value);
}

void ShaderProgram::uniformValueInt(int id, int value) {
	glUniform1i(id, value);
}

bool ShaderProgram::isUsable() {
	return programLinked;
}

void ShaderProgram::use() {
	if(programLinked) glUseProgram(prgId);
}

char* ShaderProgram::readFile(const char *filename) {
    std::ifstream fileStream(filename, std::ios::in);
    if(fileStream.is_open()) {
        fileStream.seekg(0, std::ios::end);
		int fileSize = fileStream.tellg();
		fileStream.seekg(0, std::ios::beg);
		if(fileSize < 0) std::cout << "Error reading '" << filename << "'" << std::endl;
		else {
			char *fileContents = new char[fileSize+1];
			fileStream.read(fileContents, fileSize);
			fileContents[fileSize] = '\0';
			
			return fileContents;
		}
    } else {
        std::cout << "Cannot open '" << filename << "'" << std::endl;
        return NULL;
    }
	return NULL;
}

bool ShaderProgram::compileShader(GLuint id, char *source) {
	// Compile Shader
    glShaderSource(id, 1, (const GLchar**)&source, NULL);
    glCompileShader(id);
	
    // Check Shader
	GLint result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    
    if (result == GL_FALSE) {
		return false;
	} else {
		return true;
	}
}

void ShaderProgram::printShaderInfoLog(GLuint id, const char *name) {
	GLint infoLogLength;
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
    char *infoLog = new char[infoLogLength+1];
    glGetShaderInfoLog(id, infoLogLength, NULL, infoLog);
    std::cout << "GL Shader Info Log for '" << name << "':\n" << infoLog;
	delete infoLog;
}

bool ShaderProgram::linkProgram() {
    glLinkProgram(prgId);

    // Check the program
	GLint result, infoLogLength;
    glGetProgramiv(prgId, GL_LINK_STATUS, &result);
    glGetProgramiv(prgId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (result == GL_FALSE) {
        char *infoLog = new char[infoLogLength+1];
        glGetProgramInfoLog(prgId, infoLogLength, NULL, infoLog);
        std::cout << "GL Program Info Log:\n" << infoLog;
		delete infoLog;
		return false;
	} else {
		return true;
	}
}
