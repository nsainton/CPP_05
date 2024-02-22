#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__
# include <string>
# include <exception>
# include "AForm.h"
# define TOOHIGH "The grade required is too high. The sky is out of reach for you my G"
# define TOOLOW "The grade required is too low. Hitting rock bottom won't lead you nowhere"
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

class	AForm;

class	Bureaucrat{
	std::string		_name;
	unsigned int	_grade;

	public:
		Bureaucrat( const std::string & name, unsigned int grade );
		Bureaucrat( const Bureaucrat & );
		Bureaucrat& operator=( const Bureaucrat & );
		virtual ~Bureaucrat();
		class	GradeTooHighException : public std::exception {
			virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			virtual const char * what() const throw();
		};
		unsigned int		getGrade() const ;
		const std::string &	getName() const ;
		void				UpGrade();
		void				DownGrade();
		void				signForm( AForm & f ) const ;
		void				executeForm( AForm const & form ) const ;
};

std::ostream &	operator<<(std::ostream & os, const Bureaucrat & b);
#endif
