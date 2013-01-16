#pragma once

#include <vector>
#include "block.hpp"
#include "scenemanager.hpp"

class World {
public:
	World(SceneManager* sceneman);
	~World();
	
private:
	Block block;
	std::vector<Block>* blocks;
};