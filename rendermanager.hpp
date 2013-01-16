#pragma once

#include <list>
#include <glm/glm.hpp>

#include "renderable.hpp"
#include "graphics.hpp"

class RenderManager {
public:
	RenderManager(Graphics &graphics);
	~RenderManager();
	bool initializeAndOpenWindow(int windowWidth, int windowHeight);
	void includeRenderable(Renderable* obj);
	void render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix);
	
private:
	Graphics &gfx;
	std::list<Renderable*>* scene;
	glm::mat4 ViewProjection;
};
