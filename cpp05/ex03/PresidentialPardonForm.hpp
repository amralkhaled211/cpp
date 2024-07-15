#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP


#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};


#endif