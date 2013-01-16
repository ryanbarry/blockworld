#include "rendermanager.hpp"

RenderManager::RenderManager(Graphics &graphics) : gfx(graphics) {
	scene = new std::list<Renderable*>();
}

RenderManager::~RenderManager() {
	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		delete (*it);
	}
	delete scene;
}

void RenderManager::includeRenderable(Renderable* obj) {
	scene->push_back(obj);
}

void RenderManager::render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix) {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	ViewProjection = ProjectionMatrix * ViewMatrix;

	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		(*it)->render(ViewProjection);
	}
	
	gfx.swapBuffers();
}
