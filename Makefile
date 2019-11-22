compile:
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

teste:
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

clean:
	cd src && rm -fr output.exe && cd ../
