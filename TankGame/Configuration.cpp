#include "Configuration.h"
#include <iostream>


Configuration::Configuration()
{
}


void Configuration::Input()
{
	std::cout << "Configuration Input";
}

void Configuration::Update()
{
	std::cout << "Configuration Update";
}

void Configuration::Draw()
{
	std::cout << "Configuration Draw";
}

void Configuration::Init(Platform * platform)
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
