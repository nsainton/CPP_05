#include "Bureaucrat.h"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat( const std::string & name, const unsigned int grade){
	this->_name = name;
	this->_grade = grade;
	std::clog << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & other ){
	std::clog << "Bureaucrat Copy Constructor Called" << std::endl;
	this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat & other ){
	std::clog << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	this->_name = other._name;
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::clog << "Bureaucrat Destructor Called" << std::endl;
}
