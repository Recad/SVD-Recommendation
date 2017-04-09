#include "MatrizManager.hpp"
using namespace std;

int main()
{
    MatrizManager matrizmanager;
    matrizmanager.LeerMatriz();
    matrizmanager.ImprimirMatriz(matrizmanager.getMatrizR());
    matrizmanager.NomalizarR();

   // matrizmanager.DescomponerSVD();
    return 0;
}
