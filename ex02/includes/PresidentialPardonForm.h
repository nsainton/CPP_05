#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__
# include "AForm.h"
# include <string>

class	PresidentialPardonForm : public AForm{
	std::string	_target;
	PresidentialPardonForm();

	public:
		PresidentialPardonForm( const std::string & target );
		PresidentialPardonForm( const PresidentialPardonForm & );
		PresidentialPardonForm& operator=( const PresidentialPardonForm & );
		virtual ~PresidentialPardonForm();
		virtual int	doAction() const;
};
#endif
