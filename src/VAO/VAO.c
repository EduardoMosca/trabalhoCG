#include "VAO.h"

void LinkAttrib(struct VBO VBO, unsigned int layout, unsigned int numComponents, unsigned int type, uint64_t stride, void *offset)
{
  VBO.Bind(VBO);
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind(VBO);
}

void bindVAO(struct VAO VAO)
{
  glBindVertexArray(VAO.id);
}

void unbindVAO()
{
  glBindVertexArray(0);
}

void deleteVAO(struct VAO VAO)
{
  glDeleteVertexArrays(1, &VAO.id);
}

struct VAO beginVAO()
{
  struct VAO vao;

  vao.Bind = bindVAO;
  vao.Unbind = unbindVAO;
  vao.Delete = deleteVAO;
  vao.LinkAttrib = LinkAttrib;

  glGenVertexArrays(1, &vao.id);
  return vao;
};