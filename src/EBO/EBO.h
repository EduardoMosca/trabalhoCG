#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#define GLEW_BUILD
#include <gl/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>

struct EBO
{
  //Referência de identificação do Elements Buffer Object
  unsigned int id;

  //Bind o EBO
  void (*Bind)(struct EBO ebo);
  //Unbind o EBO
  void (*Unbind)();
  //Deleta o EBO
  void (*Delete)(struct EBO ebo);
};

void bindEBO(struct EBO ebo);

void unbindEBO();

void deleteEBO(struct EBO ebo);

//"Construtor" da "classe EBO" que gera o Element Buffer Object e o associa aos indices
struct EBO beginEBO(unsigned int *indices, GLsizeiptr size);

#endif