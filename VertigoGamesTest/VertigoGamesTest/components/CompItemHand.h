#ifndef __COMP_ITEM_HAND__
#define __COMP_ITEM_HAND__

#include "CompItem.h"

class CCompItemHand : public CCompItem {
public:
	CCompItemHand() { slotToEquip = 2; }
	void render() = 0;
	virtual void action(std::vector<std::string>msg) = 0;
	std::string className() = 0;
};

#endif