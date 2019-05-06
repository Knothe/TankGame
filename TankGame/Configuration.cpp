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

void Configuration::Init()
{
	std::cout << "Configuration Init";
}



Configuration::~Configuration()
{
}
