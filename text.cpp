#include <cstdio>
#include <cstring>

#include "text.hpp"

struct TextVertex {
	float x, y, u, v;
};

Text::Text() {
	width = 128;
	height = 128;
	chars[' ']  = CharDescriptor(1,   13, 0, 0,  0, 0, 6);
	chars['!']  = CharDescriptor(2,   3,  1, 10, 0, 4, 8);
	chars['"']  = CharDescriptor(4,   1,  6, 5,  0, 12, 8);
	chars['#']  = CharDescriptor(11,  3,  6, 10, 0, 4, 8);
	chars['$']  = CharDescriptor(18,  2,  8, 12, 0, 4, 8);
	chars['%']  = CharDescriptor(27,  2,  8, 12, 0, 4, 8);
	chars['&']  = CharDescriptor(36,  3,  7, 11, 0, 4, 8);
	chars['\''] = CharDescriptor(44,  2,  2, 4,  0, 12, 8);
	chars['(']  = CharDescriptor(47,  1,  3, 15, 0, 2, 7);
	chars[')']  = CharDescriptor(51,  1,  4, 14, 0, 3, 7);
	chars['*']  = CharDescriptor(56,  4,  5, 6,  0, 7, 8);
	chars['+']  = CharDescriptor(62,  5,  7, 7,  0, 7, 8);
	chars[',']  = CharDescriptor(70,  10, 3, 6,  0, 1, 8);
	chars['-']  = CharDescriptor(74,  8,  6, 1,  0, 8, 8);
	chars['.']  = CharDescriptor(81,  11, 2, 2,  0, 4, 4);
	chars['/']  = CharDescriptor(84,  2,  7, 12, 0, 4, 8);
	chars['0']  = CharDescriptor(92,  3,  7, 10, 0, 4, 8);
	chars['1']  = CharDescriptor(100, 3,  5, 10, 0, 4, 8);
	chars['2']  = CharDescriptor(106, 2,  6, 11, 0, 4, 8);
	chars['3']  = CharDescriptor(113, 3,  6, 11, 0, 3, 8);
	chars['4']  = CharDescriptor(120, 2,  6, 11, 0, 4, 8);
	chars['5']  = CharDescriptor(1,   17, 6, 11, 0, 4, 8);
	chars['6']  = CharDescriptor(8,   18, 6, 11, 0, 3, 8);
	chars['7']  = CharDescriptor(15,  18, 6, 11, 0, 3, 8);
	chars['8']  = CharDescriptor(22,  18, 6, 11, 0, 3, 8);
	chars['9']  = CharDescriptor(29,  17, 6, 11, 0, 4, 8);
	chars[':']  = CharDescriptor(36,  21, 3, 8,  0, 4, 6);
	chars[';']  = CharDescriptor(40,  21, 4, 10, 0, 2, 8);
	chars['<']  = CharDescriptor(45,  19, 5, 8,  0, 6, 7);
	chars['=']  = CharDescriptor(51,  22, 6, 3,  0, 8, 9);
	chars['>']  = CharDescriptor(58,  20, 5, 8,  0, 5, 7);
	chars['?']  = CharDescriptor(64,  18, 7, 10, 0, 4, 8);
	chars['@']  = CharDescriptor(72,  18, 7, 12, 0, 3, 8);
	chars['A']  = CharDescriptor(80,  17, 6, 11, 0, 4, 8);
	chars['B']  = CharDescriptor(87,  18, 6, 10, 0, 4, 8);
	chars['C']  = CharDescriptor(94,  18, 7, 10, 0, 4, 8);
	chars['D']  = CharDescriptor(102, 18, 6, 10, 0, 4, 8);
	chars['E']  = CharDescriptor(109, 18, 6, 10, 0, 4, 8);
	chars['F']  = CharDescriptor(116, 18, 6, 10, 0, 4, 8);
	chars['G']  = CharDescriptor(1,   33, 7, 11, 0, 3, 8);
	chars['H']  = CharDescriptor(9,   33, 6, 10, 0, 4, 8);
	chars['I']  = CharDescriptor(16,  33, 6, 10, 0, 4, 8);
	chars['J']  = CharDescriptor(23,  33, 6, 10, 0, 4, 8);
	chars['K']  = CharDescriptor(30,  33, 7, 10, 0, 4, 8);
	chars['L']  = CharDescriptor(38,  33, 6, 10, 0, 4, 8);
	chars['M']  = CharDescriptor(45,  32, 8, 11, 0, 4, 8);
	chars['N']  = CharDescriptor(54,  32, 6, 11, 0, 4, 8);
	chars['O']  = CharDescriptor(61,  33, 6, 11, 0, 3, 8);
	chars['P']  = CharDescriptor(68,  33, 6, 10, 0, 4, 8);
	chars['Q']  = CharDescriptor(75,  33, 7, 11, 0, 3, 8);
	chars['R']  = CharDescriptor(83,  33, 7, 10, 0, 4, 8);
	chars['S']  = CharDescriptor(91,  33, 6, 10, 0, 4, 8);
	chars['T']  = CharDescriptor(98,  33, 7, 10, 0, 4, 8);
	chars['U']  = CharDescriptor(106, 33, 6, 10, 0, 4, 8);
	chars['V']  = CharDescriptor(113, 32, 8, 11, 0, 4, 8);
	chars['W']  = CharDescriptor(1,   47, 8, 11, 0, 4, 8);
	chars['X']  = CharDescriptor(10,  47, 6, 11, 0, 4, 8);
	chars['Y']  = CharDescriptor(17,  48, 7, 10, 0, 4, 8);
	chars['Z']  = CharDescriptor(25,  48, 6, 10, 0, 4, 8);
	chars['[']  = CharDescriptor(32,  46, 4, 14, 0, 3, 7);
	chars['\\'] = CharDescriptor(37,  46, 6, 13, 0, 4, 8);
	chars[']']  = CharDescriptor(44,  46, 4, 14, 0, 3, 8);
	chars['^']  = CharDescriptor(49,  46, 8, 5,  0, 12, 8);
	chars['_']  = CharDescriptor(58,  57, 8, 1,  0, 3, 8);
	chars['`']  = CharDescriptor(67,  45, 3, 5,  0, 12, 8);
	chars['a']  = CharDescriptor(71,  50, 6, 8,  0, 4, 8);
	chars['b']  = CharDescriptor(78,  47, 6, 11, 0, 4, 8);
	chars['c']  = CharDescriptor(85,  51, 7, 7,  0, 4, 8);
	chars['d']  = CharDescriptor(93,  48, 6, 11, 0, 3, 8);
	chars['e']  = CharDescriptor(100, 51, 6, 7,  0, 4, 8);
	chars['f']  = CharDescriptor(107, 48, 6, 10, 0, 4, 8);
	chars['g']  = CharDescriptor(114, 51, 6, 11, 0, 0, 8);
	chars['h']  = CharDescriptor(1,   63, 6, 11, 0, 4, 8);
	chars['i']  = CharDescriptor(8,   65, 5, 9,  0, 4, 8);
	chars['j']  = CharDescriptor(14,  64, 5, 13, 0, 1, 8);
	chars['k']  = CharDescriptor(20,  64, 6, 10, 0, 4, 8);
	chars['l']  = CharDescriptor(27,  64, 5, 10, 0, 4, 8);
	chars['m']  = CharDescriptor(33,  66, 8, 8,  0, 4, 8);
	chars['n']  = CharDescriptor(42,  66, 6, 8,  0, 4, 8);
	chars['o']  = CharDescriptor(49,  67, 6, 7,  0, 4, 8);
	chars['p']  = CharDescriptor(56,  66, 6, 11, 0, 1, 8);
	chars['q']  = CharDescriptor(63,  67, 6, 11, 0, 0, 8);
	chars['r']  = CharDescriptor(70,  66, 7, 8,  0, 4, 8);
	chars['s']  = CharDescriptor(78,  66, 7, 8,  0, 4, 8);
	chars['t']  = CharDescriptor(86,  64, 6, 10, 0, 4, 8);
	chars['u']  = CharDescriptor(93,  67, 6, 8,  0, 3, 8);
	chars['v']  = CharDescriptor(100, 67, 6, 7,  0, 4, 8);
	chars['w']  = CharDescriptor(107, 67, 7, 7,  0, 4, 8);
	chars['x']  = CharDescriptor(115, 67, 6, 7,  0, 4, 8);
	chars['y']  = CharDescriptor(1,   84, 6, 11, 0, 0, 8);
	chars['z']  = CharDescriptor(8,   84, 6, 7,  0, 4, 8);
	chars['{']  = CharDescriptor(15,  80, 6, 14, 0, 2, 8);
	chars['|']  = CharDescriptor(22,  79, 2, 14, 0, 2, 4);
	chars['}']  = CharDescriptor(25,  80, 6, 13, 0, 3, 8);
	chars['~']  = CharDescriptor(32,  84, 7, 3,  0, 7, 9);
	initialized = false;
	buffersize = 0;
	xoff = yoff = 0;
	scale = 1.0f;
	
	shader = new ShaderProgram();
	shader->loadVertexShaderSource("text.vert");
	shader->loadFragmentShaderSource("basic.frag");
	positionAttributeId = shader->getAttributeLocation("vertexPosition_screenspace");
	UVAttributeId = shader->getAttributeLocation("vertexUV");
}

