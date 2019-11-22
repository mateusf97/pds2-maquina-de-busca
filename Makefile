compile:
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

teste:
	cd data && rm -fr ./* && cd ../ && \
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

clean:
	rm -fr output.exe && cd src && rm -fr output.exe && cd ../
