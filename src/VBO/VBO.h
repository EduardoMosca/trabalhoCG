#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#define GLEW_BUILD
#include <gl/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>

struct VBO
{
  //id de referência para o Vertex Buffer Object
  unsigned int id;

  //Bind o Vertex Buffer Object
  void (*Bind)(struct VBO vbo);
  //Unbind o Vertex Buffer Object
  void (*Unbind)(struct VBO vbo);
  //Deleta o Vertex Buffer Object
  void (*Delete)(struct VBO vbo);
};

void bindVBO(struct VBO vbo);

void unbindVBO(struct VBO vbo);

void deleteVBO(struct VBO vbo);

//"Construtor" da "classe VBO" que gera o Vertex Buffer Object e o associa aos vertices
struct VBO beginVBO(float *vertices, uint64_t size);

#endif