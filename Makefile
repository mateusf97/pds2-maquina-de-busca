compile:
	cd src && g++ -std=c++14 -Wall *.cpp -o output.exe && ./output.exe && cd ../

clean:
	rm -fr ./src/output.exe
