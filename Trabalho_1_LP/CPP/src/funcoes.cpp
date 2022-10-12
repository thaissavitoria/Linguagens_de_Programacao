#include "funcoes.hpp"

void leArquivo(vector<vector<double>> matrixCalc, vector<vector<double>> identidade)
{
    fstream arq;
    vector<double> linha;

    arq.open("FECHAMENTO_MAIS_NEGOCIADAS_5minutos.csv", ios::in);

    if (!arq.is_open())
    {
        cout << "Problemas na abertura do arquivo" << endl;
        exit(EXIT_FAILURE);
    }

    int contlinhas = 0, cont;
    string line, word;
    double valor = 0;

    while (!arq.eof())
    {
        linha.clear();

        getline(arq, line);
        stringstream sstream(line);

        while (getline(sstream, word, ','))
        {
            sstream >> valor;
            linha.push_back(valor);
        }

        if (contlinhas == 12) // primeira matriz pronta
        {
            cont = matrizInversa(matrixCalc, identidade);
        }
        if (contlinhas > 12)
        {
            matrixCalc.erase(matrixCalc.begin()); // exclui a primeira linha
            matrixCalc.push_back(linha);          /// puxa a proxima
            cont = matrizInversa(matrixCalc, identidade);
            contlinhas++;
        }
        else
        {
            matrixCalc.push_back(linha);
            contlinhas++;
        }
    }

    arq.close();
    cout << endl
         << "Matrizes que não tem inversa:" << cont << endl;
}


int matrizInversa(vector<vector<double>> matrixCalc, vector<vector<double>> identidade)
{

    /// gerando identidade
    vector<double> linIdent;

    identidade.clear();

    for (int lin = 0; lin < 12; lin++)
    {
        linIdent.clear();
        for (int col = 0; col < 12; col++)
        {
            if (lin == col)
            {
                linIdent.push_back(1);
            }
            else
            {
                linIdent.push_back(0);
            }
        }
        identidade.push_back(linIdent);
    }

    /// gerando outra matriz para aproveitar o matrizCalc
    vector<vector<double>> copia;
    vector<double> lincopia;

    copia.clear();
    for (int i = 0; i < 12; i++)
    {
        lincopia.clear();
        for (int j = 0; j < 12; j++)
        {
            lincopia.push_back(matrixCalc[i][j]);
        }
        copia.push_back(lincopia);
    }

    double pivo = 0, m = 0;
    int lin, col, t = 0;

    for (col = 0; col < 12; col++)
    {
        pivo = copia[col][col];

        for (t = 0; t < 12; t++)
        {
            copia[col][t] = (copia[col][t]) / (pivo);
            identidade[col][t] = (identidade[col][t]) / (pivo);
        }

        for (lin = 0; lin < 12; lin++)
        {
            if (lin != col)
            {
                m = copia[lin][col];
                for (t = 0; t < 12; t++)
                {
                    copia[lin][t] = (copia[lin][t]) - (m * copia[col][t]);
                    identidade[lin][t] = (identidade[lin][t]) - (m * identidade[col][t]);
                }
            }
        }
    }

    ////printando inversa
    cout << endl
         << endl
         << endl;
    print(identidade);

    static int contInv = 0;
    if (isnan(identidade[0][0]))
    {
        contInv++;
    }
    return contInv;
}

void print(vector<vector<double>> matrix)
{
    for (long unsigned int i = 0; i < matrix.size(); i++)
    {
        for (long unsigned int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}