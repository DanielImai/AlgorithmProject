
#include "algoritmos.h"

using namespace std;

void saveSequencia(vector<int> vec, int tam, string algoritmo, string tipo);
vector<int> insertionSort(vector<int> avector,int tam, string algoritmo, string tipo);
vector<int> gerarSequencia(string algoritmo, string tipoNome, int tipo, int tamanho);
void realizarOperacao(int tam, string algoritmo, string tipoNome, int tipo);


void menuEscolhas(string algoritmo)
{
    int opcao;
    int tam;
    while(opcao != 4){

        cout<<"\nEscolha uma opcao sobre o algoritmo "<<algoritmo <<" em vetor:\n";
        cout<<"\n  # 1) (numeros randomicos)";
        cout<<"\n  # 2) (numeros crescentes)";
        cout<<"\n  # 3) (numeros decrescentes)";
        cout<<"\n  # 4) (escolher outro algoritmo)\n\n";

        cin>>opcao;

        switch (opcao){
            case 1:
                {
                    cout<<"\nNumeros randomicos:";
                    cout<<"\nDigite o tamanho: ";
                    cin>>tam;
                    realizarOperacao(tam, algoritmo, "Random", 1);
                    break;
                }
            case 2:
                {
                    cout<<"\nNumeros crescentes:";
                    cout<<"\nDigite o tamanho: ";
                    cin>>tam;
                    realizarOperacao(tam, algoritmo, "Crescente", 2);
                    break;
                }

            case 3:
                {
                    cout<<"\nNumeros decrescentes:";
                    cin>>tam;
                    realizarOperacao(tam, algoritmo, "Decrescente", 3);
                    break;
                }
            case 4:
                {
                    cout<<"\nVoltando para a selecao de algoritmo...";
                    break;
                }
            default:
                    cout<<"\nOpcao invalida! Tente novamente";
                    break;
        }
    }
}


void realizarOperacao(int tam, string algoritmo, string tipoNome, int tipo)
{
    vector<int> sequencia = gerarSequencia(algoritmo, tipoNome, tipo, tam);
    if(algoritmo == "InsertionSort")
    {
        vector<int> sequenciaDepois = insertionSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "SelectionSort")
    {
        vector<int> sequenciaDepois = selectionSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "BubbleSort")
    {
        vector<int> sequenciaDepois = bubbleSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "ShellSort")
    {
        vector<int> sequenciaDepois = shellSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "MergeSort")
    {
        vector<int> sequenciaDepois = mergeSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "QuickSort1")
    {
        vector<int> sequenciaDepois = quickSort(sequencia, tam, algoritmo, tipoNome, 1);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "QuickSort2")
    {
        vector<int> sequenciaDepois = quickSort(sequencia, tam, algoritmo, tipoNome, 2);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "QuickSort3")
    {
        vector<int> sequenciaDepois = quickSort(sequencia, tam, algoritmo, tipoNome, 3);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else if(algoritmo == "HeapSort")
    {
        vector<int> sequenciaDepois = heapSort(sequencia, tam, algoritmo, tipoNome);
        saveSequencia(sequenciaDepois, tam, algoritmo, tipoNome);
    }
    else
        cout<<"Algoritmo invalido!"<<endl;
}

void saveSequencia(vector<int> vec, int tam, string algoritmo, string tipo)
{
    string str = "/Saida/";

    cout<<"Salvando a sequencia do algoritmo "<<algoritmo<<" do tipo "<<tipo <<endl;

    string str1 = "/saida";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    ostream_iterator<int> output_iterator(arquivo, "\n");
    copy(begin(vec), end(vec), output_iterator);

    arquivo.close();
}

vector<int> gerarSequencia(string algoritmo, string tipoNome, int tipo, int tamanho)
{
    string str = "/Entrada/";

    cout<<"Gerando a sequencia do algoritmo "<<algoritmo<<" do tipo "<<tipoNome <<endl;

    string str1 = "/entrada";
    string str2 = to_string(tamanho);
    string str3 = ".txt";

    string filename = algoritmo + str + tipoNome + str1 + tipoNome + str2 + str3;

    switch (tipo)
    {
        case 1:
        {
            srand(static_cast<unsigned int>(time(0)));

            ofstream arquivo(filename);

            vector<int> numeros;
            if (!arquivo) {
                cerr << "Erro ao criar o arquivo!" << endl;
                return numeros;
            }

            arquivo << tamanho << endl;

            for (int i = 0; i < tamanho; ++i) {
                int numero = rand();
                numeros.push_back(numero);
                arquivo << numero << endl;
            }

            arquivo.close();
            cout << "Numeros aleatorios gerados com sucesso!" << endl;
            return numeros;
        }
        case 2:
        {
            srand(static_cast<unsigned int>(time(0)));

            vector<int> numeros;

            for (int i = 0; i < tamanho; ++i) {
                int numero = rand();
                numeros.push_back(numero);
            }

            sort(numeros.begin(), numeros.end());

            ofstream arquivo(filename);

            arquivo << tamanho << endl;

            if (!arquivo) {
                cerr << "Erro ao criar o arquivo!" << endl;
                return numeros;
            }

            for (const int numero : numeros) {
                arquivo << numero << endl; // Escreve no arquivo
            }

            arquivo.close();
            cout << "Numeros gerados com sucesso!" << endl;
            return numeros;
        }
        case 3:
        {
            srand(static_cast<unsigned int>(time(0)));

            vector<int> numeros;

            for (int i = 0; i < tamanho; ++i) {
                int numero = rand();
                numeros.push_back(numero);
            }

            sort(numeros.begin(), numeros.end(), greater<int>());

            ofstream arquivo(filename);

            arquivo << tamanho << endl;

            if (!arquivo) {
                cerr << "Erro ao criar o arquivo!" << endl;
                return numeros;
            }

            for (const int numero : numeros) {
                arquivo << numero << endl; // Escreve no arquivo
            }

            arquivo.close();
            cout << "Numeros gerados com sucesso!" << endl;
            return numeros;

        }
    }
}
