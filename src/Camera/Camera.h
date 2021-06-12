#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <stdbool.h>
#include "gl/glew.h"
#include "SDL2/SDL.h"
#include "cglm/call.h"
#include "../Shader/shaderClass.h"

struct Camera
{
  vec3 Position;
  vec3 Orientation;
  vec3 Up;
  mat4 cameraMatrix;

  bool firstClick;

  int width;
  int height;

  float speed;
  float sensitivity;

  void (*Inputs)(struct Camera *camera, SDL_Window *window);
  void (*updateMatrix)(struct Camera *camera, float FOVdeg, float nearPlane, float farPlane);
  void (*Matrix)(struct Camera *camera, struct Shader *shader, const char *uniform);
};

struct Camera beginCamera(int width, int height, vec3 position);

void Inputs(struct Camera *camera, SDL_Window *window);

void updateMatrix(struct Camera *camera, float FOVdeg, float nearPlane, float farPlane);

void Matrix(struct Camera *camera, struct Shader *shader, const char *uniform);

#endif