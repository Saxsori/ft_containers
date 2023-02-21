/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocating.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:11:33 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/10 14:59:54 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

int *array;
size_t	c;
size_t	s;
std::allocator<int> alloc;
class IntWrapper {
public:
  IntWrapper(int value) : value_(value) {}
  int getValue() const { return value_; }

private:
  int value_;
};

void	add(int val)
{
	if (s == c)
	{
		int *newArray = alloc.allocate((c == 0) ? 1 : (c * 2));
		std::copy(array, array + s, newArray);
		alloc.deallocate(array, ((c == 0) ? 1 : c));
		array = newArray;
		c = (c == 0) ? 1 : (c * 2);		
	}
	alloc.construct(array + s, val);
	s++;
}

int main ()
{
	// IntWrapper w = 5;
	// std::cout << w.getValue() << std::endl; 
	// array = NULL;
	// s = 0;
	// c = 0;
	// add(1);
	// add(2);
	// std::cout << "elements" << std::endl;
	// for (size_t i = 0; i < s; i++)
	// 	std::cout << array[i] << std::endl;
	// std::cout << "size " << s << std::endl;
	// std::cout << "capacity " << c << std::endl;
	// alloc.deallocate(array, c);
	// std::vector <int> n;
	// n.push_back(1);
	// n.push_back(2);
	// 	std::cout << "elements" << std::endl;
	// for (size_t i = 0; i < n.size(); i++)
	// 	std::cout << n[i] << std::endl;
	// std::cout << "size " << s << std::endl;
	// std::cout << "capacity " << c << std::endl;
	
}