/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tools.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:59:06 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 15:59:54 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_TOOLS_HPP
#define TREE_TOOLS_HPP

namespace ft
{
	template <class data_type>
	struct node
	{
		data_type			data;
		node				*parent;
		node				*left;
		node				*right;
		int					color;
		int					pos;
		bool				isPastTheEnd;
		template <class T>
		node(ft::node<T> &node):data(node.data), parent(node.parent), left(node.left), right(node.right), color(node.color), pos(0){}
		
	};
}

#endif