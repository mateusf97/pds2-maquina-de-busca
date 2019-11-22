compile:
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

teste:
	cd data && rm -fr ./* && \
	touch doc1.txt && \
	touch doc2.txt && \
	touch doc3.txt && \
	touch doc4.txt && \
	echo "A A A B" > doc1.txt && \
	echo "A A C" > doc2.txt && \
	echo "A A" > doc3.txt && \
	echo "B B" > doc4.txt && \
	cd ../ && \
	cd src && g++ -std=c++14 -Wall main.cpp busca.cpp leitura.cpp processar.cpp -o output.exe && ./output.exe && cd ../

clean:
	rm -fr output.exe && cd src && rm -fr output.exe && cd ../
