#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::clog << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string & name, const unsigned int grade ) : _name(name), _grade(grade){
	std::clog << "Bureaucrat Constructor Called" << std::endl;
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

void			Bureaucrat::UpGrade(){
	if (this->_grade == 1)
		throw (GradeTooHighException());
	--this->_grade;
}

void			Bureaucrat::DownGrade(){
	if (this->_grade == 150)
		throw (GradeTooLowException());
	++this->_grade;
}

void			Bureaucrat::signForm( Form & f ) const {
	try
	{
		if (f.beSigned(*this))
		{
			std::cout << this->_name << " couldn't sign form ";
			std::cout << f.getName() << " because " << "it is already signed";
			std::cout << std::endl;
		}
		else
			std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << this->_name << " couldn't sign form ";
		std::cout << f.getName() << " because " << "his grade is too low";
		std::cout << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & os, const Bureaucrat & b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
