#include "Bureaucrat.h"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat( const std::string & name, const unsigned int grade ) : _name(name), _grade(grade){
	std::clog << "Bureaucrat Default Constructor Called" << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat( const Bureaucrat & other ) : _name(other._name), _grade(other._grade){
	std::clog << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat & other ){
	std::clog << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	const_cast<std::string &>(this->_name) = other._name;
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::clog << "Bureaucrat Destructor Called" << std::endl;
}

const char *	Bureaucrat::GradeTooHighException::what() const throw(){
	return TOOHIGH;
}

const char *	Bureaucrat::GradeTooLowException::what() const throw(){
	return TOOLOW;
}

unsigned int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

const std::string &	Bureaucrat::getName() const {
	return (this->_name);
}
