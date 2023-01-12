/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:40:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/11 20:30:08 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Vector.hpp"
#include "../incl/iterator.hpp"
#include <vector>

class IntWrapper {
public:
  IntWrapper(int value) : value_(value) {}
  int getValue() const { return value_; }
  ~IntWrapper(void){std::cout << "destructor " << value_ << std::endl;}

private:
  int value_;
};

int main ()
{
	ft::vector<int> first;

	first.push_back(1);
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	std::cout << "[0] of first: " << int (first[0]) << '\n';
	first.reserve(10);
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	std::cout << "[0] of first: " << int (first[0]) << '\n';

	std::cout << "VECTOR OF CLASSSES" << std::endl;
	ft::vector<IntWrapper> first1;
	IntWrapper array [] = {IntWrapper(5), IntWrapper(6), IntWrapper(7)};
	
	first1.push_back(array[0]);
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	std::cout << "[0] of first: " << first1[0].getValue() << '\n';
	first1.reserve(10);
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	std::cout << "[0] of first: " << first1[0].getValue() << '\n';

}