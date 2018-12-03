#include "Player/Player.h"
#include "Player/gamePlayer.h"
#include "Player/BlindDecorator.h"
#include "Player/EffectsDecorator.h"
#include "Player/ForceDecorator.h"
#include "Player/HeavyDecorator.h"
#include "Blocks/OBlock.h"
#include "Blocks/JBlock.h"
#include "Blocks/IBlock.h"
#include "Blocks/SBlock.h"
#include "Blocks/ZBlock.h"
#include "Blocks/TBlock.h"
#include "Blocks/LBlock.h"
#include "Level/Level.h"
#include "Level/Level0.h"
#include "Level/Level1.h"
#include "Level/Level2.h"
#include "Level/Level3.h"
#include "Level/Level4.h"
#include "XWindow/XWindow.h"
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <regex>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cctype>

std::map<char, std::string> Block::colours = {};

void printPlayerBlocks(Player* p1, Player* p2){
	char p1NextBlock = p1->getNextBlockChar();
	char p2NextBlock = p2->getNextBlockChar();
	switch (p1NextBlock) {
	case 'S':
		std::cout << "║  SS       ║";
		break;
	case 'Z':
		std::cout << "║ ZZ        ║";
		break;
	case 'T':
		std::cout << "║ TTT       ║";
		break;
	case 'L':
		std::cout << "║   L       ║";
		break;
	case 'J':
		std::cout << "║ J         ║";
		break;
	case 'O':
		std::cout << "║ OO        ║";
		break;
	case 'I':
		std::cout << "║ IIII      ║";
		break;
	}
	std::cout << "\t\t";
	//Print second block first row
	switch (p2NextBlock) {
	case 'S':
		std::cout << "║  SS       ║" << std::endl;
		break;
	case 'Z':
		std::cout << "║ ZZ        ║" << std::endl;
		break;
	case 'T':
		std::cout << "║ TTT       ║" << std::endl;
		break;
	case 'L':
		std::cout << "║   L       ║" << std::endl;
		break;
	case 'J':
		std::cout << "║ J         ║" << std::endl;
		break;
	case 'O':
		std::cout << "║ OO        ║" << std::endl;
		break;
	case 'I':
		std::cout << "║ IIII      ║" << std::endl;
		break;
	}

	switch (p1NextBlock) {
	case 'S':
		std::cout << "║ SS        ║";
		break;
	case 'Z':
		std::cout << "║  ZZ       ║";
		break;
	case 'T':
		std::cout << "║  T        ║";
		break;
	case 'L':
		std::cout << "║ LLL       ║";
		break;
	case 'J':
		std::cout << "║ JJJ       ║";
		break;
	case 'O':
		std::cout << "║ OO        ║";
		break;
	case 'I':
		std::cout << "║           ║";
	break;
	}
	std::cout << "\t\t";
	switch (p2NextBlock) {
		case 'S':
			std::cout << "║ SS        ║" << std::endl;
			break;
		case 'Z':
			std::cout << "║  ZZ       ║" << std::endl;
			break;
		case 'T':
			std::cout << "║  T        ║" << std::endl;
			break;
		case 'L':
			std::cout << "║ LLL       ║" << std::endl;
			break;
		case 'J':
			std::cout << "║ JJJ       ║" << std::endl;
			break;
		case 'O':
			std::cout << "║ OO        ║" << std::endl;
			break;
		case 'I':
			std::cout << "║           ║" << std::endl;
		break;
	}

}

