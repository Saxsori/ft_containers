/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:35 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/09 07:40:01 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Vector.hpp"

int main ()
{
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
	
}