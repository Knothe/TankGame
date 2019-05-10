#include "Pause.h"
#include <iostream>


Pause::Pause()
{
}

void Pause::Input()
{
	std::cout << "Pause Input";
}

void Pause::Update()
{
	std::cout << "Pause Update";
}

void Pause::Draw()
{
	std::cout << "Pause Draw";
}

void Pause::Init(Platform * platform)
{
	std::cout << "Pause Init";
}

void Pause::Close()
{
	std::cout << "Pause close";
}

Pause::~Pause()
{
}
