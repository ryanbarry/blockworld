#pragma once

#include <vector>
#include "block.hpp"
#include "rendermanager.hpp"

class World {
public:
	World(RenderManager* renderman);
	~World();
	
private:
	Block block;
	std::vector<Block>* blocks;
};