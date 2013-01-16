// Include standard headers
#include <cstdio>
#include <cstdlib>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GL/glfw.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include "shader.hpp"
#include "scenemanager.hpp"
#include "renderable.hpp"
#include "controls.hpp"
#include "text.hpp"
#include "world.hpp"

#define INIT_FAILED_ERROR 1;

int main(int argc, char* argv[])
{
	double currentTime, lastTime, deltaTime;
	unsigned int framecount = 0;
	char fpsstring[64];
	
	Graphics *gfx = new Graphics();
	if(!gfx->initializeAndOpenWindow(1024, 768, false, "blockworld")) {
		delete gfx;
		std::cerr << "Failed to initialize Graphics, exiting." << std::endl;
		return INIT_FAILED_ERROR;
	}
	
	SceneManager *sceneman = new SceneManager(*gfx);
	
	lastTime = glfwGetTime();
	
    // Ensure we can capture the escape key being pressed below
    glfwEnable(GLFW_STICKY_KEYS);
	glfwDisable(GLFW_MOUSE_CURSOR);
	glfwSetMousePos(0, 0);
	
	World* world = new World(sceneman);

	Text *testtext = new Text();
	testtext->setPosition(8, 745, 1.0f);
	testtext->setText("OpenGL Test Project");

	Text *frametimedisplay = new Text();
	frametimedisplay->setPosition(8, 725, 1.0f);
	frametimedisplay->setText("00.00 fps - 00.00 ms/frame  ");
	
	sceneman->includeRenderable(frametimedisplay);
	sceneman->includeRenderable(testtext);
    
	do{
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		if(deltaTime >= 1.0) {
			snprintf(fpsstring, sizeof(fpsstring), "%.2f fps - %.2f ms/frame", double(framecount)/deltaTime, 1000.0*deltaTime/double(framecount));
			frametimedisplay->setText(fpsstring);
			framecount = 0;
			lastTime = currentTime;
		}
		
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		
		sceneman->render(ProjectionMatrix, ViewMatrix);

		framecount++;
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
               glfwGetWindowParam( GLFW_OPENED ) );
	
	delete sceneman;
	delete gfx;
    return 0;
}