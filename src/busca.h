#ifndef BUSCA_H
#define BUSCA_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>

class Busca {
  private:
    std::map<std::string, std::map<std::string, int>> indice;
    // Indice Invertido

    std::map<std::string, std::vector<double>> coordenadas;
    // Map com as coordernadas do processamento das palavras

    std::vector<std::string> enderecos;
    // Endereço dos arquivos lidos


    int N = 0;
    // Número de arquivos

    int Nx = 0;
    // Número de arquivos com a palavra X

    float Idf = 0.0;
    // Relação Log na base 2 de N por Nx

    std::vector<int> Tf;
    // Quantas vezes X aparece em cada arquivo

    std::vector<double> W;
    // Relação de Tf * Idf por arquivo



    void imprimirRelacoes();
    // Imprimir as relações

    void calcularRank(std::string);
    // Calcula o Rank

    void calcularCoordenadas(std::string);
    // Calcula o Map de coordenadas

    void imprimirCoordenadas();
    // Imprimir o Map de coordernadas

    void calcularNx(std::string);
    void calcularW();
    void calcularTf(std::string);
    void imprimirTfs();
    void calcularIdf();

  public:
    // Cria uma processador vazio.
    Busca(int N,  std::map<std::string, std::map<std::string, int>> indice, std::vector<std::string> enderecos);
    Busca();

    void realizarBusca(std::string);
    void imprimirRank();

    // Desaloca a memória alocada para a Busca.
    ~Busca();
};

#endif  // BUSCA_H
