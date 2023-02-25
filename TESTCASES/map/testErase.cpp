/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testErase.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:41:57 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 12:51:14 by aaljaber         ###   ########.fr       */
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
	std::list<ft::pair<const int, std::string> > lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::pair<const int, std::string>(i, std::string((lst_size - i), i + 65)));
	
	ft::map<int, std::string> mymap(lst.begin(), lst.end());
	// std::cout << "lst begin " << lst.begin()->first << std::endl;

	// ft::map<int, std::string>::const_iterator it, ite;
	// it = mp.begin();
	// ite = mp.end();
	// std::cout << "begin " << mp.begin()->first << std::endl;
	// std::cout << "size " << mp.size() << std::endl;
	// for (; it != ite; it++)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }

	// std::list <ft::pair<const int, int> > lst;
	// unsigned int lst_size = 10;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(ft::pair<const int, int>(i + 1, (i + 1) * 3));
	// ft::map<int, int> mymap(lst.begin(), lst.end());
	
	// ft::map<int, int> mymap;
	// std::list <std::pair<const int, int> > lst1;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst1.push_back(std::pair<const int, int>(i + 1, (i + 1) * 3));
	// std::map<int, int> mymap1;
	
	// std::map<int, int> mymap1(lst1.begin(), lst1.end());

	// mymap1.erase(mymap1.begin(), ++mymap1.begin());
	// for (std::map<int, int>::iterator it = mymap1.begin(); it != mymap1.end(); it++)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }

	// mymap.insert(mymap.begin(), ft::pair<const int, int>(100, 2));
	// ft::pair<ft::map<int, int>::iterator , bool> tmp;
	// std::pair<std::map<int, int>::iterator , bool> tmp1;

	// mymap.insert(ft::pair<const int, int>(40, 2));
	// mymap1.insert(std::pair<const int, int>(40, 2));
	
	// mymap.insert(ft::pair<const int, int>(50, 3));
	// mymap1.insert(std::pair<const int, int>(50, 3));
	
	// mymap.insert(ft::pair<const int, int>(30, 30000));
	// mymap1.insert(std::pair<const int, int>(30, 30000));
	
	// mymap.insert(ft::pair<const int, int>(45, 99));
	// mymap1.insert(std::pair<const int, int>(45, 99));

	// mymap.insert(ft::pair<const int, int>(25, 90009));
	// mymap1.insert(std::pair<const int, int>(25, 90009));

	// mymap.insert(ft::pair<const int, int>(35, 99));
	// mymap1.insert(std::pair<const int, int>(35, 99));

	// mymap.insert(++mymap.begin(), ft::pair<const int, int>(55, 33883838));
	// std::cout << mymap1.insert(++mymap1.begin(), std::pair<const int, int>(55, 33883838))->first << std::endl;

	// std::cout << "test pos of ins " << (++mymap1.begin())->first << std::endl;
	// std::cout << "test pos of ins " << (++mymap1.begin())->first << std::endl;

	// std::cout << tmp.first->first << " " << tmp.first->second << std::endl;
	// std::cout << tmp1.first->first << " " << tmp1.first->second << std::endl;
	
	// ft::pair<ft::map<int, int>::iterator , bool> tmp2;
	// std::pair<std::map<int, int>::iterator , bool> tmp3;
	

	// std::cout << tmp2.first->first << " " << tmp2.first->second << std::endl;
	// std::cout << tmp3.first->first << " " << tmp3.first->second << std::endl;

	// mymap.insert(ft::pair<const int, int>(100, 2));
	mymap.erase(++mymap.begin());

	mymap.erase(mymap.begin());
	mymap.erase(--mymap.end());
	mymap.erase(mymap.begin(), ++(++(++mymap.begin())));
	
	mymap.erase(--(--(--mymap.end())), --mymap.end());
	
	std::cout << "gonnnnaaa seg" << std::endl;
	
	mymap[10] = "Hello";
	mymap[11] = "Hi there";
	ft::map<int, std::string>::const_iterator it1, ite1;
	it1 = mymap.begin();
	ite1 = mymap.end();
	for (; it1 != ite1; it1++)
	{
		std::cout << it1->first << " " << it1->second << std::endl;
	}
	mymap.erase(--(--(--mymap.end())), mymap.end());
	
	



	// std::cout << "##############################" << std::endl;
	// std::map<int, int>::const_iterator it1, ite1;
	// it1 = mymap1.begin();
	// ite1 = mymap1.end();
	// for (; it1 != ite1; it1++)
	// {
	// 	std::cout << it1->first << " " << it1->second << std::endl;
	// }
	
	// mymap.erase(mymap.begin(), mymap.end());
	
	// ft::map<int, int>::const_iterator it, ite;
	// it = mymap.begin();
	// ite = mymap.end();
	// std::cout << "size " << mymap.size() << std::endl;
	// for (; it != ite; it++)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }
}