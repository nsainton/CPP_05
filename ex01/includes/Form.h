#ifndef __FORM_H__
# define __FORM_H__
# include <string>
# include <exception>
# include "Bureaucrat.h"
# define FTOOLOW "Where you think you goin' with that fake ass grades. This is too low, get out!"
# define FTOOHIGH "Who the hell you think this is? A goddamn golden ticket? No such high grades here"
class	Bureaucrat;

class	Form{
	const std::string		_name;
	bool					_signed;
	const unsigned int		_sign_grade;
	const unsigned int		_exec_grade;
	Form();

	public:
		Form( const std::string & name, const unsigned int sign_grade, \
		const unsigned int exec_grade );
		Form( const Form & );
		Form& operator=( const Form & );
		virtual ~Form();
		class	GradeTooHighException : public std::exception{
			virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception{
			virtual const char * what() const throw();
		};
		const std::string & getName() const;
		bool				isSigned() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		int					beSigned( const Bureaucrat & b );
};

std::ostream &	operator<<(std::ostream & os, const Form & f);
#endif
