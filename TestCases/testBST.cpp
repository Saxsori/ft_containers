/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBST.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:07:57 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/23 12:21:11 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/TOOLS/map_tools.hpp"
#include "../CONTAINERS/TOOLS/utility.hpp"
#include "./printTree.hpp"
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

int main()
{
	ft::make_pair <int, std::string> (1, "one");
	typedef	std::pair<int, std::string>::first_type first_type;
	ft::binary_search_tree<first_type, value_compare> bst;
	bst.insert(10);
	bst.insert(18);
	bst.insert(7);
	bst.insert(15);
	bst.insert(16);

	std::cout << std::endl;
	// printTree(bst.root(), NULL, false);
	std::cout << std::endl;
	
	// bst.left_rotate(bst.root()->right, bst.root());
	// printTree(bst.root(), NULL, false);
	
	// ft::binary_search_tree<first_type, value_compare> bst2;
	// bst2.insert(3);
	// bst2.insert(-2);
	// bst2.insert(-3);
	// bst2.insert(-1);
	// bst2.insert(7);
	// std::cout << std::endl;
	// printTree(bst2.root(), NULL, false);
	// std::cout << std::endl;
	
	// bst2.right_rotate(bst2.root()->left, bst2.root());
	// printTree(bst2.root(), NULL, false);
	return 0;
}