#pragma once

#include <vector>
#include "block.hpp"
#include "graphics.hpp"

class World {
public:
	World(Graphics* gfx);
	~World();
	
private:
	std::vector<Block>* blocks;
};