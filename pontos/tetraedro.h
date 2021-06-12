float tetraedroPos[] =
    {
        1.f, 0.f, 1.f, 0.6f, 1.f, 0.5f,       //canto direito 0
        1.5f, 0.f, 1.f, 0.6f, 1.f, 0.5f,      //canto esquerdo 1
        1.25f, 0.f, 1.43f, 0.6f, 1.f, 0.5f,   //ponta 2
        1.25, 0.5f, 1.216f, 0.6f, 1.f, 0.5f}; //topo 3

unsigned int tetraedroInd[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0};