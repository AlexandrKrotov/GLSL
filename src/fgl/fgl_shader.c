#include "fgl.h"

GLuint	fgl_shader_create(const char *nm, const char *shader_src, GLenum type)
{
	GLint	params;
	GLuint	shader;

	params = GL_FALSE;
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &shader_src, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &params);
	if (!params)
	{
		printf("Shader (name: %s) compile error:\n", nm);
		fgl_errors_compile_log(shader);
		fgl_errors_log(ERR_SHADER_COMPILE);
	}
	return (shader);
}

GLuint	fgl_shader_from_file(const char *fn, GLenum type)
{
	char	*src;
	GLuint	shader;

	src = fsdl_file_read(fn);
	shader = fgl_shader_create(fn, src, type);

	free(src);
	return (shader);
}

void	fgl_shader_delete_array(GLuint *shaders, GLuint size)
{
	GLuint	i;

	i = 0;
	while (i < size)
	{
		glDeleteShader(shaders[i]);
		i++;
	}
}