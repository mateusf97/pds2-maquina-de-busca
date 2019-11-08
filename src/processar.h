#ifndef PROCESSAR_H
#define PROCESSAR_H

#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

class Processar {
  private:
    std::list<std::string> lista_de_arquivos;

  public:
    typedef std::map<std::string, std::vector<std::pair<int, int>>> Indice;

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
