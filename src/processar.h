#ifndef PROCESSAR_H
#define PROCESSAR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Processar {
  private:
    std::vector<std::string> lista_de_arquivos;
    void mapearPalavras(std::string,std::string);
    void imprimirRelacoes();
    std::map<std::string, std::map<std::string, int>> indice;

  public:
    std::map<std::string, std::map<std::string, int>> getIndice();

    // Cria uma processador vazio.
    Processar();

    //Lista com endereço dos arquivos
    Processar(std::vector<std::string> lista_recebida);

    // Cria índice remissivo com a quantidade de matches de cada palavra em cada arquivo
    bool processarArquivos();

    std::vector<std::string> processarInput(std::string);

    // Desaloca a memória alocada para a Processar.
    ~Processar();
};

#endif  // PROCESSAR_H
