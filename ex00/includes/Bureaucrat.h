#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__
# include <string>

class	Bureaucrat{
	const std::string	_name;
	unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat( const Bureaucrat & );
		Bureaucrat& operator=( const Bureaucrat & );
		virtual ~Bureaucrat();
};
#endif
