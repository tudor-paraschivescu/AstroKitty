#include "Line.h"
#include <iostream>

Line::Line(glm::vec3 firstPoint, glm::vec3 secondPoint,
	Object::PlatformType platformType, CollisionLineType lineType)
{
	_firstPoint = firstPoint;
	_secondPoint = secondPoint;
	_platformType = platformType;
	_lineType = lineType;
}

Line::~Line()
{
}

glm::vec3 Line::getFirstPoint()
{
	return _firstPoint;
}

glm::vec3 Line::getSecondPoint()
{
	return _secondPoint;
}

Object::PlatformType Line::getPlatformType()
{
	return _platformType;
}

Line::CollisionLineType Line::getCollisionLineType()
{
	return _lineType;
}

void Line::toString()
{
	std::cout << "First Point [x: " << _firstPoint[0] <<
		" y: " << _firstPoint[1] << "] "
		<< "Second Point [x: " << _secondPoint[0] <<
		" y: " << _secondPoint[1] << "]" << std::endl;
}
