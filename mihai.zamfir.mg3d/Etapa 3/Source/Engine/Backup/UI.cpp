#include "UI.h"

#include <vector>
#include <iostream>

float UI::width = 12.0 / 637;
float UI::height = 16.0 / 33;

UI::UI() {
}

UI::~UI() {
}

glm::vec4 UI::GetScaleAndOffset(char ascii) {

	if (ascii == 32) {
		return glm::vec4(width, height, 26.0 * width, 1.0 * height);
	}

	if (ascii == 33) {
		return glm::vec4(width, height, 20.0 * width, 0.0 * height);
	}

	if (ascii == 34) {
		return glm::vec4(width, height, 17.0 * width, 0.0 * height);
	}

	if (ascii == 39) {
		return glm::vec4(width, height, 15.0 * width, 0.0 * height);
	}

	if (ascii == 40) {
		return glm::vec4(width, height, 19.0 * width, 0.0 * height);
	}

	if (ascii == 41) {
		return glm::vec4(width, height, 22.0 * width, 0.0 * height);
	}

	if (ascii == 42) {
		return glm::vec4(width, height, 26.0 * width, 0.0 * height);
	}

	if (ascii == 43) {
		return glm::vec4(width, height, 24.0 * width, 0.0 * height);
	}

	if (ascii == 44) {
		return glm::vec4(width, height, 12.0 * width, 0.0 * height);
	}

	if (ascii == 46) {
		return glm::vec4(width, height, 10.0 * width, 0.0 * height);
	}

	if (ascii == 47) {
		return glm::vec4(width, height, 27.0 * width, 0.0 * height);
	}

	if (ascii == 48) {
		return glm::vec4(width, height, 0.0 * width, 0.0 * height);
	}

	if ((49 <= ascii) && (ascii <= 57)) {
		return glm::vec4(width, height, (ascii - 49.0) * width, 0.0 * height);
	}

	if (ascii == 58) {
		return glm::vec4(width, height, 11.0 * width, 0.0 * height);
	}

	if (ascii == 59) {
		return glm::vec4(width, height, 13.0 * width, 0.0 * height);
	}

	if (ascii == 61) {
		return glm::vec4(width, height, 28.0 * width, 0.0 * height);
	}

	if (ascii == 63) {
		return glm::vec4(width, height, 21.0 * width, 0.0 * height);
	}

	if ((65 <= ascii) && (ascii <= 90)) {
		return glm::vec4(width, height, (ascii - 65.0 + 27) * width, 1.0 * height);
	}

	if ((97 <= ascii) && (ascii <= 122)) {
		return glm::vec4(width, height, (ascii - 97.0) * width, 1.0 * height);
	}

	if (ascii == 59) {
		return glm::vec4(width, height, 15.0 * width, 0.0 * height);
	}

	return glm::vec4(width, height, 30.0 * width, 0.0 * height);

}