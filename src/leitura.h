#ifndef LEITURA_H
#define LEITURA_H

#include <string>
#include <iostream>
#include <dirent.h>

class Leitura {

  private:
    DIR *dir;
    struct dirent *arquivos;

  public:
    // Cria uma Leitura vazia.
    Leitura();

    // Ler todos os arquivos que está na pasta data
    bool iniciarLeitura();

    // Devolve lista com o nome dos arquivos lidos
    struct dirent *buscarArquivos();

    //Imprime o nome dos arquivos lidos
    void imprimirArquivos();

    // Devolve quantos arquivos na pasta data
    int contarArquivos();

    // Desaloca a memória alocada para a Leitura.
    ~Leitura();
};

#endif  // LEITURA_H
