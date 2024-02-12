#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__
# include <string>
# include <exception>
# define TOOHIGH "The grade required is too high. The sky is out of reach for you my G"
# define TOOLOW "The grade required is too low. Hitting rock bottom won't lead you nowhere"

class	Bureaucrat{
	const std::string		_name;
	unsigned int			_grade;

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
};

#endif
