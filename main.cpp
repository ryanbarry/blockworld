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
#include "graphics.hpp"
#include "renderable.hpp"
#include "controls.hpp"
#include "text.hpp"
#include "world.hpp"

int main(int argc, char* argv[])
{
	double currentTime, lastTime, deltaTime;
	unsigned int framecount = 0;
	char fpsstring[64];
	
	Graphics *gfx = new Graphics();
	gfx->initializeAndOpenWindow(1024, 768);
	
	lastTime = glfwGetTime();
	
    // Ensure we can capture the escape key being pressed below
    glfwEnable(GLFW_STICKY_KEYS);
	glfwDisable(GLFW_MOUSE_CURSOR);
	glfwSetMousePos(0, 0);
	
	World* world = new World(gfx);

	Text *testtext = new Text();
	testtext->setPosition(8, 745, 1.0f);
	testtext->setText("OpenGL Test Project");

	Text *frametimedisplay = new Text();
	frametimedisplay->setPosition(8, 725, 1.0f);
	frametimedisplay->setText("00.00 fps - 00.00 ms/frame  ");
	
	gfx->includeRenderable(frametimedisplay);
	gfx->includeRenderable(testtext);
    
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
		
		std::cout << "calling Graphics::render()..." << std::endl;
		gfx->render(ProjectionMatrix, ViewMatrix);

		framecount++;
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
               glfwGetWindowParam( GLFW_OPENED ) );
	
	delete gfx;
    return 0;
}