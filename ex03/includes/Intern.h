#ifndef __INTERN_H__
# define __INTERN_H__
# include "ShrubberyCreationForm.h"
# include "RobotomyRequestForm.h"
# include "PresidentialPardonForm.h"
# include <string>
class	Intern;

typedef AForm *(Intern::*formfunc)( const std::string & ) const ;

class	Intern{
	public:
		Intern();
		Intern( const Intern & );
		Intern& operator=( const Intern & );
		virtual ~Intern();
		AForm	*makeShrubbery( const std::string & target ) const ;
		AForm	*makeRobotomy( const std::string & target ) const ;
		AForm	*makePresidential( const std::string & target ) const ;
		AForm	*makeForm( const std::string & name, const std::string & target ) const ;
};
#endif
