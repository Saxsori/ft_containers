/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessors.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:44:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/11 15:47:32 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Vector.hpp"
#include "../incl/iterator.hpp"
#include <vector>

int main ()
{
	std::cout << "test accessors" << std::endl;
	std::allocator<int> moo;
	ft::vector <int> boo(moo);
	boo.push_back(1);
	boo.push_back(2);
	boo.push_back(3);
	std::cout << "size " << boo.size() << std::endl;
	std::cout << "capacity " << boo.capacity() << std::endl;
	std::cout << "boo[0] " << boo[0] << std::endl;
	std::cout << "boo[1] " << boo[1] << std::endl;
	std::cout << "boo[2] " << boo[2] << std::endl;
	try
	{
		boo[15];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
		boo.at(18); // access an element outside the range of the vector
	} 
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
}