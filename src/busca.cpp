#include "busca.h"

Busca::Busca(int N,  std::map<std::string, std::map<std::string, int>> indice, std::vector<std::string> enderecos) {
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
  for (auto i: this->indice)  {
	this->W.clear();
	this->Tf.clear();

	this->calcularCoordenadas(i.first);
	int aux = 0;
	for (auto j: this->enderecos) {
	  std::vector<double> v;
	  this->coordenadas.insert(std::pair<std::string, std::vector<double>>(j, v));
	  this->coordenadas[j].push_back(W[aux]);
	  aux++;
	}
  }
  std::cout << std::left;
  for (auto k: this->coordenadas){
  	for (unsigned int l=0; l < this->indice.size(); l++){
  	  std::cout <<"|"<< std::setw(9) << k.second[l];
  	}
  std::cout << std::endl;
  }
}

void Busca::calcularCoordenadas(std::string palavra) {
  this->calcularNx(palavra);
  this->calcularIdf();
  this->calcularTf(palavra);
  this->calcularW();
}

void Busca::calcularNx(std::string palavra){
  this->Nx = this->indice[palavra].size();
}

void Busca::calcularIdf(){
  int N = this->N;
  int Nx = this->Nx;

  this->Idf = log2( (float) N / Nx);
}

void Busca::calcularTf(std::string palavra) {
  for (int i = 0; i < this->N; ++i)
  {
    if(this->indice[palavra].find(this->enderecos[i]) != this->indice[palavra].end()) {
      this->Tf.push_back(this->indice[palavra][this->enderecos[i]]);
    } else {
      this->Tf.push_back(0);
    }
  }
}

void Busca::calcularW() {
  for (int i = 0; i < this->N; ++i)
  {
    this->W.push_back(this->Idf * this->Tf[i]);
  }

  // for(auto i: this->W) {
  //   std::cout << i << std::endl;
  // }
}


void Busca::imprimirTfs() {
  for(auto i: this->Tf) {
    std::cout << i << std::endl;
  }
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
