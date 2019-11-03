#ifndef BUSCA_H
#define BUSCA_H

#include <string>

class Busca {
 public:
  // Cria uma processador vazio.
  Busca();

  // Devolve quantos arquivos na pasta data
  void realizarBusca(std::string palavra);
  void imprimirRank();

  // Desaloca a memória alocada para a Busca.
  ~Busca();
};

#endif  // BUSCA_H
