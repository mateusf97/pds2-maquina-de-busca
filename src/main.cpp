#include <string>

#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{

  Leitura *leitor = new Leitura();

  if (leitor->iniciarLeitura()) {

    leitor->buscarArquivos();



  } else {
    return -1;
  }

  return 0;
}