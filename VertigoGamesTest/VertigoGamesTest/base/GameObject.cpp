#include "stdafx.h"
#include "GameObject.h"
#include "components\CompTransform.h"
#include "components\CompItemHead.h"
#include "components\CompItemHand.h"


GameObject::~GameObject() {
	components.clear();
}

void GameObject::render(){
    glPushMatrix();
	CCompTransform* obj_trx = static_cast<CCompTransform*>(components["CCompTransform"]);
    obj_trx->modelSet();
    glColor3f(1.0f, 1.0f, 1.0f);
	for (auto comp : components)
		comp.second->render();
    glPopMatrix();
	for (auto comp : components)
		comp.second->renderHUD();

}

void GameObject::update(float dt){
	for (auto comp : components)
		comp.second->update(dt);
}

void GameObject::addComponent(CCompBase * c) {
	components[c->className()] = c;
}

CCompBase * GameObject::getComponent(std::string comp_name) {
	return components[comp_name];
}

void GameObject::sendMessage(std::vector<std::string> msg) {
	for (auto comp : components)
		comp.second->receiveMessage(msg);
}

int GameObject::slotToEquip() {
	for (auto comp : components)
		if (dynamic_cast<CCompItemHead*>(comp.second))
			return 1;
		else if (dynamic_cast<CCompItemHand*>(comp.second)) 
			return 2;
	return 0;
}