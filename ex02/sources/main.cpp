#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>
#include <cstdio>
#include <limits>

static void	exec_forms( const Bureaucrat & b , const std::string & target )
{
	ShrubberyCreationForm	s(target);
	RobotomyRequestForm		r(target);
	PresidentialPardonForm	p(target);
	AForm					*forms[3];

	*forms = &s;
	*(forms + 1) = &r;
	*(forms + 2) = &p;
	for (int i = 0; i < 3; ++i)
	{
		try
		{
			(*(forms + i))->beSigned(b);
			std::cout << **(forms + i) << std::endl;
			(*(forms + i))->execute(b);
		}
		catch (std::exception & e)
		{
			std::cout << e.what();
		}
	}
}

static void	check_form( const std::string & name, const unsigned int grade, const std::string & target)
{
	std::cout << "Creating Bureaucrat : " << RED << name << "\e[0m";
	std::cout << " with exec grade : " << GRN << grade << "\e[0m" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
		exec_forms(b, target);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
static void	check_form_loop(){
	std::string		name;
	unsigned int	sign_grade;
	unsigned int 	exec_grade;

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
		std::cin >> sign_grade;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			break ;
		}
		std::cout << "Please enter a exec_grade for your form. Send EOF to quit\n";
		std::cin >> exec_grade;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			break ;
		}
		check_form( name, sign_grade , exec_grade );
	}
}
*/

int	main(void)
{
	check_form("Bill", 4, "Salut");
	/*
	check_form("Groceries list", 120, 168);
	check_form("Groceries list", 168, 120);
	check_form("Chores", 0, 1);
	check_form("Chores", 1, 0);
	AForm	b("Bonjour", 2, 4);
	std::cout << b << std::endl;
	AForm	c("Salut", 1, 2);
	std::cout << c << std::endl;
	AForm	d(c);
	std::cout << d << std::endl;
	AForm	e(c);
	e = b;
	std::cout << e << std::endl;
	*/
	/*
	int	i(0);
	while ( i < 2 )
	{
		std::cout << "This is the index : " << i << "\nthis is the bureaucrat : " << b << std::endl;
		try
		{
			std::cout << "Trying to upgrade bureaucrat : " << RED << b.getName() << "\e[0m" << std::endl;
			b.UpGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		++i;
	}
	std::cout << "This is the index : " << i << " and this is the bureaucrat : " << b << std::endl;
	*/
	//check_form_loop();
	return (0);
}
