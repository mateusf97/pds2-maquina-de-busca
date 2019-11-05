#include "leitura.h"

Leitura::Leitura() {
  std::cout << "Inicializando leitura dos arquivos da pasta '../data/'" << std::endl;
}

Leitura::~Leitura() {
  // Destrutor
}

bool Leitura::iniciarLeitura() {

  if ((dir = opendir ("../data/")) != NULL) {

    while ((arquivos=readdir(dir)) != NULL) {
      std::cout << arquivos->d_name << std::endl;
    }

    closedir (dir);

    return true;
  } else {
    perror ("Não foi possível abrir os arquivos");
    return false;
  }
}

int Leitura::contarArquivos() {
  return 0;
}