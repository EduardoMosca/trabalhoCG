#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#define GLEW_BUILD
#include <gl/glew.h>
#include "../VBO/VBO.h"

struct VAO
{
  //ReferÊncia de identificação para o Vertex Array Object
  unsigned int id;

  //Liga o VBO ao VAO usando o layout indicado
  void (*LinkAttrib)(struct VBO VBO, unsigned int layout, unsigned int numComponents, unsigned int type, uint64_t stride, void *offset);

  //Bind o VAO
  void (*Bind)(struct VAO VAO);

  //Unbind o VAO
  void (*Unbind)();

  //Deleta o VAO
  void (*Delete)(struct VAO VAO);
};

void LinkAttrib(struct VBO VBO, unsigned int layout, unsigned int numComponents, unsigned int type, uint64_t stride, void *offset);

void bindVAO(struct VAO VAO);

void unbindVAO();

void deleteVAO(struct VAO VAO);

//"Construtor" da "classe VAO" que gera o id do VAO
struct VAO beginVAO();

#endif