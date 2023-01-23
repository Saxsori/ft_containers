/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBST.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:07:57 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/23 00:39:25 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/TOOLS/map_tools.hpp"
#include "../CONTAINERS/TOOLS/utility.hpp"
#include <iomanip>

# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define DEFCOLO "\033[0m"

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

/*
 * C++ Program to Print Binary Tree
	https://www.techiedelight.com/c-program-print-binary-tree/
*/
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
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->right, trunk, true);
 
    if (!prev)
        trunk->str = "———";
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else 
	{
        trunk->str = "`———";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
	
	if (root->color == 'r')
		std::cout << BRED << root->data << DEFCOLO << std::endl;
	else
		std::cout << BBLK << root->data << DEFCOLO << std::endl; 
    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";
 
    printTree(root->left, trunk, false);
}

int main()
{
	ft::make_pair <int, std::string> (1, "one");
	typedef	std::pair<int, std::string>::first_type first_type;
	ft::binary_search_tree<first_type, value_compare> bst;
	std::cout << std::endl;
	bst.insert(3);
	bst.insert(8);
	bst.insert(9);
	bst.insert(7);
	// bst.insert(0);
	ft::node<first_type> *node = bst.root();
	// std::cout << "Root: " << node->data << std::endl;
	printTree(node, NULL, false);
	std::cout << std::endl;
	bst.left_rotate(bst.root()->right, bst.root());
	std::cout << "Root: " << bst.root()->data << std::endl;
	node = bst.root();
	printTree(node, NULL, false);
	std::cout << std::endl;
	std::cout << std::endl;
	ft::binary_search_tree<first_type, value_compare> bst2;
	bst2.insert(3);
	bst2.insert(-2);
	bst2.insert(-3);
	bst2.insert(-1);
	printTree(bst2.root(), NULL, false);
	bst2.right_rotate(bst2.root()->left, bst2.root());
	printTree(bst2.root(), NULL, false);
	return 0;
}