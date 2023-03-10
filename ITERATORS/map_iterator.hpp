/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:55:33 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/28 06:15:40 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "./bidirectional_iterator.hpp"
#include "./iterator.hpp"

namespace ft
{
	template <class T, class key_compare, class tree_type, class allocator_type, bool is_const>
	class map_iterator:public ft::bidirectional_iterator <T, is_const>
	{
		public:
			typedef std::ptrdiff_t																difference_type;
			typedef ft::bidirectional_iterator_tag												iterator_category;
			typedef typename ft::bidirectional_iterator<T, is_const>::node							node;
			typedef ft::bidirectional_iterator<T, is_const> 										base;
			
			mutable tree_type																		_tree;	
			
			map_iterator(void){}
			map_iterator(tree_type Tree, node _node):bidirectional_iterator<T, is_const>(_node),_tree(Tree){}
			
			map_iterator(const map_iterator<T, key_compare, tree_type, allocator_type, false> &other):bidirectional_iterator<T, is_const>(other._currentNode), _tree(other._tree){}

			map_iterator(const map_iterator<T, key_compare, tree_type, allocator_type, true> &other):bidirectional_iterator<T, true>(other._currentNode), _tree(other._tree){}
			~map_iterator(void){}
			// * Assignment operator
			map_iterator&				operator=(const map_iterator &other) {this->_currentNode = other._currentNode; _tree = other._tree; return (*this);}
			// * Dereference operators
			// * Increment/decrement operators
			map_iterator&				operator++(void){this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return *this;}
			map_iterator&				operator--(void){this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return *this;}
			map_iterator				operator++(int){map_iterator tmp = *this; this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return tmp;}
			map_iterator				operator--(int){map_iterator tmp = *this; this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return tmp;}
			// * Comparison operators
			bool						operator!=(const map_iterator &other) const{ return (this->_currentNode != other._currentNode);}			
			bool						operator==(const map_iterator &other) const{ return (this->_currentNode == other._currentNode);}
	};

	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator!=(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode != rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator==(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode == rhs._currentNode);}
	
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator<=(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode <= rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator>=(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode >= rhs._currentNode);}

	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator<(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode < rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator>(const ft::map_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::map_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode > rhs._currentNode);}
}
#endif