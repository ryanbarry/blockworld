#pragma once

#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();
	bool initializeAndOpenWindow(int windowWidth, int windowHeight, bool fullscreen = false, std::string windowTitle = "OpenGL Test");
	void clear();
	void swapBuffers();
	void setWindowTitle(std::string &text);
	void setFullscreen(bool fullscreen);
	
private:
	bool fullscreen;
	int windowWidth, windowHeight;
};
