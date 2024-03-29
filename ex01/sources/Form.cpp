#include "Form.h"
#include <iostream>

Form::Form() : _name(""), _signed(false), _sign_grade(1), _exec_grade(1) {
	std::clog << "Form Default Constructor Called" << std::endl;
}

Form::Form( const std::string & name, const unsigned int sign_grade, \
const unsigned int exec_grade ) : _name(name), _signed(false), _sign_grade(sign_grade), \
_exec_grade(exec_grade){
	std::clog << "Form Constructor Called" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw (GradeTooHighException());
	if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooLowException());
}

Form::Form( const Form & other ) : _name(other._name), _signed(other._signed), \
_sign_grade(other._sign_grade), _exec_grade(other._exec_grade){
	std::clog << "Form Copy Constructor Called" << std::endl;
}

Form&	Form::operator=( const Form & other ){
	std::clog << "Form Copy Assignment Operator Called" << std::endl;
	_signed = other._signed;
	return (*this);
}

Form::~Form(){
	std::clog << "Form Destructor Called" << std::endl;
}

const char *	Form::GradeTooLowException::what() const throw(){
	return (FTOOLOW);
}

const char *	Form::GradeTooHighException::what() const throw(){
	return (FTOOHIGH);
}

const std::string &	Form::getName() const{
	return (this->_name);
}

bool			Form::isSigned() const{
	return (this->_signed);
}

unsigned int	Form::getSignGrade() const{
	return (this->_sign_grade);
}

unsigned int	Form::getExecGrade() const{
	return (this->_exec_grade);
}

int				Form::beSigned( const Bureaucrat & b )
{
	if (this->_signed)
		return (1);
	if (b.getGrade() > this->_sign_grade)
		throw (GradeTooLowException());
	this->_signed = true;
	return (0);
}

std::ostream &	operator<<(std::ostream & os, const Form & f){
	os << "Form : " << f.getName();
	os << "\nSigned ? " << std::boolalpha << f.isSigned();
	os << std::noboolalpha;
	os << "\nSign Grade : " << f.getSignGrade();
	os << "\nExec Grade : " << f.getExecGrade();
	return (os);
}
