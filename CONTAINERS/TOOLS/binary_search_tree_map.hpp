/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree_map.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:09:17 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/27 10:37:33 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_MAP_HPP
# define BINARY_SEARCH_TREE_MAP_HPP

#include <iostream>
#include <memory>
#include "./utility.hpp"
#include "./algorithm.hpp"
#include "./tree_tools.hpp"

#define BLACK 'b'
#define RED 'r'

#define MIN 1
#define MAX 2
#define EQUAL 3

/*
	** binary_search_tree_map
	
*/
namespace ft
{	
	template <class data_type, class key_compare, class allocator>
	class binary_search_tree_map
	{
		public:
			typedef ft::node<data_type>*					Node;
		private:
			mutable ft::node<data_type>						*_nodeSearched;
			ft::node<data_type>								*_root;
			key_compare										_comp;
			std::allocator<ft::node<data_type> >			_allocNode;
			allocator										_allocData;
			size_t											_size;
			ft::node<data_type>*							_pastTheEnd;
			bool											_isShallowCopy;
			ft::node<data_type>*							_head;
			ft::node<data_type>				*_createNode(const data_type &data)
			{
				ft::node<data_type>	*node;
				node = _allocNode.allocate(1);
				_allocData.construct(&node->data, data);
				node->color = RED;
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				node->pos = 0;
				node->isPastTheEnd = false;
				_size++;	
				return (node);
			}
			void							_recolor(ft::node<data_type> *node)
			{
				node->color = (node->color == BLACK) ? RED : BLACK;
			}
			void							_swapColor(ft::node<data_type> *bro, ft::node<data_type> *parent)
			{
				int tempColor = bro->color;
				bro->color = parent->color;
				parent->color = tempColor;
			}
			/* This function traverses tree
			in post order to delete each
			and every node of the tree */
			void							_deleteTree(ft::node<data_type>* node)
			{
				if (node == NULL) return;
			
				/* first delete both subtrees */
				_deleteTree(node->left);
				_deleteTree(node->right);
				_allocData.destroy(&node->data);
				_allocNode.deallocate(node, 1);
			}
			bool							_isBlackNode(ft::node<data_type> *node)
			{
				if (node == NULL)
					return true;
				if (node->color == BLACK)
					return true;
				return false;
			}
			void							_reinsert_oldChild(ft::node<data_type> *old_child, ft::node<data_type> *new_root)
			{
				while (true)
				{
					if (_comp(new_root->data.first, old_child->data.first))
					{
						if (new_root->right)
							new_root = new_root->right;
						else
						{
							new_root->right = old_child;
							old_child->parent = new_root;
							return ;
						}
					}
					else
					{
						if (new_root->left)
							new_root = new_root->left;
						else
						{
							new_root->left = old_child;
							old_child->parent = new_root;
							return ;
						}
					}
				}
			}
			void						left_rotate(ft::node<data_type> *median, ft::node<data_type> *old_root)
			{
				ft::node<data_type> *old_child = median->left;
				median->left = old_root;
				median->parent = old_root->parent;
				if (old_root->parent)
				{
					if (old_root->parent->left == old_root)
						old_root->parent->left = median;
					else if (old_root->parent->right == old_root)
						old_root->parent->right = median;
				}
				else
					_root = median;
				old_root->parent = median;
				old_root->right = NULL;
				if (old_child)
				{
					if (old_root->right)					
						_reinsert_oldChild(old_child, old_root->right);
					else
					{
						old_root->right = old_child;
						old_child->parent = old_root;
					}
				}
			}
			void					right_rotate(ft::node<data_type> *median, ft::node<data_type> *old_root)
			{
				ft::node<data_type> *old_child = median->right;
				median->right = old_root;
				median->parent = old_root->parent;
				if (old_root->parent)
				{
					if (old_root->parent->left == old_root)
						old_root->parent->left = median;
					else if (old_root->parent->right == old_root)
						old_root->parent->right = median;
				}
				else
					_root = median;
				old_root->parent = median;
				old_root->left = NULL;
				if (old_child)
				{
					if (old_root->left)					
						_reinsert_oldChild(old_child, old_root->left);
					else
					{
						old_root->left = old_child;
						old_child->parent = old_root;
					}
				}
			}
			void							_rebalance(ft::node<data_type> *new_node)
			{
				while (true)
				{
					if (new_node->parent == NULL)
					{
						new_node->color = BLACK;
						break;
					}
					if (new_node->parent->color == BLACK)
						break;
					else if (new_node->parent->color == RED)
					{
						if (new_node->parent == new_node->parent->parent->left)
						{
							/*
								these are two possible cases where the uncle is in the left side and the father is in the right	
											grandpa									grandpa
											/		\           or 					/		\
										father		uncle						father		uncle
										/											\
									newnode											newnode
							*/
							if (new_node->parent->parent->right == NULL || (new_node->parent->parent->right && new_node->parent->parent->right->color == BLACK))
							{
								// rotate
								// recolor the median and the parent of the median
								if (new_node == new_node->parent->right)
								{
									left_rotate(new_node, new_node->parent);
									right_rotate(new_node, new_node->parent);
									_recolor(new_node);
									_recolor(new_node->right);		
								}
								else
								{
									right_rotate(new_node->parent, new_node->parent->parent);
									_recolor(new_node->parent->right);
									_recolor(new_node->parent);									
								}
								break;
							}
							else if (new_node->parent->parent->right->color == RED)
							{
								// recolor uncle and father
								// recolor grandpa if not root, if root exit
								// if grandpa is not root, make it newnode
								_recolor(new_node->parent->parent->right);
								_recolor(new_node->parent->parent->left);
								if (new_node->parent->parent != _root)
								{
									_recolor(new_node->parent->parent);
									new_node = new_node->parent->parent;
								}
								else
									break;
							}
						}
						else if (new_node->parent == new_node->parent->parent->right)
						{
							/*
								these are two possible cases where my uncle is in the right side and my father is in the left
											grandpa									grandpa
											/		\								/		\
										uncle		father			or			father		uncle
														\									/
														new_node							new_node		
							*/
							if (new_node->parent->parent->left == NULL || (new_node->parent->parent->left && new_node->parent->parent->left->color == BLACK))
							{
								// rotate
								// _recolor the median and the parent of the median
								if (new_node == new_node->parent->left)
								{
									right_rotate(new_node, new_node->parent);
									left_rotate(new_node, new_node->parent);
									_recolor(new_node);
									_recolor(new_node->left);
								}
								else
								{
									left_rotate(new_node->parent, new_node->parent->parent);
									_recolor(new_node->parent->left);
									_recolor(new_node->parent);
								}
								break;
							}
							else if (new_node->parent->parent->left->color == RED)
							{
								// _recolor uncle and father
								// _recolor grandpa if not root, if root exit
								// if grandpa is not root, make it new_node
								_recolor(new_node->parent->parent->right);
								_recolor(new_node->parent->parent->left);
								if (new_node->parent->parent != _root)
								{
									_recolor(new_node->parent->parent);
									new_node = new_node->parent->parent;
								}
								else
									break;
							}
						}
					}
				}
			}
			void					_resolveDB(ft::node<data_type> *node)
			{
				if (node == _root)
					return;
				if (node->parent->left == node)
				{
					// if the sibling was nill or black and his children were black
					// ! note if one of them was null ... if bro was null or black && his children was either black or nill
					if (node->parent->right && node->parent->right->color == BLACK && _isBlackNode(node->parent->right->right) && _isBlackNode(node->parent->right->left))
					{
						if (node->parent->right)
							node->parent->right->color = RED;
						if (node->parent->color == RED)
							node->parent->color = BLACK;
						else
							_resolveDB(node->parent);
					}
					else if (node->parent->right && node->parent->right->color == RED)
					{
						int temp = node->parent->color;
						node->parent->color = node->parent->right->color;
						node->parent->right->color = temp;
						left_rotate(node->parent->right, node->parent);
						_resolveDB(node);
					}
					else if (node->parent->right && _isBlackNode(node->parent->right) && _isBlackNode(node->parent->right->right) && node->parent->right->left->color == RED)
					{
						int temp = node->parent->right->color;
						node->parent->right->color = node->parent->right->left->color;
						node->parent->right->left->color = temp;
						right_rotate(node->parent->right->left, node->parent->right);
						_resolveDB(node);
					}
					else if (node->parent->right && _isBlackNode(node->parent->right) && node->parent->right->right->color == RED)
					{
						int temp = node->parent->right->color;
						node->parent->right->color = node->parent->color;
						node->parent->color = temp;
						node->parent->right->right->color = BLACK;
						left_rotate(node->parent->right, node->parent);
					}
				}
				else if (node->parent->right == node)
				{
					if (node->parent->left && node->parent->left->color == BLACK && _isBlackNode(node->parent->left->right) && _isBlackNode(node->parent->left->left))
					{
						if (node->parent->left)
							node->parent->left->color = RED;
						if (node->parent->color == RED)
							node->parent->color = BLACK;
						else
							_resolveDB(node->parent);

					}
					else if (node->parent->left && node->parent->left->color == RED)
					{
						int temp = node->parent->color;
						node->parent->color = node->parent->left->color;
						node->parent->left->color = temp;
						right_rotate(node->parent->left, node->parent);
						_resolveDB(node);
					}
					else if (_isBlackNode(node->parent->left) && _isBlackNode(node->parent->left->left) && node->parent->left->right->color == RED)
					{
						int temp = node->parent->left->color;
						node->parent->left->color = node->parent->left->right->color;
						node->parent->left->right->color = temp;
						left_rotate(node->parent->left->right, node->parent->left);
						_resolveDB(node);
					}
					else if (_isBlackNode(node->parent->left) && node->parent->left->left->color == RED)
					{
						int temp = node->parent->left->color;
						node->parent->left->color = node->parent->color;
						node->parent->color = temp;
						node->parent->left->left->color = BLACK;
						right_rotate(node->parent->left, node->parent);
					}
				}
			}
			ft::node<data_type>		*_createPastTheEnd(void)
			{
				ft::node<data_type>	*node;
				node = _allocNode.allocate(1);
				_allocData.construct(&node->data, data_type());
				node->color = BLACK;
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				node->pos = _size;
				node->isPastTheEnd = true;
				return (node);
			}
			ft::node<data_type>			*_findGreatGrandFather(ft::node<data_type> *node) const
			{
				ft::node<data_type>	*firstNode = node;
				while (true)
				{
					if (node->parent && _comp(node->data.first, node->parent->data.first))
						return (node->parent);
					else if (!node->parent)
					{
						if (_comp(node->data.first, firstNode->data.first))
							return _pastTheEnd;
						else
							return node;
					}
					node = node->parent;
				}
			}
			ft::node<data_type>			*_findLeftMost(ft::node<data_type> *node) const
			{
				while (true)
				{
					if (!_isNode(node->left))
						return (node);
					node = node->left;
				}
			}
			bool	_isNode(ft::node<data_type> *node) const
			{
				if (node == NULL || node == _pastTheEnd)
					return false;
				return true;
			}
			ft::node<data_type>			*_findYoungGrandFather(ft::node<data_type> *node) const
			{
				ft::node<data_type>	*firstNode = node;
				while (true)
				{
					if (node->parent && _comp(node->parent->data.first, node->data.first))
						return (node->parent);
					else if (!node->parent)
					{
						if (_comp(firstNode->data.first, node->data.first))
							return NULL;
						else
							return node;
					}
					node = node->parent;
				}
			}
			ft::node<data_type>			*_findRightMost(ft::node<data_type> *node) const
			{
				while (true)
				{
					if (!_isNode(node->right))
						return (node);
					node = node->right;
				}
			}
			
