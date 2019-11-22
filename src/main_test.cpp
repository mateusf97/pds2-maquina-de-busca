#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "leitura.h"
#include "busca.h"
#include "processar.h"

TEST_CASE("Teste 1 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  CHECK(leitor->iniciarLeitura() == true);
  delete leitor;
}

TEST_CASE("Teste 2 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);
  CHECK(leitor->contarArquivos() == 4);
  delete leitor;
}


TEST_CASE("Teste 3 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);
  REQUIRE(leitor->contarArquivos() == 4);
  std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  CHECK(lista_de_arquivos[0] == "../data/doc1.txt");
  delete leitor;
}


TEST_CASE("Teste 4 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);
  REQUIRE(leitor->contarArquivos() == 4);
  std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  CHECK(lista_de_arquivos[1] == "../data/doc2.txt");
  CHECK(lista_de_arquivos[2] == "../data/doc3.txt");
  CHECK(lista_de_arquivos[3] == "../data/doc4.txt");
  delete leitor;
}


TEST_CASE("Teste 1 – Processador de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);

 	std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  Processar *processador = new Processar(lista_de_arquivos);

  CHECK(processador->processarArquivos() == true);
}


TEST_CASE("Teste 2 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);

 	std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  Processar *processador = new Processar(lista_de_arquivos);

  REQUIRE(processador->processarArquivos() == true);
  CHECK(processador->getIndice()["a"]["../data/doc1.txt"] == 3);
}

TEST_CASE("Teste 3 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);

 	std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  Processar *processador = new Processar(lista_de_arquivos);

  REQUIRE(processador->processarArquivos() == true);
  CHECK(processador->getIndice()["b"]["../data/doc1.txt"] == 1);
}


TEST_CASE("Teste 4 – Leitura de arquivos") {
  Leitura *leitor = new Leitura();
  REQUIRE(leitor->iniciarLeitura() == true);

 	std::vector<std::string> lista_de_arquivos = leitor->listarArquivos();
  Processar *processador = new Processar(lista_de_arquivos);

  REQUIRE(processador->processarArquivos() == true);
  CHECK(processador->getIndice()["c"]["../data/doc1.txt"] == 0);
  CHECK(processador->getIndice()["c"]["../data/doc2.txt"] == 1);
  CHECK(processador->getIndice()["c"]["../data/doc3.txt"] == 0);
  CHECK(processador->getIndice()["c"]["../data/doc3.txt"] == 0);
}






// TEST_CASE("Teste Game - Caso Também Muito Mais Complicado") {
// 	Game *jogo = new Game();
// 	jogo->start(3);
// 	jogo->generate_hand();
// 	std::shared_ptr<Card> carta(new Card("NB9"));

// 	CHECK_THROWS_AS(jogo->check_move(carta, "NR0", 2), Invalid_Card);

// 	delete jogo;
// }







