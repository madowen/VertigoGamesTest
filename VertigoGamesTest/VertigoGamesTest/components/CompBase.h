#ifndef __COMP_BASE__
#define __COMP_BASE__

class GameObject;
class CCompBase {
protected:
	GameObject* owner;
public:
	virtual void render() {};
	virtual void renderHUD() {};
	virtual void update(float elapsed) {};
	virtual std::string className() =0;
	void setOwner(GameObject* o) { owner = o; }
	virtual void receiveMessage(std::vector<std::string> msg) {};
};

#endif