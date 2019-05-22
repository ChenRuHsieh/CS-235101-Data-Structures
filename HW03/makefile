main:
	g++ code.cpp main.cpp -O2 -lm -std=c++11 -o main.exe -Wall


.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	del main.exe *.o
else
	rm main *.o
endif
