#ifndef TROCA_COR_H
#define TROCA_COR_H

#include <gl/glew.h>
#include <SDL2/SDL.h>

#include "cglm/call.h"
#include "Shader/shaderClass.h"

void trocaCor(const Uint8 *keyState, vec4 lightColor, struct Shader lightShader)
{
  //Reduz o RGB do cubo pressionando R, G e B respecticamente
  if (keyState[SDL_SCANCODE_R] && lightColor[0] > 0.0f)
  {
    lightColor[0] = lightColor[0] - 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }
  if (keyState[SDL_SCANCODE_G] && lightColor[1] > 0.0f)
  {
    lightColor[1] = lightColor[1] - 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }
  if (keyState[SDL_SCANCODE_B] && lightColor[2] > 0.0f)
  {
    lightColor[2] = lightColor[2] - 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }

  //Aumenta o RGB do cubo pressionando T, G, N respectivamente
  if (keyState[SDL_SCANCODE_T] && lightColor[0] < 1.0f)
  {
    lightColor[0] = lightColor[0] + 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }
  if (keyState[SDL_SCANCODE_H] && lightColor[1] < 1.0f)
  {
    lightColor[1] = lightColor[1] + 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }
  if (keyState[SDL_SCANCODE_N] && lightColor[2] < 1.0f)
  {
    lightColor[2] = lightColor[2] + 0.01;
    glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  }
}

#endif