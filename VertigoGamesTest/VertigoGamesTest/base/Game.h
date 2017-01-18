#ifndef __GAME__
#define __GAME__

#include <stdio.h>
#include <map>
#include <vector>

class GameObject;
class Game{
public:
    Game();
    void update(float dt);
    void display();
    void reshape(int w, int h);
	void stop();
	GameObject* getPlayer();
	void addObject(GameObject * obj);
	GameObject* getObject(int id);
	void quitObject(int id);
	void deleteObject(GameObject * obj);
private:
	int next_id;
	long last_time;
	std::map<int,GameObject*> gameObjects;
	std::vector<int>gameObjectsToDestroy;
	std::vector<GameObject*>gameObjectsToDelete;
};

extern Game* game;
#endif