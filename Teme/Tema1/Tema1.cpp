#include "Tema1.h"

#include <vector>
#include <iostream>

using namespace std;

Tema1::Tema1()
{
}

void Tema1::Init()
{
	// Set the camera
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	// Variable initialization
	tx1 = 0;
	ty1 = 0;
	up1 = true;
	scaleFactor2 = 1;
	grow2 = true;
	rotationAngle3 = 0;
	scaleFactor3 = 1;
	grow3 = true;
	rotationAngle4 = 0;
	centerOfAstronaut = ASTRONAUT_CENTER;
	topOfAstronaut = Astronaut::GetTop(centerOfAstronaut, ASTRONAUT_EDGE_LENGTH, M_PI / 2);

	// Create and add the meshes to the list
	// The astronaut
	AddMeshToList(Object::CreateAstronaut(ASTRONAUT_NAME, ASTRONAUT_CENTER, ASTRONAUT_EDGE_LENGTH));

	// The walls
	AddMeshToList(Object::CreatePlatform(WALL_UP_NAME, WALL_UP_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, WALL_UP_WIDTH, Object::PlatformType::STATIONARY));
	AddMeshToList(Object::CreatePlatform(WALL_DOWN_NAME, WALL_DOWN_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, WALL_DOWN_WIDTH, Object::PlatformType::STATIONARY));
	AddMeshToList(Object::CreatePlatform(WALL_LEFT_NAME, WALL_LEFT_BOTTOM_LEFT_CORNER,
		WALL_LEFT_HEIGHT, PLATFORM_THICKNESS, Object::PlatformType::STATIONARY));
	AddMeshToList(Object::CreatePlatform(WALL_RIGHT_NAME, WALL_RIGHT_BOTTOM_LEFT_CORNER,
		WALL_RIGHT_HEIGHT, PLATFORM_THICKNESS, Object::PlatformType::STATIONARY));

	// The stationary, bounce and finish platforms
	AddMeshToList(Object::CreatePlatform(PLATFORM_STATIONARY1_NAME, PLATFORM_STATIONARY1_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, PLATFORM_STATIONARY1_WIDTH, Object::PlatformType::STATIONARY));
	AddMeshToList(Object::CreatePlatform(PLATFORM_STATIONARY2_NAME, PLATFORM_STATIONARY2_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, PLATFORM_STATIONARY2_WIDTH, Object::PlatformType::STATIONARY));
	AddMeshToList(Object::CreatePlatform(PLATFORM_BOUNCE1_NAME, PLATFORM_BOUNCE1_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, PLATFORM_BOUNCE1_WIDTH, Object::PlatformType::BOUNCE));
	AddMeshToList(Object::CreatePlatform(PLATFORM_BOUNCE2_NAME, PLATFORM_BOUNCE2_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, PLATFORM_BOUNCE2_WIDTH, Object::PlatformType::BOUNCE));
	AddMeshToList(Object::CreatePlatform(PLATFORM_BOUNCE3_NAME, PLATFORM_BOUNCE3_BOTTOM_LEFT_CORNER,
		PLATFORM_THICKNESS, PLATFORM_BOUNCE3_WIDTH, Object::PlatformType::BOUNCE));
	AddMeshToList(Object::CreatePlatform(PLATFORM_FINISH_NAME, PLATFORM_FINISH_BOTTOM_LEFT_CORNER,
		PLATFORM_FINISH_HEIGHT, PLATFORM_THICKNESS, Object::PlatformType::FINISH));

	// The asteroids
	AddMeshToList(Object::CreateAsteroid(ASTEROID1_NAME, ASTEROID1_CENTER, ASTEROID1_RADIUS));
	AddMeshToList(Object::CreateAsteroid(ASTEROID2_NAME, ASTEROID2_CENTER, ASTEROID2_RADIUS));
	AddMeshToList(Object::CreateAsteroid(ASTEROID3_NAME, ASTEROID3_CENTER, ASTEROID3_RADIUS));
	AddMeshToList(Object::CreateAsteroid(ASTEROID4_NAME, ASTEROID4_CENTER, ASTEROID4_RADIUS));
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// Render walls
	RenderMesh2D(meshes[WALL_UP_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[WALL_DOWN_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[WALL_LEFT_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[WALL_RIGHT_NAME], shaders["VertexColor"], glm::mat3(1));

	// Render platforms
	RenderMesh2D(meshes[PLATFORM_STATIONARY1_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[PLATFORM_STATIONARY2_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[PLATFORM_BOUNCE1_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[PLATFORM_BOUNCE2_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[PLATFORM_BOUNCE3_NAME], shaders["VertexColor"], glm::mat3(1));
	RenderMesh2D(meshes[PLATFORM_FINISH_NAME], shaders["VertexColor"], glm::mat3(1));
}

void Tema1::Update(float deltaTimeSeconds)
{
	// Animate and render asteroid 1
	animateAsteroid1(deltaTimeSeconds);
	RenderMesh2D(meshes[ASTEROID1_NAME], shaders["VertexColor"], modelMatrix);

	// Animate and render asteroid 2
	animateAsteroid2(deltaTimeSeconds);
	RenderMesh2D(meshes[ASTEROID2_NAME], shaders["VertexColor"], modelMatrix);

	// Animate and render asteroid 3
	animateAsteroid3(deltaTimeSeconds);
	RenderMesh2D(meshes[ASTEROID3_NAME], shaders["VertexColor"], modelMatrix);

	// Animate and render asteroid 4
	animateAsteroid4(deltaTimeSeconds);
	RenderMesh2D(meshes[ASTEROID4_NAME], shaders["VertexColor"], modelMatrix);

	// Render astronaut
	RenderMesh2D(meshes[ASTRONAUT_NAME], shaders["VertexColor"], glm::mat3(1));
}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
