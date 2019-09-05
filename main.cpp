#include <iostream>
#include "MatrizDispersa.h"
using namespace std;

int main()
{

        int sparseMatrix[4][5] =
            {
                    {0 , 0 , 3 , 0 , 4 },
                    {0 , 0 , 5 , 7 , 0 },
                    {0 , 0 , 0 , 0 , 0 },
                    {0 , 2 , 6 , 0 , 0 }
            };


    MatrizDispersa md=MatrizDispersa(sparseMatrix);

    md.suma(sparseMatrix);
    cout<<"========="<<endl;
    md.transposicion(sparseMatrix);
    cout<<"========="<<endl;
    md.multiplicacionEscalar(sparseMatrix);
    cout<<"=========="<<endl;
    md.multiplicacionDeMatrices(sparseMatrix);

    return 0;
}
