#include "UIList.h"

#include <vector>
#include <iostream>


UIList::UIList() {

	/*
	UIElement* uiElements;
	int noUIElements;
	*/

	noUIElements = 5;
	uiElements = (UIElement*)malloc(noUIElements * sizeof(UIElement));

}

UIList::~UIList() {
}

void UIList::Draw() {
	std::cout << "UIList::Draw" << std::endl;
}
