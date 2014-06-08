#pragma once

#include "renderable.hpp"
#include "shaderprogram.hpp"

#include <vector>
#include <glm/glm.hpp>

class Block {
public:
	Block();
	Block(const Block& original);
	~Block();
	Renderable* getRenderable();
	void translate(float x, float y, float z);
	
private:
  std::vector<glm::vec3>* generateVertexCoordinates(std::vector<glm::vec3>* points, float x, float y, float z);
	static const float vertexCoordinates[];
	static const float vertexNormals[];
	static const float vertexTextureCoordinates[];
	Renderable *renderable;
	ShaderProgram *shader;
};
