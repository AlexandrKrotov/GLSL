#ifndef FGL_H
# define FGL_H

# include "ft_errors.h"
# include "GL/glew.h"
# include "fsdl.h"
# include <stdio.h>

# define FGL_VERSION "#version 450\n"
/*
** Custom OpenGL and GLEW error defines
*/
# define ERR_SHADER_COMPILE 90
# define ERR_PROGRAM_LINKING 91
# define ERR_ATTRIBUTE 92
# define ERR_UNIFORM 93

typedef struct s_attr	t_attr;
typedef struct s_glbf	t_glbf;

struct s_elem
{
	GLfloat coord3d[3];
};

struct s_attr
{
	const char	*name;
	GLuint		attr;
};

struct s_glbf
{
	GLsizei	name_num;
	GLuint	buff;
	GLenum	targ;
	GLenum	usage;
};
/*
** fgl_error_management.c
*/
void	fgl_errors_log(int err);
void	fgl_errors_compile_log(GLuint obj);
/*
** fgl_extension_info.c
*/
void	fgl_extension_info_by_index(GLint index);
void	fgl_extension_info_all(void);
int		fgl_extension_info_check_support(const char *ext);
/*
** fgl_program.c
*/
GLuint	fgl_program_create_and_link(GLuint *arr, int size);
/*
** fgl_project.c
*/
void	fgl_glew_init(void);
/*
** fgl_shader.c
*/
GLuint	fgl_shader_create(const char *nm, const char *shader_src, GLenum type);
GLuint	fgl_shader_from_file(const char *fn, GLenum type);
void	fgl_shader_delete_array(GLuint *shaders, GLuint size);
/*
** fgl_texture.c
*/
GLuint fgl_texture_from_surface(const char *fn);

#endif
