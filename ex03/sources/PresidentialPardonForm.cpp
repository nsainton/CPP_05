#include "PresidentialPardonForm.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( const std::string & target ) : \
AForm( "PresidentialPardon", 25, 5 ), _target( target ){
	std::clog << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other ) : \
AForm( other ), _target ( other._target ){
	std::clog << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm & other ){
	std::clog << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	AForm::operator=( other );
	const_cast<std::string &>(this->_target) = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::clog << "PresidentialPardonForm Destructor Called" << std::endl;
}

int	PresidentialPardonForm::doAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (00);
}
