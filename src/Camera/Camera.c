#include "Camera.h"

void updateMatrix(struct Camera *camera, float FOVdeg, float nearPlane, float farPlane)
{
  mat4 view;
  mat4 proj;
  glmc_mat4_identity(view);
  glmc_mat4_identity(proj);

  vec3 add_view_proj = GLM_VEC3_ZERO_INIT;
  mat4 mult_proj_view;
  glm_mat4_identity(mult_proj_view);

  glmc_vec3_add(camera->Position, camera->Orientation, add_view_proj);
  glmc_lookat(camera->Position, add_view_proj, camera->Up, view);
  glmc_perspective(glm_rad(FOVdeg), (float)(camera->width / camera->height), nearPlane, farPlane, proj);

  glmc_mat4_mul(proj, view, mult_proj_view);
  glmc_mat4_copy(mult_proj_view, camera->cameraMatrix);
}

void Matrix(struct Camera *camera, struct Shader *shader, const char *uniform)
{
  glUniformMatrix4fv(glGetUniformLocation(shader->id, uniform), 1, GL_FALSE, (float *)camera->cameraMatrix);
}

void Inputs(struct Camera *camera, SDL_Window *window)
{
  SDL_PumpEvents();

  const Uint8 *keyState = SDL_GetKeyboardState(NULL);
  int mouseX = 0, mouseY = 0;

  if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON_LMASK)
  {
    SDL_ShowCursor(SDL_DISABLE);
    SDL_WarpMouseInWindow(window, (camera->width / 2), (camera->height / 2));

    vec3 newOrientation = GLM_VEC3_ZERO_INIT;
    vec3 negative_up = GLM_VEC3_ZERO_INIT;
    vec3 normalize_orientation_up = GLM_VEC3_ZERO_INIT;

    float rotX = camera->sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
    float rotY = camera->sensitivity * (float)(mouseX - (camera->height / 2)) / camera->height;

    glmc_vec3_cross(camera->Orientation, camera->Up, normalize_orientation_up);
    glmc_vec3_normalize(normalize_orientation_up);
    glmc_vec3_copy(camera->Orientation, newOrientation);
    //Se der errado tentar usar apenas glmc_rotate
    glmc_vec3_rotate(newOrientation, glm_rad(-rotX), normalize_orientation_up);
    glmc_vec3_negate_to(camera->Up, negative_up);
    if (!((glmc_vec3_angle(newOrientation, camera->Up) <= glm_rad(5.f)) || (glmc_vec3_angle(newOrientation, negative_up) <= glm_rad(5.f))))
    {
      glmc_vec3_copy(newOrientation, camera->Orientation);
    }
    //Caso der errado trocar aqui tbm
    glmc_vec3_rotate(camera->Orientation, glm_rad(-rotY), camera->Up);
  }
  else
  {
    SDL_ShowCursor(SDL_ENABLE);
  }

  if (keyState[SDL_SCANCODE_W])
  {
    vec3 multi_orientation_speed = GLM_VEC3_ZERO_INIT;
    glmc_vec3_scale(camera->Orientation, camera->speed, multi_orientation_speed);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, multi_orientation_speed, camera->Position);
  }
  if (keyState[SDL_SCANCODE_A])
  {
    vec3 normalize_orientation_up = GLM_VEC3_ZERO_INIT;
    vec3 multi_orientation_speed = GLM_VEC3_ZERO_INIT;
    glmc_vec3_cross(camera->Orientation, camera->Up, normalize_orientation_up);
    glmc_vec3_normalize(normalize_orientation_up);
    glmc_vec3_negate(normalize_orientation_up);
    glmc_vec3_scale(normalize_orientation_up, camera->speed, normalize_orientation_up);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, normalize_orientation_up, camera->Position);
  }
  if (keyState[SDL_SCANCODE_S])
  {
    vec3 multi_orientation_speed = GLM_VEC3_ZERO_INIT;
    vec3 negative_orientation = GLM_VEC3_ZERO_INIT;

    glmc_vec3_negate_to(camera->Orientation, negative_orientation);
    glmc_vec3_scale(negative_orientation, camera->speed, multi_orientation_speed);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, multi_orientation_speed, camera->Position);
  }
  if (keyState[SDL_SCANCODE_D])
  {
    vec3 normalize_orientation_up = GLM_VEC3_ZERO_INIT;
    vec3 multi_orientation_speed = GLM_VEC3_ZERO_INIT;
    glmc_vec3_cross(camera->Orientation, camera->Up, normalize_orientation_up);
    glmc_vec3_normalize(normalize_orientation_up);
    glmc_vec3_scale(normalize_orientation_up, camera->speed, normalize_orientation_up);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, normalize_orientation_up, camera->Position);
  }

  if (keyState[SDL_SCANCODE_SPACE])
  {
    vec3 multi_speed_up = GLM_VEC3_ZERO_INIT;
    glmc_vec3_scale(camera->Up, camera->speed, multi_speed_up);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, multi_speed_up, camera->Position);
  }

  if (keyState[SDL_SCANCODE_LCTRL])
  {
    vec3 negative_up = GLM_VEC3_ZERO_INIT;
    vec3 multi_speed_up = GLM_VEC3_ZERO_INIT;
    glmc_vec3_negate_to(camera->Up, negative_up);
    glmc_vec3_scale(negative_up, camera->speed, multi_speed_up);
    //se der ruim criar variável auxiliar para fazer de position e depois fazer a atribuição
    glmc_vec3_add(camera->Position, multi_speed_up, camera->Position);
  }

  if (keyState[SDL_SCANCODE_LSHIFT])
  {
    camera->speed = 0.4f;
  }
  else if (!keyState[SDL_SCANCODE_LSHIFT])
  {
    camera->speed = 0.1f;
  }
}

struct Camera beginCamera(int width, int height, vec3 position)
{
  struct Camera camera;

  camera.Position;
  camera.width = width;
  camera.height = height;
  glm_mat4_identity(camera.cameraMatrix);

  camera.Inputs = Inputs;
  camera.Matrix = Matrix;
  camera.updateMatrix = updateMatrix;

  camera.speed = 0.1f;
  camera.sensitivity = 100.f;

  camera.firstClick = true;

  glmc_vec3_copy(position, camera.Position);
  glmc_vec3_copy((vec3){0.f, 0.f, -1.f}, camera.Orientation);
  glmc_vec3_copy((vec3){0.f, 1.f, 0.f}, camera.Up);

  return camera;
}