
TARGETAPP=main
LIBINC=SDL2
LIBSDLIMG=SDL2_image-2.0.0
LIBSDLTTF=SDL2_ttf-2.0.0
GCCOBJOPT=-shared -fPIC
BUILDMAINOPT=-Wl,-rpath,.
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
		GCCOBJOPT = ""
		BUILDMAINOPT = ""
	endif
endif
 


$(TARGETAPP): $(TARGETAPP).cpp game.o color.o
	g++ $(BUILDMAINOPT) -L . $(TARGETAPP).cpp -o $(TARGETAPP) -lgame -lcolor
game.o : game.cpp game.h menuGame.o sdlHandler.o gameState.o color.o
	g++ -c $(GCCOBJOPT) -o game.o game.cpp
	g++ -L . -shared -fPIC -o libgame.so game.o -l sdlHandler -l menuGame -lgameState -lcolor
menuGame.o : menuGame.cpp menuGame.h gameState.o sdlHandler.o sdlObject.o gameMessage.o color.o flippers.o tanker.o spikers.o enemy.o
	g++ -c $(GCCOBJOPT) -o menuGame.o menuGame.cpp 
	g++ -I . -L . -shared -fPIC -o libmenuGame.so menuGame.o -lgameState -lsdlHandler -lsdlObject -lgameMessage -lcolor -lflippers -lenemy -lspikers -ltanker
sdlObject.o : sdlObject.cpp sdlObject.h gameState.o sdlHandler.o sdlDrawnObj.o
	g++ -c $(GCCOBJOPT) -o sdlObject.o sdlObject.cpp
	g++ -I . -L . -shared -fPIC -o libsdlObject.so sdlObject.o -lgameState -lsdlHandler -lsdlDrawnObj
sdlHandler.o : sdlHandler.cpp sdlHandler.h gameState.o sdlDrawnObj.o gameObj.o color.o
	g++ -c $(GCCOBJOPT) -o sdlHandler.o sdlHandler.cpp
	g++ -L . -shared -fPIC -o libsdlHandler.so sdlHandler.o -lgameState -l $(LIBINC) -lsdlDrawnObj -lgameObj -lcolor
sdlDrawnObj.o : sdlDrawnObj.cpp sdlDrawnObj.h gameObj.o color.o
	g++ -c $(GCCOBJOPT) -o sdlDrawnObj.o sdlDrawnObj.cpp
	g++ -I . -L . -shared -fPIC -o libsdlDrawnObj.so sdlDrawnObj.o -l $(LIBSDLIMG) -l $(LIBSDLTTF) -l $(LIBINC) -lgameObj -lcolor
gameState.o : gameState.cpp gameState.h
	g++ -c $(GCCOBJOPT) -o gameState.o gameState.cpp
	g++ -shared -fPIC -o libgameState.so gameState.o
gameObj.o : gameObj.cpp gameObj.h
	g++ -c $(GCCOBJOPT) -o gameObj.o gameObj.cpp
	g++ -I . -L . -shared -fPIC -o libgameObj.so gameObj.o 
gameMessage.o : gameMessage.cpp gameMessage.h
	g++ -c $(GCCOBJOPT) -o gameMessage.o gameMessage.cpp
	g++ -shared -fPIC -o libgameMessage.so gameMessage.o
color.o : color.cpp color.h
	g++ -c $(GCCOBJOPT) -o color.o color.cpp
	g++ -shared -fPIC -o libcolor.so color.o -l $(LIBINC)
flippers.o : flippers.cpp flippers.h enemy.o
	g++ -c $(GCCOBJOPT) -o flippers.o flippers.cpp
	g++ -I . -L . -shared -fPIC -o libflippers.so flippers.o -lenemy
spikers.o : spikers.cpp spikers.h enemy.o
	g++ -c $(GCCOBJOPT) -o spikers.o spikers.cpp
	g++ -I . -L . -shared -fPIC -o libspikers.so spikers.o -lenemy
tanker.o : tanker.cpp tanker.h enemy.o
	g++ -c $(GCCOBJOPT) -o tanker.o tanker.cpp
	g++ -I . -L . -shared -fPIC -o libtanker.so tanker.o -lenemy
enemy.o : enemy.cpp enemy.h
	g++ -c $(GCCOBJOPT) -o enemy.o enemy.cpp
	g++ -I . -L . -shared -fPIC -o libenemy.so enemy.o

clean:
	rm *.o *.so $(TARGETAPP)