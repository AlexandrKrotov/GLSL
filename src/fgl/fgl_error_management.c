#include "fgl.h"

//TODO Prinf use check
void	fgl_errors_log(int err)
{
	if (err == ERR_SHADER_COMPILE)
		printf("Error during shader compile!\n");
	else if (err == ERR_PROGRAM_LINKING)
		printf("Error in glLinkProgram!\n");
	else if (err == ERR_ATTRIBUTE)
		printf("Error: could not bind attribute.\n");
	else if (err == ERR_UNIFORM)
		printf("Error: could not bind uniform.\n");
	exit(0);
}

//TODO Prinf use check
void	fgl_errors_compile_log(GLuint obj)
{
	GLint	log_len;
	char	*log;

	log_len = 0;
	if (glIsShader(obj))
		glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &log_len);
	else if (glIsProgram(obj))
		glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &log_len);
	else
	{
		printf("Not a shader or program!\n");
		return ;
	}
	log = malloc(sizeof(char) * log_len);
	if (glIsShader(obj))
		glGetShaderInfoLog(obj, log_len, NULL, log);
	else if (glIsProgram(obj))
		glGetProgramInfoLog(obj, log_len, NULL, log);
	printf("LOG:\n %s\n", log);
	free(log);
}
