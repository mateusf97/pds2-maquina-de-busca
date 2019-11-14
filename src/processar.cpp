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
  // começou de imprimir os arquivos
  std::list<std::string> a = this->lista_de_arquivos;

  for (auto i = a.begin(); i != a.end(); i++) {

    std::string palavra;
    std::ifstream texto;
    texto.open(*i);
    char b;

    if (texto.is_open()) {
      while (texto.get(b)) {
        //Analísa caracter por caracter do arquivo
        if (!ispunct(b)) {
          //Se o caracter lido não for pontuação, continua o código
          if (isupper(b)) {
            b += 32;
            //se for uma letra maíscula, tranforma em minúscula
          }

          if (b == ' ' || b == '\n' || b == '\0'|| b == '\r'|| b == '\t') {
            // std::cout << palavra << std::endl;
            if (palavra != "") {
              this->mapearPalavras(palavra, *i);
            }
            palavra.clear();
            //se for um espaço entre letras, separa as palavras
          } else {
            palavra.push_back(b);
          }
        }
      }

      // std::cout << palavra << std::endl;
      //pega a ultima palavra depois do EOF
      this->mapearPalavras(palavra, *i);
      palavra.clear();
      texto.close();
    } else {
      std::cout << "Não foi possível abrir o arquivo" << std::endl;
    }
  }
}


void Processar::mapearPalavras(std::string palavra, std::string endereco) {
  std::map<std::string, int> relacao;

  if (this->indice.find(palavra) != this->indice.end()) {

    if (this->indice[palavra].find(endereco) != relacao.end()) {
      int i = this->indice[palavra][endereco];
      i++;
      this->indice[palavra][endereco] = i;
    } else {
      relacao.insert (std::pair< std::string, int>(endereco, 1));
    }

  } else {
    relacao.insert (std::pair< std::string, int>(endereco, 1));
    this->indice.insert (std::pair< std::string, std::map<std::string, int>>(palavra, relacao));
  }
}

void Processar::imprimirRelacoes() {

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

std::map<std::string, std::map<std::string, int>> Processar::getIndice() {
  return this->indice;
}
