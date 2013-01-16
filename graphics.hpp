#pragma once

#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();
	bool initializeAndOpenWindow(int windowWidth, int windowHeight, bool fullscreen = false, std::string windowTitle = "OpenGL Test");
	void setWindowTitle(std::string &text);
	void swapBuffers();
	
private:
	bool fullscreen;
	int windowWidth, windowHeight;
};
