#define GLEW_BUILD
#include <gl/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "cglm/call.h"
#include "src/Camera/Camera.h"
#include "src/Shader/shaderClass.h"
#include "src/Texture/Texture.h"
#include "src/STB/stb_image.h"
#include "src/VAO/VAO.h"
#include "src/VBO/VBO.h"
#include "src/EBO/EBO.h"

#include "src/trocaCor.h"
#include "src/moveCubo.h"

#include "pontos/piramide.h"
#include "pontos/paralelepipedo.h"
#include "pontos/pendulo.h"
#include "pontos/light.h"
#include "pontos/platao.h"
#include "pontos/prisma.h"
#include "pontos/prismahex.h"
#include "pontos/piramidehex.h"
#include "pontos/tetraedro.h"
#include "pontos/pentagono.h"

#include "rotacao/movimentos.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

//-mwindow

int SDL_main(int argc, char *args[])
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Hello",
                                        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

  if (NULL == window)
  {
    return EXIT_FAILURE;
  }

  SDL_Event windowEvent;

  SDL_GL_CreateContext(window);

  if (glewInit() != GLEW_OK)
    return EXIT_FAILURE;

  //printf("%s\n", glGetString(GL_VERSION));

  //Gera o Shader
  struct Shader shaderProgram = beginShader("res/shaders/piramide/sv1.shader", "res/shaders/piramide/sf1.shader");
  //Gerao Vertex Array Object e bainda ele
  struct VAO vao1 = beginVAO();
  vao1.Bind(vao1);

  //Gera o Vertex Buffer linkando-o ao vértice
  struct VBO vbo1 = beginVBO(positions, sizeof(positions));
  //Gera o Element Buffer e linka ele com os índices do vetor posições
  struct EBO ebo1 = beginEBO(indices, sizeof(indices));

  //Conecta o VBO ao VAO
  vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void *)0);
  vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void *)(3 * sizeof(float)));
  vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void *)(6 * sizeof(float)));
  vao1.LinkAttrib(vbo1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void *)(8 * sizeof(float)));
  //Unbind em todos os objetos que foram bindados
  vao1.Unbind(vao1);
  vbo1.Unbind(vbo1);
  ebo1.Unbind(ebo1);

  //Prisma Shader

  struct Shader prismaShader = beginShader("res/shaders/prisma/prismaVertex.shader", "res/shaders/prisma/prismaFragment.shader");

  struct VAO prismaVAO = beginVAO();
  prismaVAO.Bind(prismaVAO);

  struct VBO prismaVBO = beginVBO(prismaPos, sizeof(prismaPos));
  struct EBO prismaEBO = beginEBO(prismaInd, sizeof(prismaInd));

  prismaVAO.LinkAttrib(prismaVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  prismaVAO.LinkAttrib(prismaVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  prismaVAO.Unbind(prismaVAO);
  prismaVBO.Unbind(prismaVBO);
  prismaEBO.Unbind(prismaEBO);

  //Platao Shader

  struct Shader plataoShader = beginShader("res/shaders/platao/plataoVertex.shader", "res/shaders/platao/plataoFragment.shader");

  struct VAO plataoVAO = beginVAO();
  plataoVAO.Bind(plataoVAO);

  struct VBO plataoVBO = beginVBO(plataoPos, sizeof(plataoPos));
  struct EBO plataoEBO = beginEBO(plataoInd, sizeof(plataoInd));

  plataoVAO.LinkAttrib(plataoVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  plataoVAO.LinkAttrib(plataoVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  plataoVAO.Unbind(plataoVAO);
  plataoVBO.Unbind(plataoVBO);
  plataoEBO.Unbind(plataoEBO);

  //Prisma Hex shader

  struct Shader prismahexShader = beginShader("res/shaders/prismahex/prismahexVertex.shader", "res/shaders/prismahex/prismahexFragment.shader");

  struct VAO prismahexVAO = beginVAO();
  prismahexVAO.Bind(prismahexVAO);

  struct VBO prismahexVBO = beginVBO(prismahexPos, sizeof(prismahexPos));
  struct EBO prismahexEBO = beginEBO(prismahexInd, sizeof(prismahexInd));

  prismahexVAO.LinkAttrib(prismahexVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  prismahexVAO.LinkAttrib(prismahexVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  prismahexVAO.Unbind(prismahexVAO);
  prismahexVBO.Unbind(prismahexVBO);
  prismahexEBO.Unbind(prismahexEBO);

  //Paralelepipedo shader

  struct Shader paralelShader = beginShader("res/shaders/paralelepipedo/paralelVertex.shader", "res/shaders/paralelepipedo/paralelFragment.shader");

  struct VAO paralelVAO = beginVAO();
  paralelVAO.Bind(paralelVAO);

  struct VBO paralelVBO = beginVBO(paralelPos, sizeof(paralelPos));
  struct EBO paralelEBO = beginEBO(paralelIndices, sizeof(paralelIndices));

  paralelVAO.LinkAttrib(paralelVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  paralelVAO.LinkAttrib(paralelVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  paralelVAO.Unbind(paralelVAO);
  paralelVBO.Unbind(paralelVBO);
  paralelEBO.Unbind(paralelEBO);

  //Tetraedro Shader

  struct Shader tetraedroShader = beginShader("res/shaders/tetraedro/tetraedroVertex.shader", "res/shaders/tetraedro/tetraedroFragment.shader");

  struct VAO tetraedroVAO = beginVAO();
  tetraedroVAO.Bind(tetraedroVAO);

  struct VBO tetraedroVBO = beginVBO(tetraedroPos, sizeof(tetraedroPos));
  struct EBO tetraedroEBO = beginEBO(tetraedroInd, sizeof(tetraedroInd));

  tetraedroVAO.LinkAttrib(tetraedroVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  tetraedroVAO.LinkAttrib(tetraedroVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  tetraedroVAO.Unbind(tetraedroVAO);
  tetraedroVBO.Unbind(tetraedroVBO);
  tetraedroEBO.Unbind(tetraedroEBO);

  //Pentagono Shader

  struct Shader pentShader = beginShader("res/shaders/pentagono/pentagonoVertex.shader", "res/shaders/pentagono/pentagonoFragment.shader");

  struct VAO pentVAO = beginVAO();
  pentVAO.Bind(pentVAO);

  struct VBO pentVBO = beginVBO(pentPos, sizeof(pentPos));
  struct EBO pentEBO = beginEBO(pentInd, sizeof(pentInd));

  pentVAO.LinkAttrib(pentVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  pentVAO.LinkAttrib(pentVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  pentVAO.Unbind(pentVAO);
  pentVBO.Unbind(pentVBO);
  pentEBO.Unbind(pentEBO);

  //Piramide hex Shader

  struct Shader piramidehexShader = beginShader("res/shaders/piramidehex/piramidehexVertex.shader", "res/shaders/piramidehex/piramidehexFragment.shader");

  struct VAO piramidehexVAO = beginVAO();
  piramidehexVAO.Bind(piramidehexVAO);

  struct VBO piramidehexVBO = beginVBO(piramidehexPos, sizeof(piramidehexPos));
  struct EBO piramidehexEBO = beginEBO(piramidehexInd, sizeof(piramidehexInd));

  piramidehexVAO.LinkAttrib(piramidehexVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  piramidehexVAO.LinkAttrib(piramidehexVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void *)(3 * sizeof(float)));

  piramidehexVAO.Unbind(piramidehexVAO);
  piramidehexVBO.Unbind(piramidehexVBO);
  piramidehexEBO.Unbind(piramidehexEBO);

  //Pendulum Shader
  struct Shader pendShader = beginShader("res/shaders/pendulo/pendVert.shader", "res/shaders/pendulo/pendFrag.shader");

  struct VAO pendVAO = beginVAO();

  pendVAO.Bind(pendVAO);

  struct VBO pendVBO = beginVBO(pendPos, sizeof(pendPos));

  struct EBO pendEBO = beginEBO(indicesPend, sizeof(indicesPend));

  pendVAO.LinkAttrib(pendVBO, 0, 3, GL_FLOAT, 11 * sizeof(float), (void *)0);
  pendVAO.LinkAttrib(pendVBO, 1, 3, GL_FLOAT, 11 * sizeof(float), (void *)(3 * sizeof(float)));
  pendVAO.LinkAttrib(pendVBO, 2, 2, GL_FLOAT, 11 * sizeof(float), (void *)(6 * sizeof(float)));
  pendVAO.LinkAttrib(pendVBO, 3, 2, GL_FLOAT, 11 * sizeof(float), (void *)(8 * sizeof(float)));

  pendVAO.Unbind(pendVAO);
  pendVBO.Unbind(pendVBO);
  pendEBO.Unbind(pendEBO);

  //Ligh Shader
  struct Shader lightShader = beginShader("res/shaders/light/lightVertex.shader", "res/shaders/light/lightFragment.shader");

  struct VAO lightVAO = beginVAO();

  lightVAO.Bind(lightVAO);

  struct VBO lightVBO = beginVBO(lightVertices, sizeof(lightVertices));
  struct EBO lightEBO = beginEBO(lightIndices, sizeof(lightIndices));

  lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);

  vec4 lightColor = {1.0f, 1.0f, 1.0f};

  vec3 lightPos = {0.5f, 0.5f, 0.5f};
  mat4 lightModel;
  glmc_mat4_identity(lightModel);
  glm_translate(lightModel, lightPos);

  vec3 pyramidPos = GLM_VEC3_ZERO_INIT;
  mat4 pyramidModel;
  glmc_mat4_identity(pyramidModel);
  glm_translate(pyramidModel, pyramidPos);

  vec3 pend_pos = GLM_VEC3_ZERO_INIT;
  mat4 prismModel;
  glmc_mat4_identity(prismModel);
  glm_translate(prismModel, pend_pos);

  pendShader.Activate(pendShader);
  glUniformMatrix4fv(glGetUniformLocation(shaderProgram.id, "model"), 1, GL_FALSE, (float *)(pyramidModel));
  glUniform4f(glGetUniformLocation(shaderProgram.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  glUniform3f(glGetUniformLocation(shaderProgram.id, "lightPos"), lightPos[0], lightPos[1], lightPos[2]);

  lightShader.Activate(lightShader);
  glUniformMatrix4fv(glGetUniformLocation(lightShader.id, "model"), 1, GL_FALSE, (float *)lightModel);
  glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);

  shaderProgram.Activate(shaderProgram);
  glUniformMatrix4fv(glGetUniformLocation(shaderProgram.id, "model"), 1, GL_FALSE, (float *)(pyramidModel));
  glUniform4f(glGetUniformLocation(shaderProgram.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
  glUniform3f(glGetUniformLocation(shaderProgram.id, "lightPos"), lightPos[0], lightPos[1], lightPos[2]);

  //GL_RGBA para png e GL_RGB para jpeg/jpg
  struct Texture imagem = beginTexture("src/textures/brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
  struct Texture imagem2 = beginTexture("src/textures/granito.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
  imagem.texUnit(shaderProgram, "tex0", 0);
  imagem2.texUnit(pendShader, "tex0", 0);

  glEnable(GL_DEPTH_TEST);

  struct Camera camera = beginCamera(SCREEN_WIDTH, SCREEN_HEIGHT, (vec3){0.f, 0.f, 2.f});
  SDL_GL_SetSwapInterval(-1);
  while (true)
  {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    if (SDL_PollEvent(&windowEvent))
    {
      if (SDL_QUIT == windowEvent.type)
      {
        return EXIT_SUCCESS;
      }
    }
    //Cor do background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    //Limpa o buffer e o atribui uma nova cor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.Inputs(&camera, window);

    camera.updateMatrix(&camera, 45.f, 0.1f, 100.f);

    trocaCor(keyState, lightColor, lightShader);
    lightShader.Activate(lightShader);
    if (keyState[SDL_SCANCODE_UP])
    {
      moveCuboFrente(lightVertices, lightPos, lightVBO);
      lightVBO = beginVBO(lightVertices, sizeof(lightVertices));
      lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
    }

    if (keyState[SDL_SCANCODE_DOWN])
    {
      moveCuboTras(lightVertices, lightPos, lightVBO);
      lightVBO = beginVBO(lightVertices, sizeof(lightVertices));
      lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
    }

    if (keyState[SDL_SCANCODE_LEFT])
    {
      moveCuboEsquerda(lightVertices, lightPos, lightVBO);
      lightVBO = beginVBO(lightVertices, sizeof(lightVertices));
      lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
    }

    if (keyState[SDL_SCANCODE_RIGHT])
    {
      moveCuboDireita(lightVertices, lightPos, lightVBO);
      lightVBO = beginVBO(lightVertices, sizeof(lightVertices));
      lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
    }
    //Ativa o Programa Shader designado
    shaderProgram.Activate(shaderProgram);
    glUniform3f(glGetUniformLocation(shaderProgram.id, "camPos"), camera.Position[0], camera.Position[1], camera.Position[2]);
    glUniform4f(glGetUniformLocation(shaderProgram.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
    glUniform3f(glGetUniformLocation(shaderProgram.id, "lightPos"), lightPos[0], lightPos[1], lightPos[2]);
    camera.Matrix(&camera, &shaderProgram, "camMatrix");
    //Liga a textura para aparecer na renderização
    imagem.Bind(imagem);
    //Vincula o VAO ao OpenGL para ser usado
    vao1.Bind(vao1);
    //Desenha o elemento
    glDrawElements(GL_TRIANGLES, (sizeof(indices) / sizeof(unsigned int)), GL_UNSIGNED_INT, 0);

    imagem2.Bind(imagem2);

    //Ativa Pend
    pendShader.Activate(pendShader);
    glUniform3f(glGetUniformLocation(pendShader.id, "camPos"), camera.Position[0], camera.Position[1], camera.Position[2]);
    glUniform4f(glGetUniformLocation(pendShader.id, "lightColor"), lightColor[0], lightColor[1], lightColor[2], lightColor[3]);
    glUniform3f(glGetUniformLocation(pendShader.id, "lightPos"), lightPos[0], lightPos[1], lightPos[2]);
    camera.Matrix(&camera, &pendShader, "camMatrix");
    pendVAO.Bind(pendVAO);
    glDrawElements(GL_TRIANGLES, (sizeof(indicesPend) / sizeof(unsigned int)), GL_UNSIGNED_INT, 0);

    //Ativa prisma hex
    prismahexShader.Activate(prismahexShader);
    camera.Matrix(&camera, &prismahexShader, "camMatrix");
    prismahexVAO.Bind(prismahexVAO);
    orbita(prismahexShader);
    glDrawElements(GL_TRIANGLES, (sizeof(prismahexInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa prisma
    prismaShader.Activate(prismaShader);
    camera.Matrix(&camera, &plataoShader, "camMatrix");
    prismaVAO.Bind(prismaVAO);
    glDrawElements(GL_TRIANGLES, (sizeof(prismaInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa platao
    plataoShader.Activate(plataoShader);
    camera.Matrix(&camera, &plataoShader, "camMatrix");
    plataoVAO.Bind(plataoVAO);
    glDrawElements(GL_TRIANGLES, (sizeof(plataoInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa pentagono
    pentShader.Activate(pentShader);
    camera.Matrix(&camera, &pentShader, "camMatrix");
    pentVAO.Bind(pentVAO);
    martelo(pentShader);
    glDrawElements(GL_TRIANGLES, (sizeof(pentInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa tetraedro
    tetraedroShader.Activate(tetraedroShader);
    camera.Matrix(&camera, &tetraedroShader, "camMatrix");
    tetraedroVAO.Bind(tetraedroVAO);
    orbita2(tetraedroShader);
    glDrawElements(GL_TRIANGLES, (sizeof(tetraedroInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa piramide hex base
    piramidehexShader.Activate(piramidehexShader);
    camera.Matrix(&camera, &piramidehexShader, "camMatrix");
    piramidehexVAO.Bind(piramidehexVAO);
    vai_e_vem(piramidehexShader);
    glDrawElements(GL_TRIANGLES, (sizeof(piramidehexInd) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa paralelepipedo
    paralelShader.Activate(paralelShader);
    camera.Matrix(&camera, &paralelShader, "camMatrix");
    paralelVAO.Bind(paralelVAO);
    glDrawElements(GL_TRIANGLES, (sizeof(paralelIndices) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //Ativa light
    lightShader.Activate(lightShader);
    camera.Matrix(&camera, &lightShader, "camMatrix");
    lightVAO.Bind(lightVAO);
    glDrawElements(GL_TRIANGLES, (sizeof(lightIndices) / sizeof(unsigned int)), GL_UNSIGNED_INT, (void *)0);

    //update the window
    SDL_GL_SwapWindow(window);
  }

  lightVAO.Unbind(lightVAO);
  lightVBO.Unbind(lightVBO);
  lightEBO.Unbind(lightEBO);

  shaderProgram.deleteAll(shaderProgram, vao1, vbo1, ebo1);
  lightShader.deleteAll(lightShader, lightVAO, lightVBO, lightEBO);
  pendShader.deleteAll(pendShader, pendVAO, pendVBO, pendEBO);
  paralelShader.deleteAll(paralelShader, paralelVAO, paralelVBO, paralelEBO);
  plataoShader.deleteAll(plataoShader, plataoVAO, plataoVBO, plataoEBO);
  prismaShader.deleteAll(prismaShader, prismaVAO, prismaVBO, prismaEBO);
  prismahexShader.deleteAll(prismahexShader, prismahexVAO, prismahexVBO, prismahexEBO);
  piramidehexShader.deleteAll(piramidehexShader, piramidehexVAO, piramidehexVBO, piramidehexEBO);
  tetraedroShader.deleteAll(tetraedroShader, tetraedroVAO, tetraedroVBO, tetraedroEBO);
  pentShader.deleteAll(pentShader, pentVAO, pentVBO, pentEBO);

  imagem.Delete(imagem);
  imagem2.Delete(imagem2);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}