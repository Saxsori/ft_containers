/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:40:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/14 20:58:23 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/Vector.hpp"
#include <vector>

class IntWrapper {
public:
  IntWrapper(int value) : value_(value) {}
  int getValue() const { return value_; }
  ~IntWrapper(void){std::cout << "destructor " << value_ << std::endl;}

private:
  int value_;
};

/*
Test the reserve method after inserting, removing or swapping elements in the vector.
Test the reserve method with a capacity that's less than the current capacity of the vector.
Test the reserve method with a capacity that's greater than the current capacity of the vector.

*/

int main ()
{
	// // ft::vector<int> first;

	// // first.push_back(1);
	// // std::cout << "Size of first: " << int (first.size()) << '\n';
	// // std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	// // std::cout << "[0] of first: " << int (first[0]) << '\n';
	// // first.reserve(10);
	// // std::cout << "Size of first: " << int (first.size()) << '\n';
	// // std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	// // std::cout << "[0] of first: " << int (first[0]) << '\n';

	// // std::cout << "VECTOR OF CLASSSES" << std::endl;
	// // ft::vector<IntWrapper> first1;
	// // IntWrapper array [] = {IntWrapper(5), IntWrapper(6), IntWrapper(7)};
	
	// // first1.push_back(array[0]);
	// // std::cout << "Size of first: " << int (first1.size()) << '\n';
	// // std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	// // std::cout << "[0] of first: " << first1[0].getValue() << '\n';
	// // first1.reserve(10);
	// // std::cout << "Size of first: " << int (first1.size()) << '\n';
	// // std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	// // std::cout << "[0] of first: " << first1[0].getValue() << '\n';
	
	ft::vector<int> myVector;
    std::vector<int> stdVector;

    myVector.reserve(10);
    stdVector.reserve(10);
    if (myVector.capacity() == stdVector.capacity())
        std::cout << "Test case 1 passed" << std::endl;
    else
        std::cout << "Test case 1 failed" << std::endl;
	// Test the reserve method on a vector with a large initial capacity.
    myVector.reserve(5);
    stdVector.reserve(5);
	if (myVector.capacity() == stdVector.capacity())
        std::cout << "Test case 2 passed" << std::endl;
	else
        std::cout << "Test case 2 failed" << std::endl;

	myVector.reserve(0);
    stdVector.reserve(0);
    if (myVector.capacity() == stdVector.capacity())
        std::cout << "Test case 3 passed" << std::endl;
	else
        std::cout << "Test case 3 failed" << std::endl;


	ft::vector<int> myVector1;
    std::vector<int> stdVector1;
	// Test the reserve method on a vector with a small initial capacity.
    myVector1.reserve(5);
    stdVector1.reserve(5);
	if (myVector1.capacity() == stdVector1.capacity())
        std::cout << "Test case 4 passed" << std::endl;
	else
        std::cout << "Test case 4 failed" << std::endl;
	myVector1.reserve(10);
    stdVector1.reserve(10);
	if (myVector1.capacity() == stdVector1.capacity())
        std::cout << "Test case 4 passed" << std::endl;
	else
        std::cout << "Test case 4 failed" << std::endl;
	ft::vector<int> myVector2;
    std::vector<int> stdVector2;

	myVector2.resize(5, 10);
    stdVector2.resize(5, 10);
	if (myVector2.capacity() == stdVector2.capacity())
		std::cout << "Test case 5 passed" << std::endl;
	else
		std::cout << "Test case 5 failed" << std::endl;
	if (myVector2.size() == stdVector2.size())
		std::cout << "Test case 5 passed" << std::endl;
	else
		std::cout << "Test case 5 failed" << std::endl;
	std::cout << "size of mine " << myVector2.size() << std::endl;
	std::cout << "size of std " << stdVector2.size() << std::endl;
	std::cout << "size of mine " << myVector2.capacity() << std::endl;
	std::cout << "size of std " << stdVector2.capacity() << std::endl;
	
	ft::vector<int> myVector5;
	std::vector<int> stdVector5;
	stdVector5.clear();
	for (int i = 0; i < 10; ++i) 
	{
		myVector5.push_back(i);
		stdVector5.push_back(i);
	}
	myVector5.reserve(myVector5.size());
	stdVector.reserve(stdVector5.size());

	if (myVector5.capacity() == stdVector5.capacity())
		std::cout << "Test case 5 passed" << std::endl;
	else
		std::cout << "Test case 5 failed" << std::endl;
	ft::vector<int> myVector6;
	std::vector<int> stdVector6;
	for (int i = 0; i < 10; ++i) {
		myVector6.push_back(i);
		stdVector6.push_back(i);
	}
	myVector6.reserve(myVector6.size()-5);
	stdVector6.reserve(stdVector6.size()-5);
	if (myVector6.capacity() == stdVector6.capacity()) {
		std::cout << "Test case 6 passed" << std::endl;
	} else {
		std::cout << "Test case 6 failed" << std::endl;
	}
	ft::vector<int> myVector7;
	std::vector<int> stdVector7;
	for (int i = 0; i < 10; ++i) {
		myVector7.push_back(i);
		stdVector7.push_back(i);
	}
	myVector7.reserve(myVector7.size()+5);
	stdVector7.reserve(stdVector7.size()+5);
	if (myVector7.capacity() == stdVector7.capacity()) {
		std::cout << "Test case 7 passed" << std::endl;
	} else {
		std::cout << "Test case 7 failed" << std::endl;
	}

}