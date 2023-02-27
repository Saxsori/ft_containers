/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 19:50:43 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include "../CONTAINERS/TOOLS/binary_search_tree_map.hpp"

/*
	bidirectional_iterator is a derived class of iterator
	which is a derived class of std::iterator
	it allows to iterate over a container in a bidirectional manner
	which means that it can be incremented and decremented by 1
	which is not the case with random_access_iterator
*/

namespace ft
{
	template<class T, bool is_const> class bidirectional_iterator {};
	template<class T>
	class bidirectional_iterator<T, false>
	{	
		public:
		typedef T				value_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef ft::node<T>*	node;
		mutable node 			_currentNode;
		bidirectional_iterator(void) {_currentNode = NULL;}
		bidirectional_iterator(node _node) {_currentNode = _node;}
		T& operator*(void) const {return (_currentNode->data);}
		T* operator->(void) const {return (&_currentNode->data);}	
		~bidirectional_iterator(void) {}
	};
	template<class T>
	class bidirectional_iterator<T, true>
	{
		public:
		typedef const T			value_type;
		typedef const T*		pointer;
		typedef const T&		reference;
		typedef ft::node<T>*	node;
		mutable node 			_currentNode;
		bidirectional_iterator(void) {_currentNode = NULL;}
		bidirectional_iterator(node _node) {_currentNode = _node;}
		const T& operator*(void) const {return (_currentNode->data);}
		const T* operator->(void) const {return (&_currentNode->data);}
		~bidirectional_iterator(void) {}
	};
}

#endif