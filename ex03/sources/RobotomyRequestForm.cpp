#include "RobotomyRequestForm.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : _target(""){
	std::clog << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string & target ) : \
AForm( "RobotomyRequest", 72, 45 ), _target( target ){
	std::clog << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & other ) : \
AForm( other ), _target( other._target ){
	std::clog << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm & other ){
	std::clog << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::clog << "RobotomyRequestForm Destructor Called" << std::endl;
}

int	RobotomyRequestForm::doAction() const
{
	if (std::rand() % 2)
		std::cout << "Robotomy failed" << std::endl;
	else
		std::cout << this->_target << " has been robotomized" << std::endl;
	return (0);
}