void printPlayers(Player* activePlayer, Player *p1, Player *p2, int highScore, Xwindow* window=nullptr){
    system("clear");
	std::cout << "+====================+" << std::endl;
	std::cout << " HIGHSCORE       " << highScore << std::endl;
	std::cout << "+====================+" << std::endl;
    std::cout << " Level:   " << p1->getLevel() << " \t\t" << " Level:   " << p2->getLevel() << std::endl;
    std::cout << " Score:   " << p1->getScore() << " \t\t" << " Score:   " << p2->getScore() << std::endl;
    std::cout << "+===========+\t\t+===========+" << std::endl;
	std::cout << "╔═══════════╗\t\t╔═══════════╗" << std::endl;

	// draw the background
	window->setFill("111111");
	window->fillRectangle(0, window->getHeight()*0.15, window->getWidth()/3, window->getHeight());
	window->fillRectangle(window->getWidth()*(0.66667), window->getHeight()*0.15, window->getWidth()/3, window->getHeight());
	window->setFill("333333");
	for(int i = 0; i < window->getWidth()/3; i += (window->getWidth()/3)/11){
		window->drawLine(i, window->getHeight()*0.15, i, window->getHeight());
		window->drawLine(i + window->getWidth()*(0.66667), window->getHeight()*0.15, i + window->getWidth()*(0.66667), window->getHeight());
	}

	for(int i = window->getHeight()*0.15; i < window->getHeight(); i += (window->getHeight()*(0.85))/18){
		window->drawLine(0, i, window->getWidth()/3, i);
		window->drawLine(window->getWidth()*(0.66667), i, window->getWidth(), i);
	}

    for(int i = 0; i < 18; i++){
		if(i != 2) std::cout << "║";
		else std::cout << "╠";
        p1->printRow(i, window);
		if(i != 2) std::cout << "║";
		else std::cout << "╣";
        std::cout << "\t\t";
		if(i != 2) std::cout << "║";
		else std::cout << "╠";
        p2->printRow(i, window);
        if(i != 2) std::cout << "║" << std::endl;
		else std::cout << "╣" << std::endl;
    }
    std::cout << "╚═══════════╝\t\t╚═══════════╝" << std::endl;
	std::cout << "╔═══════════╗\t\t╔═══════════╗" << std::endl;
    std::cout << "║ Next:     ║\t\t║ Next:     ║" << std::endl;
	printPlayerBlocks(p1,p2);
	std::cout << "╚═══════════╝\t\t╚═══════════╝" << std::endl;
	std::cout << std::endl;
	if(activePlayer->getPlayerId() == 1){
        std::cout << "Player One's Turn" << std::endl;
    } else {
        std::cout << "Player Two's Turn" << std::endl;
    }
	std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    std::cout << "Command: " << std::endl;
}

Level* getLevel(int playerId, Grid *g, int startlevel, std::string scriptfile1, std::string scriptfile2, int seed){
	switch(startlevel){
		case 0:
			if(playerId == 1) return new Level0(scriptfile1);
			else return new Level0(scriptfile2);
			break;
		case 1:
			return new Level1(seed);
			break;
		case 2:
			return new Level2(seed);
			break;
		case 3:
			return new Level3(seed);
			break;
		case 4:
			return new Level4(g, seed);
			break;
	}
	return nullptr;
}

//Make a vector of supported commands
std::vector<std::string> initVector(){
    std::vector<std::string> tmp;
    tmp.emplace_back("left");
    tmp.emplace_back("right");
    tmp.emplace_back("down");
    tmp.emplace_back("clockwise");
    tmp.emplace_back("counterclockwise");
    tmp.emplace_back("drop");
    tmp.emplace_back("levelup");
    tmp.emplace_back("leveldown");
    tmp.emplace_back("norandom");
    tmp.emplace_back("random");
    tmp.emplace_back("sequence");
    tmp.emplace_back("I");
    tmp.emplace_back("J");
    tmp.emplace_back("L");
    tmp.emplace_back("T");
    tmp.emplace_back("S");
    tmp.emplace_back("Z");
    tmp.emplace_back("O");
	tmp.emplace_back("restart");
    return tmp;
}

int getNumTimes(std::string &s){
    int numTimes;
    for (int i = 0; i < s.length(); i++){
        if (!isdigit(s[i])){
            if (i == 0) return 1;
            std::stringstream ss{s.substr(0,i+1)};
            s = s.substr(i);
            ss>>numTimes;
            return numTimes;
        }
    }
}

