#include <string>

#include "leitura.h"
#include "processar.h"
#include "busca.h"

int main(int argc, char const *argv[])
{

  Leitura *leitor = new Leitura();


  if (leitor->iniciarLeitura()) {

    int num_arquivos = leitor->contarArquivos();

    if (num_arquivos > 0) {

      std::list<std::string> lista_de_arquivos = leitor->listarArquivos();

      Processar *processador = new Processar(lista_de_arquivos);

      processador->processarArquivos();

      delete processador;
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