/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:59:22 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 17:53:32 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/map.hpp"
#include <iostream>
#include <map>

#ifndef NAMESPACE
#define NAMESPACE std
#endif


int main() {
    // Default constructor
    NAMESPACE::map<int, std::string> myMap;
    std::cout << "myMap is empty: " << myMap.empty() << std::endl;
    
    // Range constructor
    NAMESPACE::pair<int, std::string> myPairArray[] = {
        NAMESPACE::make_pair(1, "One"),
        NAMESPACE::make_pair(2, "Two"),
        NAMESPACE::make_pair(3, "Three"),
        NAMESPACE::make_pair(4, "Four"),
        NAMESPACE::make_pair(5, "Five")
    };
	
    NAMESPACE::map<int, std::string> myMap2(myPairArray, myPairArray + (sizeof(myPairArray) / sizeof(myPairArray[0])));
    std::cout << "myMap2 size is: " << myMap2.size() << std::endl;

    // Copy constructor
    NAMESPACE::map<int, std::string> myMap3(myMap2);
    std::cout << "myMap3 size is: " << myMap3.size() << std::endl;

    // Assignment operator
    myMap = myMap2;
    std::cout << "myMap size after assignment: " << myMap.size() << std::endl;

    // Iterators
    NAMESPACE::map<int, std::string>::iterator it = myMap.begin();
    std::cout << "The first element of myMap is: " << it->second << std::endl;
    NAMESPACE::map<int, std::string>::reverse_iterator rit = myMap.rbegin();
    std::cout << "The last element of myMap is: " << rit->second << std::endl;
   
    std::cout << "The elements of myMap are: ";
    for (it = myMap.begin(); it != myMap.end(); it++)
        std::cout << "(" << it->first << "," << it->second << ") ";
		
    std::cout << std::endl;

    // Capacity
    std::cout << "myMap is empty: " << myMap.empty() << std::endl;
    std::cout << "myMap size is: " << myMap.size() << std::endl;
    std::cout << "myMap max size is: " << myMap.max_size() << std::endl;

    // Element access
    myMap[1] = "First";
    std::cout << "The value of key 1 is: " << myMap[1] << std::endl;

    // Modifiers
   
   // insert
    NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, bool> ret = myMap.insert(NAMESPACE::make_pair(6, "Six"));
    if (ret.second == false)
        std::cout << "Insertion failed, key 6 already exists." << std::endl;
    myMap.insert(NAMESPACE::make_pair(7, "Seven"));
    myMap.insert(NAMESPACE::make_pair(8, "Eight"));
    std::cout << "myMap size after insertions: " << myMap.size() << std::endl;
    
	it = myMap.find(6);
	myMap.erase(it);
    std::cout << "myMap size after erasing key 6: " << myMap.size() << std::endl;
    
	// swap
	std::swap(myMap, myMap2);
    std::cout << "Swapped myMap: ";
    for (NAMESPACE::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) 
        std::cout << "(" << it->first << "," << it->second << ") ";
    std::cout << std::endl;

    std::cout << "Swapped myMap2: ";
    for (NAMESPACE::map<int, std::string>::iterator it = myMap2.begin(); it != myMap2.end(); ++it)
        std::cout << "(" << it->first << "," << it->second << ") ";
    std::cout << std::endl;

	// Operations
	it = myMap.find(2);
	if (it != myMap.end())
	    std::cout << "Key 2 is present in myMap with value: " << it->second << std::endl;
	else
	    std::cout << "Key 2 is not present in myMap" << std::endl;
	int count = myMap.count(3);
	std::cout << "Key 3 appears " << count << " times in myMap" << std::endl;
	std::cout << "Lower bound of key 4 in myMap is: " << myMap.lower_bound(4)->second << std::endl;
	std::cout << "Upper bound of key 4 in myMap is: " << myMap.upper_bound(4)->second << std::endl;
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, NAMESPACE::map<int, std::string>::iterator> ret2;
	ret2 = myMap.equal_range(5);
	std::cout << "All values with key 5 in myMap are: ";
	for (it = ret2.first; it != ret2.second; it++)
	    std::cout << it->second << " ";
	std::cout << std::endl;

	return 0;
}