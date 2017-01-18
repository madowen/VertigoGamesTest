#ifndef __COMP_ITEM__
#define __COMP_ITEM__

#include "CompBase.h"

class CCompItem : public CCompBase {
protected:
	int equiped;
	int slotToEquip;
public:
	CCompItem():equiped(0){}
	void render();
	virtual std::string className() = 0;
	void receiveMessage(std::vector<std::string> msg);
	void update(float elapsed);
};

#endif 
