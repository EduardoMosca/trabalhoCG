#include "EBO.h"

void bindEBO(struct EBO ebo)
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);
}

void unbindEBO()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void deleteEBO(struct EBO ebo)
{
  glDeleteBuffers(1, &ebo.id);
}

struct EBO beginEBO(unsigned int *indices, GLsizeiptr size)
{
  struct EBO ebo;

  ebo.Bind = bindEBO;
  ebo.Unbind = unbindEBO;
  ebo.Delete = deleteEBO;

  glGenBuffers(1, &ebo.id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  return ebo;
}