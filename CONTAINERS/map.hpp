/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:43:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/20 21:05:47 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "./TOOLS/utility.hpp"
#include "./ITERATORS/bidirectional_iterator.hpp"
#include "./ITERATORS/reverse_iterator.hpp"
#include "./TOOLS/map_tools.hpp"
namespace ft
{
	/*
		map is a sorted associative container that contains key-value pairs with unique keys.
		Search, removal, and insertion operations have logarithmic complexity.
		map is usually implemented as red-black tree.
		
		map is templated on the following types:
		- Key: the type of the keys.
		- T: the type of the mapped values.
		- Compare: the type of the comparison function object which defaults to std::less<Key>.
		- Allocator: the type of the allocator object which defaults to std::allocator<ft::pair<const Key, T>>.
		the comparison function object must induce a strict weak ordering taking two arguments of type Key
		and returning a value convertible to bool.
		The expression comp(a,b), where comp is an object of the comparison type and a and b are key values,
		must return true if a is considered to go before b in the strict weak ordering the function defines.
		std::less<Key> is a comparison function object that returns the same as applying the less-than operator (<)
		to its arguments.
	*/
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>>> class map
	{
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const Key, T>								value_type;
			typedef Compare												key_compare;
			typedef value_comp											value_compare;
			typedef Allocator											allocator_type;
			typedef	allocator_type::reference							reference;
			typedef	allocator_type::const_reference						const_reference;
			typedef	allocator_type::pointer								pointer;
			typedef	allocator_type::const_pointer						const_pointer;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;
			typedef ft::bidirectional_iterator<value_type>				iterator;
			typedef ft::bidirectional_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			
			/*  			Constructors and destructor			*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				(void)comp;
				(void)alloc;
			}
			
			
	};

}


#endif