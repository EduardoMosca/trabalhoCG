//0.47f, 0.8f, 0.84f,
float paralelPos[] = {
    0.825f, -0.15f, 0.15f, 0.47f, 0.8f, 0.84f,
    0.825f, -0.15f, -0.15f, 0.47f, 0.8f, 0.84f,
    1.825f, -0.15f, -0.15f, 0.47f, 0.8f, 0.84f,
    1.825f, -0.15f, 0.15f, 0.47f, 0.8f, 0.84f,
    0.825f, 0.15f, 0.15f, 0.47f, 0.8f, 0.84f,
    0.825f, 0.15f, -0.15f, 0.47f, 0.8f, 0.84f,
    1.825f, 0.15f, -0.15f, 0.47f, 0.8f, 0.84f,
    1.825f, 0.15f, 0.15f, 0.47f, 0.8f, 0.84f};

unsigned int paralelIndices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 4, 7,
        0, 7, 3,
        3, 7, 6,
        3, 6, 2,
        2, 6, 5,
        2, 5, 1,
        1, 5, 4,
        1, 4, 0,
        4, 5, 6,
        4, 6, 7};