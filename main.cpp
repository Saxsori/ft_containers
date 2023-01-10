/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:35 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/10 07:41:06 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Vector.hpp"
#include "./incl/iterator.hpp"
#include <vector>


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
	// std::allocator<int> moo;
	// std::vector<int> v(moo);
	// v.push_back(1);
	// std::cout << "v[0] " << v[0] << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0] << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;
	// v.pop_back();
	// std::cout << "v[0] " << v[0] << std::endl;
	// std::cout << "size " << v.size() << std::endl;
	// std::cout << "capacity " << v.capacity() << std::endl;

	// try 
	// {
	// 	v.at(3); // access an element outside the range of the vector
	// } 
	// catch (const std::out_of_range& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	ft::vector<int> boo;
	boo.push_back(1);
	boo.push_back(2);
	for(size_t i = 0; i < boo.size(); i++)
		std::cout << *(boo.begin() + i) << std::endl;

	
}