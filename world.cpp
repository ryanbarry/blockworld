#include "world.hpp"

World::World(RenderManager* renderman) {
	blocks = new std::vector<Block>(16, block);
	int i = 0;
	float x, z;
	for(std::vector<Block>::iterator it = blocks->begin(); it != blocks->end(); it++) {
		x = (i%4);
		z = (i/4);
		it->translate(x, 0.0f, z);
		renderman->includeRenderable(it->getRenderable());
		i++;
	}
}

World::~World() {
	delete blocks;
}
