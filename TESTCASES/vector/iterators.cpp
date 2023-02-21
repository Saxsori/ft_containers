/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:35 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/11 15:48:37 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Vector.hpp"
#include "./incl/iterator.hpp"
#include <vector>

int main ()
{
	ft::vector<int> boo;
	boo.push_back(1);
	boo.push_back(2);
	
	for(size_t i = 0; i < boo.size(); i++)
		std::cout << *(boo.begin() + i) << std::endl;	
}