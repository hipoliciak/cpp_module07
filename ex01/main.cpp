/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:44:35 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/03/13 13:56:25 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "iter.hpp"

void print_int(int &i)
{
    std::cout << i << " ";
}

void add_one_int(int &i)
{
    i++;
}

void remove_one_int(int &i)
{
    i--;
}

void print_float(float &f)
{
    std::cout << f << " ";
}

void print_string(std::string &s)
{
    std::cout << s << " ";
}

int main(void)
{
    int intArray[5] = {1, 2, 3, 4, 5};
    float floatArray[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::string stringArray[5] = {"one", "two", "three", "four", "five"};

    std::cout << "intArray: ";
    iter(intArray, 5, print_int);
    std::cout << std::endl;

    std::cout << "intArray + 1: ";
    iter(intArray, 5, add_one_int);
    iter(intArray, 5, print_int);
    std::cout << std::endl;

    std::cout << "intArray - 1: ";
    iter(intArray, 5, remove_one_int);
    iter(intArray, 5, print_int);
    std::cout << std::endl;

    std::cout << "floatArray: ";
    iter(floatArray, 5, print_float);
    std::cout << std::endl;

    std::cout << "stringArray: ";
    iter(stringArray, 5, print_string);
    std::cout << std::endl;

    return 0;
}