//Takes a vector of commands and finds the matching command
std::string matchCommand(std::string input, std::vector<std::string> commands){
    int numMatches = 0;
    std::string command;
    for(auto i : commands){
        if(std::regex_match(i,std::regex("^" + input + "(.*)"))){
            numMatches++;
            command = i;
        }
    }
    if(numMatches == 1 || std::find(commands.begin(), commands.end(), input) != commands.end()){
        return command;
    }
    return "Please be more specific"; 
}

void changeTurn( Player* &activePlayer, Player* &p1, Player* &p2){
    activePlayer->setNextBlock();
    if(activePlayer->getPlayerId() == 1){
		p1 = p1->getBasePlayer();
        activePlayer = p2;
    } else {
		p2 = p2->getBasePlayer();
        activePlayer = p1;
    }
}

//Execute the command given
void executeCommand(std::string s, Player* &activePlayer, Player* &p1, Player* &p2, std::vector<std::string> commands, int highScore,
					std::string scriptfile1, std::string scriptfile2, int seed, int times = 1){
    if(s == "left"){
        activePlayer->moveLeft(times);
        if (activePlayer->isPlayerOnePlaying() != activePlayer->getPlayerId()){
            changeTurn(activePlayer, p1, p2);  
        }
    } else if (s == "right"){
        activePlayer->moveRight(times);
        if (activePlayer->isPlayerOnePlaying() != activePlayer->getPlayerId()){
            changeTurn(activePlayer, p1, p2);  
        }
    } else if (s == "down"){
        activePlayer->moveDown(times);
        if (activePlayer->isPlayerOnePlaying() != activePlayer->getPlayerId()){
            changeTurn(activePlayer, p1, p2);  
        }
    } else if (s == "clockwise"){
        activePlayer->rotate("CW", times);
        if (activePlayer->isPlayerOnePlaying() != activePlayer->getPlayerId()){
            changeTurn(activePlayer, p1, p2);  
        }
    } else if (s == "counterclockwise"){
        activePlayer->rotate("CCW", times);
        if (activePlayer->isPlayerOnePlaying() != activePlayer->getPlayerId()){
            changeTurn(activePlayer, p1, p2);  
        }
    } else if (s == "drop"){

        //If they clear two or more lines, then take input for the other player
		if(activePlayer->drop() >= 2){
			std::string decorator;
            std::cout << "Enter your Special Command:" <<std::endl;
			std::cin >> decorator;
			if(decorator == "blind"){
				if(activePlayer->getPlayerId() == 1) {
                    p2 = new BlindDecorator(p2);
                } else {
                    p1 = new BlindDecorator(p1);
                }
			} else if (decorator == "heavy"){
				if(activePlayer->getPlayerId() == 1) {
                    p2 = new HeavyDecorator(p2);
                }
			    else {
                    p1 = new HeavyDecorator(p1);
                }
			} else if (decorator == "force"){
			    char type;
				std::cin >> type;
				if(activePlayer->getPlayerId() == 1) {
                    p2 = new ForceDecorator(p2, type);
                }
                else {
                    p1 = new ForceDecorator(p1, type);
                }
			}
		}
        changeTurn(activePlayer, p1, p2); 
    } else if (s == "levelup"){
        activePlayer->levelUp(times, seed);
    } else if (s == "leveldown"){
        activePlayer->levelDown(times,scriptfile1,scriptfile2, seed);
    } else if (s == "norandom"){
        std::string sequencefile;
        std::cin >> sequencefile;
        activePlayer->noRandom(sequencefile);
    } else if (s == "sequence"){
        std::string sequencefile;
        std::cin >> sequencefile;
		std::ifstream inputFile{sequencefile};
		std::cout << sequencefile << std::endl;
        while(!inputFile.fail()){
			std::string command;
			getline(inputFile,command);
			int numTimes = getNumTimes(command);
            command = matchCommand(command, commands);
            executeCommand(command,activePlayer, p1, p2, commands, highScore, scriptfile1, scriptfile2, numTimes);
		}
    } else if (s == "restart"){
        throw std::string("restart");
    } else if (s == "I" || s == "J" || s == "L" || s == "S" || s == "Z" || s == "T" || s == "O"){
        activePlayer->replaceBlock(s[0]);
    }
}



