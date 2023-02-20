/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:41:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/20 03:27:04 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <memory>
#include <list>
#include "../../CONTAINERS/map.hpp"

int main ()
{
	ft::map<int, int> mapp;
	// std::map<int, int> mapp1;
	
	mapp.insert(ft::pair<const int, int>(1,1));
	// mapp.insert(ft::pair<const int, int>(4,1));
	// mapp.insert(ft::pair<const int, int>(5,1));
	
	// mapp1.insert(std::pair<const int, int>(4,1));
	// mapp1.insert(std::pair<const int, int>(5,1));
	
	// mapp[4] = 2;
	// mapp1[4] = 2;
	
	// mapp[5] = 6;
	// mapp1[5] = 5;

	
	// ft::map<int, int>::iterator ret = mapp.find(4);
	// ft::map<int, int>::iterator ret = mapp.find(1);
	// std::map<int, int>::iterator ret1 = mapp1.find(4);

	// std::cout << ret1->first << " " << ret1->second << std::endl;
	// std::cout << ret->first << " " << ret->second << std::endl;
	
	// ft::map<int, int> mapp2;

	// mapp2 = mapp;
	
	return 0;
}