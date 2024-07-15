#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target , 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }
	srand(time(0)); // Seed the random number generator
    std::cout << "*drilling noises*" << std::endl;
    int randomValue = rand(); // Store the result of rand() in a variable
	//std::cout << "Random value: " << randomValue << std::endl; // Print the random value
    if (randomValue % 2)
        std::cout << this->getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->getName() << " robotomization failed." << std::endl;
}