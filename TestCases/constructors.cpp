/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:33 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/11 15:46:55 by aaljaber         ###   ########.fr       */
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

	std::allocator<int> moo;
	IntWrapper noo(5);
	std::vector<IntWrapper> v;
	v.push_back(noo);
	std::cout << (*(v.begin())).getValue() << std::endl;
	ft::vector<IntWrapper> boo(v.begin(), v.end(), moo);
	std::vector<IntWrapper> boo1(v.begin(), v.end(), moo);
	
	
}