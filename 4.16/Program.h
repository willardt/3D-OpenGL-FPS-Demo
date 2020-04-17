#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

struct Program {
	unsigned short type;
	const char* file_path;
};

// last address in program must end with type = GL_NONE
GLuint load_shaders(const Program* program);

#endif