/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:35 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/11 11:40:56 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Vector.hpp"
#include "./incl/iterator.hpp"
#include <vector>

std::allocator<int> alloc;
class IntWrapper {
public:
  IntWrapper(int value) : value_(value) {}
  int getValue() const { return value_; }
  ~IntWrapper(void){std::cout << "destructor" << std::endl;}

private:
  int value_;
};

int main ()
{
	// std::allocator<int> moo;
	// ft::vector <int> boo(moo);
	// boo.push_back(1);
	// boo.push_back(2);
	// boo.push_back(3);
	// std::cout << "size " << boo.size() << std::endl;
	// std::cout << "capacity " << boo.capacity() << std::endl;
	// std::cout << "boo[0] " << boo[0] << std::endl;
	// std::cout << "boo[1] " << boo[1] << std::endl;
	// std::cout << "boo[2] " << boo[2] << std::endl;
	// v.push_back(1);
	// try
	// {
	// 	boo[15];
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	/*  
	 ! SILLY STD VECTOR 
	*/
	std::allocator<int> moo;
	IntWrapper noo(5);
	std::vector<IntWrapper> v;
	v.push_back(noo);
	std::cout << "v[0] " << v[0].getValue() << std::endl;
	std::cout << "size " << v.size() << std::endl;
	std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0].getValue() << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0].getValue() << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;

	std::cout << (*(v.begin())).getValue() << std::endl;
	ft::vector<IntWrapper> boo(v.begin(), v.end(), moo);
	std::vector<IntWrapper> boo1(v.begin(), v.end(), moo);
	
	// try 
	// {
	// 	v.at(3); // access an element outside the range of the vector
	// } 
	// catch (const std::out_of_range& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	// ft::vector<int> boo;
	// boo.push_back(1);
	// boo.push_back(2);
	
	// for(size_t i = 0; i < boo.size(); i++)
	// 	std::cout << *(boo.begin() + i) << std::endl;

	
}