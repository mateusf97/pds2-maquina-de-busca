#ifndef PROCESSAR_H
#define PROCESSAR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

class Processar {
  private:
    std::list<std::string> lista_de_arquivos;
    void mapearPalavras(std::string,std::string);

  public:
    std::map<std::string, std::vector<std::pair<std::string, int>>> Indice;

    // Cria uma processador vazio.
    Processar();

    //Lista com endereço dos arquivos
    Processar(std::list<std::string> lista_recebida);

    // Cria índice remissivo com a quantidade de matches de cada palavra em cada arquivo
    void processarArquivos();

    // Desaloca a memória alocada para a Processar.
    ~Processar();
};

#endif  // PROCESSAR_H
