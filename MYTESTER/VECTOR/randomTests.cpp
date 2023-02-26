/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:59:22 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 19:04:18 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/vector.hpp"
#include <iostream>
#include <vector>

#ifndef NAMESPACE
#define NAMESPACE std
#endif


int main()
{
    // Constructor
    NAMESPACE::vector<int> myVector;

    // push_back
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // operator[]
    std::cout << "myVector[0]: " << myVector[0] << std::endl;

    // at
    std::cout << "myVector.at(1): " << myVector.at(1) << std::endl;

    // front
    std::cout << "myVector.front(): " << myVector.front() << std::endl;

    // back
    std::cout << "myVector.back(): " << myVector.back() << std::endl;

    // size
    std::cout << "myVector.size(): " << myVector.size() << std::endl;

    // max_size
    std::cout << "myVector.max_size(): " << myVector.max_size() << std::endl;

    // capacity
    std::cout << "myVector.capacity(): " << myVector.capacity() << std::endl;

    // empty
    std::cout << "myVector.empty(): " << myVector.empty() << std::endl;

    // reserve
    myVector.reserve(10);
    std::cout << "myVector.capacity() after reserve: " << myVector.capacity() << std::endl;

    // resize
    myVector.resize(5);
    std::cout << "myVector.size() after resize: " << myVector.size() << std::endl;

    // assign
    NAMESPACE::vector<int> myOtherVector;
    myOtherVector.assign(3, 42);
    std::cout << "myOtherVector[0]: " << myOtherVector[0] << std::endl;

    // insert
    NAMESPACE::vector<int>::iterator it = myVector.begin() + 1;
    myVector.insert(it, 4);
    std::cout << "myVector[1]: " << myVector[1] << std::endl;

    // erase
    it = myVector.begin() + 2;
    myVector.erase(it);
    std::cout << "myVector[2]: " << myVector[2] << std::endl;

    // swap
    NAMESPACE::vector<int> myThirdVector;
    myThirdVector.push_back(5);
    myThirdVector.push_back(6);
    myVector.swap(myThirdVector);
    std::cout << "myVector[0]: " << myVector[0] << std::endl;

    // clear
    myVector.clear();
    std::cout << "myVector.size() after clear: " << myVector.size() << std::endl;

    return 0;
}