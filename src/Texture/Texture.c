#include "Texture.h"

void texUnit(struct Shader shader, const char *uniform, unsigned int unit)
{
  unsigned int tex0Uni = glGetUniformLocation(shader.id, uniform);
  shader.Activate(shader);
  glUniform1i(tex0Uni, unit);
}

void bindTexture(struct Texture texture)
{
  glBindTexture(texture.type, texture.id);
}

void unbindTexture(struct Texture texture)
{
  glBindTexture(texture.type, 0);
}

void deleteTexture(struct Texture texture)
{
  glDeleteTextures(1, &texture.id);
}

struct Texture beginTexture(const char *image, unsigned int texType, unsigned int slot, unsigned int format, unsigned int pixelType)
{
  struct Texture texture;
  texture.type = texType;

  texture.texUnit = texUnit;
  texture.Bind = bindTexture;
  texture.Unbind = unbindTexture;
  texture.Delete = deleteTexture;

  int widthImg, heightImg, numColCh;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

  glGenTextures(1, &texture.id);
  glActiveTexture(slot);
  glBindTexture(texType, texture.id);

  glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

  //float flatColor[] = {1.f, 1.f, 1.f, 1.f};
  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatcolor);

  glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
  glGenerateMipmap(texType);

  stbi_image_free(bytes);
  glBindTexture(texType, 0);

  return texture;
}