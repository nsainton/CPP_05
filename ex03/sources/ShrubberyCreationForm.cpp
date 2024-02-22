#include "ShrubberyCreationForm.h"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target ) : \
AForm( "ShruberryCreation", 145, 137), _target(target){
	std::clog << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other ) : \
AForm( other ), _target( other._target ){
	std::clog << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm & other ){
	std::clog << "ShrubberyCreationForm Copy Assignment Operator Called" << std::endl;
	AForm::operator=(other);
	const_cast<std::string &>(this->_target) = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::clog << "ShrubberyCreationForm Destructor Called" << std::endl;
}

int	ShrubberyCreationForm::doAction() const{
	std::ofstream	write_stream;

	write_stream.open((this->_target + "_shrubbery").c_str());
	if (! write_stream.is_open())
		return (1);
	write_stream << TREE << std::endl;
	write_stream.close();
	return (0);
}
