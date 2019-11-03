#ifndef PROCESSAR_H
#define PROCESSAR_H

#include <string>
using std::string;

class Processar {
 public:
  // Cria uma processador vazio.
  Processar();

  // Cria índice remissivo com a quantidade de matches de cada palavra em cada arquivo
  void processarArquivos();

  // Desaloca a memória alocada para a Processar.
  ~Processar();
};

#endif  // PROCESSAR_H
