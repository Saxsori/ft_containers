/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:09:17 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/20 21:45:29 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TOOLS_HPP
# define MAP_TOOLS_HPP

#include <iostream>
#include "./utility.hpp"

namespace ft
{
	template <class value_type>
	struct node
	{
		value_type			&data;
		node				*parent;
		node				*left;
		node				*right;
	};

	template <class value_type, class key_compare>
	struct binary_search_tree
	{
		ft::node<value_type>		root;
		key_compare					comp;

		binary_search_tree():root(NULL),comp(){};
		binary_search_tree(const key_compare& comp):root(NULL),comp(comp){};
		~binary_search_tree(){};
	};
	
}

#endif