#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <iostream>
#include <vector>
#include <Core/Engine.h>
#include "Objects\Object.h"
#include "Transformations\Math.h"
#include "Transformations\Transformation.h"
#include "Objects\Astronaut.h"

class Tema1 : public SimpleScene
{
public:

	Tema1();
	~Tema1();
	void Init() override;

	static const int WINDOW_HEIGHT = 960;
	static const int WINDOW_WIDTH = 1720;

private:

	// Private Methods
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;
	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	// Private constants for the meshes

	// ------------------------------ ASTRONAUT ------------------------------
	const std::string ASTRONAUT_NAME = "astronaut";
	const glm::vec3 ASTRONAUT_CENTER = glm::vec3(400, 400, 1);
	const float ASTRONAUT_EDGE_LENGTH = 25;
	const float ASTRONAUT_SPEED = 400;
	// -----------------------------------------------------------------------

	// ------------------------------ ASTEROIDS ------------------------------
	const std::string ASTEROID1_NAME = "asteroid1";
	const glm::vec3 ASTEROID1_CENTER = glm::vec3(150, 150, 1);
	const float ASTEROID1_RADIUS = 35;
	const int ASTEROID1_Y_TRANSLATION_FACTOR = 200;
	const int ASTEROID1_Y_LIMIT_UP = 500;
	const int ASTEROID1_Y_LIMIT_DOWN = 100;

	const std::string ASTEROID2_NAME = "asteroid2";
	const glm::vec3 ASTEROID2_CENTER = glm::vec3(600, 400, 1);
	const float ASTEROID2_RADIUS = 100;
	const float ASTEROID2_SCALE_FACTOR_MIN = 0.5;
	const float ASTEROID2_SCALE_FACTOR_MAX = 2;
	const float ASTEROID2_SCALE_FACTOR = 0.40;
	const float ASTEROID2_OFFSET_X = 600;
	const float ASTEROID2_OFFSET_Y = 400;

	const std::string ASTEROID3_NAME = "asteroid3";
	const glm::vec3 ASTEROID3_CENTER = glm::vec3(1400, 200, 1);
	const float ASTEROID3_RADIUS = 75;
	const float ASTEROID3_SCALE_FACTOR_MIN = 0.9;
	const float ASTEROID3_SCALE_FACTOR_MAX = 2.2;
	const float ASTEROID3_SCALE_FACTOR = 0.5;
	const float ASTEROID3_ROTATION_FACTOR = 1.6;
	const float ASTEROID3_OFFSET_X = 1400;
	const float ASTEROID3_OFFSET_Y = 200;

	const std::string ASTEROID4_NAME = "asteroid4";
	const glm::vec3 ASTEROID4_CENTER = glm::vec3(1450, 550, 1);
	const float ASTEROID4_RADIUS = 120;
	const float ASTEROID4_ROTATION_FACTOR = 2.0;
	const float ASTEROID4_OFFSET_X = 1450;
	const float ASTEROID4_OFFSET_Y = 550;
	// -----------------------------------------------------------------------

	// ------------------------------ PLATFORMS ------------------------------
	const float PLATFORM_THICKNESS = 20;

	const std::string WALL_UP_NAME = "wall_up";
	const glm::vec3 WALL_UP_BOTTOM_LEFT_CORNER = glm::vec3(0, WINDOW_HEIGHT - PLATFORM_THICKNESS, 1);
	const float WALL_UP_WIDTH = (float) WINDOW_WIDTH;

	const std::string WALL_DOWN_NAME = "wall_down";
	const glm::vec3 WALL_DOWN_BOTTOM_LEFT_CORNER = glm::vec3(0, 0, 1);
	const float WALL_DOWN_WIDTH = (float) WINDOW_WIDTH;

	const std::string WALL_LEFT_NAME = "wall_left";
	const glm::vec3 WALL_LEFT_BOTTOM_LEFT_CORNER = glm::vec3(0, 0, 1);
	const float WALL_LEFT_HEIGHT = (float) WINDOW_HEIGHT;

