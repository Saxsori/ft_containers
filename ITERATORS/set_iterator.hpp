/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:01:49 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/27 19:31:10 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP
#include "./bidirectional_iterator.hpp"
# include "../CONTAINERS/TOOLS/binary_search_tree_map.hpp"
#include "./iterator.hpp"

namespace ft
{
	template <class T, class key_compare, class tree_type, class allocator_type, bool is_const>
	class set_iterator:public ft::bidirectional_iterator <T, is_const>
	{
		public:
			typedef std::ptrdiff_t																difference_type;
			typedef ft::bidirectional_iterator_tag												iterator_category;
			typedef typename ft::bidirectional_iterator<T, is_const>::node							node;
			typedef ft::bidirectional_iterator<T, is_const> 										base;
			mutable tree_type																		_tree;	
			set_iterator(void){}
			set_iterator(tree_type Tree, node _node):bidirectional_iterator<T, is_const>(), _tree(Tree)
			{
				if (!_node)
					this->_currentNode = NULL;
				else
					this->_currentNode = _node;
			}
			/*
				when having this only it doens't compile error .. and pass all the cases
				but without the true overload .. for some reason it doesn't know where to go
				and enters an infinite loop
			*/
			set_iterator(const set_iterator<T, key_compare, tree_type, allocator_type, false> &other):bidirectional_iterator<T, is_const>(other._currentNode), _tree(other._tree){}

			set_iterator(const set_iterator<T, key_compare, tree_type, allocator_type, true> &other):bidirectional_iterator<T, is_const>(other._currentNode), _tree(other._tree) {}

			~set_iterator(void){}
			// * Assignment operator
			set_iterator &operator=(const set_iterator &other) {base::_currentNode = other._currentNode; _tree = other._tree; return (*this);}
			// * Dereference operators
			// * Increment/decrement operators
			set_iterator&		operator++(void){this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return *this;}
			set_iterator&		operator--(void){this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return *this;}
			set_iterator		operator++(int){set_iterator tmp = *this; this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return tmp;}
			set_iterator		operator--(int){set_iterator tmp = *this; this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return tmp;}
			// * Comparison operators
			bool						operator!=(const set_iterator &other) const{ return (this->_currentNode != other._currentNode);}			
			bool						operator==(const set_iterator &other) const{ return (this->_currentNode == other._currentNode);}
	};

	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator!=(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode != rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator==(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode == rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator>=(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode >= rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator<=(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode <= rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator<(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode < rhs._currentNode);}
	template<class pair1, class pair2, class comp1, class comp2, class alloc1, class alloc2, class tree_type1, class tree_type2, bool isC1, bool isC2>
	bool	operator>(const ft::set_iterator<pair1, comp1, tree_type1, alloc1, isC1> &lhs, const ft::set_iterator<pair2, comp2, tree_type2, alloc2, isC2> &rhs){return (lhs._currentNode > rhs._currentNode);}

}
#endif