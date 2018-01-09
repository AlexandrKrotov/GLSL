#include "fgl.h"

GLuint fgl_texture_from_surface(const char *fn)
{
	SDL_Surface *s;
	GLuint 		texture;
	GLenum			mode;

	if ((s = IMG_Load(fn)) == NULL)
		ft_errors_custom(IMG_GetError());
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	mode = GL_RGB;
	if (s->format->BytesPerPixel == 4)
		mode = GL_RGBA;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, s->w, s->h, 0, mode, GL_UNSIGNED_BYTE, s->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_FreeSurface(s);
	return (texture);
}
