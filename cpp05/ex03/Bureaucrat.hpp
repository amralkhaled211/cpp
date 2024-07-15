#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;


class Bureaucrat
{
	private:
		std::string		name;
		int		grade;
	public:
		Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();


		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form) const;
		


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
#endif