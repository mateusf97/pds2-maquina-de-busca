compile:
	g++ -std=c++14 -Wall ./src/*.cpp -o output.exe && ./output.exe

clean:
	rm -fr ./src/output.exe
