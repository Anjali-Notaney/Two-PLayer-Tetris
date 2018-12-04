#include "interpreter.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

// gets a command and finds the correct command function for it
cmdfunc matchCommand(Player& pl, std::map<std::string, cmdfunc>& commands){
	bool found_match = false; // check if we have found a match
	int iterations = 1;
	std::string result;
	std::cin >> result; // get the command from the player
	if(std::cin.fail()){ // no command input so exit
		return nullptr;
	}
	std::istringstream ss(result); // create a stream from it

	// we get if there is an integer for the number of iterations
	ss >> iterations;
	if(ss.fail()){ // move on because there is no number of iterations given
		iterations = 1; // reset to default, doing the command only once
	}

	ss >> result;
	std::regex match_regex((std::string)"^" + result + (std::string)".*");
	cmdfunc command_function = nullptr;

	for(auto& it : commands){
		if(std::regex_match(it.first, match_regex)){
			if(found_match){ // too many matches so the function is terminated
				return nullptr;
			}else{
				found_match = true;
				command_function = it.second;
			}
		}
	}

	if(command_function != nullptr){ // we found a SINGLE match
		executeCommand(pl, command_function, iterations);
	}
	return command_function;
}


void executeCommand(Player& pl, cmdfunc command, int times){
	for(int i = 0; i < times; i++){
		command(pl);
	}
}

