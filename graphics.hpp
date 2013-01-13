#pragma once

#include <list>
#include <glm/glm.hpp>

#include "renderable.hpp"

class Graphics {
public:
	Graphics();
	~Graphics();
	bool initializeAndOpenWindow(int windowWidth, int windowHeight);
	void includeRenderable(Renderable* obj);
	void render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix);
	
private:
	std::list<Renderable*>* scene;
	glm::mat4 ViewProjection;
};
