/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:41:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/20 08:18:00 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <memory>
#include <list>
#include "../../CONTAINERS/map.hpp"

int main ()
{
	// std::list <std::pair<const int, int> > lst2;
	std::list <ft::pair<const int, int> > lst;
	// std::list <ft::pair<const int, int> > lst1;
	
    unsigned int lst_size = 10;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(ft::pair<const int, int>(i + 1, (i + 1) * 3));
    ft::map <int, int> mp(lst.begin(), lst.end());
    ft::map<int, int>::const_iterator it = mp.begin(), ite = mp.end();
    for (; it != ite; it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

	
    // ft::map<int, int>::iterator tryit = mp.begin();

	// tryit->second = 10000000;
	
	
	// for (unsigned int i = 0; i < lst_size; ++i)
        // lst1.push_back(ft::pair<const int, int>(i + 2, (i + 2) * 3));
    // ft::map <int, int> mapp(lst1.begin(), lst1.end());
    // ft::map <int, int> mapp;
	// mp.clear();
    // std::cout << "begin " << mp.begin()->first << std::endl;
    // std::cout << "size " << mp.size() << std::endl;
	// std::cout << "content of mp" << std::endl;

    // ft::map<int, int>::const_iterator it2[2];
	// it2[0] = mapp.begin(), it2[1] = mapp.end();
	
	// for (; it2[0] != it2[1]; it2[0]++)
    // {
    //     std::cout << it2[0]->first << " " << it2[0]->second << std::endl;
    // }
	// std::cout << "copying" << std::endl;
	// mapp = mp;
	// std::cout << "copy ended" << std::endl;
	// it2[0] = mapp.begin(), it2[1] = mapp.end();

	// std::cout << "content of mapp" << std::endl;
	// for (; it2[0] != it2[1]; it2[0]++)
    // {
    //     std::cout << it2[0]->first << " " << it2[0]->second << std::endl;
    // }
	// std::map<int, int> mapp1;
	
	// mapp.insert(ft::pair<const int, int>(1,1));
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