#include "MatrizManager.hpp"

using namespace JAMA;

MatrizManager::MatrizManager() :MatrizR(7,10)
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

void MatrizManager::ImprimirMatriz(){
    for(int i=0; i<7;i++) {
        for(int j=0; j<10;j++) {
            cout << this->MatrizR[i][j];
        }
        cout << endl;
    }
}


void MatrizManager::NomalizarR()
{

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
