//0.74f, 0.7f, 0.56f,
float piramidehexPos[] =
    {
        0.f, 1.5f, -1.f, 0.74f, 0.7f, 0.56f,      //Ponta inferior esquerda 0
        0.5f, 1.5f, -1.f, 0.74f, 0.7f, 0.56f,     // Ponta inferior direita 1
        -0.25f, 1.5f, -1.43f, 0.74f, 0.7f, 0.56f, // Ponta media esquerda 2
        0.75f, 1.5f, -1.43f, 0.74f, 0.7f, 0.56f,  // Ponta media direita 3
        0.f, 1.5f, -1.86f, 0.74f, 0.7f, 0.56f,    //Ponta superior esquerda 4
        0.5f, 1.5f, -1.86f, 0.74f, 0.7f, 0.56f,   //Ponta superior direita 5
        0.25f, 1.5f, -1.43f, 0.74f, 0.7f, 0.56f,  // Centro 6
        0.25f, 2.5f, -1.43f, 0.74f, 0.7f, 0.56f,  // Topo 7
};

unsigned int piramidehexInd[] =
    {
        //Base
        0, 6, 1,
        1, 6, 3,
        3, 6, 5,
        5, 6, 4,
        4, 6, 2,
        2, 6, 0,

        0, 7, 1,
        1, 7, 3,
        2, 7, 5,
        5, 7, 4,
        4, 7, 2,
        2, 7, 0};