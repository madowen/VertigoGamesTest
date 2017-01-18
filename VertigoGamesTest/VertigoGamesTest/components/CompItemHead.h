#ifndef __COMP_ITEM_HEAD__
#define __COMP_ITEM_HEAD__

#include "CompItem.h"

class CCompItemHead : public CCompItem {
public:
	CCompItemHead() { slotToEquip = 1; }
	void render()=0;

	std::string className() = 0;
};

#endif