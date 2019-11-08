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

struct dirent *Leitura::buscarArquivos() {
  return this->arquivos;
}


int Leitura::contarArquivos() {

  this->dir = opendir ("../data/");
  int i = -2;
  // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior

  struct dirent *arquivos_heap = this->buscarArquivos();


  while ((arquivos_heap = readdir(this->dir)) != NULL) {
    i++;
  }
  closedir(this->dir);

  return i;
}

std::list<std::string> Leitura::listarArquivos() {
  this->dir = opendir ("../data/");

  int remover = 0;
  struct dirent *arquivos_heap = this->buscarArquivos();
  std::list<std::string> enderecos;


  while ((arquivos_heap = readdir(this->dir)) != NULL) {
    if (remover > 1) {
      // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior
      // std::cout << arquivos_heap->d_name << std::endl;
      auto s1 = std::to_string("../data/");
      auto s2 = std::to_string(arquivos_heap->d_name);
      enderecos.push_back((s1+s2));

    }

    remover++;
  }
  if (remover>1) {
    return enderecos;
  } else {
    enderecos.clear();
    return enderecos;
  }
  closedir (this->dir);
}

void Leitura::imprimirArquivos() {
  this->dir = opendir ("../data/");

  int remover = 0;
  struct dirent *arquivos_heap = this->buscarArquivos();


  while ((arquivos_heap = readdir(this->dir)) != NULL) {
    if (remover > 1) {
      // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior
      std::cout << arquivos_heap->d_name << std::endl;
    }

    remover++;
  }

  closedir (this->dir);
}