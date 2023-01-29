/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/29 08:36:08 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include "./iterator.hpp"
# include "../CONTAINERS/TOOLS/utility.hpp"
# include "../CONTAINERS/TOOLS/map_tools.hpp"

/*
	bidirectional_iterator is a derived class of iterator
	which is a derived class of std::iterator
	it allows to iterate over a container in a bidirectional manner
	which means that it can be incremented and decremented by 1
	which is not the case with random_access_iterator
*/
namespace ft
{
	template <class value_type, class key_compare>
	class bidirectional_iterator
	{
		public:
			typedef value_type														value_type;
			typedef value_type*														pointer;
			typedef value_type&														reference;
			typedef std::ptrdiff_t													difference_type;
			typedef ft::bidirectional_iterator_tag									iterator_category;
			typedef ft::binary_search_tree<value_type, key_compare>::Node			node;
			typedef ft::binary_search_tree<value_type, key_compare>					tree;
			
		private:
			node				_currentNode;
			size_t				_currentPos;
			tree				_tree;	
		public:
			bidirectional_iterator(void):_currentNode(NULL),_currentPos(0){_tree();}
			// bidirectional_iterator(pointer ptr);
			~bidirectional_iterator(void){}
			bidirectional_iterator(const bidirectional_iterator &other){*this = other;}
			// * Assignment operator
			bidirectional_iterator& operator=(const bidirectional_iterator &other){_currentNode = other._currentNode; _currentPos = other._currentPos; _tree = other._tree; return *this;}
			// pointer getPointer(void) const;
			// * Dereference operators
			reference operator*(void) const{ return _currentNode->data; }
			pointer operator->(void) const{ return &(_currentNode->data);}
			// * Increment/decrement operators
			bidirectional_iterator&	operator++(void){bst.sortedIterator(bst.root(), _currentPos + 1); _currentNode = _tree.nodeSearched; _currentPos++; return *this;}
			bidirectional_iterator&	operator--(void){bst.sortedIterator(bst.root(), _currentPos - 1); _currentNode = _tree.nodeSearched; _currentPos++;return *this;}
			bidirectional_iterator	operator++(int){bidirectional_iterator tmp = *this; bst.sortedIterator(bst.root(), _currentPos + 1); _currentNode = _tree.nodeSearched; _currentPos++; return tmp;}
			bidirectional_iterator	operator--(int){bidirectional_iterator tmp = *this; bst.sortedIterator(bst.root(), _currentPos - 1); _currentNode = _tree.nodeSearched; _currentPos++; return tmp;}
			// * Comparison operators
			bool operator==(const bidirectional_iterator &other) const{ return (_currentNode == other._currentNode);}
			bool operator!=(const bidirectional_iterator &other) const{ return (_currentNode != other._currentNode);}
	};
}

#endif