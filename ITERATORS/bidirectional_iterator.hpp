/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/11 17:37:06 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include "./iterator.hpp"
// # include "../CONTAINERS/TOOLS/utility.hpp"
# include "../CONTAINERS/TOOLS/binary_search_tree.hpp"

/*
	bidirectional_iterator is a derived class of iterator
	which is a derived class of std::iterator
	it allows to iterate over a container in a bidirectional manner
	which means that it can be incremented and decremented by 1
	which is not the case with random_access_iterator
*/


namespace ft
{
	template<class T, class Tree, bool is_const> class map_iterator {};
	template<class T, class Tree>
	class map_iterator<T, Tree, false>
	{	
		public:
		typedef	Tree					tree;
		typedef typename Tree::Node		node;
		mutable node 							_currentNode;
		map_iterator(void): _currentNode(NULL){}
		map_iterator(node _node): _currentNode(_node){}
		~map_iterator(void){}
		T& operator*(void) const
		{
			return (_currentNode->data);
		}
		T* operator->(void) const
		{
			return (&_currentNode->data);
		}	
	};
	template<class T, class Tree>
	class map_iterator<T, Tree, true>
	{
		public:
		typedef	Tree					tree;
		typedef typename Tree::Node		node;
		mutable node 							_currentNode;
		map_iterator(void): _currentNode(NULL){}
		map_iterator(node _node): _currentNode(_node){}
		~map_iterator(void){}
		const T& operator*(void) const
		{
			return (_currentNode->data);
		}
		const T* operator->(void) const
		{
			return (&_currentNode->data);
		}
	};
	
	template <class T, class key_compare, class allocator_type, bool is_const>
	class bidirectional_iterator:public ft::map_iterator <T, ft::binary_search_tree<T, key_compare, allocator_type>, is_const>
	{
		public:
			typedef T																			value_type;
			typedef T*																			pointer;
			typedef T&																			reference;
			typedef std::ptrdiff_t																difference_type;
			typedef ft::bidirectional_iterator_tag												iterator_category;
			typedef ft::binary_search_tree<T, key_compare, allocator_type>						tree;
			typedef typename tree::Node															node;
			typedef ft::map_iterator<T, tree, is_const> 										base;
			
			mutable size_t				_currentPos;
			mutable tree				_tree;	
		public:
			bidirectional_iterator(void): map_iterator<T, tree, is_const>(), _currentPos(0){_tree = tree();}
			bidirectional_iterator(tree Tree, node _node):map_iterator<T, tree, is_const>(_node), _tree(Tree){
				if (!_node) 
				{
					// std::cout << "NULL" << std::endl;
					this->_currentNode = NULL;
					this->_currentPos = 0;
				}
				else
				{
					// if (_node->parent)
					// std::cout << "dada val is " << _node->parent->data.first << std::endl;
					// else
						// std::cout << "1 dada is NULL" << std::endl;
					this->_currentNode = _node;
					this->_currentPos = _node->pos;
				}
				}
			bidirectional_iterator(const bidirectional_iterator<T, key_compare, allocator_type, false> &other):map_iterator<T, tree, is_const>(other._currentNode){*this = other;}
			~bidirectional_iterator(void){}
			// operator map_iterator<T, tree, is_const>()
			// {
			// 	return map_iterator<T, tree, is_const>(this->_currentNode);
			// }
			// * Assignment operator
			bidirectional_iterator &operator=(const bidirectional_iterator &other)
			{
				base::_currentNode = other._currentNode;
				_currentPos = other._currentPos;
				_tree = other._tree;
				return (*this);
			}
			// this worked
			// bidirectional_iterator& operator=(const bidirectional_iterator<T, key_compare, allocator_type, false>& other) const
			// {
			// 	base::_currentNode = other._currentNode;
			// 	_currentPos = other._currentPos;
			// 	_tree = other._tree;
			// 	return *this;
			// }
			// * Dereference operators
			// * Increment/decrement operators
			bidirectional_iterator&		operator++(void){_tree.sortAll(); this->_currentNode = _tree.search_node(this->_currentPos + 1); this->_currentPos++; return *this;}
			bidirectional_iterator&		operator--(void){_tree.sortAll(); this->_currentNode = _tree.search_node(this->_currentPos - 1); this->_currentPos--; return *this;}
			bidirectional_iterator		operator++(int){
				bidirectional_iterator tmp = *this;
				 _tree.sortAll();
				 this->_currentNode = _tree.search_node(this->_currentPos + 1);
				 this->_currentPos++; return tmp;
				}
			bidirectional_iterator		operator--(int){bidirectional_iterator tmp = *this; _tree.sortAll(); this->_currentNode = _tree.search_node(this->_currentPos - 1); this->_currentPos--; return tmp;}
			// * Comparison operators
			bool						operator!=(const bidirectional_iterator &other) const{ return (this->_currentNode != other._currentNode);}
			// template <bool U>
			// bool						operator!=(const bidirectional_iterator<T, key_compare, allocator_type, U>& other) const
			// {
			// 	return (base::_currentNode != other._currentNode);
			// }			
			bool						operator==(const bidirectional_iterator &other) const{ return (this->_currentNode == other._currentNode);}
	};

	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator==(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode == rhs._currentNode);}
	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator!=(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode != rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	bool	operator!=(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode != rhs._currentNode);}
	// 	template<class T, class T2, class key_compare, class allocator_type>
	// bool	operator!=(const ft::bidirectional_iterator<T, key_compare, allocator_type, true> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, false> &rhs){return (lhs._currentNode != rhs._currentNode);}

	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator<(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode < rhs._currentNode);}
	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator<=(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode <= rhs._currentNode);}
	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator>(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode > rhs._currentNode);}
	// template<class T, class key_compare, class allocator_type, bool is_const>
	// bool	operator>=(const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &lhs, const ft::bidirectional_iterator<T, key_compare, allocator_type, is_const> &rhs){return (lhs._currentNode >= rhs._currentNode);}
}

#endif