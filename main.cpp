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
        int anotherMatrix[4][5] =
            {
                    {0 , 0 , 5 , 0 , 1 },
                    {0 , 0 , 8 , 9 , 0 },
                    {0 , 0 , 0 , 0 , 0 },
                    {0 , 6 , 5 , 12, 0 }
            };

    MatrizDispersa md=MatrizDispersa(sparseMatrix);

    md.suma(anotherMatrix);

    md.transposicion(sparseMatrix);

    md.multiplicacionEscalar(sparseMatrix);



    return 0;
}
