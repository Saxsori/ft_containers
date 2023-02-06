/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:40:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/17 09:08:40 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/Vector.hpp"
#include "../ITERATORS/iterator.hpp"
#include <vector>
#include "./printSize.hpp"
#include <list>
class IntWrapper {
public:
  IntWrapper(int value) : value_(value) {}
  int getValue() const { return value_; }
  ~IntWrapper(void){std::cout << "destructor " << value_ << std::endl;}

private:
  int value_;
};
#define TESTED_TYPE int


int main ()
{
	/*  
	 ! SILLY STD VECTOR 
	*/
	// std::allocator<int> moo;
	// IntWrapper noo(5);
	// ft::vector<IntWrapper> v;
	// v.push_back(noo);
	// std::cout << "v[0] " << v[0].getValue() << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0].getValue() << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0].getValue() << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,200);
	second.assign (3,100);
	
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	std::cout << "[0] of first: " << int (first[0]) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of second: " << int (second.capacity()) << '\n';
	std::cout << "[0] of second: " << int (second[0]) << '\n';

	first.assign (second.begin(), second.end());   // assigning from array.
	
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "capacity of first: " << int (first.capacity()) << '\n';
	std::cout << "[0] of first: " << int (first[0]) << '\n';
	std::cout << "[5] of first: " << int (first[5]) << '\n';

	std::cout << "VECTOR OF CLASSSES" << std::endl;
	IntWrapper boo(2);
	IntWrapper boo2(3);
	std::vector<IntWrapper> first1;
	std::vector<IntWrapper> second1;
	std::vector<IntWrapper> third1;
	IntWrapper array [] = {IntWrapper(5), IntWrapper(6), IntWrapper(7)};
	IntWrapper array2 [] = {IntWrapper(8), IntWrapper(9), IntWrapper(10), IntWrapper(11), IntWrapper(12), IntWrapper(13), IntWrapper(14)};
	first1.assign (array2, array2+6);   // assigning from array.
	second1.assign (3,boo2);
	
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	std::cout << "[0] of first: " << first1[0].getValue() << '\n';
	std::cout << "Size of second: " << int (second1.size()) << '\n';
	std::cout << "Size of second: " << int (second1.capacity()) << '\n';
	std::cout << "[0] of second: " <<  second1[0].getValue()  << '\n';

	std::cout << "REASSIGN FIRST1" << std::endl;
	first1.assign (array, array+2);   // assigning from array.
	// first1.assign (2,boo2);
	
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "capacity of first: " << int (first1.capacity()) << '\n';
	std::cout << "[0] of first: " << first1[0].getValue()  << '\n';
	// std::cout << "[5] of first: " << first1[5].getValue()  << '\n';
	std::cout << "END OF TEST" << std::endl;
	// second.assign (first.begin(), first.end());   // assigning from array.
	
	// std::cout << "Size of second: " << int (second.size()) << '\n';
	// std::cout << "Size of second: " << int (second.capacity()) << '\n';
	// std::cout << "[0] of second: " << int (second[0]) << '\n';

	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	std::vector<TESTED_TYPE> vct1(lst.begin(), lst.end());
	// ft::printSize(vct1);
	ft::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	
	// ft::printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	
	vct.assign(lst.begin(), lst.end());
	vct1.assign(lst.begin(), lst.end());
	
	// ft::printSize(vct);
	// ft::printSize(vct1);
	
	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	vct1.insert(vct1.end(), lst.rbegin(), lst.rend());
	
	ft::printSize(vct);
	ft::printSize(vct1);

		
	std::list<TESTED_TYPE> lst3;
	std::list<TESTED_TYPE>::iterator lst_it3;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<TESTED_TYPE> vct6(lst3.begin(), lst3.end());
	printSize(vct6);

	lst_it3 = lst3.begin();
	for (int i = 1; lst_it3 != lst3.end(); ++i)
		*lst_it3++ = i * 5;
	vct6.assign(lst3.begin(), lst3.end());
	ft::printSize(vct6);

	vct6.insert(vct6.end(), lst3.rbegin(), lst3.rend());
	ft::printSize(vct6);
	return (0);
}