//0.56f, 0.3f, 0.33f,
float pentPos[] =
    {
        -2, 0, -3.2, 0.56f, 0.3f, 0.33f,     //inferior esquerdo 0
        -1.5, 0, -3.2, 0.56f, 0.3f, 0.33f,   //inferior direito 1
        -1.5, 0, -2, 0.56f, 0.3f, 0.33f,     //supereior direito 2
        -2, 0, -2, 0.56f, 0.3f, 0.33f,       //superior esquerdo 3
        -2.35, 0, -2.34, 0.56f, 0.3f, 0.33f, //esquerda cima 4
        -2.35, 0, -2.84, 0.56f, 0.3f, 0.33f, //esquerda baixo 5
        -1.14, 0, -2.34, 0.56f, 0.3f, 0.33f, //direita cima 6
        -1.14, 0, -2.84, 0.56f, 0.3f, 0.33f, //direita baixo 7
        -1.75, 0, -2.59, 0.56f, 0.3f, 0.33f, // Centro 8

        -2, 1, -3.2, 0.56f, 0.3f, 0.33f,     //inferior esquerdo 0 -> 9
        -1.5, 1, -3.2, 0.56f, 0.3f, 0.33f,   //inferior direito 1 -> 10
        -1.5, 1, -2, 0.56f, 0.3f, 0.33f,     //supereior direito 2 -> 11
        -2, 1, -2, 0.56f, 0.3f, 0.33f,       //superior esquerdo 3 -> 12
        -2.35, 1, -2.34, 0.56f, 0.3f, 0.33f, //esquerda cima 4 -> 13
        -2.35, 1, -2.84, 0.56f, 0.3f, 0.33f, //esquerda baixo 5 -> 14
        -1.14, 1, -2.34, 0.56f, 0.3f, 0.33f, //direita cima 6 -> 15
        -1.14, 1, -2.84, 0.56f, 0.3f, 0.33f, //direita baixo 7 -> 16
        -1.75, 1, -2.59, 0.56f, 0.3f, 0.33f  // Centro 8 -> 17

};

unsigned int pentInd[] =
    {
        0, 8, 1, //ok
        1, 8, 7, //ok
        7, 8, 6, //ok
        6, 8, 2, //ok
        2, 8, 3, //ok
        3, 8, 4, //ok
        4, 8, 5, //ok
        5, 8, 0, //ok

        9, 17, 10,
        10, 17, 16,
        16, 17, 15,
        15, 17, 11,
        11, 17, 12,
        12, 17, 13,
        13, 17, 14,
        14, 17, 9,

        0, 10, 1,
        0, 10, 9,
        1, 16, 7,
        1, 16, 10,
        7, 15, 6,
        7, 15, 16,
        2, 12, 3,
        2, 12, 11,
        3, 13, 4,
        3, 13, 12,
        4, 14, 13,
        4, 14, 5,
        5, 9, 14,
        5, 9, 0,
        6, 11, 15,
        6, 11, 2};