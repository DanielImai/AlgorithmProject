#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

vector<int> insertionSort(vector<int> avector, int tam, string algoritmo, string tipo) {
    cout<<"Realizando o Insertion Sort"<<endl;

    clock_t start_t, end_t;
    start_t = clock();

    for (unsigned int index=1; index<avector.size(); index++) {

        int currentvalue = avector[index];
        int position = index;

        while (position>0 && avector[position-1]>currentvalue) {
            avector[position] = avector[position-1];
            position--;
        }

        avector[position] = currentvalue;
    }

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    string str = "/Tempo/";

    cout<<"Salvando o tempo do algoritmo "<<algoritmo<<" do tipo "<< tipo <<endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    arquivo << tempo << endl;

    arquivo.close();


    return avector;
}

vector<int> bubbleSort(vector<int> avector, int tam, string algoritmo, string tipo) {
    cout << "Realizando o Bubble Sort" << endl;

    clock_t start_t, end_t;
    start_t = clock();

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (avector[j] > avector[j + 1]) {
                int temp = avector[j];
                avector[j] = avector[j + 1];
                avector[j + 1] = temp;
            }
        }
    }

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    string str = "/Tempo/";

    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    arquivo << tempo << endl;

    arquivo.close();

    return avector;
}

vector<int> selectionSort(vector<int> avector, int tam, string algoritmo, string tipo) {
    cout << "Realizando o Selection Sort" << endl;

    clock_t start_t, end_t;
    start_t = clock();

    for (int i = 0; i < tam - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; j++) {
            if (avector[j] < avector[minIndex]) {
                minIndex = j;
            }
        }
        int temp = avector[i];
        avector[i] = avector[minIndex];
        avector[minIndex] = temp;
    }

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    string str = "/Tempo/";

    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    arquivo << tempo << endl;

    arquivo.close();

    return avector;
}

vector<int> shellSort(vector<int> avector, int tam, string algoritmo, string tipo) {
    cout << "Realizando o Shell Sort" << endl;

    clock_t start_t, end_t;
    start_t = clock();

    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = avector[i];
            int j;
            for (j = i; j >= gap && avector[j - gap] > temp; j -= gap) {
                avector[j] = avector[j - gap];
            }
            avector[j] = temp;
        }
    }

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    string str = "/Tempo/";

    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    arquivo << tempo << endl;

    arquivo.close();

    return avector;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSortaux(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortaux(arr, left, mid);
        mergeSortaux(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> mergeSort(vector<int> avector, int tam, string algoritmo, string tipo) {
    cout << "Realizando o Merge Sort" << endl;

    clock_t start_t, end_t;
    start_t = clock();

    mergeSortaux(avector, 0, tam - 1);

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    string str = "/Tempo/";

    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);

    arquivo << tempo << endl;

    arquivo.close();

    return avector;
}

int partition_v1(vector<int>& avector, int low, int high) {
    int pivot = avector[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && avector[i] <= pivot) {
            i++;
        }
        while (avector[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(avector[i], avector[j]);
        }
    }
    swap(avector[low], avector[j]);
    return j;
}

int medianOfThree(vector<int>& avector, int low, int high) {
    int mid = low + (high - low) / 2;

    if (avector[low] > avector[mid]) swap(avector[low], avector[mid]);
    if (avector[low] > avector[high]) swap(avector[low], avector[high]);
    if (avector[mid] > avector[high]) swap(avector[mid], avector[high]);

    swap(avector[mid], avector[low]);
    return avector[low];
}

int partition_v2(vector<int>& avector, int low, int high) {
    int pivot = medianOfThree(avector, low, high);
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && avector[i] <= pivot) {
            i++;
        }
        while (avector[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(avector[i], avector[j]);
        }
    }
    swap(avector[low], avector[j]);
    return j;
}

int randomPivot(vector<int>& avector, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(avector[low], avector[randomIndex]);
    return avector[low];
}

int partition_v3(vector<int>& avector, int low, int high) {
    int pivot = randomPivot(avector, low, high);
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && avector[i] <= pivot) {
            i++;
        }
        while (avector[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(avector[i], avector[j]);
        }
    }
    swap(avector[low], avector[j]);
    return j;
}

void quickSort_aux(vector<int>& avector, int low, int high, int version) {
    if (low < high) {
        int pivotIndex;
        if (version == 1) {
            pivotIndex = partition_v1(avector, low, high);
        } else if (version == 2) {
            pivotIndex = partition_v2(avector, low, high);
        } else {
            pivotIndex = partition_v3(avector, low, high);
        }
        quickSort_aux(avector, low, pivotIndex - 1, version);
        quickSort_aux(avector, pivotIndex + 1, high, version);
    }
}

vector<int> quickSort(vector<int> avector, int tam, string algoritmo, string tipo, int version) {

    cout << "Realizando o QuickSort " << version << endl;

    if (version == 3) srand(time(0));

    clock_t start_t, end_t;
    start_t = clock();

    quickSort_aux(avector, 0, tam - 1, version);

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    cout <<"test1"<<version<<endl;

    string str = "/Tempo/";
    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string str1 = "/tempo";
    string str2 = to_string(tam);
    string str3 = ".txt";

    string filename = algoritmo + str + tipo + str1 + tipo + str2 + str3;

    ofstream arquivo(filename);
    arquivo << tempo << endl;
    arquivo.close();

    return avector;
}

void MIN_HEAPIFY(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        MIN_HEAPIFY(heap, n, smallest);
    }
}

void BUILD_MIN_HEAP(vector<int>& heap) {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        MIN_HEAPIFY(heap, n, i);
    }
}

vector<int> heapSort(vector<int> avector, int tam, string algoritmo, string tipo) {
   cout << "Realizando o HeapSort" << endl;

    clock_t start_t, end_t;
    start_t = clock();

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : avector) {
        minHeap.push(num);
    }

    vector<int> sortedVector;
    while (!minHeap.empty()) {
        sortedVector.push_back(minHeap.top());
        minHeap.pop();
    }

    end_t = clock();
    float tempo = ((end_t - start_t) / (float)CLOCKS_PER_SEC);

    cout << "Salvando o tempo do algoritmo " << algoritmo << " do tipo " << tipo << endl;

    string filename = algoritmo + "/Tempo/" + tipo + "/tempo" + tipo + to_string(tam) + ".txt";
    ofstream arquivo(filename);

    arquivo << tempo << endl;
    arquivo.close();

    return sortedVector;
}

#endif // ALGORITMOS_H_INCLUDED
