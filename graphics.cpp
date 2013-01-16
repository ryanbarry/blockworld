#include <iostream>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "graphics.hpp"

Graphics::Graphics() {
	
}

Graphics::~Graphics() {
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}

bool Graphics::initializeAndOpenWindow(int windowWidth, int windowHeight, bool fullscreen, std::string windowTitle) {
	this->fullscreen = fullscreen;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	
	// used as return value later, assume failure to begin with
    bool result = false;
	
	// Initialise GLFW
    if(!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		result = false;
    } else {
	    //glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
		glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		// Open a window and create its OpenGL context
	    if(!glfwOpenWindow(windowWidth, windowHeight, 0,0,0,0, 32,0, GLFW_WINDOW))
	    {
            std::cerr << "Failed to open GLFW window." << std::endl;
            glfwTerminate();
            result = false;
	    } else {
	    	setWindowTitle(windowTitle);
			
			// this is needed for OpenGL 3 features to work properly on OS X
			glewExperimental = true;
		    // Initialize GLEW
		    if (glewInit() != GLEW_OK) {
		            std::cerr << "Failed to initialize GLEW" << std::endl;
		            result = false;
		    } else {
			    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		    	result = true;
		    }
	    }
    }

	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);

    //glfwSwapInterval(0);
	
	return result;
}

void Graphics::setWindowTitle(std::string &text) {
	glfwSetWindowTitle(text.c_str());
}

void Graphics::swapBuffers() {
    // Swap buffers
    glfwSwapBuffers();
}

void Graphics::clear() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
