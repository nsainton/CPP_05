#ifndef __SHRUBBERYCREATIONFORM_H__
# define __SHRUBBERYCREATIONFORM_H__
# include "AForm.h"
# define TREE ""\
"    0    \n"\
"   000   \n"\
"  00000  \n"\
" 0000000 \n"\
"   ::    \n"\
"   ::    \n"\
"   ::    \n"\
"__/||\\__\n"

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
