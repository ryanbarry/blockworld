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
