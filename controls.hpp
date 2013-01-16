#pragma once
#include <glm/glm.hpp>

class Controls {
public:
	Controls();
	~Controls();
	void computeMatricesFromInputs();
	glm::mat4& getViewMatrix();
	glm::mat4& getProjectionMatrix();
	
private:
	glm::mat4 viewMatrix, projectionMatrix;
	// give initial position on +Z
	glm::vec3 position;
	// initial horizontal angle toward -Z
	float horizontalAngle;
	// no initial vertical angle
	float verticalAngle;

	float speed;
	float mouseSpeed;
};