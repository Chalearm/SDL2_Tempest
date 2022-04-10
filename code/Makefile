
TARGETAPP=main
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


$(TARGETAPP): $(TARGETAPP).cpp game.o 
	g++ -L . $(TARGETAPP).cpp -o $(TARGETAPP) -lgame
	${EXTRA_ENVIRONMENT_SET}
game.o : game.cpp game.h sdlObject.o sdlWindowHandler.o gameObject.o
	g++ -c -o game.o game.cpp
	g++ -L . -shared -fPIC -o libgame.so game.o -l $(LIBINC) -l sdlWindowHandler -l sdlObject -lgameObject
sdlWindowHandler.o : sdlWindowHandler.cpp sdlWindowHandler.h sdlRenderer.o gameObject.o
	g++ -c -o sdlWindowHandler.o sdlWindowHandler.cpp
	g++ -L . -shared -fPIC -o libsdlWindowHandler.so sdlWindowHandler.o -lsdlRenderer -lgameObject -l $(LIBINC)
sdlObject.o : sdlObject.cpp sdlObject.h sdlRenderer.o gameObject.o
	g++ -c -o sdlObject.o sdlObject.cpp
	g++ -I . -L . -shared -fPIC -o libsdlObject.so sdlObject.o -lsdlRenderer -l $(LIBSDLIMG) -lgameObject -l $(LIBINC)
gameObject.o : gameObject.cpp gameObject.h
	g++ -c -o gameObject.o gameObject.cpp
	g++ -shared -fPIC -o libgameObject.so gameObject.o
sdlRenderer.o : sdlRenderer.cpp sdlRenderer.h
	g++ -c -o sdlRenderer.o sdlRenderer.cpp
	g++ -shared -fPIC -o libsdlRenderer.so sdlRenderer.o -l $(LIBINC)

clean:
	rm *.o *.so $(TARGETAPP)