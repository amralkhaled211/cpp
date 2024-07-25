#include "Base.hpp"

Base::~Base() {}

A::A() {}

B::B() {}

C::C() {}

Base *generate(void)
{
	int	i;

	srand(time(NULL));
	i = rand() % 3;
	std::cout << "Random number: " << i << std::endl;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void    identify( Base& p )
{
    try
	{
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    }
	catch(const std::exception& e)
	{
		
		std::cerr << "A :" << e.what() << std::endl;
	}
    try
	{
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    }
	catch( const std::exception& e )
	{
		
		std::cerr << "B :" << e.what() << std::endl;
	}
    try
	{
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    }
	catch( const std::exception& e )
	{
		std::cerr << "C :" << e.what() << std::endl;
	}
}
