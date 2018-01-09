#include "fgl.h"

/*
** Create needed number of buffers n in array buffers:
** void glCreateBuffers(GLsizei n, GLuint *buffers);

** Allocating data stores:
** void glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
** void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);

** Copy data to buffer:
** void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
** void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);

** Copy data to buffer part
** void *glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
** void *glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);

** Set mapped access to buffer in client space
** void *glMapBuffer(GLenum target, GLenum usage);
** void *glMapNamedBuffer(GLuint buffer, GLenum usage);

** Release the mapping of buffer
** void glUnmapBuffer(GLenum target);
** void glUnmapNamedBuffer(GLuint buffer);

** Bind created buffer name to target
** void glBindBuffer(GLenum target, GLuint buffer);

** Put constant data to buffer
** void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum type, GLenum type, const void *data);
** void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);

** Copy data from buffer to buffer
void glCopyBufferSubData(GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
*/


