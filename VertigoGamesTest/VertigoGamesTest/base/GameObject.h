#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <stdio.h>
#include <map>
#include <string>

class CCompBase;
class GameObject {
public:
	GameObject() {};
	~GameObject();
	void render();
	void update(float dt);
	void addComponent(CCompBase* c);
	CCompBase* getComponent(std::string comp_name);
	void sendMessage(std::vector<std::string> msg);
	int slotToEquip();
	void setID(int id) { ID = id; }
	int getID() { return ID; }
private:
	int ID;
	std::map<std::string, CCompBase*> components;
};
#endif 
