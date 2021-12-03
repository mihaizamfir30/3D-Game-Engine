#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::Draw() {
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}