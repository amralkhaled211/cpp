/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:15:48 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 16:16:49 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "Brain.hpp"

int main( void )
{
    /* const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i; */

    Dog basic;
    {
        Dog tmp = basic;
    }

    /* const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    } */

    return 0;
}