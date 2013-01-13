#include <cstdio>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "graphics.hpp"

Graphics::Graphics() {
	scene = new std::list<Renderable*>();
}

Graphics::~Graphics() {
    // Close OpenGL window and terminate GLFW
    glfwTerminate();

	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		delete (*it);
	}
	delete scene;
}

bool Graphics::initializeAndOpenWindow(int windowWidth, int windowHeight) {
    bool result = false;
	
	// Initialise GLFW
    if(!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
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
            fprintf(stderr, "Failed to open GLFW window.\n");
            glfwTerminate();
            result = false;
	    } else {
	    	glfwSetWindowTitle("OpenGL Test");
			
			// this is needed for OpenGL 3 features to work properly on OS X
			glewExperimental = true;
		    // Initialize GLEW
		    if (glewInit() != GLEW_OK) {
		            fprintf(stderr, "Failed to initialize GLEW\n");
		            result = false;
		    } else {
			    // Dark blue background
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

void Graphics::includeRenderable(Renderable* obj) {
	scene->push_back(obj);
}

void Graphics::render(glm::mat4& ProjectionMatrix, glm::mat4& ViewMatrix) {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	ViewProjection = ProjectionMatrix * ViewMatrix;

	std::list<Renderable*>::iterator it;
	for(it = scene->begin(); it != scene->end(); it++) {
		(*it)->render(ViewProjection);
	}
	
    // Swap buffers
    glfwSwapBuffers();
}
