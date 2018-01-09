#include "fgl.h"

void	fgl_extension_info_by_index(GLint index)
{
	GLint extension_count;

	glGetIntegerv(GL_NUM_EXTENSIONS, &extension_count);
	printf("%s\n", glGetStringi(GL_EXTENSIONS, index));
}

void	fgl_extension_info_all(void)
{
	GLint	extension_count;
	int		i;

	i = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &extension_count);
	while (i < extension_count)
	{
		printf("%s\n", glGetStringi(GL_EXTENSIONS, i));
		i++;
	}
}

int		fgl_extension_info_check_support(const char *ext)
{
	GLint extension_count;
	int		i;

	i = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &extension_count);
	while (i < extension_count)
	{
		//TODO strcmp?
		if (strcmp(ext, (char *)glGetStringi(GL_EXTENSIONS, i)) == 0)
			return (1);
		i++;
	}
	return (0);
}