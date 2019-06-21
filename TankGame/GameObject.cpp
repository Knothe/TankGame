#pragma once
#include "GameObject.h"

void GameObject::SetCenterInGame()
{
	centerInGame = position + center;
}

Vector GameObject::GetCenter()
{
	return centerInGame;
}

float GameObject::GetRadius()
{
	return radius;
}

int GameObject::GetPosX()
{
	return position.GetX();
}

int GameObject::GetPosY()
{
	return position.GetY();
}

Vector GameObject::GetPosition()
{
	return position;
}

void GameObject::SetState(bool estado)
{
	state = estado;
}

bool GameObject::GetState()
{
	return state;
}

void GameObject::SetPosition(Vector position)
{
	this->position = position;
	SetCenterInGame();
}