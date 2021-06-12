#include "shaderClass.h"

//Lê os conteúdos dos arquivos .shader e converte para um char *
static char *ParseShader(const char *shader)
{
  FILE *file;
  char *ss;
  long size;
  file = fopen(shader, "r");

  if (file == NULL)
  {
    puts("Arquivo nao encontrado\n");
  }

  fseek(file, 0, SEEK_END);
  size = ftell(file);
  fseek(file, 0, SEEK_SET);
  ss = (char *)calloc((size / sizeof(char)), size);
  fread(ss, size, 1, file);

  free(file);

  fclose(file);

  return ss;
}

void activateShader(struct Shader shader)
{
  //Usa o Programa Shader situado baseado em sua identificação
  glUseProgram(shader.id);
}

void deleteShader(struct Shader shader)
{
  //Deleta o Programa Shader com sua identificação
  glDeleteProgram(shader.id);
}

void deleteAll(struct Shader shader, struct VAO vao, struct VBO vbo, struct EBO ebo)
{
  shader.Delete(shader);
  vao.Delete(vao);
  vbo.Delete(vbo);
  ebo.Delete(ebo);
}

struct Shader beginShader(const char *vs, const char *fs)
{
  struct Shader shader;

  shader.Activate = activateShader;
  shader.Delete = deleteShader;

  //Conteúdo dos arquivos Vertice e Fragment Shader
  const char *vertexSource = ParseShader(vs);
  const char *fragmentSource = ParseShader(fs);

  //Cria a referência e o número de referência para o Vertex Shader Object
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  //Anexa o Vertex Shader Source ao Vertex Shader Object
  glShaderSource(vertexShader, 1, &vertexSource, NULL);

  //Compila o Vertex Chader
  glCompileShader(vertexShader);

  int result;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE)
  {
    int lenght;
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &lenght);
    char *message = (char *)_alloca(lenght * sizeof(char));
    glGetShaderInfoLog(vertexShader, lenght, &lenght, message);
    puts("Failed to compile vertex shader\n");
    puts(message);
    glDeleteShader(vertexShader);
  }

  //Cria a referência e o de referência para o Fragment Shader Object
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  //Anexa o Fragment Shader Source ao Vertex Shader Object
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

  //Compila o Fragment Shader
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE)
  {
    int lenght;
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &lenght);
    char *message = (char *)malloc(lenght * sizeof(char));
    glGetShaderInfoLog(fragmentShader, lenght, &lenght, message);
    puts("Failed to compile fragment shader\n");
    puts(message);
    glDeleteShader(fragmentShader);
  }

  //Cria o programa e sua referência
  shader.id = glCreateProgram();

  //Junta o Vertex e o Fragment Shaders em um Programa Shader
  glAttachShader(shader.id, vertexShader);
  glAttachShader(shader.id, fragmentShader);

  //Liga todos os Shaders ao Programa Shader
  glLinkProgram(shader.id);

  //Desliga o Vertex Shader e o Fragment Shader do Programa Shader
  glDetachShader(shader.id, vertexShader);
  glDetachShader(shader.id, fragmentShader);

  //Deleta o Vertex Shader e o Fragment Shader
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  return shader;
}