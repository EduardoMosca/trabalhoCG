#include "VBO.h"

void bindVBO(struct VBO vbo)
{
  glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
}

void unbindVBO(struct VBO vbo)
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void deleteVBO(struct VBO vbo)
{
  glDeleteBuffers(1, &vbo.id);
}

struct VBO beginVBO(float *vertices, uint64_t size)
{
  struct VBO vbo;

  vbo.Bind = bindVBO;
  vbo.Unbind = unbindVBO;
  vbo.Delete = deleteVBO;

  glGenBuffers(1, &vbo.id);
  glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  return vbo;
}