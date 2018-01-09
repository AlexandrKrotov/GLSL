#include "fgl.h"

GLuint	fgl_program_create_and_link(GLuint *arr, int size)
{
	GLuint	program;
	GLint	link;
	int		i;
	
	program = glCreateProgram();
	i = 0;
	while (i < size)
	{
		glAttachShader(program, arr[i]);
		i++;
	}
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link);
	if (!link)
	{
		fgl_errors_compile_log(program);
		fgl_errors_log(ERR_PROGRAM_LINKING);
	}
	return (program);
}