Text::~Text() {

}

void Text::setPosition(int xoff, int yoff, float scale) {
	this->xoff = xoff;
	this->yoff = yoff;
	this->scale = scale;
}

void Text::setText(const char *text) {
	int c = strlen(text);
	vertexCount = c*6;
	float currentX = 0.0f;
	unsigned short CharX, CharY, Width, Height, OffsetX, OffsetY;

	if(!initialized) {
		useTexture("free_pixel_regular_12.tga");
		initialized = true;
	}

	glBindBuffer(GL_ARRAY_BUFFER, this->bufferId);
	if(vertexCount*4*sizeof(float) > buffersize) {
		buffersize = sizeof(float)*vertexCount*4;
    	glBufferData(GL_ARRAY_BUFFER, buffersize, NULL, GL_DYNAMIC_DRAW);
	}
	TextVertex *verts = (TextVertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

	if(verts == NULL) {
		printf("Error mapping VBO for text\n");
		return;
	}

	for(int i = 0; i < c; i++) {
		CharX   = chars[(int)text[i]].x;
		CharY   = chars[(int)text[i]].y;
		Width   = chars[(int)text[i]].width;
		Height  = chars[(int)text[i]].height;
		OffsetX = chars[(int)text[i]].xoffset;
		OffsetY = chars[(int)text[i]].yoffset;

		// lower left
		verts[i*6].x   = scale * (float) (currentX + OffsetX) + xoff;
		verts[i*6].y   = scale * (float) OffsetY + (float) yoff;
		verts[i*6].u   = (float) CharX / (float) width;
		verts[i*6].v   = 1.0f - (float) (CharY + Height) / (float) height;

		// lower right
		verts[i*6+1].x = scale * (float) (Width + currentX + OffsetX) + xoff;
		verts[i*6+1].y = scale * (float) OffsetY + (float) yoff;
		verts[i*6+1].u = (float) (CharX + Width) / (float) width;
		verts[i*6+1].v = 1.0f - (float) (CharY + Height) / (float) height;

		// upper left
		verts[i*6+2].x = scale * (float) (currentX + OffsetX) + xoff;
		verts[i*6+2].y = scale * (float) (Height + OffsetY) + yoff;
		verts[i*6+2].u = (float) CharX / (float) width;
		verts[i*6+2].v = 1.0f - (float) CharY / (float) height;

		// upper left
		verts[i*6+3].x = scale * (float) (currentX + OffsetX) + xoff;
		verts[i*6+3].y = scale * (float) (Height + OffsetY) + yoff;
		verts[i*6+3].u = (float) CharX / (float) width;
		verts[i*6+3].v = 1.0f - (float) CharY / (float) height;

		// lower right
		verts[i*6+4].x = scale * (float) (Width + currentX + OffsetX) + xoff;
		verts[i*6+4].y = scale * (float) OffsetY + (float) yoff;
		verts[i*6+4].u = (float) (CharX + Width) / (float) width;
		verts[i*6+4].v = 1.0f - (float) (CharY + Height) / (float) height;

		// upper right
		verts[i*6+5].x = scale * (float) (Width + currentX + OffsetX) + xoff;
		verts[i*6+5].y = scale * (float) (Height + OffsetY) + yoff;
		verts[i*6+5].u = (float) (CharX + Width) / (float) width;
		verts[i*6+5].v = 1.0f - (float) CharY / (float) height;

		currentX += (float) chars[(int)text[i]].xadvance;
	}

	if(glUnmapBuffer(GL_ARRAY_BUFFER) == GL_FALSE) {
		printf("glUnmapBuffer() returned GL_FALSE!\n");
		setText(text);
	}
}

void Text::render(glm::mat4& ViewProjection) {
	this->shader->use();
	
	if(enableTexture) {
		glActiveTexture(GL_TEXTURE0);
		// Bind our texture in Texture Unit 0
		glBindTexture(GL_TEXTURE_2D, texId);
		// Set our "myTextureSampler" sampler to user Texture Unit 0
		this->shader->uniformValueInt(shaderTexId, 0);
	}
	
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	
    // 1rst attribute: vertex positions
    glEnableVertexAttribArray(positionAttributeId);
    glVertexAttribPointer(
            positionAttributeId,// attribute id
            2,				// size
            GL_FLOAT,		// type
            GL_FALSE,		// normalized?
            4*sizeof(float),// stride
            (void*)0		// array buffer offset
    );
	
	if(enableTexture) {
		// 2nd attribute: UVs
		glEnableVertexAttribArray(UVAttributeId);
		glVertexAttribPointer(
		        UVAttributeId,// attribute id
		        2,			// size : U+V => 2
		        GL_FLOAT,	// type
		        GL_FALSE,	// normalized?
		        4*sizeof(float),// stride
		        (void*)(2*sizeof(float))	// array buffer offset
		);
	}

    // Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_DEPTH_TEST);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    glEnable(GL_DEPTH_TEST);

    glDisable(GL_BLEND);
	
    glDisableVertexAttribArray(positionAttributeId);
    glDisableVertexAttribArray(UVAttributeId);
}