int main(int argc, const char* argv[]){
	//Get the game flags
	bool onlyText = false;
	std::string sequencefile1 = "sequence1.txt";
	std::string sequencefile2 = "sequence2.txt";
	int numLevel = 0;
	int seed = -1;
	for(int i = 0; i < argc; i++){
		if(std::string(argv[i]) == "-text"){
			onlyText = true;
		}
		if(std::string(argv[i]) == "-scriptfile1"){
			sequencefile1 = argv[i+1];
		}
		if(std::string(argv[i]) == "-scriptfile2"){
			sequencefile2 = argv[i+1];
		}
		if(std::string(argv[i]) == "-startlevel"){
			std::stringstream s{argv[i+1]};
			s >> numLevel;
		}
		if(std::string(argv[i]) == "-seed"){
			std::stringstream s{argv[i+1]};
			s >> seed;
		}
	}   
	std::cout << sequencefile1 << std::endl; 
	std::cout << sequencefile2 << std::endl; 
	std::cout << onlyText << std::endl; 
	std::cout << numLevel << std::endl; 
	std::cout << seed << std::endl; 
    //Initialize Game
    Xwindow* window = new Xwindow(624, 400);
	int highScore = 0;

	// set middle
	window->setFill("222288");
	window->fillRectangle(0, 0, window->getWidth(), window->getHeight());
	window->drawString(window->getWidth()/2 - 40, window->getHeight()*0.05, "BIQUADRIS!");

	// set colours
	Block::colours.emplace(std::make_pair('T', "cc33ff"));
	Block::colours.emplace(std::make_pair('I', "66ffff"));
	Block::colours.emplace(std::make_pair('L', "ff6600"));
	Block::colours.emplace(std::make_pair('O', "ffff00"));
	Block::colours.emplace(std::make_pair('S', "00cc00"));
	Block::colours.emplace(std::make_pair('Z', "ff0000"));
	Block::colours.emplace(std::make_pair('J', "3333cc"));

	while(true){
		std::vector<std::string> commands = initVector();
		Grid *g1 = new Grid();
		Grid *g2 = new Grid();
		Level *p1Level = getLevel(1,g1,numLevel, sequencefile1, sequencefile1, seed);
		Level *p2Level = getLevel(0,g2, numLevel, sequencefile1, sequencefile2, seed);
		Player *p1 = new GamePlayer(g1,p1Level, 1);
		Player *p2 = new GamePlayer(g2,p2Level, 0);
		p1->setNextBlock();
		p2->setNextBlock();

		// change the display offset of player 2
		static_cast<GamePlayer*>(p2)->setDisplayOffset(window->getWidth()*(0.6667));
		//Set active player to player one
		Player *activePlayer = p1;

		//GAME LOOP
		printPlayers(activePlayer,p1,p2,highScore, window);
		while(!std::cin.fail()){
			try{
				std::string s;
				std::cin >> s;
				int numTimes = getNumTimes(s);
				s = matchCommand(s, commands);
				executeCommand(s,activePlayer, p1, p2, commands, highScore, sequencefile1, sequencefile2, seed, numTimes);
				if(p1->getScore() > highScore || p2->getScore() > highScore) highScore = std::max(p1->getScore(), p2->getScore());
				printPlayers(activePlayer,p1,p2,highScore);
			} catch(std::exception){
				std::cout << "Game Over!" << std::endl;
				if(activePlayer->getPlayerId() == 0){
					std::cout << "Player 2 WINS!" << std::endl;
				} else {
					std::cout << "Player 1 WINS!" << std::endl;
				}
				break;
			} catch (std::string) {
				break;
			}
		}
		delete p1;
		delete p2;
	}
}

