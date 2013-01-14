#pragma once

#include <vector>
#include "block.hpp"
#include "graphics.hpp"

class World {
public:
	World(Graphics* gfx);
	~World();
	
private:
	Block block;
	std::vector<Block>* blocks;
};