		public:
			binary_search_tree_map(void):_comp()
			{
				// std::cout << "default" << std::endl;
				_nodeSearched = NULL;
				_root = NULL;
				_size = 0;
				_pastTheEnd = _createPastTheEnd();
				_isShallowCopy = false;
			}
			binary_search_tree_map(const binary_search_tree_map &x):_nodeSearched(NULL),_root(NULL),_comp(),_size(0),_pastTheEnd(NULL)
			{
				// std::cout << "copy" << std::endl;
				_size = x._size;
				_comp = x._comp;
				_root = x._root;
				_pastTheEnd = x._pastTheEnd;
				_isShallowCopy = true;
			}
			~binary_search_tree_map()
			{
				// std::cout<< "HERE ALKA1" << std::endl; 
				if (_isShallowCopy == false)
				{
					if (_root)
					{
						_deleteTree(_root);
						_root = NULL;
					}
					// std::cout << "free default" << std::endl;
					if (_pastTheEnd)
					{
						// _allocData.destroy(&_pastTheEnd->data);
						// delete _pastTheEnd;
						// std::cout<< "HERE ALKA" << std::endl; 
						_allocNode.deallocate(_pastTheEnd, 1);
						_pastTheEnd = NULL;
					}
				}
				// else
				// 	std::cout << "free copy" << std::endl;
				// std::cout << "--------" << std::endl;
			}
			void						swap(binary_search_tree_map &x)
			{
				ft::node<data_type>								*T_nodeSearched;
				ft::node<data_type>								*T_root;
				ft::node<data_type>								*T_pastTheEnd;
				key_compare										T_comp;
				std::allocator<ft::node<data_type> >			T_allocNode;
				allocator										T_allocData;
				size_t											T_size;

				T_nodeSearched = _nodeSearched;
				T_root = _root;
				T_comp = _comp;
				T_allocNode = _allocNode;
				T_allocData = _allocData;
				T_size = _size;
				T_pastTheEnd = _pastTheEnd;
				
				_nodeSearched = x._nodeSearched;
				_root = x._root;
				_comp = x._comp;
				_allocNode = x._allocNode;
				_allocData = x._allocData;
				_size = x._size;
				_pastTheEnd = x._pastTheEnd;
				
				x._nodeSearched = T_nodeSearched;
				x._root = T_root;
				x._comp = T_comp;
				x._allocNode = T_allocNode;
				x._allocData = T_allocData;
				x._size = T_size;
				x._pastTheEnd = T_pastTheEnd;
			}
			ft::node<data_type>			*root(void) const {return _root;}
			size_t						size(void) const {return _size;}
			size_t						max_size(void) const {return _allocNode.max_size();}
			template <class key_type>
			ft::node<data_type>			*find(const key_type& key) const
			{
				ft::node<data_type> *node = _root;
				while (node)
				{
					if (_comp(key, node->data.first))
						node = node->left;
					else if (_comp(node->data.first, key))
						node = node->right;
					else
						return node;
				}
				return NULL;
			}
			ft::node<data_type>			*getPastTheEnd(void) const {return _pastTheEnd;}
			ft::node<data_type>			*getNode(ft::node<data_type> *node, int option) const
			{
				if (option == MIN)
				{
					if (node->left)
						return getNode(node->left, option);
					else
						return node;
				}
				else if (option == MAX)
				{
					if (node->isPastTheEnd)
						return node->parent;
					if (node->right)
						return getNode(node->right, option);
					else
						return node;
				}
				return NULL;
			}
			ft::node<data_type>			*getNode(data_type data) const
			{
				ft::node<data_type> *traversal = _root;
				while (traversal)
				{
					if (_comp(data.first, traversal->data.first))
						traversal = traversal->left;
					else if (_comp(traversal->data.first, data.first))
						traversal = traversal->right;
					else
						return traversal;
				}
				return NULL;
			}
			void						insert(data_type data)
			{
				if (!_root)
				{
					_root = _createNode(data);
					_root->color = BLACK;
				}
				else
				{
					ft::node<data_type>	*traversal = _root;
					ft::node<data_type>	*new_node = _root;
					while (true)
					{
						if (_comp(data.first, traversal->data.first))
						{
							if (!traversal->left)
							{
								traversal->left = _createNode(data);
								traversal->left->parent = traversal;
								new_node = traversal->left;
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
								new_node = traversal->right;
								break;
							}
							else
								traversal = traversal->right;
						}
					}
					_rebalance(new_node);
				}
			}
			void				erase(ft::node<data_type> *node)
			{
				if (node)
				{
					if (!node->left && !node->right)
					{
						if (node->parent)
						{
							if (node->parent->right == node)
							{
								_allocData.destroy(&node->data);
								if (node->color == BLACK)
									_resolveDB(node);
								node = node->parent;
								_allocNode.deallocate(node->right, 1);
								node->right = NULL;
								_size--;
							}
							else if (node->parent->left == node)
							{
								_allocData.destroy(&node->data);
								if (node->color == BLACK)
									_resolveDB(node);
								node = node->parent;
								_allocNode.deallocate(node->left, 1);
								node->left = NULL;
								_size--;
							}
						}
						else
						{
							_allocData.destroy(&node->data);
							_allocNode.deallocate(node, 1);
							_root = NULL;
							_size--;
						}
					}
					else
					{
						ft::node<data_type>	*child = NULL;
						if (node->left)
							child = getNode(node->left, MAX);
						else if (node->right)
							child = node->right;
						_allocData.destroy(&node->data);
						_allocData.construct(&node->data, child->data);
						erase(child);
					}
				}
			}
			void			erase(data_type data)
			{
				erase(getNode(data));
			}
			ft::node<data_type>			*decrementNodeByOne(ft::node<data_type> *node) const
			{
				if (!node)
					return NULL;
				else if (node == _pastTheEnd)
					return getNode(_root, MAX);
				if (!_isNode(node->left) && node->parent && _comp(node->parent->data.first, node->data.first))
					return (node->parent);
				else if (!_isNode(node->left) && node->parent && _comp(node->data.first, node->parent->data.first))
					return (_findYoungGrandFather(node));
				else if (_isNode(node->left) && !_isNode(node->left->right))
					return (node->left);
				else if (_isNode(node->left) && _isNode(node->left->right))
					return (_findRightMost(node->left));
				return (NULL);
			}
			ft::node<data_type>			*incrementNodeByOne(ft::node<data_type> *node) const
			{
				if (!node || node == _pastTheEnd)
					return NULL;
				else if (!_isNode(node->right) && !_isNode(node->parent))
					return (_pastTheEnd);
				if (!_isNode(node->right) && node->parent && _comp(node->data.first, node->parent->data.first))
					return (node->parent);
				else if (!_isNode(node->right) && node->parent && _comp(node->parent->data.first, node->data.first))
					return (_findGreatGrandFather(node));
				else if (_isNode(node->right) && !_isNode(node->right->left))
					return (node->right);
				else if (_isNode(node->right) && _isNode(node->right->left))
					return (_findLeftMost(node->right));
				return (NULL);
			}
	};
}

