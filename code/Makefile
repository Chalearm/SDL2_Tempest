
TARGETAPP=main
LIBINC=SDL2
LIBSDLIMG=SDL2_image-2.0.0
LIBSDLTTF=SDL2_ttf-2.0.0
ifeq ($(OS),Windows_NT)
		echo "Windows!"
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBINC = SDL2
		LIBSDLIMG = SDL2_image
		LIBSDLTTF = SDL2_ttf
	endif
	ifeq ($(UNAME_S),Darwin)
		LIBINC = SDL2-2.0.0
		LIBSDLIMG = SDL2_image-2.0.0
		LIBSDLTTF = SDL2_ttf-2.0.0
	endif
endif


$(TARGETAPP): $(TARGETAPP).cpp game.o 
	g++ -L . $(TARGETAPP).cpp -o $(TARGETAPP) -lgame
	${EXTRA_ENVIRONMENT_SET}
game.o : game.cpp game.h sdlObject.o sdlHandler.o gameObject.o
	g++ -c -o game.o game.cpp
	g++ -L . -shared -fPIC -o libgame.so game.o -l sdlHandler -l sdlObject -lgameObject
sdlHandler.o : sdlHandler.cpp sdlHandler.h gameObject.o sdlDrawnObj.o
	g++ -c -o sdlHandler.o sdlHandler.cpp
	g++ -L . -shared -fPIC -o libsdlHandler.so sdlHandler.o -lgameObject -l $(LIBINC) -lsdlDrawnObj
sdlDrawnObj.o : sdlDrawnObj.cpp sdlDrawnObj.h
	g++ -c -o sdlDrawnObj.o sdlDrawnObj.cpp
	g++ -I . -L . -shared -fPIC -o libsdlDrawnObj.so sdlDrawnObj.o -l $(LIBSDLIMG) -l $(LIBSDLTTF) -l $(LIBINC)
sdlObject.o : sdlObject.cpp sdlObject.h gameObject.o
	g++ -c -o sdlObject.o sdlObject.cpp
	g++ -I . -L . -shared -fPIC -o libsdlObject.so sdlObject.o -lgameObject -l $(LIBINC)
gameObject.o : gameObject.cpp gameObject.h
	g++ -c -o gameObject.o gameObject.cpp
	g++ -shared -fPIC -o libgameObject.so gameObject.o

clean:
	rm *.o *.so $(TARGETAPP)