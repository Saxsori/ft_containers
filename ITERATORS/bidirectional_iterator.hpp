/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:11 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/27 23:04:33 by aaljaber         ###   ########.fr       */
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
			typedef ft::binary_search_tree<value_type, key_compare>::SortedTree		SortedTree;
			
		private:
			node				_currentNode;
			SortedTree			_tree;
			
		public:
			bidirectional_iterator(void);
			// bidirectional_iterator(pointer ptr);
			~bidirectional_iterator(void);
			bidirectional_iterator(const bidirectional_iterator &other);
			// * Assignment operator
			bidirectional_iterator& operator=(const bidirectional_iterator &other);
			pointer getPointer(void) const;
			// * Dereference operators
			reference operator*(void) const;
			pointer operator->(void) const;
			// * Increment/decrement operators
			bidirectional_iterator&	operator++(void);
			bidirectional_iterator&	operator--(void);
			bidirectional_iterator	operator++(int);
			bidirectional_iterator	operator--(int);
			// * Comparison operators
			bool operator==(const bidirectional_iterator &other) const;
			bool operator!=(const bidirectional_iterator &other) const;
	};
}

#endif