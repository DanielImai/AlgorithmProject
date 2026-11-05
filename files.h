#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
void verificaCriaPasta(string pathname);

void verificaCriaPasta(string pathname)
{
    LPCSTR pasta = pathname.c_str();

    DWORD atributos = GetFileAttributesA(pasta);
    if (atributos != INVALID_FILE_ATTRIBUTES && (atributos & FILE_ATTRIBUTE_DIRECTORY))
    {
        cout << "A pasta do caminho " << pathname << " ja existe" << endl;
    }
    else
    {
        if (CreateDirectoryA(pasta, NULL)) {
            cout << "Pasta "<< pathname <<" criada com sucesso!" << endl;
        } else {
            cout << "Erro ao criar a pasta " << pathname << endl;
        }
    }
}

void criarPastas(string algoritmo)
{
     string str = "Projeto de Algoritmos\\";
     string str2 = "\\Entrada";
     string str3 = "\\Saida";
     string str4 = "\\Tempo";
     string str5 = "\\Crescente";
     string str6 = "\\Decrescente";
     string str7 = "\\Random";

     string filepath = algoritmo;
     verificaCriaPasta(filepath);

     verificaCriaPasta(filepath + str2);
     verificaCriaPasta(filepath + str2 + str5);
     verificaCriaPasta(filepath + str2 + str6);
     verificaCriaPasta(filepath + str2 + str7);

     verificaCriaPasta(filepath + str3);
     verificaCriaPasta(filepath + str3 + str5);
     verificaCriaPasta(filepath + str3 + str6);
     verificaCriaPasta(filepath + str3 + str7);

     verificaCriaPasta(filepath + str4);
     verificaCriaPasta(filepath + str4 + str5);
     verificaCriaPasta(filepath + str4 + str6);
     verificaCriaPasta(filepath + str4 + str7);
}

#endif // FILES_H_INCLUDED
