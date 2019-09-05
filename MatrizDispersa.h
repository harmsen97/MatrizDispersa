
#ifndef TMR_MATRIZDISPERSA_H
#define TMR_MATRIZDISPERSA_H

#include <stdio.h>
class MatrizDispersa {
private:
    int **matriz;
    const static int COL=5;
    const static int FIL=4;


public:
    MatrizDispersa(int sparseMatrix[][COL]){

        this->matriz = new int*[3];
        for(int i = 0; i < 3; ++i)
            this->matriz[i] = new int[COL];
        this->matriz=convertidor(sparseMatrix);

        std::cout<<"Matriz Dispera"<<std::endl;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<COL; j++)
                printf("%d ", matriz[i][j]);

            printf("\n");
            }

    }
     int** convertidor(int sparseMatrix[][COL]){
        int size = 0;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < COL; j++)
                if (sparseMatrix[i][j] != 0)
                    size++;

        int **compactMatrix=new int*[3];
         for(int i = 0; i < 3; i++)
             compactMatrix[i] = new int[size];

        int k = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < COL; j++)
                if (sparseMatrix[i][j] != 0)
                {
                    compactMatrix[0][k] = i;
                    compactMatrix[1][k] = j;
                    compactMatrix[2][k] = sparseMatrix[i][j];
                    k++;
                }

        }

         return compactMatrix;
        }

    int** suma(int Matrix[][COL]){
            int** aMatrix = new int*[3];
            for(int i = 0; i < 3; ++i)
                aMatrix[i] = new int[COL];
            aMatrix=convertidor(Matrix);

            int** outputMatrix = new int*[3];
            for(int i = 0; i < 3; ++i)
                outputMatrix[i] = new int[COL];


            for (int j = 0; j <COL+1; j++) {

                if(aMatrix[0][j]==matriz[0][j] && aMatrix[1][j]==matriz[1][j]){
                    outputMatrix[0][j]=aMatrix[0][j];
                    outputMatrix[1][j]=aMatrix[1][j];
                    outputMatrix[2][j]=aMatrix[2][j]+matriz[2][j];
                }
                else if(aMatrix[0][j]==matriz[0][j] && aMatrix[1][j]<matriz[1][j]){
                    outputMatrix[0][j]=aMatrix[0][j];
                    outputMatrix[1][j]=aMatrix[1][j];
                    outputMatrix[2][j]=aMatrix[2][j];
                }

                else if(aMatrix[0][j]==matriz[0][j] && aMatrix[1][j]>matriz[1][j]){
                    outputMatrix[0][j]=aMatrix[0][j];
                    outputMatrix[1][j]=matriz[1][j];
                    outputMatrix[2][j]=matriz[2][j];
                }
                else if(aMatrix[0][j]<matriz[0][j]){
                    outputMatrix[0][j]=aMatrix[0][j];
                    outputMatrix[1][j]=aMatrix[1][j];
                    outputMatrix[2][j]=aMatrix[2][j];
                }
                else if(aMatrix[0][j]>matriz[0][j]){
                    outputMatrix[0][j]=matriz[0][j];
                    outputMatrix[1][j]=matriz[1][j];
                    outputMatrix[2][j]=matriz[2][j];
                }
            }

        std::cout<<"============"<<std::endl;
        std::cout<<"Suma de matrices"<<std::endl;


        for (int i=0; i<3; i++)
            {
                for (int j=0; j<COL+1; j++)
                    printf("%d ", outputMatrix[i][j]);

                printf("\n");
            }
        return outputMatrix;
        }

    int transposicion(int Matrix[][COL]){
        int** aMatrix = new int*[3];
        for(int i = 0; i < 3; ++i)
            aMatrix[i] = new int[COL];
        aMatrix=convertidor(Matrix);

        int array[COL];
        for (int i = 0; i < COL; i++) {
            array[i]=aMatrix[0][i];
            aMatrix[0][i]=aMatrix[1][i];
            aMatrix[1][i]=array[i];
        }
        std::cout<<"============"<<std::endl;
        std::cout<<"Matriz transpuesta"<<std::endl;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<COL+1; j++)
                printf("%d ", aMatrix[i][j]);

            printf("\n");
        }
    }

    void multiplicacionEscalar(int Matrix[][COL]){
        int** aMatrix = new int*[3];
        for(int i = 0; i < 3; ++i)
            aMatrix[i] = new int[COL];
        aMatrix=convertidor(Matrix);

        int** outputMatrix = new int*[FIL];
        for(int i = 0; i < 3; ++i)
            outputMatrix[i] = new int[COL];


        for (int j = 0; j <COL+1; j++) {

            if(aMatrix[0][j]==matriz[0][j] && aMatrix[1][j]==matriz[1][j]){
                outputMatrix[0][j]=aMatrix[0][j];
                outputMatrix[1][j]=aMatrix[1][j];
                outputMatrix[2][j]=aMatrix[2][j]*matriz[2][j];
            }
            else{
                outputMatrix[0][j]=aMatrix[0][j];
                outputMatrix[1][j]=aMatrix[1][j];
                outputMatrix[2][j]=0;
            }
        }
        std::cout<<"============"<<std::endl;
        std::cout<<"Multiplicacion Escalar"<<std::endl;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<COL+1; j++)
                printf("%d ", outputMatrix[i][j]);

            printf("\n");
        }



        }
    void multiplicacionDeMatrices(int Matrix[][COL]){
        int** aMatrix = new int*[3];
        for(int i = 0; i < 3; ++i)
            aMatrix[i] = new int[COL];
        aMatrix=convertidor(Matrix);

        int** outputMatrix = new int*[FIL];
        for(int i = 0; i < 3; ++i)
            outputMatrix[i] = new int[FIL];


        for (int i = 0; i <FIL; i++) {
            int sum=0;
            for (int j = 0; j <COL ; j++) {
               if(matriz[0][i]==aMatrix[1][j]){
                   sum=sum+matriz[2][i]*aMatrix[2][j];
               }

            }


        }
    }


    };


#endif //TMR_MATRIZDISPERSA_H
