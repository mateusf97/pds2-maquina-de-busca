#include <string>

#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{

  Leitura *leitor = new Leitura();

  if (leitor->iniciarLeitura()) {

    int i = leitor->contarArquivos();
    i++;
    delete leitor;



  } else {
    return -1;
  }

  return 0;
}