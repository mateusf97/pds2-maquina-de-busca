#include <string>

#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{

  Leitura *leitor = new Leitura();

  if (leitor->iniciarLeitura()) {

    // leitor->imprimirArquivos();
    // int i = leitor->contarArquivos();
    // std::cout << "O número de arquivos encontrados foi " << i << std::endl;

  } else {
    return -1;
  }

  return 0;
}