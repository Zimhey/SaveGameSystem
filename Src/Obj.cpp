/*
 * Obj.cpp
 *
 *  Created on: Aug 9, 2013
 *      Author: Corey Dixon
 */

#include "Obj.h"
#include <GLFW/glfw3.h>

Obj::Obj()
{
	x = y = z = width = height = type = 0;
}

Obj::Obj(float x, float y)
{
	this->x = x;
	this->y = y;
	z = width = height = type = 0;
}

Obj::Obj(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	width = height = type = 0;
}

Obj::Obj(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	z = type = 0;
}

Obj::Obj(float x, float y, float z, float width, float height)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	type = 0;
}

Obj::~Obj()
{
}

float Obj::getHeight() const
{
	return height;
}

void Obj::setHeight(float height)
{
	this->height = height;
}

float Obj::getWidth() const
{
	return width;
}

void Obj::setWidth(float width)
{
	this->width = width;
}

float Obj::getX() const
{
	return x;
}

void Obj::setX(float x)
{
	this->x = x;
}

float Obj::getY() const
{
	return y;
}

void Obj::setY(float y)
{
	this->y = y;
}

float Obj::getZ() const
{
	return z;
}

void Obj::setZ(float z)
{
	this->z = z;
}

int Obj::getType() const
{
	return type;
}

void Obj::setType(int type)
{
	this->type = type;
}

void Obj::draw()
{

}

void Obj::drawDebug()
{

}

void Obj::tick()
{

}
