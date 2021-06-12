#ifndef MOVE_CUBO_H
#define MOVE_CUBO_H

#include <gl/glew.h>
#include <SDL2/SDL.h>
#include "cglm/call.h"

#include "Shader/shaderClass.h"
#include "VAO/VAO.h"
#include "VBO/VBO.h"

void moveCuboFrente(float *lightVertices, vec3 lightPos, struct VBO lightVBO)
{
  lightVertices[2] -= 0.01f;
  lightVertices[5] -= 0.01f;
  lightVertices[8] -= 0.01f;
  lightVertices[11] -= 0.01f;
  lightVertices[14] -= 0.01f;
  lightVertices[17] -= 0.01f;
  lightVertices[20] -= 0.01f;
  lightVertices[23] -= 0.01f;
  lightPos[2] -= 0.01f;
}

void moveCuboTras(float *lightVertices, vec3 lightPos, struct VBO lightVBO)
{
  lightVertices[2] += 0.01f;
  lightVertices[5] += 0.01f;
  lightVertices[8] += 0.01f;
  lightVertices[11] += 0.01f;
  lightVertices[14] += 0.01f;
  lightVertices[17] += 0.01f;
  lightVertices[20] += 0.01f;
  lightVertices[23] += 0.01f;
  lightPos[2] += 0.01f;
}

void moveCuboEsquerda(float *lightVertices, vec3 lightPos, struct VBO lightVBO)
{
  lightVertices[0] -= 0.01f;
  lightVertices[3] -= 0.01f;
  lightVertices[6] -= 0.01f;
  lightVertices[9] -= 0.01f;
  lightVertices[12] -= 0.01f;
  lightVertices[15] -= 0.01f;
  lightVertices[18] -= 0.01f;
  lightVertices[21] -= 0.01f;
  lightPos[0] -= 0.01f;
}

void moveCuboDireita(float *lightVertices, vec3 lightPos, struct VBO lightVBO)
{
  lightVertices[0] += 0.01f;
  lightVertices[3] += 0.01f;
  lightVertices[6] += 0.01f;
  lightVertices[9] += 0.01f;
  lightVertices[12] += 0.01f;
  lightVertices[15] += 0.01f;
  lightVertices[18] += 0.01f;
  lightVertices[21] += 0.01f;
  lightPos[0] += 0.01f;
}

#endif