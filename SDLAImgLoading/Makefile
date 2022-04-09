
LIBINC=SDL2
LIBSDLIMG=SDL2_image-2.0.0
ifeq ($(OS),Windows_NT)
		echo "Windows!"
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBINC = SDL2
		LIBSDLIMG = SDL2_image
	endif
	ifeq ($(UNAME_S),Darwin)
		LIBINC = SDL2-2.0.0
		LIBSDLIMG = SDL2_image-2.0.0
	endif
endif


SDLAImgLoading: SDLAImgLoading.cpp game.o 
	g++ -L . SDLAImgLoading.cpp -o SDLAImgLoading -lgame
	${EXTRA_ENVIRONMENT_SET}
game.o : game.cpp game.h
	g++ -c -o game.o game.cpp
	g++ -shared -fPIC -o libgame.so game.o -l $(LIBINC) -l $(LIBSDLIMG)

clean:
	rm game.o libgame.so SDLAImgLoading