#include "TPApp.hpp"

#include <iostream>

void TP::TPApp::init()
{
	std::cout << "Calling TPApp init()" << std::endl;
}

void TP::TPApp::run()
{
	std::cout << "Calling TPApp run()" << std::endl;
	init();
	exit();
}

void TP::TPApp::exit()
{
	std::cout << "Calling TPApp exit()" << std::endl;
}
