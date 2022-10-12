#include "funcoes.hpp"

int main()
{
    vector<vector<double>>matrixPla;///matriz que terá toda a planilha

    vector<vector<double>>matrixCalc;///matriz que percorrerá a planilha

    vector<vector<double>>identidade;///matriz identidade

    leArquivo(matrixPla,matrixCalc,identidade);


    return 0;
}