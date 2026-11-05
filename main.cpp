
#include "functions.h"
#include "files.h"

using namespace std;

int main() {

    int opcao;

    cout<<"\t######################################";
    cout<<"\nBem vindo ao menu do projeto de algoritmos" << endl;

    criarPastas("InsertionSort");
    criarPastas("SelectionSort");
    criarPastas("BubbleSort");
    criarPastas("ShellSort");
    criarPastas("MergeSort");
    criarPastas("QuickSort1");
    criarPastas("QuickSort2");
    criarPastas("QuickSort3");
    criarPastas("HeapSort");

    while(opcao != 5){
        cout<<"\nEscolha seu algoritmo: " << endl;
        cout<<"\n###################\n" << endl;
        cout<<"  # 1) - Insertion Sort" << endl;
        cout<<"  # 2) - Selection Sort" << endl;
        cout<<"  # 3) - Bubble Sort" << endl;
        cout<<"  # 4) - Shell Sort" << endl;
        cout<<"  # 5) - Merge Sort" << endl;
        cout<<"  # 6) - Quick Sort 1" << endl;
        cout<<"  # 7) - Quick Sort 2" << endl;
        cout<<"  # 8) - Quick Sort 3" << endl;
        cout<<"  # 9) - Heap Sort" << endl;
        cout<<"  # 10) - Finalizar o programa\n" << endl;

        cin>>opcao;

        switch(opcao) {
            case 1:
                {
                    menuEscolhas("InsertionSort");
                    break;
                }
            case 2:
                {
                    menuEscolhas("SelectionSort");
                    break;
                }
            case 3:
                {
                    menuEscolhas("BubbleSort");
                    break;
                }
            case 4:
                {
                    menuEscolhas("ShellSort");
                    break;
                }
            case 5:
                {
                    menuEscolhas("MergeSort");
                    break;
                }
            case 6:
                {
                    menuEscolhas("QuickSort1");
                    break;
                }
            case 7:
                {
                    menuEscolhas("QuickSort2");
                    break;
                }
            case 8:
                {
                    menuEscolhas("QuickSort3");
                    break;
                }
            case 9:
                {
                    menuEscolhas("HeapSort");
                    break;
                }
            case 10:
                {
                    cout<<"\nFechando o programa...";
                    break;
                }

            default:
                cout<<"\nOpcao invalida! Tente novamente";
                break;
        }

}
    return 0;
}

