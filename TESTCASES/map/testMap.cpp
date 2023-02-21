/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:39:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/12 20:28:59 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <memory>
#include <list>
#include "../../CONTAINERS/map.hpp"
// typedef ft::pair<const int, foo<int>>
int main ()
{
	std::list <ft::pair<const int, int> > lst;
	unsigned int lst_size = 2;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::pair<const int, int>(i + 1, (i + 1) * 3));
	ft::map<int, int> mymap(lst.begin(), lst.end());
	
	// ft::map<int, int>::iterator it = mymap.begin();
	// mymap.end();
	// std::cout << "mymap contains:" << std::endl;
	// for (; it != mymap.end(); it++)
		// std::cout << it->first << " - " << it->second << std::endl;
	// it++;
	// std::cout << it->first << " - " << it->second << std::endl;
	// std::list <std::pair<const int, int> > lst1;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst1.push_back(std::pair<const int, int>(i + 1, (i + 1) * 3));
	// std::map<int, int> stdmap(lst1.begin(), lst1.end());
	
	// std::cout << "stdmap contains:" << std::endl;
	// std::map<int, int>::iterator sit = stdmap.begin();
	// for (; sit != stdmap.end(); sit++)
	// {
	// 	std::cout << sit->first << " - " << sit->second << std::endl;
	// 	std::cout << stdmap.end()->first << " - " << stdmap.end()->second << std::endl;
	// }
	
	// std::cout << stdmap.end()->first << std::endl;

	ft::map<char, float> mp;
	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	
	ft::map<char, float>::const_iterator itm = mp.begin();
	std::cout << itm->first << std::endl;
}