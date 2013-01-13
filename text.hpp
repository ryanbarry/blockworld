#pragma once

#include "renderable.hpp"

struct CharDescriptor {
	unsigned short x, y;
	unsigned short width, height;
	unsigned short xoffset, yoffset;
	unsigned short xadvance;
	CharDescriptor() : x(0), y(0), width(0), height(0), xoffset(0), yoffset(0), xadvance(0) {}
	CharDescriptor(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned short xoff, unsigned short yoff, unsigned short xadv) {
		this->x = x;
		this->y = y;
		width = w;
		height = h;
		xoffset = xoff;
		yoffset = yoff;
		xadvance = xadv;
	}
};

class Text : public Renderable {
public:
	Text();
	~Text();
	void setPosition(int xoff, int yoff, float scale);
	void setText(const char *text);
	void render(glm::mat4& ViewProjection);

private:
	const char *fontImageFileName;
	CharDescriptor chars[256];
	unsigned short width;
	unsigned short height;
	bool initialized;
	int buffersize, xoff, yoff;
	float scale;
};