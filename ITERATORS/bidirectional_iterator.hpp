/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/30 00:22:50 by aaljaber         ###   ########.fr       */
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
	template <class T, class key_compare, class allocator_type>
	class bidirectional_iterator
	{
		public:
			typedef T																													value_type;
			typedef T*																													pointer;
			typedef T&																													reference;
			typedef std::ptrdiff_t																										difference_type;
			typedef ft::bidirectional_iterator_tag																						iterator_category;
			typedef ft::binary_search_tree<typename value_type::first_type, typename value_type::second_type, key_compare, allocator_type>				tree;
			typedef typename tree::Node																									node;
			
		private:
			node				_currentNode;
			size_t				_currentPos;
			tree				_tree;	
		public:
			bidirectional_iterator(void):_currentNode(NULL),_currentPos(0){_tree();}
			bidirectional_iterator(node _node):_currentNode(_node){}
			template <class U> bidirectional_iterator(const bidirectional_iterator<U> &other):_currentNode(NULL){_currentNode = other._currentNode; _currentPos = other._currentPos; _tree = other._tree}
			~bidirectional_iterator(void){}
			bidirectional_iterator(const bidirectional_iterator &other){*this = other;}
			// * Assignment operator
			bidirectional_iterator& operator=(const bidirectional_iterator &other){_currentNode = other._currentNode; _currentPos = other._currentPos; _tree = other._tree; return *this;}
			// pointer getPointer(void) const;
			// * Dereference operators
			reference operator*(void) const{ return _currentNode->data; }
			pointer operator->(void) const{ return &(_currentNode->data);}
			// * Increment/decrement operators
			bidirectional_iterator&	operator++(void){_tree.sortedIterator(_tree.root(), _currentPos + 1); _currentNode = _tree.nodeSearched; _currentPos++; return *this;}
			bidirectional_iterator&	operator--(void){_tree.sortedIterator(_tree.root(), _currentPos - 1); _currentNode = _tree.nodeSearched; _currentPos++;return *this;}
			bidirectional_iterator	operator++(int){bidirectional_iterator tmp = *this; _tree.sortedIterator(_tree.root(), _currentPos + 1); _currentNode = _tree.nodeSearched; _currentPos++; return tmp;}
			bidirectional_iterator	operator--(int){bidirectional_iterator tmp = *this; _tree.sortedIterator(_tree.root(), _currentPos - 1); _currentNode = _tree.nodeSearched; _currentPos++; return tmp;}
			// * Comparison operators
			bool operator==(const bidirectional_iterator &other) const{ return (_currentNode == other._currentNode);}
			bool operator!=(const bidirectional_iterator &other) const{ return (_currentNode != other._currentNode);}
	};
}

#endif