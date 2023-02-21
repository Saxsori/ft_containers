/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:57:06 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/19 03:02:50 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/map.hpp"
#include <iostream>
#include <map>
#include <list>

int main ()
{
	std::list <ft::pair<const int, int> > lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::pair<const int, int>(i + 1, (i + 1) * 3));
	ft::map <int, int> mp(lst.begin(), lst.end());
	if (mp.upper_bound(10) == mp.end())
		std::cout << "END" << std::endl;
	else
		std::cout << mp.upper_bound(10)->first << std::endl;
	
}