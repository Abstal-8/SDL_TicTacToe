all: comp run

comp:
	g++ -I src/include -I Game_Logic -L src/lib -o main main.cpp Game_Logic/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
run:
	.\main.exe