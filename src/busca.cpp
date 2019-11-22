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
  this->imprimirCoordenadas();
  this->cosineRank(palavra);
}

double Busca::cosineRank(std::string palavra) {

  std::map<std::string, std::map<std::string, int>>::iterator it;
  unsigned int cnt = 0;

  for (it = this->indice.begin(); it != this->indice.end(); ++it)
    {
      if (it->first == palavra) {
        // Caso encontre a palavra, cancela a execução do laço e retorno a coluna dele no cnt.
        break;
      }

      cnt++;
    }

  this->Tf.clear();

  for (auto i: this->coordenadas) {
    double acumulado = 0.0;
    double acumulado_ao_quadrado = 0.0;
    double resultado = 0.0;

    for (unsigned int l=0; l < this->indice.size(); l++) {
      this->calcularCoordenadas(palavra);

      if(l==cnt){
        acumulado = i.second[l] * this->Idf;
      }

      double ao_quadrado = pow(i.second[l], 2);
      acumulado_ao_quadrado += ao_quadrado;
      this->Tf.clear();

    }

    double denominador = (sqrt(acumulado_ao_quadrado)*this->Idf);
    resultado = (acumulado/denominador);
    std::cout << resultado << std::endl;
  }

  std::cout << std::endl;

  imprimirCoordenadas();
  return 1;
}

void Busca::imprimirCoordenadas() {
  std::cout << "começou impressão das coordenadas" << std::endl;
  std::cout << std::left;

  for (auto k: this->coordenadas) {
    std::cout << k.first << std::endl;

  	for (unsigned int l=0; l < this->indice.size(); l++){
  	  std::cout << "|" << std::setw(9) << k.second[l];
  	}

    std::cout << std::endl << std::endl;
  }

  std::cout << "terminou impressão das coordenadas" << std::endl;
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

  this->Idf = log2( (double) N / Nx);
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

}


void Busca::imprimirTfs() {
  for(auto i: this->Tf) {
    std::cout << i << " | ";
  }

  std::cout << std::endl;
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
