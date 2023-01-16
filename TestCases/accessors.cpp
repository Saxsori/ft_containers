/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessors.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:44:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/16 16:49:15 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/Vector.hpp"
#include "../ITERATORS/random_access_iterator.hpp"
#include <iostream>
#include <vector>
#include "./printSize.hpp"

int main ()
{
	// std::cout << "test accessors" << std::endl;
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
	// try
	// {
	// 	boo[15];
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try 
	// {
	// 	boo.at(18); // access an element outside the range of the vector
	// } 
	// catch (const std::out_of_range& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	ft::vector<TESTED_TYPE> vct(7);
	// ft::vector<TESTED_TYPE> vct(7);
	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	ft::printSize(vct);

	std::cout << "lol" << std::endl;
	ft::vector<TESTED_TYPE> const vct_c(vct);

	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	for (unsigned long int i = 0; i < vct_c.size(); ++i)
		std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
	try {
		std::cout << vct_c.at(10) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	ft::printSize(vct_c);
	return (0);
	
}