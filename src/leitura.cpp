#include "leitura.h"

Leitura::Leitura() {
  std::cout << "Inicializando leitura dos arquivos da pasta '../data/'" << std::endl;
}

Leitura::~Leitura() {
  closedir (this->dir);
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

struct dirent Leitura::buscarArquivos() {
  return *this->arquivos;
}

void Leitura::imprimirArquivos() {
  this->dir = opendir ("../data/");

  int remover = 0;

  while ((this->arquivos = readdir(this->dir)) != NULL) {
    if (remover > 1) {
      // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior
      std::cout << arquivos->d_name << std::endl;
    }

    remover++;
  }

  closedir (this->dir);
}

int Leitura::contarArquivos() {
  this->dir = opendir ("../data/");

  int i = -2;
  // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior

  while ((this->arquivos = readdir(this->dir)) != NULL) {
    i++;
  }

  closedir (this->dir);
  return i;
}
