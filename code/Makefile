
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
 


$(TARGETAPP): ./src/$(TARGETAPP).cpp ./obj/game.o ./obj/color.o
	g++ $(BUILDMAINOPT) -I ./include -L ./lib ./src/$(TARGETAPP).cpp -o $(TARGETAPP) -l game -lcolor
./obj/game.o : ./src/game.cpp ./include/game.h ./obj/menuGame.o ./obj/sdlHandler.o ./obj/gameState.o ./obj/color.o ./obj/level1.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/game.o ./src/game.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libgame.so ./obj/game.o -lsdlHandler -lmenuGame -lgameState -lcolor -llevel1 -llevel
./obj/menuGame.o : ./src/menuGame.cpp ./include/menuGame.h ./obj/gameState.o ./obj/sdlHandler.o ./obj/sdlObject.o ./obj/gameMessage.o ./obj/color.o ./obj/flippers.o ./obj/tanker.o ./obj/spikers.o ./obj/enemy.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/menuGame.o ./src/menuGame.cpp 
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libmenuGame.so ./obj/menuGame.o -lgameState -lsdlHandler -lsdlObject -lgameMessage -lcolor -lflippers -lenemy -lspikers -ltanker -llineWithColor
./obj/level1.o : ./src/level1.cpp ./include/level1.h ./obj/level.o ./obj/gameMessage.o 
	g++ -I ./include  -c $(GCCOBJOPT) -o ./obj/level1.o ./src/level1.cpp
	g++ -I ./include  -L ./lib -shared -fPIC -o ./lib/liblevel1.so ./obj/level1.o -llevel -lgameMessage  -lcolor
./obj/level.o : ./src/level.cpp ./include/level.h ./obj/gameState.o ./obj/sdlHandler.o ./obj/sdlObject.o ./obj/gameMessage.o ./obj/color.o ./obj/flippers.o ./obj/tanker.o ./obj/spikers.o ./obj/enemy.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/level.o ./src/level.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/liblevel.so ./obj/level.o -lgameState -lsdlHandler -lsdlObject -lgameMessage -lcolor -lflippers -lenemy -lspikers -ltanker -llineWithColor
./obj/sdlObject.o : ./src/sdlObject.cpp ./include/sdlObject.h ./obj/gameState.o ./obj/sdlHandler.o ./obj/sdlDrawnObj.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlObject.o ./src/sdlObject.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libsdlObject.so ./obj/sdlObject.o -lgameState -lsdlHandler -lsdlDrawnObj -lcolor
./obj/sdlHandler.o : ./src/sdlHandler.cpp ./include/sdlHandler.h ./obj/gameState.o ./obj/sdlDrawnObj.o ./obj/gameObj.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlHandler.o ./src/sdlHandler.cpp
	g++ -L ./lib -shared -fPIC -o ./lib/libsdlHandler.so ./obj/sdlHandler.o -lgameState -l $(LIBINC) -lsdlDrawnObj -lgameObj -lcolor
./obj/sdlDrawnObj.o : ./src/sdlDrawnObj.cpp ./include/sdlDrawnObj.h ./obj/gameObj.o ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/sdlDrawnObj.o ./src/sdlDrawnObj.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libsdlDrawnObj.so ./obj/sdlDrawnObj.o -l $(LIBSDLIMG) -l $(LIBSDLTTF) -l $(LIBINC) -lgameObj -lcolor
./obj/gameState.o : ./src/gameState.cpp ./include/gameState.h
	g++ -I ./include  -c $(GCCOBJOPT) -o ./obj/gameState.o ./src/gameState.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libgameState.so ./obj/gameState.o
./obj/gameObj.o : ./src/gameObj.cpp ./include/gameObj.h
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/gameObj.o ./src/gameObj.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libgameObj.so ./obj/gameObj.o 
./obj/gameMessage.o : ./src/gameMessage.cpp ./include/gameMessage.h
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/gameMessage.o ./src/gameMessage.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libgameMessage.so ./obj/gameMessage.o
./obj/flippers.o : ./src/flippers.cpp ./include/flippers.h ./obj/enemy.o ./obj/color.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/flippers.o ./src/flippers.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libflippers.so ./obj/flippers.o -lenemy -lcolor -llineWithColor -lmotion2D
./obj/spikers.o : ./src/spikers.cpp ./include/spikers.h ./obj/enemy.o ./obj/color.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/spikers.o ./src/spikers.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libspikers.so ./obj/spikers.o -lenemy -lcolor -llineWithColor -lmotion2D
./obj/tanker.o : ./src/tanker.cpp ./include/tanker.h ./obj/enemy.o ./obj/color.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/tanker.o ./src/tanker.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libtanker.so ./obj/tanker.o -lenemy -lcolor -llineWithColor -lmotion2D
./obj/enemy.o : ./src/enemy.cpp ./include/enemy.h ./obj/color.o ./obj/lineWithColor.o ./obj/motion2D.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/enemy.o ./src/enemy.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libenemy.so ./obj/enemy.o -lcolor -llineWithColor -lmotion2D
./obj/motion2D.o : ./src/motion2D.cpp ./include/motion2D.h ./obj/color.o ./obj/lineWithColor.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/motion2D.o ./src/motion2D.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/libmotion2D.so ./obj/motion2D.o -lcolor -llineWithColor
./obj/lineWithColor.o : ./src/lineWithColor.cpp ./include/lineWithColor.h ./obj/color.o
	g++ -I ./include -c $(GCCOBJOPT) -o ./obj/lineWithColor.o ./src/lineWithColor.cpp
	g++ -I ./include -L ./lib -shared -fPIC -o ./lib/liblineWithColor.so ./obj/lineWithColor.o -lcolor
./obj/color.o : ./src/color.cpp ./include/color.h
	g++ -I ./include  -c $(GCCOBJOPT) -o ./obj/color.o ./src/color.cpp
	g++ -I ./include -shared -fPIC -o ./lib/libcolor.so ./obj/color.o -l $(LIBINC)

clean:
	rm ./obj/*.o ./lib/*.so $(TARGETAPP)