/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:15:22 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/23 12:25:03 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTTREE_HPP
# define PRINTTREE_HPP
#include <iomanip>
#include <iostream>
#include "../CONTAINERS/TOOLS/utility.hpp"
#include "../CONTAINERS/TOOLS/map_tools.hpp"


# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define DEFCOLO "\033[0m"
namespace ft
{
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
	void showTrunks(Trunk *p);

	template <typename first_type>
	void printTree(ft::node<first_type>* root, Trunk *prev, bool isLeft);
}

#endif