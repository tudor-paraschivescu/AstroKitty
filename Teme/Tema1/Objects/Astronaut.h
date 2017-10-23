#pragma once

#include <include/glm.h>

namespace Astronaut {

	inline glm::vec3 GetTop(glm::vec3 center, float edge, float angle) {
		float medianLength = (((float)sqrt(5)) * edge) / 2;
		float totalOffset = medianLength * 2 / 3;
		float offsetX = totalOffset * cos(angle);
		float offsetY = totalOffset * sin(angle);
		return center + glm::vec3(offsetX, offsetY, 0);
	}

}