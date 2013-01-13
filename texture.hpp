#pragma once

int loadTextureFromFile(const char *filename);

GLuint loadDDS(const char *imagepath);

GLuint loadBMP_custom(const char * imagepath);

GLuint loadTGA_glfw(const char * imagepath);