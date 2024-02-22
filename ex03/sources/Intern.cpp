#include "Intern.h"
#include <iostream>

Intern::Intern(){
	std::clog << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern( const Intern & other ){
	std::clog << "Intern Copy Constructor Called" << std::endl;
	(void)other;
}

Intern&	Intern::operator=( const Intern & other ){
	std::clog << "Intern Copy Assignment Operator Called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(){
	std::clog << "Intern Destructor Called" << std::endl;
}

AForm	*Intern::makeShrubbery( const std::string & target ) const {
	return (new ShrubberyCreationForm( target ));
}

AForm	*Intern::makeRobotomy( const std::string & target ) const {
	return (new RobotomyRequestForm( target ));
}

AForm	*Intern::makePresidential( const std::string & target ) const {
	return (new PresidentialPardonForm( target ));
}

AForm	*Intern::makeForm( const std::string & name, const std::string & target ) const {
	formfunc			forms[3];
	const std::string	names[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	int					i(0);

	*forms = &Intern::makeShrubbery;
	*(forms + 1) = &Intern::makeRobotomy;
	*(forms + 2) = &Intern::makePresidential;
	while (i < 3)
	{
		if (! name.compare(*(names + i)))
		{
			std::cout << "Intern creates " << *(names + i) << std::endl;
			return ((this->*(*(forms + i)))(target));
		}
		++i;
	}
	std::cout << "Intern can't create " << name << " because it doesn't exist" << std::endl;
	return (NULL);
}
