/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 08:00:02 by dfurneau         ###   ########.fr       */
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
		typedef T				value_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef	Tree			tree;
		typedef ft::node<T>*	node;
		mutable node 			_currentNode;
		map_iterator(void)
		{
			_currentNode = NULL;
		}
		map_iterator(node _node)
		{
			_currentNode = _node;
		}
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
		typedef const T			value_type;
		typedef const T*		pointer;
		typedef const T&		reference;
		typedef	Tree			tree;
		typedef ft::node<T>*	node;
		mutable node 			_currentNode;
		map_iterator(void)
		{
			_currentNode = NULL;
		}
		map_iterator(node _node)
		{
			_currentNode = _node;
		}
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
			typedef std::ptrdiff_t																difference_type;
			typedef ft::bidirectional_iterator_tag												iterator_category;
			typedef ft::binary_search_tree<T, key_compare, allocator_type>						tree;

			typedef typename ft::map_iterator<T, tree, is_const>::node															node;
			typedef ft::map_iterator<T, tree, is_const> 										base;
			
			mutable tree				_tree;	
		public:
			bidirectional_iterator(void): map_iterator<T, tree, is_const>(), _tree(){}
			bidirectional_iterator(tree Tree, node _node):map_iterator<T, tree, is_const>()
			{
				_tree = Tree;
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
			bidirectional_iterator(const bidirectional_iterator<T, key_compare, allocator_type, false> &other):map_iterator<T, tree, is_const>()
			{
				base::_currentNode = other._currentNode;
				_tree = other._tree;
			}

			bidirectional_iterator(const bidirectional_iterator<T, key_compare, allocator_type, true> &other):map_iterator<T, tree, true>()
			{
				base::_currentNode = other._currentNode;
				_tree = other._tree;
			}
			~bidirectional_iterator(void){}
			// * Assignment operator
			bidirectional_iterator &operator=(const bidirectional_iterator &other)
			{
				base::_currentNode = other._currentNode;
				_tree = other._tree;
				return (*this);
			}
			// * Dereference operators
			// * Increment/decrement operators
			bidirectional_iterator&		operator++(void){this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return *this;}
			bidirectional_iterator&		operator--(void){this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return *this;}
			bidirectional_iterator		operator++(int){bidirectional_iterator tmp = *this; this->_currentNode = _tree.incrementNodeByOne(this->_currentNode); return tmp;}
			bidirectional_iterator		operator--(int){bidirectional_iterator tmp = *this; this->_currentNode = _tree.decrementNodeByOne(this->_currentNode); return tmp;}
			// * Comparison operators
			bool						operator!=(const bidirectional_iterator &other) const{ return (this->_currentNode != other._currentNode);}			
			bool						operator==(const bidirectional_iterator &other) const{ return (this->_currentNode == other._currentNode);}
	};

	template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	bool	operator!=(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode != rhs._currentNode);}
	// template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	// bool	operator==(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode == rhs._currentNode);}
	// template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	// bool	operator<=(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode <= rhs._currentNode);}
	// template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	// bool	operator>=(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode >= rhs._currentNode);}
	// template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	// bool	operator<(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode < rhs._currentNode);}
	// template<class pair1, class pair2, class comp1, class comp2,  class alloc1, class alloc2, bool isC1, bool isC2>
	// bool	operator>(const ft::bidirectional_iterator<pair1, comp1, alloc1, isC1> &lhs, const ft::bidirectional_iterator<pair2, comp2, alloc2, isC2> &rhs){return (lhs._currentNode > rhs._currentNode);}
}

#endif