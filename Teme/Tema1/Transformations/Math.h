#pragma once

#include <include/glm.h>

namespace Math {

	inline float AngleBetween3Points(glm::vec3 center, glm::vec3 top, glm::vec3 direction)
	{
		float angle1 = atan2(center[1] - top[1], center[0] - top[0]);
		float angle2 = atan2(center[1] - direction[1], center[0] - direction[0]);
		return angle1 - angle2;
	}

}