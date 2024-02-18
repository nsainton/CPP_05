#include "AForm.h"
#include <iostream>

AForm::AForm( const std::string & name, const unsigned int sign_grade, \
const unsigned int exec_grade ) : _name(name), _signed(false), _sign_grade(sign_grade), \
_exec_grade(exec_grade){
	std::clog << "AForm Default Constructor Called" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw (GradeTooHighException());
	if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooLowException());
}

AForm::AForm( const AForm & other ) : _name(other._name), _signed(other._signed), \
_sign_grade(other._sign_grade), _exec_grade(other._exec_grade){
	std::clog << "AForm Copy Constructor Called" << std::endl;
}

AForm&	AForm::operator=( const AForm & other ){
	std::clog << "AForm Copy Assignment Operator Called" << std::endl;
	_signed = other._signed;
	const_cast<unsigned int &>(this->_sign_grade) = other._sign_grade;
	const_cast<unsigned int &>(this->_exec_grade) = other._exec_grade;
	const_cast<std::string &>(this->_name) = other._name;
	return (*this);
}

AForm::~AForm(){
	std::clog << "AForm Destructor Called" << std::endl;
}

const char *	AForm::GradeTooLowException::what() const throw(){
	return (FTOOLOW);
}

const char *	AForm::GradeTooHighException::what() const throw(){
	return (FTOOHIGH);
}

const std::string &	AForm::getName() const{
	return (this->_name);
}

bool			AForm::isSigned() const{
	return (this->_signed);
}

unsigned int	AForm::getSignGrade() const{
	return (this->_sign_grade);
}

unsigned int	AForm::getExecGrade() const{
	return (this->_exec_grade);
}

int				AForm::beSigned( const Bureaucrat & b )
{
	if (this->_signed)
		return (1);
	if (b.getGrade() > this->_sign_grade)
		throw (GradeTooLowException());
	this->_signed = true;
	return (0);
}

std::ostream &	operator<<(std::ostream & os, const AForm & f){
	os << "AForm : " << f.getName();
	os << "\nSigned ? " << std::boolalpha << f.isSigned();
	os << std::noboolalpha;
	os << "\nSign Grade : " << f.getSignGrade();
	os << "\nExec Grade : " << f.getExecGrade();
	return (os);
}
