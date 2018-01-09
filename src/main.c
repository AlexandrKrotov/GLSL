#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fsdl.h"
#include "fgl.h"

#define D_WIDTH		1200
#define D_HEIGHT	800
#define D_NAME		"BestShaderEver"		

typedef struct s_m t_m;

struct s_m {
	t_bool			loop;
	t_lprm			*lprm;
	SDL_GLContext	gLContext;
	float			zoom;
	float			trans_x;
	float			trans_y;
};


void    ft_general_keydown_check(t_m *id)
{
	SDL_Event *e;

	e = &id->lprm->e;
	if (id->lprm->efl == false)
		return;
	if (e->type == SDL_QUIT)
		id->loop = false;
	else if (e->type == SDL_KEYDOWN)
	{
		if (e->key.keysym.sym == SDLK_ESCAPE)
			id->loop = false;
		else if (e->key.keysym.sym == SDLK_EQUALS )
			id->zoom += 0.01f;
		else if (e->key.keysym.sym == SDLK_MINUS && id->zoom - 0.01 >= 0)
			id->zoom -= 0.01f;
		else if (e->key.keysym.sym == SDLK_UP)
			id->trans_y += 0.01f;
		else if (e->key.keysym.sym == SDLK_DOWN)
			id->trans_y -= 0.01f;
		else if (e->key.keysym.sym == SDLK_LEFT)
			id->trans_x -= 0.01f;
		else if (e->key.keysym.sym == SDLK_RIGHT)
			id->trans_x += 0.01f;
	}
}

void ft_init(t_m *m)
{
	m->lprm = fsdl_lprm_create();
	m->lprm->wnd = fsdl_window_create_stuct(D_WIDTH, D_HEIGHT, D_NAME);
	fsdl_window_create(m->lprm->wnd);
	m->gLContext = fsdl_glcontext_create(m->lprm->wnd);
	fgl_glew_init();
	m->zoom = 1.0;
	m->trans_x = 0.0;
	m->trans_y = 0.0;
	m->loop = true;
}

void ft_loop(t_m *m)
{
	///triangle programm
		//GLuint triangleShader[2];
		//triangleShader[0] = fgl_shader_from_file("shaders/triangle.vs.glsl", GL_VERTEX_SHADER);
		//triangleShader[1] = fgl_shader_from_file("shaders/triangle.fs.glsl", GL_FRAGMENT_SHADER);
		//GLuint triangleProgram;
		//triangleProgram = fgl_program_create_and_link(triangleShader, 2);
		//GLfloat points[] = {
		//	0.0f,  0.5f,  0.0f,
		//	0.5f, -0.5f,  0.0f,
		//	-0.5f, -0.5f,  0.0f
		//};
		//GLuint vbo = 0;
		//glGenBuffers(1, &vbo);
		//glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);
		//GLuint vao = 0;
		//glGenVertexArrays(1, &vao);
		//glBindVertexArray(vao);
		//glEnableVertexAttribArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	///end

	///sphere program
		GLuint shader[1];
		shader[0] = fgl_shader_from_file("shaders/sphere.fs.glsl", GL_FRAGMENT_SHADER);
		GLuint program;
		program = fgl_program_create_and_link(shader, 1);
		static const GLfloat quadvertices[] = {
			-1.0f, 1.0f, .0f,
			1.0f, -1.0f, .0f,
			-1.0f, -1.0f, .0f,
			-1.0f, 1.0f, .0f,
			1.0f, 1.0f, .0f,
			1.0f, -1.0f, .0f,
		};
		GLuint vbo = 0;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadvertices), quadvertices, GL_STATIC_DRAW);
		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(0);
	///end
	///quads program
		//GLuint shader[1];
		//shader[0] = fgl_shader_from_file("shaders/quads.fs.glsl", GL_FRAGMENT_SHADER);
		//GLuint program;
		//program = fgl_program_create_and_link(shader, 1);
	///end
	float frames = 0;
	while (m->loop == true)
	{
		fsdl_loop_regular_operations(m->lprm);
		ft_general_keydown_check(m);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		///sphere program
			GLuint idTime = glGetUniformLocation(program, "iTime");
			printf("%f\n", frames);
			glUniform1f(idTime, frames);
			glUseProgram(program);
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
		///quads program
			//GLuint idTime = glGetUniformLocation(program, "iTime");
			//printf("%f\n", frames );
			//glUniform1f(idTime, frames);
			//glUseProgram(program);
		///end
		///triangle programm
			//glBindVertexArray(vao);
			//GLuint zoomId = glGetUniformLocation(triangleProgram, "nav.zoom");
			//glUniform1f(zoomId, m->zoom);
			//GLuint transId = glGetUniformLocation(triangleProgram, "tv");
			//glUniform2f(transId, m->trans_x, m->trans_y);
			//glUseProgram(triangleProgram);
			//glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
		///end
		///quads program
			//glBegin(GL_QUADS);
			//	glTexCoord2f(0, 0);
			//	glVertex2f(-1, -1);
			//	glTexCoord2f(1, 0);
			//	glVertex2f(1, -1);
			//	glTexCoord2f(1, 1);
			//	glVertex2f(1, 1);
			//	glTexCoord2f(0, 1);
			//	glVertex2f(-1, 1);
			//glEnd();

		///end
		SDL_GL_SwapWindow(m->lprm->wnd->p);
		SDL_Delay(10);
		frames += 0.01;
	}
}

void	lets_start(void)
{
	t_m m;

	ft_init(&m);
	ft_loop(&m);
}

int	main(int argc, char **argv)
{
	fsdl_project_exec_no_data(lets_start, SDL_ALL);
	return (0);	
}