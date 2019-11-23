#include <string>

#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{

  std::string input;
  Leitura *leitor = new Leitura();


  if (leitor->iniciarLeitura()) {

    int num_arquivos = leitor->contarArquivos();

    if (num_arquivos > 0) {

      std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();

      Processar *processador = new Processar(lista_de_arquivos);

      if (processador->processarArquivos()) {
        Busca *buscador = new Busca(num_arquivos, processador->getIndice(), lista_de_arquivos);

        std::cout << "Entre com as palavras a serem pesquisadas, separadas por 'espaço':" << std::endl;
        std::getline(std::cin, input);
        std::cout << "Terminou de ler!" << std::endl;
        std::vector<std::string> lista_de_inputs = processador->processarInput(input);
        for (auto i: lista_de_inputs){
          std::cout << i << std::endl;
        }
        buscador->realizarBusca("a");

        delete processador;
        delete buscador;
      } else {
        std::cout << "Não foi possível extrair os arquivos da pasta '../data'\n";
        std::cout << "Talvez você não tenha permissão de leitura da pasta.\n";
        std::cout << "Tente executar este programa como administrador." << std::endl;
        delete processador;
      }

    } else {
      std::cout << "Nenhum arquivos encontrado na pasta '../data'. ";
      std::cout << "Adicione  Um arquivo '.txt' para poder";
      std::cout << " executar este programa." << std::endl;
    }
  } else {
    std::cout << "Não foi possível extrair os arquivos da pasta '../data'\n";
    std::cout << "Talvez você não tenha permissão de leitura da pasta.\n";
    std::cout << "Tente executar este programa como administrador." << std::endl;
  }


  delete leitor;
  return 0;
}