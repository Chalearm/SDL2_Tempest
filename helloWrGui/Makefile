
LIBINC=SDL2
ifeq ($(OS),Windows_NT)
		echo "Windows!"
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBINC = SDL2
	endif
	ifeq ($(UNAME_S),Darwin)
		LIBINC = SDL2-2.0.0
	endif
endif


all:
	g++ helloRedScr.cpp -o helloRedScr -l $(LIBINC)