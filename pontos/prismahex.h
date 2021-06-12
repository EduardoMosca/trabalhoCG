//0.33f, 0.3f, 0.34f,
float prismahexPos[] =
    {
        0.f, 0.f, -1.f, 0.33f, 0.3f, 0.34f,      //Ponta inferior esquerda 0
        0.5f, 0.f, -1.f, 0.33f, 0.3f, 0.34f,     // Ponta inferior direita 1
        -0.25f, 0.f, -1.43f, 0.33f, 0.3f, 0.34f, // Ponta media esquerda 2
        0.75f, 0.f, -1.43f, 0.33f, 0.3f, 0.34f,  // Ponta media direita 3
        0.f, 0.f, -1.86f, 0.33f, 0.3f, 0.34f,    //Ponta superior esquerda 4
        0.5f, 0.f, -1.86f, 0.33f, 0.3f, 0.34f,   //Ponta superior direita 5
        0.25f, 0.f, -1.43f, 0.33f, 0.3f, 0.34f,  // Centro 6

        0.f, 1.f, -1.f, 0.33f, 0.3f, 0.34f,      //Ponta inferior esquerda 7
        0.5f, 1.f, -1.f, 0.33f, 0.3f, 0.34f,     // Ponta inferior direita 8
        -0.25f, 1.f, -1.43f, 0.33f, 0.3f, 0.34f, // Ponta media esquerda 9
        0.75f, 1.f, -1.43f, 0.33f, 0.3f, 0.34f,  // Ponta media direita 10
        0.f, 1.f, -1.86f, 0.33f, 0.3f, 0.34f,    //Ponta superior esquerda 11
        0.5f, 1.f, -1.86f, 0.33f, 0.3f, 0.34f,   //Ponta superior direita 12
        0.25f, 1.f, -1.43f, 0.33f, 0.3f, 0.34f   // Centro 13
};

unsigned int prismahexInd[] =
    {
        //Base
        0, 6, 1,
        1, 6, 3,
        3, 6, 5,
        5, 6, 4,
        4, 6, 2,
        2, 6, 0,

        //Face superior
        7, 13, 8,
        8, 13, 10,
        10, 13, 12,
        12, 13, 11,
        11, 13, 9,
        9, 13, 7,

        //Lados
        0, 8, 7,
        0, 8, 1,

        1, 10, 7,
        1, 10, 3,

        3, 12, 10,
        3, 12, 5,

        5, 11, 12,
        5, 11, 4,

        4, 9, 11,
        4, 9, 2,

        2, 7, 9,
        2, 7, 0};
