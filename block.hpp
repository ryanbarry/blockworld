#pragma once

#include "renderable.hpp"
#include "shaderprogram.hpp"

class Block {
public:
	Block();
	Block(const Block& original);
	~Block();
	Renderable* getRenderable();
	void translate(float x, float y, float z);
	
private:
	static const float vertexCoordinates[];
	static const float vertexNormals[];
	static const float vertexTextureCoordinates[];
	Renderable *renderable;
	ShaderProgram *shader;
};
