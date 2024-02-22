#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>
#include <cstdio>
#include <limits>
# define OPEN(x) std::cout << GRN << "-----------------------------Beginning of " << x << "--------------------\e[0m" << std::endl;
# define CLOSE(x) std::cout << RED << "-------------------------------End of " << x << "------------------------\e[0m" << std::endl;

static void	try_form( AForm * form, const Bureaucrat & b)
{
	std::cout << b << std::endl;
	std::cout << *form << std::endl;
	std::cout << "Sign Attempt" << std::endl;
	b.signForm(*form);
	try
	{
		std::cout << "Execution Attempt" << std::endl;
		form->execute(b);
		std::cout << "Form Executed" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Form Not Executed" << std::endl;
	}
}

static void	choose_form( AForm *form, const Bureaucrat & b, unsigned int i)
{
	static std::string	forms[3];
	unsigned int		j(0);

	forms[0] = "ShrubberyCreation";
	forms[1] = "RobotomyRequest";
	forms[2] = "PresidentialPardon";

	while (j < 3)
	{
		if (j == i)
		{
			OPEN(forms[j] + " testing");
			try_form(form, b);
			CLOSE(forms[j] + " testing");
			break ;
		}
		++j;
	}
}
static void	exec_forms( const Bureaucrat & b , const std::string & target )
{
	OPEN("Forms Creation");
	ShrubberyCreationForm	s(target);
	RobotomyRequestForm		r(target);
	PresidentialPardonForm	p(target);
	CLOSE("Forms Creation");
	AForm					*forms[3];

	*forms = &s;
	*(forms + 1) = &r;
	*(forms + 2) = &p;
	OPEN("Forms Testing");
	for (int i = 0; i < 3; ++i)
	{
		choose_form( *(forms + i), b, i );
	}
	CLOSE("Forms Testing");
	OPEN("Forms Destruction");
}

static void	check_form( const std::string & name, const unsigned int grade, const std::string & target)
{
	std::cout << "Creating Bureaucrat : " << RED << name << "\e[0m";
	std::cout << " with exec grade : " << GRN << grade << "\e[0m" << std::endl;
	try
	{
		OPEN("Bureaucrat Testing");
		Bureaucrat b(name, grade);
		CLOSE("Bureaucrat Testing");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b(name, grade);
	std::cout << b << std::endl;
	exec_forms(b, target);
	CLOSE("Forms Destruction");
}

static void	check_form_loop(){
	std::string		name;
	unsigned int	grade;
	std::string		target;

	while (1)
	{
		std::cout << "Please enter a name for your form. Enter EXIT to quit\n";
		std::getline(std::cin, name);
		if (std::cin.eof()){
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			continue ;
		}
		if (! name.compare("EXIT"))
			break ;
		std::cout << "Please enter a sign_grade for your form. Send EOF to quit\n";
		std::cin >> grade;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			break ;
		}
		std::cout << "Please enter a target for your form. Enter EXIT to quit\n";
		std::getline(std::cin, target);
		if (std::cin.eof()){
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			continue ;
		}
		if (! target.compare("EXIT"))
			break ;
		check_form( name, grade , target );
	}
}

int	main(void)
{
	check_form("Bill", 95, "Salut");
	check_form("Patrick", 10, "Bonjour");
	check_form_loop();
	return (0);
}
