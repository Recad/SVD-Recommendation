#include "MatrizManager.hpp"
#include <bits/stdc++.h>
using namespace JAMA;

MatrizManager::MatrizManager() :MatrizR(7,10) ,MatrizRprom(7,10)
{

}

MatrizManager::~MatrizManager()
{
    //dtor
}


void MatrizManager::LeerMatriz() {
    try {
        ifstream fe("sparse_matrix.txt");

        for(int i=0; i<7;i++) {
            for(int j=0; j<10;j++) {
                fe >> this->MatrizR[i][j];
            }

        }
        fe.close();
    }catch(const ifstream::failure& e){
        cout << "NO se pudo leer el archivo"<<endl;

    }

}

void MatrizManager::ImprimirMatriz(Array2D<double> array){

    int cols = sizeof( array )/(sizeof( array[0] )-1);
    int rows = sizeof( array[0] )-1;
    cout <<"filas "<< rows<<endl;
    cout <<"columnas "<< cols<<endl;
    for(int i=0; i<rows;i++) {
        for(int j=0; j<cols;j++) {
            cout << array[i][j]<<" ";
        }
        cout << endl;
    }
}


void MatrizManager::NomalizarR()
{
    //primero vamos a rellenar los espacios en 0 de la matrizoriginal
    this->MatrizRprom=this->MatrizR;
    double array_acumulador[10];
    float prom=0.0;
    for(int i=0; i<7;i++) {
        for(int j=0; j<10;j++) {
            if(i==0) {
                array_acumulador[j]=this->MatrizR[i][j];
            }
            else {
                array_acumulador[j]=array_acumulador[j]+this->MatrizR[i][j];
            }
        }
    }
/* Descomentar para ver el array de sumatorias de columnas
    for(int j=0; j<(sizeof(array_acumulador)/sizeof(*array_acumulador));j++) {
          cout << array_acumulador[j] <<" - ";
        }*/


        //buscando lo valores 0 y remplazandolos y signadolos a la matriz con promedios
        for(int i=0; i<7;i++) {
            for(int j=0; j<10;j++) {
                if (this->MatrizRprom[i][j]==0) {
                    this->MatrizRprom[i][j]= (array_acumulador[j]/7);
                }
        }
    }

    ImprimirMatriz(this->MatrizRprom);
}
//esta funcion no la use
void MatrizManager::RellenarProm(int columna,double prom){

    for (int fila=0;fila<7;fila++){
        if (this->MatrizRprom[fila][columna] == 0){
            this->MatrizRprom[fila][columna]= prom;
        }

    }

}

void MatrizManager::DescomponerSVD()
{
    SVD<double> svd(this->MatrizRnomr);
    svd.getV(this->V);
    svd.getSingularValues(this->singular);
    svd.getU(this->U);

}

void MatrizManager::ImprimirS()
{

}

void MatrizManager::ImprimirV()
{

}

void MatrizManager::ImpirmirD()
{

}

Array2D<double> MatrizManager::getMatrizR(){
    return this->MatrizR;
}

Array2D<double> MatrizManager::getMatrizRprom(){
    return this->MatrizRprom;
}
