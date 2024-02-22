#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__
# include "AForm.h"
# include <string>

class	PresidentialPardonForm : public AForm{
	const std::string & _target;
	public:
		PresidentialPardonForm( const std::string & target );
		PresidentialPardonForm( const PresidentialPardonForm & );
		PresidentialPardonForm& operator=( const PresidentialPardonForm & );
		virtual ~PresidentialPardonForm();
		virtual int	doAction() const;
};
#endif
