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
    std::cout <<"lendo "<< *i << std::endl;

    std::string palavra;
    std::ifstream texto;
    texto.open (*i);
    char b;

    if (texto.is_open())
    {
    	while (texto.get (b)){	//Analísa caracter por caracter do arquivo
    		if (ispunct(b)) b = ' ';	//se for uma pontuação, ignora
    		else
    		{
    			if (isupper(b)) b += 32;	//se for uma letra maíscula, tranforma em minúscula
    			palavra.push_back(b);

    			if (b == ' ') {std::cout << palavra << std::endl; palavra.clear(); }	//se for um espaço entre letras, separa as palavras
    		}
    	}
    std::cout << palavra << std::endl;	//pega a ultima palavra depois do EOF
    palavra.clear();
    texto.close();
    }else{
    	std::cout << "Não foi possível abrir o arquivo" << std::endl;
    }
    std::cout << '\n';

  }

  std::cout << "acabou de imprimir os arquivos" << std::endl;
}


void Processar::mapearPalavras(std::string palavra, std::string endereco) {

}