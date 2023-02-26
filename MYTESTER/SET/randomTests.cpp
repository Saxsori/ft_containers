/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:59:22 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 18:51:56 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/set.hpp"
#include <iostream>
#include <set>

#ifndef NAMESPACE
#define NAMESPACE std
#endif


int main() {
    // Default constructor
    NAMESPACE::set<int> mySet;
    std::cout << "mySet is empty: " << mySet.empty() << std::endl;
    
    // Range constructor
    int myArray[] = { 1, 2, 3, 4, 5 };
	
    NAMESPACE::set<int> mySet2(myArray, myArray + (sizeof(myArray) / sizeof(myArray[0])));
    std::cout << "mySet2 size is: " << mySet2.size() << std::endl;

    // Copy constructor
    NAMESPACE::set<int> mySet3(mySet2);
    std::cout << "mySet3 size is: " << mySet3.size() << std::endl;

    // Assignment operator
    mySet = mySet2;
    std::cout << "mySet size after assignment: " << mySet.size() << std::endl;

    // Iterators
    NAMESPACE::set<int>::iterator it = mySet.begin();
    std::cout << "The first element of mySet is: " << *it << std::endl;
    NAMESPACE::set<int>::reverse_iterator rit = mySet.rbegin();
    std::cout << "The last element of mySet is: " << *rit << std::endl;
   
    std::cout << "The elements of mySet are: ";
    for (it = mySet.begin(); it != mySet.end(); it++)
        std::cout << "(" << *it << "," << *it << ") ";
		
    std::cout << std::endl;

    // Capacity
    std::cout << "mySet is empty: " << mySet.empty() << std::endl;
    std::cout << "mySet size is: " << mySet.size() << std::endl;
    std::cout << "mySet max size is: " << mySet.max_size() << std::endl;

    // Modifiers
   
   // insert
    NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret = mySet.insert(6);
    if (ret.second == false)
        std::cout << "Insertion failed, key 6 already exists." << std::endl;
    mySet.insert(7);
    mySet.insert(8);
    std::cout << "mySet size after insertions: " << mySet.size() << std::endl;
    
	it = mySet.find(6);
	mySet.erase(it);
    std::cout << "mySet size after erasing key 6: " << mySet.size() << std::endl;
    
	// swap
	std::swap(mySet, mySet2);
    std::cout << "Swapped mySet: ";
    for (NAMESPACE::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) 
        std::cout << "(" << *it << ") ";
    std::cout << std::endl;

    std::cout << "Swapped mySet2: ";
    for (NAMESPACE::set<int>::iterator it = mySet2.begin(); it != mySet2.end(); ++it)
        std::cout << "(" << *it << ") ";
    std::cout << std::endl;

	// Operations
	it = mySet.find(2);
	if (it != mySet.end())
	    std::cout << "Key 2 is present in mySet with value: " << *it << std::endl;
	else
	    std::cout << "Key 2 is not present in mySet" << std::endl;
	int count = mySet.count(3);
	std::cout << "Key 3 appears " << count << " times in mySet" << std::endl;
	std::cout << "Lower bound of key 4 in mySet is: " << *mySet.lower_bound(4) << std::endl;
	std::cout << "Upper bound of key 4 in mySet is: " << *mySet.upper_bound(4) << std::endl;
	NAMESPACE::pair<NAMESPACE::set<int>::iterator, NAMESPACE::set<int>::iterator> ret2;
	ret2 = mySet.equal_range(5);
	std::cout << "All values with key 5 in mySet are: ";
	for (it = ret2.first; it != ret2.second; it++)
	    std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}