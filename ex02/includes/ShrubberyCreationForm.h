#ifndef __SHRUBBERYCREATIONFORM_H__
# define __SHRUBBERYCREATIONFORM_H__
# include "AForm.h"
# define TREE ""\
"    0    "\
"   000   "\
"  00000  "\
" 0000000 "\
"   ::    "\
"   ::    "\
"   ::    "\
"__/||\\__"

class	ShrubberyCreationForm : public AForm{
	const std::string	_target;

	public:
		ShrubberyCreationForm( const std::string & target );
		ShrubberyCreationForm( const ShrubberyCreationForm & );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm & );
		virtual ~ShrubberyCreationForm();
		virtual int	doAction() const;
};

#endif
