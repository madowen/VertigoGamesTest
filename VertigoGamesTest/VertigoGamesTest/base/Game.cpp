#include "stdafx.h"
#include "Game.h"
#include "GameObject.h"
#include "GameObjectGenerator.h"
#include "io\io.h"
#include "utils\utils.h"

extern Game* game = nullptr;

Game::Game() {
	last_time = 0;
	next_id = 0;

	// create player //
	addObject(generatePlayer());

	// create items //
	addObject(generateItem(Vector3(20, -16, 0), HAT));
	addObject(generateItem(Vector3(25, 10, 0), FLASHLIGHT));
	addObject(generateItem(Vector3(27, -23, 0), STONE));
	addObject(generateItem(Vector3(-20, 0, 0), GUN));
	addObject(generateItem(Vector3(-25, 25, 0), AMMO));
	addObject(generateItem(Vector3(5, 25, 0), AMMO));
	addObject(generateItem(Vector3(-16, -12, 0), GUN));
	addObject(generateItem(Vector3(0, 10, 0), LEVER));
}

void Game::update(float dt){
	if (io->keys[KEY_ESC].becomesPressed())
		exit(0);

	// update all objects //   
	for (auto object : gameObjects)
		object.second->update(dt);

	// erase objects //
	for (auto id : gameObjectsToDestroy)
		gameObjects.erase(gameObjects.find(id));

	// delete objects //
	for (auto id : gameObjectsToDelete)
		delete id;

	gameObjectsToDestroy.clear();
	gameObjectsToDelete.clear();
}

void Game::display() {
    //OpenGL functions to draw a basic triangle
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	// render all objects //
	for (auto object : gameObjects)
		object.second->render();

    glutSwapBuffers(); //Swaps the double-buffer
    
    //update logic
    double elapsed_time = (SDL_GetTicks() - this->last_time) * 0.001; //0.001 converts from milliseconds to seconds
    this->last_time = SDL_GetTicks();
    this->update(elapsed_time);
	io->update(elapsed_time);
}

void Game::reshape(int w, int h){
    glutReshapeWindow( WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-UNIT_SIZE, UNIT_SIZE, -UNIT_SIZE, UNIT_SIZE, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void Game::stop() {
	gameObjects.clear();
}

GameObject * Game::getPlayer() {
	return gameObjects[0];
}

void Game::addObject(GameObject* obj) {
	gameObjects[next_id] = obj;
	obj->setID(next_id);
	next_id++;
}

GameObject* Game::getObject(int id) {
	return gameObjects[id];
}

void Game::quitObject(int id) {
	gameObjectsToDestroy.push_back(id);
}

void Game::deleteObject(GameObject* obj) {
	gameObjectsToDelete.push_back(obj);
}

