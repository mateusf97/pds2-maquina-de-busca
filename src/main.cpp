#include <iostream>
#include <string>
#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{
  // g++ -Wall main.cpp leitura.cpp busca.cpp processar.cpp -o output.exe && ./output.exe
  std::cout << "Compilou!!" << std::endl;

  Leitura *leitor = new Leitura();
  Processar *processador = new Processar();
  Busca *busca = new Busca();

  leitor->iniciarLeitura();
  int i = leitor->contarArquivos();
  i++;
  // lista_de_arquivos = leitor->buscarArquivos();

  processador->processarArquivos();
  busca->realizarBusca("BATATA");
  busca->imprimirRank();

  delete leitor;
  delete processador;
  delete busca;

  return 0;
}