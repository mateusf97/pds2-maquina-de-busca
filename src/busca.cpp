#include "busca.h"

Busca::Busca(int N,  std::map<std::string, std::map<std::string, int>> indice, std::list<std::string> enderecos) {
  this->N = N;
  this->indice = indice;
  this->enderecos = enderecos;
}

Busca::Busca() {
  std::cout <<  "Não é possível inicializar um buscador sem arquivos/parâmetros. Como você chegou aqui?" << std::endl;
}

Busca::~Busca() {
  // Destrutor
}

void Busca::realizarBusca(std::string palavra) {
  this->calcularRank(palavra);
}

// void Busca::imprimirRank() {
// }

void Busca::calcularRank(std::string palavra) {
  this->calcularNx(palavra);
  this->calcularIdf();
  this->calcularTf(palavra);
  // this->calcularNx(palavra);
}

void Busca::calcularNx(std::string palavra){
  this->Nx = this->indice[palavra].size();
}

void Busca::calcularTf(std::string palavra) {
  // this->Tf = this->indice[palavra][this->enderecos].second;
}

void Busca::calcularIdf(){
  int N = this->N;
  int Nx = this->Nx;

  this->Idf = log((float) N / Nx);

  std::cout << N << std::endl;
  std::cout << Nx << std::endl;
  std::cout << this->Idf << std::endl;
}


void Busca::imprimirRelacoes() {

  std::map<std::string, std::map<std::string, int>>::iterator it_palavras;
  std::map<std::string, int>::iterator it_relacao;
  std::map<std::string, int>::iterator end_relacao;
  std::cout << std::endl << "Inicio da impressão das relações" << std::endl;

  for (it_palavras = this->indice.begin(); it_palavras != this->indice.end(); it_palavras++) {
    std::cout <<  "KEY['" << it_palavras->first << "']" << std::endl;
    it_relacao = this->indice[it_palavras->first].begin();
    end_relacao = this->indice[it_palavras->first].end();

    for (; it_relacao != end_relacao; it_relacao++) {
      std::cout <<  "     ('" << it_relacao->first << ", " << it_relacao->second << "')" << std::endl;
    }
  }

  std::cout << std::endl << "Fim da impressão das relações" << std::endl;
}
