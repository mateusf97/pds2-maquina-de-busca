#include "processar.h"

Processar::Processar() {
  std::cout <<  "Não é possível inicializar um processador sem arquivos. Como você chegou aqui?" << std::endl;
}

Processar::Processar(std::list<std::string> lista_recebida) {
  this->lista_de_arquivos = lista_recebida;
}

Processar::~Processar() {
  // Destrutor
}

void Processar::processarArquivos() {
  std::cout << "começou de imprimir os arquivos" << std::endl;
  std::list<std::string> a = this->lista_de_arquivos;

  for (auto i = a.begin(); i != a.end(); i++)
  {
    std::cout << *i << std::endl;
  }

  std::cout << "acabou de imprimir os arquivos" << std::endl;
}
