#include "leitura.h"

Leitura::Leitura() {
  std::cout << std::endl << "Inicializando leitura dos arquivos da pasta './data/'" << std::endl;
}

Leitura::~Leitura() {
}

bool Leitura::iniciarLeitura() {
  this->dir = opendir("../data/");

  if (this->dir != nullptr) {
    closedir (this->dir);
    return true;

  } else {
    perror ("Não foi possível abrir os arquivos");
    closedir (this->dir);
    return false;
  }
}

int Leitura::contarArquivos() {
  this->dir = opendir("../data/");

  int num_arquivos = -2;
  // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior

  while ((this->arquivos = readdir(this->dir)) != NULL) {
    num_arquivos++;
  }

  closedir (this->dir);

  return num_arquivos;
}

std::vector<std::string> Leitura::listarArquivos() {
  this->dir = opendir("../data/");
  int remover = 0;
  std::vector<std::string> enderecos;

  while ((this->arquivos = readdir(this->dir)) != NULL) {


    if (remover > 1) {
      // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior
      auto s1 = std::string("../data/");
      auto s2 = std::string(this->arquivos->d_name);
      enderecos.push_back((s1+s2));
    }

    remover++;
  }

  closedir (this->dir);
  std::cout << "Foram encontrados " << this->contarArquivos() << " arquivos na pasta './data/'." << std::endl;
  this->imprimirArquivos();
  std::cout << "Término do processamento de leitura." << std::endl << std::endl;

  if (remover > 1) {
    //Caso o número de arquivos seja maior do que 0
    return enderecos;

  } else {
    enderecos.clear ();
    return enderecos;
  }
}

void Leitura::imprimirArquivos() {
  this->dir = opendir("../data/");

  int remover = 0;
  std::cout << std::endl;

  while ((this->arquivos = readdir(this->dir)) != NULL) {
    if (remover > 1) {
      // Os dois primeiros items da lista de arquivos são a pasta atual e a pasta anterior
      std::cout << this->arquivos->d_name << std::endl;
    }

    remover++;
  }

  std::cout << std::endl;
  closedir (this->dir);
}