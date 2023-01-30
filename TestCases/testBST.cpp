/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBST.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:07:57 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/30 07:41:18 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/TOOLS/binary_search_tree.hpp"
#include "../CONTAINERS/TOOLS/utility.hpp"
#include <iomanip>
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define DEFCOLO "\033[0m"
#include <vector>
#include <iostream>
#include <map>
#include <memory>
#include "../CONTAINERS/map.hpp"
#include "../ITERATORS/bidirectional_iterator.hpp"

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

/*
* C++ Program to Print Binary Tree
	https://www.techiedelight.com/c-program-print-binary-tree/
*/
struct Trunk
{
	Trunk *prev;
	std::string str;

	Trunk(Trunk *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

void showTrunks(Trunk *p)
{
	if (!p)
		return;
	showTrunks(p->prev);
	std::cout << p->str;
}

template <typename first_type>
void printTree(ft::node<first_type>* root, Trunk *prev, bool isLeft)
{
	if (!root)
		return;

	std::string prev_str = "    ";
	Trunk trunk1 = Trunk(prev, prev_str);
	Trunk &trunk = trunk1;

	printTree(root->right, &trunk, true);

	if (!prev)
		trunk.str = "———";
	else if (isLeft)
	{
		trunk.str = ".———";
		prev_str = "   |";
	}
	else 
	{
		trunk.str = "`———";
		prev->str = prev_str;
	}

	showTrunks(&trunk);
	
	if (root->color == 'r')
		std::cout << BRED << root->data.first << "-" << root->pos << DEFCOLO << std::endl;
	else
		std::cout << BBLK << root->data.first << "-" << root->pos << DEFCOLO << std::endl; 
	if (prev)
		prev->str = prev_str;
	trunk.str = "   |";

	printTree(root->left, &trunk, false);
}

// int main()
// {
// 	typedef	ft::pair<int, std::string>  map_type;
// 	ft::binary_search_tree<int, std::string, value_compare, std::allocator<map_type> > bst;
	
// 	bst.insert(ft::make_pair <int, std::string> (10, "one"));
// 	bst.insert(ft::make_pair <int, std::string> (18, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (7, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (15, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (16, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (30, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (25, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (40, "two"));
// 	bst.insert(ft::make_pair <int, std::string> (60, "ewo"));
// 	bst.insert(ft::make_pair <int, std::string> (2, "nwo"));
// 	bst.insert(ft::make_pair <int, std::string> (1, "mww"));
// 	bst.insert(ft::make_pair <int, std::string> (70, "tll"));
	
	/*******************************************/
	
	// bst.insert(ft::make_pair <int, std::string> (50, "two"));
	// bst.insert(ft::make_pair <int, std::string> (20, "two"));
	// bst.insert(ft::make_pair <int, std::string> (15, "two"));
	// bst.insert(ft::make_pair <int, std::string> (35, "two"));
	// bst.insert(ft::make_pair <int, std::string> (65, "two"));
	// bst.insert(ft::make_pair <int, std::string> (55, "two"));
	// bst.insert(ft::make_pair <int, std::string> (70, "two"));
	// bst.insert(ft::make_pair <int, std::string> (68, "two"));
	// bst.insert(ft::make_pair <int, std::string> (80, "two"));
	// bst.insert(ft::make_pair <int, std::string> (90, "two"));
	
	/*******************************************/

	// std::cout << std::endl;
	// printTree(bst.root(), NULL, false);
	// std::cout << std::endl;
	
	
	
	// bst.sortedIterator(0);
	// bst.sortedIterator(1);
	// bst.sortedIterator(3);
	// bst.sortedIterator(2);

	// std::cout << bst.nodeSearched->data.first << std::endl;
	// std::cout << bst.sortedIterator(bst.root(), 1)->data.first << std::endl;
	// std::cout << << std::endl;

		
	// bst.erase(ft::make_pair <int, std::string> (55, "two"));
	// bst.erase(ft::make_pair <int, std::string> (20, "two"));
	// bst.erase(ft::make_pair <int, std::string> (90, "two"));
	// bst.erase(ft::make_pair <int, std::string> (80, "two"));
	// bst.erase(ft::make_pair <int, std::string> (50, "two"));
	// bst.erase(ft::make_pair <int, std::string> (35, "two"));
	// bst.erase(ft::make_pair <int, std::string> (15, "two"));
	// bst.erase(ft::make_pair <int, std::string> (65, "two"));
	// bst.erase(ft::make_pair <int, std::string> (68, "two"));
	// bst.erase(ft::make_pair <int, std::string> (70, "two"));
	
	/*******************************************/
	
	// bst.erase(ft::make_pair <int, std::string> (10, "one"));
	// bst.erase(ft::make_pair <int, std::string> (7, "two"));
	// bst.erase(ft::make_pair <int, std::string> (18, "two"));
	// bst.erase(ft::make_pair <int, std::string> (15, "two"));
	// bst.erase(ft::make_pair <int, std::string> (16, "two"));
	// bst.erase(ft::make_pair <int, std::string> (30, "two"));
	// bst.erase(ft::make_pair <int, std::string> (25, "two"));
	// bst.erase(ft::make_pair <int, std::string> (40, "two"));
	// bst.erase(ft::make_pair <int, std::string> (60, "ewo"));
	// bst.erase(ft::make_pair <int, std::string> (2, "nwo"));
	// bst.erase(ft::make_pair <int, std::string> (1, "mww"));
	// bst.erase(ft::make_pair <int, std::string> (70, "tll"));

	/*******************************************/

	// bst.erase(ft::make_pair <int, std::string> (10, "one"));
// 	std::cout << std::endl;
// 	printTree(bst.root(), NULL, false);
// 	std::cout << std::endl;
// 	return 0;
// }

int		main(void)
{
	ft::map<char, int>::iterator it;
	ft::map<char, float>::const_iterator ite;

	ite = it.begin();
	
	// std::cout << (it != ite) << std::endl;
	return (0);
}