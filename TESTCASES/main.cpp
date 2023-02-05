/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:35 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/20 18:21:57 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/vector.hpp"
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
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator stdit;
	
	std::cout << "myvector size: " << myvector.size() << std::endl;
	std::cout << "stdvector size: " << stdvector.size() << std::endl;
	stdvector.begin();
	myvector.begin();
	std::cout << "myvector size: " << myvector.size() << std::endl;
	int *noo = NULL;
	std::cout << &noo[0] << std::endl;

}