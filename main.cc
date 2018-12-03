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
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <regex>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cctype>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

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

void printPlayers(Player* activePlayer, Player *p1, Player *p2, int highScore){
    system("clear");
	std::cout << "+====================+" << std::endl;
	std::cout << " HIGHSCORE       " << highScore << std::endl;
	std::cout << "+====================+" << std::endl;
    std::cout << " Level:   " << p1->getLevel() << " \t\t" << " Level:   " << p2->getLevel() << std::endl;
    std::cout << " Score:   " << p1->getScore() << " \t\t" << " Score:   " << p2->getScore() << std::endl;
    std::cout << "+===========+\t\t+===========+" << std::endl;
	std::cout << "╔═══════════╗\t\t╔═══════════╗" << std::endl;
    for(int i = 0; i < 18; i++){
		if(i != 2) std::cout << "║";
		else std::cout << "╠";
        p1->printRow(i);
		if(i != 2) std::cout << "║";
		else std::cout << "╣";
        std::cout << "\t\t";
		if(i != 2) std::cout << "║";
		else std::cout << "╠";
        p2->printRow(i);
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

Level* getLevel(int playerId){
    #if startlevel == 0
    if(playerId == 1){
        #ifdef scriptfile1
        return new Level0(STRINGIZE_VALUE_OF(scriptfile1));
        #endif
        return new Level0("sequence1.txt");
    } else {
        #ifdef scriptfile2
        return new Level0(STRINGIZE_VALUE_OF(scriptfile2));
        #endif
        return new Level0("sequence2.txt");
    }
    #elif startlevel == 1 
    return new Level1;
    #elif startlevel == 2 
    return new Level2;
    #elif startlevel == 3 
    return new Level3;
    #elif startlevel == 4 
    return new Level4;
    #endif
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
void executeCommand(std::string s, Player* &activePlayer, Player* &p1, Player* &p2, std::vector<std::string> commands, int highScore, int times = 1){
    if ((s == "left") or (s == "right") or (s == "down") or (s == "clockwise") or (s == "counterclockwise")){
		if(s == "left") activePlayer->moveLeft(times);
		else if (s == "right") activePlayer->moveRight(times);
		else if (s == "down") activePlayer->moveDown(times);
		else if (s == "clockwise") activePlayer->rotate("CW", times);
		else if (s == "counterclockwise") activePlayer->rotate("CCW", times);
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
        activePlayer->levelUp(times);
    } else if (s == "leveldown"){
        activePlayer->levelDown(times);
    } else if (s == "norandom"){
        std::string sequencefile;
        std::cin >> sequencefile;
        activePlayer->noRandom(sequencefile);
    } else if (s == "random"){
		activePlayer->random();
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
            executeCommand(command,activePlayer, p1, p2, commands, highScore, numTimes);
		}
    } else if (s == "restart"){
        throw std::string("restart");
    } else if (s == "I" || s == "J" || s == "L" || s == "S" || s == "Z" || s == "T" || s == "O"){
        activePlayer->replaceBlock(s[0]);
    }
}



int main(){    
    //Initialize Game
	int highScore = 0;
	while(!(std::cin.eof() || std::cin.fail())){
		std::vector<std::string> commands = initVector();
		Grid *g1 = new Grid();
		Grid *g2 = new Grid();
		Level *p1Level = getLevel(1);
		Level *p2Level = getLevel(0);
		Player *p1 = new GamePlayer(g1,p1Level, 1);
		Player *p2 = new GamePlayer(g2,p2Level, 0);
		p1->setNextBlock();
		p2->setNextBlock();

		//Set active player to player one
		Player *activePlayer = p1;

		//GAME LOOP
		printPlayers(activePlayer,p1,p2,highScore);
		while(!(std::cin.eof() || std::cin.fail())){
			try{
				std::string s;
				std::cin >> s;
				int numTimes = getNumTimes(s);
				s = matchCommand(s, commands);
				executeCommand(s,activePlayer, p1, p2, commands, highScore, numTimes);
				if(p1->getScore() > highScore || p2->getScore() > highScore) highScore = std::max(p1->getScore(), p2->getScore());
				printPlayers(activePlayer,p1,p2,highScore);
			} catch(std::exception){
				std::cout << "Game Over!" << std::endl;
				if(activePlayer->getPlayerId() == 1){
					std::cout << "Player 2 WINS!" << std::endl;
				} else {
					std::cout << "Player 1 WINS!" << std::endl;
				}
				std::cout << "RETURN to continue, EXIT to quit" << std::endl;
				std::cout << "> ";
				std::string s;
				std::cin>>s; 
				if(s == "RETURN"){
					break;
				} else if (s == "EXIT"){
					exit(0);
				}
				break;
			} catch (std::string) {
				break;
			}
		}
		p1->setPlayerOneActive();
		delete p1;
		delete p2;
		delete g1;
		delete g2;
		delete p1Level;
		delete p2Level;
	}
}

