#include "leitura.h"

Leitura::Leitura() {
  std::cout << "Inicializando leitura dos arquivos da pasta '../data/'" << std::endl;
}

Leitura::~Leitura() {
  // Destrutor
}

bool Leitura::iniciarLeitura() {

  if ((this->dir = opendir ("../data/")) != NULL) {
    closedir (this->dir);
    return true;
  } else {
    perror ("Não foi possível abrir os arquivos");
    return false;
  }
}

int Leitura::contarArquivos() {
  return 0;
}

void Leitura::buscarArquivos() {
  this->dir = opendir ("../data/");

  while ((this->arquivos = readdir(this->dir)) != NULL) {
    std::cout << arquivos->d_name << std::endl;
  }

  closedir (this->dir);
}