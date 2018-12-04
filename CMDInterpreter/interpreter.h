#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <map>

class Player;

typedef void (*cmdfunc)(Player&);

void executeCommand(Player& pl, cmdfunc command, int times = 1);

cmdfunc matchCommand(Player& pl, std::map<std::string, cmdfunc>& commands);

#endif

