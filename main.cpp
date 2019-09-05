#include <iostream>
#include "MatrizDispersa.h"
using namespace std;

int main()
{

        int sparseMatrix[4][5] =
            {
                    {0 , 0 , 4 , 0 , 4 },
                    {0 , 0 , 1 , 2 , 0 },
                    {0 , 0 , 0 , 0 , 0 },
                    {0 , 2 , 2 , 1 , 0 }
            };


    MatrizDispersa md=MatrizDispersa(sparseMatrix);

    md.suma(sparseMatrix);

    md.transposicion(sparseMatrix);

    md.multiplicacionEscalar(sparseMatrix);



    return 0;
}
