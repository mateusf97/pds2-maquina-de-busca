#ifndef LEITURA_H
#define LEITURA_H

#include <string>
using std::string;

class Leitura {
 public:
  // Cria uma Leitura vazia.
  Leitura();

  // Ler todos os arquivos que está na pasta data
  void iniciarLeitura();

  // Devolve lista com o nome dos arquivos lidos
  // Não void
  void buscarArquivos();

  // Devolve quantos arquivos na pasta data
  int contarArquivos();

  // Desaloca a memória alocada para a Leitura.
  ~Leitura();
};

#endif  // LEITURA_H
