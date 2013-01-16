#include "rendermanager.hpp"

SceneManager::SceneManager(Graphics &graphics) : gfx(graphics) {
	scene = new std::list<Renderable*>();
}

SceneManager::~SceneManager() {
	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		delete (*it);
	}
	delete scene;
}

void SceneManager::includeRenderable(Renderable* obj) {
	scene->push_back(obj);
}

void SceneManager::render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix) {
    gfx.clear();
	
	ViewProjection = ProjectionMatrix * ViewMatrix;

	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		(*it)->render(ViewProjection);
	}
	
	gfx.swapBuffers();
}
