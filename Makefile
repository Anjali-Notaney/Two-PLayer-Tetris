MAINFLAGS = $(flags)

biquadris: main.o Level.o Level0.o Level1.o Level2.o Level3.o Level4.o Grid.o GridCell.o Block.o JBlock.o LBlock.o SBlock.o ZBlock.o OBlock.o TBlock.o IBlock.o Player.o gamePlayer.o BlindDecorator.o ForceDecorator.o HeavyDecorator.o EffectsDecorator.o XWindow.o
	g++ -g -Dstartlevel=1 -std=c++14 -L/usr/X11R6/lib  main.o Level.o Level0.o Level1.o Level2.o Level3.o Level4.o Grid.o GridCell.o Block.o JBlock.o LBlock.o SBlock.o ZBlock.o OBlock.o TBlock.o IBlock.o Player.o gamePlayer.o BlindDecorator.o ForceDecorator.o HeavyDecorator.o EffectsDecorator.o XWindow.o -o biquadris -lX11

main.o: main.cc
	g++ -g ${MAINFLAGS} -std=c++14 -c main.cc

Grid.o: Grid/Grid.cc Grid/Grid.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Grid/Grid.cc

GridCell.o: Grid/GridCell.cc Grid/GridCell.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Grid/GridCell.cc

Block.o: Blocks/Block.cc Blocks/Block.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/Block.cc

JBlock.o: Blocks/JBlock.cc Blocks/JBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/JBlock.cc

LBlock.o: Blocks/LBlock.cc Blocks/LBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/LBlock.cc

SBlock.o: Blocks/SBlock.cc Blocks/SBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/SBlock.cc

ZBlock.o: Blocks/ZBlock.cc Blocks/ZBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/ZBlock.cc

OBlock.o: Blocks/OBlock.cc Blocks/OBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/OBlock.cc

TBlock.o: Blocks/TBlock.cc Blocks/TBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/TBlock.cc

IBlock.o: Blocks/IBlock.cc Blocks/IBlock.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Blocks/IBlock.cc

Player.o: Player/Player.cc Player/Player.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/Player.cc

gamePlayer.o: Player/gamePlayer.cc Player/gamePlayer.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/gamePlayer.cc

Level.o: Level/Level.cc Level/Level.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level.cc

Level0.o: Level/Level0.cc Level/Level0.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level0.cc

Level1.o: Level/Level1.cc Level/Level1.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level1.cc

Level2.o: Level/Level2.cc Level/Level2.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level2.cc

Level3.o: Level/Level3.cc Level/Level3.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level3.cc

Level4.o: Level/Level4.cc Level/Level4.h
	g++ -g ${MAINFLAGS} -std=c++14 -c Level/Level4.cc

BlindDecorator.o: Player/BlindDecorator.h Player/BlindDecorator.cc
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/BlindDecorator.cc

ForceDecorator.o: Player/ForceDecorator.h Player/ForceDecorator.cc
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/ForceDecorator.cc

HeavyDecorator.o: Player/HeavyDecorator.h Player/HeavyDecorator.cc
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/HeavyDecorator.cc

EffectsDecorator.o: Player/EffectsDecorator.h Player/EffectsDecorator.cc
	g++ -g ${MAINFLAGS} -std=c++14 -c Player/EffectsDecorator.cc

XWindow.o: XWindow/XWindow.h XWindow/XWindow.cc
	g++ -g -std=c++14 -c XWindow/XWindow.cc

.PHONY: clean

clean:
	rm *.o biquadris
