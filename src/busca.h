#ifndef BUSCA_H
#define BUSCA_H

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <cmath>

class Busca {
  private:
    std::map<std::string, std::map<std::string, int>> indice;
    std::list<std::string> enderecos;

    int N = 0;
    int Nx = 0;
    float Idf = 0.0;
    int Tf;

    void imprimirRelacoes();
    void calcularRank(std::string);
    void calcularNx(std::string);
    void calcularTf(std::string);
    void calcularIdf();
    //N refere-se ao número de arquivos.
  public:
    // Cria uma processador vazio.
    Busca(int N,  std::map<std::string, std::map<std::string, int>> indice, std::list<std::string> enderecos);
    Busca();


    // Devolve quantos arquivos na pasta data
    void realizarBusca(std::string);
    void imprimirRank();

    // Desaloca a memória alocada para a Busca.
    ~Busca();
};

#endif  // BUSCA_H
