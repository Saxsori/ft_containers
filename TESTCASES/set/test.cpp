/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:32 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 18:39:35 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/set.hpp"
// #include <set>
#include <iostream>

int main ()
{
	ft::set <int> sett;
	
	sett.insert(1);
	std::set<int>::iterator it = sett.begin();
	std::set<int>::iterator it1 = sett.end();

	for (; it != it1; it++)
	{
		std::cout << *it << std::endl;
	}
	
		

	return 0;
}