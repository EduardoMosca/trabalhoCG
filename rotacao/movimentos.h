#include "cglm/call.h"
#include "gl/glew.h"
#include "src/Shader/shaderClass.h"
#include <SDL2/SDL.h>
#include <stdio.h>
//SDL_GetTicks()
void orbita(struct Shader shader)
{
  mat4 trans;
  glmc_mat4_identity(trans);
  glm_translate(trans, (vec3){-0.5f, 0.f, 0.5f});
  glm_rotate(trans, (float)SDL_GetTicks() / 1000, (vec3){1.0f, 0.f, .0f});
  glUniformMatrix4fv(glGetUniformLocation(shader.id, "transform"), 1, GL_FALSE, (float *)trans);
}

void orbita2(struct Shader shader)
{
  mat4 trans;
  glmc_mat4_identity(trans);
  glm_translate(trans, (vec3){0.5f, -0.5f, 0.0f});
  glm_rotate(trans, (float)SDL_GetTicks() / 1000, (vec3){1.0f, 1.0f, 0.0f});
  glUniformMatrix4fv(glGetUniformLocation(shader.id, "transform"), 1, GL_FALSE, (float *)trans);
}

void vai_e_vem(struct Shader shader)
{
  mat4 trans;
  glmc_mat4_identity(trans);
  glm_translate(trans, (vec3){0.5f, -0.5f, 0.0f});
  glm_rotate(trans, (float)SDL_GetTicks() / 1000, (vec3){.0f, .0f, .0f});
  glUniformMatrix4fv(glGetUniformLocation(shader.id, "transform"), 1, GL_FALSE, (float *)trans);
}

void martelo(struct Shader shader)
{
  mat4 trans;
  glmc_mat4_identity(trans);
  glm_rotate(trans, (float)cos((((float)SDL_GetTicks() / 10) * M_PI) / 180), (vec3){.0f, .0f, 1.0f});
  glUniformMatrix4fv(glGetUniformLocation(shader.id, "transform"), 1, GL_FALSE, (float *)trans);
}