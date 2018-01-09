#include "fgl.h"

void	fgl_glew_init(void)
{
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		printf("Error GLEW init: %s\n", glewGetErrorString(glew_status));
		exit(0);
	}
}