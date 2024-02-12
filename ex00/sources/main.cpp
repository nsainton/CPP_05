#include "Bureaucrat.h"
#include <iostream>
#include <cstdio>
#include <limits>

static void	check_bureaucrat( const std::string & name, const unsigned int grade)
{
	std::cout << "Trying to create bureaucrat : " << RED << name << "\e[0m";
	std::cout << " with grade : " << GRN << grade << "\e[0m" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	check_bureaucrat_loop(){
	std::string		name;
	unsigned int	grade;

	while (1)
	{
		std::cout << "Please enter a name for your bureaucrat. Enter EXIT to quit\n";
		std::getline(std::cin, name);
		if (std::cin.eof()){
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			continue ;
		}
		if (! name.compare("EXIT"))
			break ;
		std::cout << "Please enter a grade for your bureaucrat. Send EOF to quit\n";
		std::cin >> grade;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
		{
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
			std::cout << "\n";
			break ;
		}
		check_bureaucrat( name, grade );
	}
}

int	main(void)
{
	check_bureaucrat("Patrick", 151);
	check_bureaucrat("James", 0);
	Bureaucrat	b("Bonjour", 2);
	std::cout << b << std::endl;
	Bureaucrat	c("Salut", 123);
	std::cout << c << std::endl;
	Bureaucrat	d(c);
	std::cout << d << std::endl;
	Bureaucrat	e(c);
	e = b;
	std::cout << e << std::endl;
	int	i(0);
	while ( i < 2 )
	{
		std::cout << "This is the index : " << i << " and this is the bureaucrat : " << b << std::endl;
		try
		{
			b.UpGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		++i;
	}
	std::cout << "This is the index : " << i << " and this is the bureaucrat : " << b << std::endl;
	check_bureaucrat_loop();
	return (0);
}
