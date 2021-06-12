#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#define GLEW_BUILD
#include <gl/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "../VAO/VAO.h"
#include "../VBO/VBO.h"
#include "../EBO/EBO.h"

struct Shader
{
  //Referência do Shader Program
  unsigned int id;

  //Ativa o programa Shader
  void (*Activate)(struct Shader shader);
  //Deleta o programa Shader
  void (*Delete)(struct Shader shader);

  void (*deleteAll)(struct Shader shader, struct VAO vao, struct VBO vbo, struct EBO ebo);
};

struct Shader beginShader(const char *vs, const char *fs);

void deleteShader(struct Shader shader);

void activateShader(struct Shader shader);

void deleteAll(struct Shader shader, struct VAO vao, struct VBO vbo, struct EBO ebo);

//"Construtor" da "classe Shader" para construir o Vertice e o Fragment Shader
static char *ParseShader(const char *shader);

#endif