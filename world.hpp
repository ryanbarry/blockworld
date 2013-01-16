#pragma once

#include <vector>
#include "block.hpp"
#include "rendermanager.hpp"

class World {
public:
	World(SceneManager* sceneman);
	~World();
	
private:
	Block block;
	std::vector<Block>* blocks;
};