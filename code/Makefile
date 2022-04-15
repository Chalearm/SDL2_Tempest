
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
game.o : game.cpp game.h menuGame.o sdlHandler.o gameState.o
	g++ -c -o game.o game.cpp
	g++ -L . -shared -fPIC -o libgame.so game.o -l sdlHandler -l menuGame -lgameState
menuGame.o : menuGame.cpp menuGame.h gameState.o sdlHandler.o sdlObject.o
	g++ -c -o menuGame.o menuGame.cpp
	g++ -I . -L . -shared -fPIC -o libmenuGame.so menuGame.o -lgameState -lsdlHandler -lsdlObject
sdlObject.o : sdlObject.cpp sdlObject.h gameState.o sdlHandler.o sdlDrawnObj.o
	g++ -c -o sdlObject.o sdlObject.cpp
	g++ -I . -L . -shared -fPIC -o libsdlObject.so sdlObject.o -lgameState -lsdlHandler -lsdlDrawnObj
sdlHandler.o : sdlHandler.cpp sdlHandler.h gameState.o sdlDrawnObj.o gameObj.o
	g++ -c -o sdlHandler.o sdlHandler.cpp
	g++ -L . -shared -fPIC -o libsdlHandler.so sdlHandler.o -lgameState -l $(LIBINC) -lsdlDrawnObj -lgameObj
sdlDrawnObj.o : sdlDrawnObj.cpp sdlDrawnObj.h gameObj.o
	g++ -c -o sdlDrawnObj.o sdlDrawnObj.cpp
	g++ -I . -L . -shared -fPIC -o libsdlDrawnObj.so sdlDrawnObj.o -l $(LIBSDLIMG) -l $(LIBSDLTTF) -l $(LIBINC) -lgameObj
gameState.o : gameState.cpp gameState.h
	g++ -c -o gameState.o gameState.cpp
	g++ -shared -fPIC -o libgameState.so gameState.o
gameObj.o : gameObj.cpp gameObj.h
	g++ -c -o gameObj.o gameObj.cpp
	g++ -shared -fPIC -o libgameObj.so gameObj.o

clean:
	rm *.o *.so $(TARGETAPP)