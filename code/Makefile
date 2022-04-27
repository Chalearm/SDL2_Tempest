
TARGETAPP=main
LIBINC=SDL2
LIBSDLIMG=SDL2_image-2.0.0
LIBSDLTTF=SDL2_ttf-2.0.0
GCCOBJOPT=-shared -fPIC
BUILDMAINOPT=-Wl,-rpath,./lib
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
 


$(TARGETAPP): $(TARGETAPP).cpp ./obj/game.o ./obj/color.o
	g++ $(BUILDMAINOPT) -I ./include -L ./lib $(TARGETAPP).cpp -o $(TARGETAPP) -lgame -lcolor
./obj/game.o : game.cpp ./include/game.h ./obj/menuGame.o ./obj/sdlHandler.o ./obj/gameState.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/game.o game.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libgame.so ./obj/game.o -lsdlHandler -lmenuGame -lgameState -lcolor
./obj/menuGame.o : menuGame.cpp ./include/menuGame.h ./obj/gameState.o ./obj/sdlHandler.o ./obj/sdlObject.o ./obj/gameMessage.o ./obj/color.o ./obj/flippers.o ./obj/tanker.o ./obj/spikers.o ./obj/enemy.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/menuGame.o menuGame.cpp 
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libmenuGame.so ./obj/menuGame.o -lgameState -lsdlHandler -lsdlObject -lgameMessage -lcolor -lflippers -lenemy -lspikers -ltanker
./obj/sdlObject.o : sdlObject.cpp ./include/sdlObject.h ./obj/gameState.o ./obj/sdlHandler.o ./obj/sdlDrawnObj.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlObject.o sdlObject.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libsdlObject.so ./obj/sdlObject.o -lgameState -lsdlHandler -lsdlDrawnObj
./obj/sdlHandler.o : sdlHandler.cpp ./include/sdlHandler.h ./obj/gameState.o ./obj/sdlDrawnObj.o ./obj/gameObj.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlHandler.o sdlHandler.cpp
	g++ -L ./lib -shared -fPIC -o ./lib/libsdlHandler.so ./obj/sdlHandler.o -lgameState -l $(LIBINC) -lsdlDrawnObj -lgameObj -lcolor
./obj/sdlDrawnObj.o : sdlDrawnObj.cpp ./include/sdlDrawnObj.h ./obj/gameObj.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlDrawnObj.o sdlDrawnObj.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libsdlDrawnObj.so ./obj/sdlDrawnObj.o -l $(LIBSDLIMG) -l $(LIBSDLTTF) -l $(LIBINC) -lgameObj -lcolor
./obj/gameState.o : gameState.cpp ./include/gameState.h
	g++ -I ./include  -c $(GCCOBJOPT) -o ./obj/gameState.o gameState.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libgameState.so ./obj/gameState.o
./obj/gameObj.o : gameObj.cpp ./include/gameObj.h
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/gameObj.o gameObj.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libgameObj.so ./obj/gameObj.o 
./obj/gameMessage.o : gameMessage.cpp ./include/gameMessage.h
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/gameMessage.o gameMessage.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libgameMessage.so ./obj/gameMessage.o
./obj/color.o : color.cpp ./include/color.h
	g++ -I ./include  -c $(GCCOBJOPT) -o ./obj/color.o color.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libcolor.so ./obj/color.o -l $(LIBINC)
./obj/flippers.o : flippers.cpp ./include/flippers.h ./obj/enemy.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/flippers.o flippers.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libflippers.so ./obj/flippers.o -lenemy
./obj/spikers.o : spikers.cpp ./include/spikers.h ./obj/enemy.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/spikers.o spikers.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libspikers.so ./obj/spikers.o -lenemy
./obj/tanker.o : tanker.cpp ./include/tanker.h ./obj/enemy.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/tanker.o tanker.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libtanker.so ./obj/tanker.o -lenemy
./obj/enemy.o : enemy.cpp ./include/enemy.h
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/enemy.o enemy.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libenemy.so ./obj/enemy.o

clean:
	rm ./obj/*.o ./lib/*.so $(TARGETAPP)