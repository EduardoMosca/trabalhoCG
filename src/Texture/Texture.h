#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <gl/glew.h>
#include <stdbool.h>
#include "../stb/stb_image.h"
#include "../Shader/shaderClass.h"

struct Texture
{
  unsigned int id;
  unsigned int type;

  void (*texUnit)(struct Shader shader, const char *uniform, unsigned int unit);
  void (*Bind)(struct Texture texture);
  void (*Unbind)(struct Texture texture);
  void (*Delete)(struct Texture texture);
};

struct Texture beginTexture(const char *image, unsigned int texType, unsigned int slot, unsigned int format, unsigned int pixelType);

void texUnit(struct Shader shader, const char *uniform, unsigned int unit);

void bindTexture(struct Texture texture);

void unbindTexture(struct Texture texture);

void deleteTexture(struct Texture texture);

#endif
