#include "world.hpp"

World::World(Graphics* gfx) {
	Block block;
	blocks = new std::vector<Block>(16, block);
	int i = 0;
	float x, z;
	for(std::vector<Block>::iterator it = blocks->begin(); it != blocks->end(); it++) {
		x = (i%4) * 0.5f;
		z = (i/4) * 0.5f;
		it->translate(x, 0.0f, z);
		gfx->includeRenderable(it->getRenderable());
		i++;
	}
}

World::~World() {
	delete blocks;
}
