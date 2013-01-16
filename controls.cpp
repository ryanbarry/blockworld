#include "controls.hpp"
#include <GL/glfw.h>
#include <glm/gtc/matrix_transform.hpp>

#define PI 3.14159265f

Controls::Controls() {
	// give initial position on +Z
	position = glm::vec3(0,0,5);
	// initial horizontal angle toward -Z
	horizontalAngle = PI;
	// no initial vertical angle
	verticalAngle = 0.0f;

	speed = 3.0f;
	mouseSpeed = -0.005f;
	
    // Ensure we can capture the escape key being pressed below
    glfwEnable(GLFW_STICKY_KEYS);
	glfwDisable(GLFW_MOUSE_CURSOR);
	glfwSetMousePos(0, 0);
}

glm::mat4& Controls::getViewMatrix() {
	return viewMatrix;
}

glm::mat4& Controls::getProjectionMatrix() {
	return projectionMatrix;
}

void Controls::computeMatricesFromInputs() {
	static double lastTime = glfwGetTime();
	
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	
	int xpos, ypos;
	glfwGetMousePos(&xpos, &ypos);
	
	// must keep cursor fixed in one place in order to keep it from leaving the window
	glfwSetMousePos(0, 0);
	
	// compute new orientation
	horizontalAngle += mouseSpeed * float(xpos);
	verticalAngle += mouseSpeed * float(ypos);
	if(verticalAngle > 0.5f*PI) verticalAngle = 0.5f*PI;
	else if(verticalAngle < -0.5f*PI) verticalAngle = -0.5f*PI;
	
	// convert spherical direction coordinates to cartesian
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	
	// right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - PI/2.0f),
		0,
		cos(horizontalAngle - PI/2.0f)
	);
	
	// up vector
	glm::vec3 up = glm::cross(right, direction);
	
	if(glfwGetKey('W') == GLFW_PRESS) {
		position += direction * deltaTime * speed;
	}
	if(glfwGetKey('S') == GLFW_PRESS) {
		position -= direction * deltaTime * speed;
	}
	if(glfwGetKey('D') == GLFW_PRESS) {
		position += right * deltaTime * speed;
	}
	if(glfwGetKey('A') == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}
	
	//float FOV = initialFOV - 5 * glfwGetMouseWheel();
	
	projectionMatrix = glm::perspective(65.0f, 4.0f/3.0f, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(position, position+direction, up);
	
	lastTime = currentTime;
}