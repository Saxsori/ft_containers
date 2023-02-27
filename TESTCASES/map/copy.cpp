/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:41:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/27 19:15:08 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <memory>
#include <list>
#include "../../CONTAINERS/map.hpp"



bool	comp(int a, int b)
{
	return a < b;
}

class value_compare
{
	public:
	value_compare(){}
	bool operator()(const int& x, const int& y) const{return comp(x, y);}
};


int main ()
{
	// std::list <std::pair<const int, int> > lst2;
	std::list <ft::pair<const int, int> > lst;
	// std::list <ft::pair<const int, int> > lst1;
	
	std::cout << "BOO " << std::endl;
    unsigned int lst_size = 1;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(ft::pair<const int, int>(i + 1, (i + 1) * 3));
    ft::map <int, int> mp(lst.begin(), lst.end());
    ft::map<int, int>::const_iterator it = mp.begin();
	// std::cout << mp.begin()->first << std::endl;
	// ft::map<int, int>::const_iterator it3 = ite;
	// std::cout << (--it3)->first << std::endl;
    // for (; it != ite; it++)
    // {
	// 	std::cout << "content" << std::endl;
    //     std::cout << it->first << " " << it->second << std::endl;
    // }

	// ft::map<int, int> mp;
	// std::map<int, int> mp1;


	// mp.insert(ft::make_pair<int, int>(1, 3));

	// mp1.insert(std::make_pair<int, int>(1, 3));
	
	// ft::map<int, int>::iterator testMap;

    // for(int i = 0; i < 10000000; ++i)
    // {
    //     testMap.insert(ft::make_pair(i, i+1));
    // }
    // testMap.erase(testMap.begin(), testMap.end());

	// ft::binary_search_tree_map<ft::pair<const int, int> , value_compare, std::allocator<ft::pair<const int, int> > > bst;

	// bst.insert(ft::make_pair <const int, int> (22, 2));
	// bst.insert(ft::make_pair <const int, int> (33, 3));
	// bst.insert(ft::make_pair <const int, int> (88, 554));
	// bst.insert(ft::make_pair <const int, int> (19, 774));	
	// bst.insert(ft::make_pair <const int, int> (26, 446));	
	// bst.insert(ft::make_pair <const int, int> (37, 344));	
	// bst.insert(ft::make_pair <const int, int> (1, 433));	
	// bst.insert(ft::make_pair <const int, int> (2, 34));	
	// bst.insert(ft::make_pair <const int, int> (3, 42));	
	// bst.insert(ft::make_pair <const int, int> (10, 4));	
	// bst.insert(ft::make_pair <const int, int> (38, 242));	
	
		
    // for(int i = 0; i < 4; ++i)
    // {
	// 	bst.insert(ft::make_pair <const int, int> (i, i+1));
	// 	// std::cout << i << std::endl;
    // }
	
    // ft::map<int, int>::iterator tryit = mp.begin();

	// tryit->second = 10000000;

	// ft::node <ft::pair<const int, int> > *node;
	// node = bst.getNode(bst.root(), 1);

	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << node->data.first << std::endl;
	// 	std::cout << i << std::endl;
	// 	node = bst.incrementNodeByOne(node);
	// }

	// node = bst.getNode(bst.root(), 1);

	// for (int i = 0; i < 2; i++)
	// {
	// 	std::cout << "content: " << node->data.first << std::endl;
		// std::cout << i << std::endl;
		// node = bst.incrementNodeByOne(node);
	// }
	
	

	
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