#ifndef AFROM_HPP
#define AFROM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class	AForm
{

	private:
		const  std::string	name;
		bool				_signed;
		int const			gradeToSign;
		int const			gradeToExecute;

	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		AForm &operator=(AForm const &src);
		virtual ~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif