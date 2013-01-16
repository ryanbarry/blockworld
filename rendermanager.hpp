#pragma once

#include <list>
#include <glm/glm.hpp>

#include "renderable.hpp"
#include "graphics.hpp"

class SceneManager {
public:
	SceneManager(Graphics &graphics);
	~SceneManager();
	bool initializeAndOpenWindow(int windowWidth, int windowHeight);
	void includeRenderable(Renderable* obj);
	void render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix);
	
private:
	Graphics &gfx;
	std::list<Renderable*>* scene;
	glm::mat4 ViewProjection;
};
