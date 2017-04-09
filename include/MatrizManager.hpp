#ifndef MATRIZMANAGER_H
#define MATRIZMANAGER_H
#include <iostream>
#include <fstream>
#include "jama_svd.h"
#include "tnt_array2d.h"
#include "tnt_array2d_utils.h"

class MatrizManager
{
    public:
        MatrizManager();
        ~MatrizManager();

        void LeerMatriz(); //se encarga de leer l matriz del archivo
        void NomalizarR(); //se encarga de rellenar los 0 y normalizar
        void ImprimirMatriz(); //Se encarga de Imprimir la matriz R (se puede modificar para imprimir cualquier matriz)
        void DescomponerSVD(); //Se encarga de descomponer la matriz Rnorm en U,V y singular que son matrices de SVD
        void ImprimirS();//imprime singular
        void ImprimirV();//imprime V
        void ImpirmirD();//imprime D



    protected:


    private:

    Array2D<double> MatrizR; //matriz original
    Array2D<double> MatrizRnomr;//matriz lista para descomponer
    Array2D<double> V;//resultado de matriz V de SVD
    Array2D<double> U;//resultado de matriz U de SVD corresponde a D
    Array1D<double> singular;//resultado de matris S de SVD


};

#endif // MATRIZMANAGER_H