#endif


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
						these are two possible cases where my uncle is in the left side and my father is in the right	
									grandpa									grandpa
									/		\           or 					/		\
								father		uncle						father		uncle
								/											\
							newnode											newnode
						if (newnode.parent == newnode.parent.parent.left)
						{
							if (newnode.parent.parent.right.color == red)
							{
								// recolor uncle and father
								// recolor grandpa if not root, if root exit
								// if grandpa is not root, make it newnode
								recolor(newnode.parent.parent.right)
								recolor(newnode.parent.parent.left)
								if (newnode.parent.parent != root)
								{
									recolor(newnode.parent.parent)
									newnode = newnode.parent.parent
								}
								else
									break;
							}
							else if (newnode.parent.parent.right.color == black)
							{
								// rotate
								// recolor the median and the parent of the median
								if (newnode == newnode.parent.right)
									left rotate(newnode, newnode.parent)
								right rotate(newnode.parent, newnode.parent.parent)
								recolor(newnode.parent)
								recolor(newnode.parent.parent)
							}
						}
						these are two possible cases where my uncle is in the right side and my father is in the left
									grandpa									grandpa
									/		\								/		\
								uncle		father			or			father		uncle
												\									/
												newnode							newnode		
						else if (newnode.parent == newnode.parent.parent.right)
						{
							if (newnode.parent.parent.left.color == red)
							{
								// recolor uncle and father
								// recolor grandpa if not root, if root exit
								// if grandpa is not root, make it newnode
								recolor(newnode.parent.parent.right)
								recolor(newnode.parent.parent.left)
								if (newnode.parent.parent != root)
								{
									recolor(newnode.parent.parent)
									newnode = newnode.parent.parent
								}
								else
									break;
							}
							else if (newnode.parent.parent.left.color == black)
							{
								// rotate
								// recolor the median and the parent of the median
								if (newnode == newnode.parent.left)
									right rotate(newnode, newnode.parent)
								left rotate(newnode.parent, newnode.parent.parent)
								recolor(newnode.parent)
								recolor(newnode.parent.parent)
							}
						}
					}
				}
			}
		}
	
	*/