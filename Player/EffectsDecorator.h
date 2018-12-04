#ifndef __EFFECTSDECORATOR_H__
#define __EFFECTSDECORATOR_H__
#include "Player.h"
#include "gamePlayer.h"

class EffectsDecorator: public Player{
	public:
	virtual ~EffectsDecorator() = 0; //pure virtual destructor for this abstract class
};
#endif

