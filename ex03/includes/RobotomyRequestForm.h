#ifndef __ROBOTOMYREQUESTFORM_H__
# define __ROBOTOMYREQUESTFORM_H__
#include <string>
#include "AForm.h"

class	RobotomyRequestForm : public AForm{
	std::string	_target;

	public:
		RobotomyRequestForm( const std::string & target );
		RobotomyRequestForm( const RobotomyRequestForm & );
		RobotomyRequestForm& operator=( const RobotomyRequestForm & );
		virtual ~RobotomyRequestForm();
		virtual int	doAction() const;
};
#endif