	const std::string WALL_RIGHT_NAME = "wall_right";
	const glm::vec3 WALL_RIGHT_BOTTOM_LEFT_CORNER = glm::vec3(WINDOW_WIDTH - PLATFORM_THICKNESS, 0, 1);
	const float WALL_RIGHT_HEIGHT = (float) WINDOW_HEIGHT;

	const std::string PLATFORM_STATIONARY1_NAME = "platform_stationary1";
	const glm::vec3 PLATFORM_STATIONARY1_BOTTOM_LEFT_CORNER = glm::vec3(120, 820, 1);
	const float PLATFORM_STATIONARY1_WIDTH = 150;

	const std::string PLATFORM_STATIONARY2_NAME = "platform_stationary2";
	const glm::vec3 PLATFORM_STATIONARY2_BOTTOM_LEFT_CORNER = glm::vec3(500, 720, 1);
	const float PLATFORM_STATIONARY2_WIDTH = 240;

	const std::string PLATFORM_BOUNCE1_NAME = "platform_bounce1";
	const glm::vec3 PLATFORM_BOUNCE1_BOTTOM_LEFT_CORNER = glm::vec3(250, 50, 1);
	const float PLATFORM_BOUNCE1_WIDTH = 200;

	const std::string PLATFORM_BOUNCE2_NAME = "platform_bounce2";
	const glm::vec3 PLATFORM_BOUNCE2_BOTTOM_LEFT_CORNER = glm::vec3(700, 100, 1);
	const float PLATFORM_BOUNCE2_WIDTH = 400;

	const std::string PLATFORM_BOUNCE3_NAME = "platform_bounce3";
	const glm::vec3 PLATFORM_BOUNCE3_BOTTOM_LEFT_CORNER = glm::vec3(1050, 850, 1);
	const float PLATFORM_BOUNCE3_WIDTH = 400;

	const std::string PLATFORM_FINISH_NAME = "platform_finish";
	const glm::vec3 PLATFORM_FINISH_BOTTOM_LEFT_CORNER = glm::vec3(WINDOW_WIDTH - 2 * PLATFORM_THICKNESS, 200, 1);
	const float PLATFORM_FINISH_HEIGHT = 300;
	// -----------------------------------------------------------------------
	
	// Private variables
	glm::mat3 modelMatrix;		// the matrix used for transformations in the Update method
	float tx1;					// translation value for Ox (asteroid1)
	float ty1;					// translation value for Oy (asteroid1)
	bool up1;					// condition variable for going up or down (asteroid1)
	float scaleFactor2;			// scale factor value (asteroid2)
	bool grow2;					// condition variable for growing or shrinking (asteroid2)
	float rotationAngle3;		// angle for the rotation (asteroid3)
	float scaleFactor3;			// scale factor value (asteroid3)
	bool grow3;					// condition variable for growing or shrinking (asteroid3)
	float rotationAngle4;		// angle for the rotation (asteroid4)

	glm::vec3 centerOfAstronaut;			// coordinates for the center of the Astronaut
	float txA;								// translation for the Astronaut on Ox axis
	float tyA;								// translation for the Astronaut on Oy axis
	float rotationAngleOfAstronaut;			// angle of the Astronaut movement (in [-90, 270] deg interval)
	bool canAstronautChangeDirection;		// condition variable that is activated when the Astronaut is staying
	bool mouseClick;						// condition variable to determine if a mouse click ocurred
	// -----------------------------------------------------------------------

	// Animations for all asteroids

	void animateAsteroid1(float deltaTimeSeconds) {
		if (ty1 > ASTEROID1_Y_LIMIT_UP) {
			up1 = false;			// Asteroid 1 must change its direction and go down
		}
		else if (ty1 < ASTEROID1_Y_LIMIT_DOWN) {
			up1 = true;				// Asteroid 1 must change its direction and go up
		}

		if (up1) {
			ty1 += deltaTimeSeconds * ASTEROID1_Y_TRANSLATION_FACTOR;	// Move asteroid 1 up
		}
		else {
			ty1 -= deltaTimeSeconds * ASTEROID1_Y_TRANSLATION_FACTOR;	// Move asteroid 1 down
		}

		// Calculate the transformation matrix
		modelMatrix = Transformation::Translate(tx1, ty1);
	}

