#include "Configuration.h"
#include <iostream>


Configuration::Configuration()
{
}


bool Configuration::Input(int keyInput)
{
	std::cout << "Configuration Input";
	return false;
}

void Configuration::Update()
{
	std::cout << "Configuration Update";
}

void Configuration::Draw()
{
	std::cout << "Configuration Draw";
}

void Configuration::Init(Platform * platform, StateManager *stateManager)
{
	std::cout << "Configuration Init";
}

void Configuration::Close()
{
	std::cout << "Configuration close";
}

Configuration::~Configuration()
{
}
