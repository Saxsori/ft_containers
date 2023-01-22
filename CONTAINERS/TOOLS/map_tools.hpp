/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:09:17 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/22 21:54:15 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TOOLS_HPP
# define MAP_TOOLS_HPP

#include <iostream>
#include <memory>
#include "./utility.hpp"

#define BLACK 'b'
#define RED 'r'


/*
	** binary_search_tree
	
*/
namespace ft
{
	template <class data_type>
	struct node
	{
		data_type	data;
		node				*parent;
		node				*left;
		node				*right;
		int					color;
		template <class T>
		node(ft::node<T> &node):data(node.data), parent(node.parent), left(node.left), right(node.right), color(node.color){}
	};
	
	/*
	
		if !root
			insert root
		else if root
		{
			create node red and put it in the right place for BST
			then
			{
				while (true)
				{
					if newnode.parent.color == black
						break;
					else if newnode.parent.color == red
					{
						if newnode.parent == newnode.parent.parent.left
						{
							if (newnode.parent.parent.right.color == red)
							{
								// recolor uncle and father
								// recolor grandpa if not root, if root exit
								// if grandpa is not root, make it newnode
							}
							else if (newnode.parent.parent.right.color == black)
							{
								// rotate
								// recolor the median and the parent of the median
							}
						}
						else if newnode.parent == newnode.parent.parent.right
						{
							if (newnode.parent.parent.left.color == red)
							{
								// recolor uncle and father
								// recolor grandpa if not root, if root exit
								// if grandpa is not root, make it newnode
							}
							else if (newnode.parent.parent.left.color == black)
							{
								// rotate
								// recolor the median and the parent of the median
							}
						}
					}
				}
			}
		}
	
	*/

	template <class value_type, class key_compare>
	class binary_search_tree
	{
		public:
			typedef value_type								data_type;
		private:
			ft::node<data_type>								*_root;
			key_compare										_comp;
			std::allocator<ft::node<data_type> >			_allocNode;
			std::allocator<data_type>						_allocData;
			ft::node<data_type>								*_createNode(const data_type &data)
			{
				ft::node<data_type>	*node;
				node = _allocNode.allocate(1);
				_allocData.construct(&node->data, data);
				node->color = RED;
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				return (node);
		}
		public:
			
			binary_search_tree():_root(NULL),_comp(){};
			~binary_search_tree(){};
			ft::node<data_type>			*root() const {return _root;}
			void						insert(data_type data)
			{
				if (!_root)
					_root = _createNode(data);
				else
				{
					ft::node<data_type>	*traversal = _root;
					while (true)
					{
						if (_comp(data, traversal->data))
						{
							if (!traversal->left)
							{
								traversal->left = _createNode(data);
								traversal->left->parent = traversal;
								break;
							}
							else
								traversal = traversal->left;
						}
						else
						{
							if (!traversal->right)
							{
								traversal->right = _createNode(data);
								traversal->right->parent = traversal;
								break;
							}
							else
								traversal = traversal->right;
						}
					}
				}
			}
	};
}

#endif