	void animateAsteroid2(float deltaTimeSeconds) {
		if (scaleFactor2 > ASTEROID2_SCALE_FACTOR_MAX) {
			grow2 = false;			// Asteroid 2 must shrink
		}
		else if (scaleFactor2 < ASTEROID2_SCALE_FACTOR_MIN) {
			grow2 = true;			// Asteroid 2 must grow
		}

		if (grow2) {
			scaleFactor2 += deltaTimeSeconds * ASTEROID2_SCALE_FACTOR;	// Grow asteroid2
		}
		else {
			scaleFactor2 -= deltaTimeSeconds * ASTEROID2_SCALE_FACTOR;	// Shrink asteroid2
		}

		// Calculate the transformation matrix
		modelMatrix = Transformation::Translate(ASTEROID2_OFFSET_X, ASTEROID2_OFFSET_Y);
		modelMatrix *= Transformation::Scale(scaleFactor2, scaleFactor2);
		modelMatrix *= Transformation::Translate(-ASTEROID2_OFFSET_X, -ASTEROID2_OFFSET_Y);
	}

	void animateAsteroid3(float deltaTimeSeconds) {
		// Update the angle
		rotationAngle3 += deltaTimeSeconds * ASTEROID3_ROTATION_FACTOR;

		if (scaleFactor3 > ASTEROID3_SCALE_FACTOR_MAX) {
			grow3 = false;			// Asteroid 3 must shrink
		}
		else if (scaleFactor3 < ASTEROID3_SCALE_FACTOR_MIN) {
			grow3 = true;			// Asteroid 3 must grow
		}

		if (grow3) {
			scaleFactor3 += deltaTimeSeconds * ASTEROID3_SCALE_FACTOR;	// Grow asteroid3
		}
		else {
			scaleFactor3 -= deltaTimeSeconds * ASTEROID3_SCALE_FACTOR;	// Shrink asteroid3
		}

		// Calculate the transformation matrix
		modelMatrix = Transformation::Translate(ASTEROID3_OFFSET_X, ASTEROID3_OFFSET_Y);
		modelMatrix *= Transformation::Rotate(rotationAngle3);
		modelMatrix *= Transformation::Scale(scaleFactor3, scaleFactor3);
		modelMatrix *= Transformation::Translate(-ASTEROID3_OFFSET_X, -ASTEROID3_OFFSET_Y);
	}

	void animateAsteroid4(float deltaTimeSeconds) {
		// Update the angle
		rotationAngle4 += deltaTimeSeconds * ASTEROID4_ROTATION_FACTOR;

		// Calculate the transformation matrix
		modelMatrix = Transformation::Translate(ASTEROID4_OFFSET_X, ASTEROID4_OFFSET_Y);
		modelMatrix *= Transformation::Rotate(rotationAngle4);
		modelMatrix *= Transformation::Translate(-ASTEROID4_OFFSET_X, -ASTEROID4_OFFSET_Y);
	}

	void animateAstronaut(float deltaTimeSeconds) {

		if (canAstronautChangeDirection) {
			if (mouseClick) {
				// The astronaut cannot change its direction after the mouse click
				canAstronautChangeDirection = false;
			}
		}
		else {
			float updatedSpeed = deltaTimeSeconds * ASTRONAUT_SPEED;

			// Update the translation factors for both axis
			txA += updatedSpeed * cos(M_PI / 2 + rotationAngleOfAstronaut);
			tyA += updatedSpeed * sin(M_PI / 2 + rotationAngleOfAstronaut);
		}

		// Move the astronaut
		modelMatrix = Transformation::Translate(ASTRONAUT_CENTER[0] + txA, ASTRONAUT_CENTER[1] + tyA);
		modelMatrix *= Transformation::Rotate(rotationAngleOfAstronaut);
		modelMatrix *= Transformation::Translate(-ASTRONAUT_CENTER[0], -ASTRONAUT_CENTER[1]);

		// Update the center of the astronaut
		centerOfAstronaut[0] = ASTRONAUT_CENTER[0] + txA;
		centerOfAstronaut[1] = ASTRONAUT_CENTER[1] + tyA;
	}

};
