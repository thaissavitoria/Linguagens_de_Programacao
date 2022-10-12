#include "funcoes.hpp"

int main()
{
    vector<vector<double>>matrixPla;///matriz que terá toda a planilha

    vector<vector<double>>matrixCalc;///matriz que percorrerá a planilha

    vector<vector<double>>identidade;///matriz identidade

    std::chrono::steady_clock::time_point comeco= std::chrono::steady_clock::now();

    leArquivo(matrixPla,matrixCalc,identidade);

    std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();

    cout << endl << "O tempo necessário para exeutar o programa foi de aproximadamente " << std::chrono::duration_cast<std::chrono::seconds>(fim - comeco).count() << "s."<<endl<<endl;


    return 0;
}