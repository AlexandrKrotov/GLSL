/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:06:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:06:42 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void		fsdl_project_exec_no_data(t_fvoid f, t_sdlsub subs)
{
	fsdl_init_everything();
	if (subs & SDL_TTF)
		fsdl_init_ttf();
	if (subs & SDL_MIX)
		fsdl_init_mixer();
	if (f != NULL)
		f();
	if (subs & SDL_MIX)
		Mix_Quit();
	if (subs & SDL_TTF)
		TTF_Quit();
	SDL_Quit();
}

void		fsdl_project_exec_with_data(t_fdata f, void *data, t_sdlsub subs)
{
	fsdl_init_everything();
	if (subs & SDL_TTF)
		TTF_Init();
	if (subs & SDL_MIX)
		fsdl_init_mixer();
	if (f != NULL)
		f(data);
	if (subs & SDL_MIX)
		Mix_Quit();
	if (subs & SDL_TTF)
		TTF_Quit();
	SDL_Quit();
}

void		fsdl_init_everything(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL could not init. SDL Err: %s\n", SDL_GetError());
		exit(0);
	}
}

void		fsdl_init_ttf(void)
{
	if (TTF_Init() < 0)
	{
		SDL_Log("SDL TTF could not init. SDL Err: %s\n", SDL_GetError());
		exit(0);
	}
}

void		fsdl_init_mixer(void)
{
	if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3) < 0)
	{
		SDL_Log("SDL MIXER could not init. SDL Err: %s\n", SDL_GetError());
		exit(0);
	}
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 4096) < 0)
	{
		SDL_Log("SDL Audio failed. SDL Err: %s\n", SDL_GetError());
		exit(0);
	}
}

SDL_GLTXT	fsdl_glcontext_create(t_wnd *wnd)
{
	SDL_GLContext gl;

	if ((gl = SDL_GL_CreateContext(wnd->p)) == NULL)
		fsdl_errors_log(ERR_GL_CONTEXT);
	return (gl);
}
