#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() const {
	std::cout << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void	Harl::info() const {
	std::cout << "[INFO] - I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void	Harl::warning() const {
	std::cout << "[WARNING] - I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error() const {
	std::cout << "[ERROR] - This is unacceptable ! I want to speak to the manager now.\n";
}

void	Harl::complain(str level) {
	void	(Harl::*funcPtr)(void) const = NULL;
	void	(Harl::*arrayPtr[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	str		arrayLevel[4] = {"debug", "info", "warning", "error"};
	int		i = -1;

	while (++i < 4) {
		if (arrayLevel[i] == level)
			funcPtr = arrayPtr[i];
	}
	if (!funcPtr) {
		std::cout << "Invalid Harl's complain !" << std::endl; return;
	}
	(this->*funcPtr)();
}