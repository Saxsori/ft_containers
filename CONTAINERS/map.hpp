/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:43:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/20 22:48:00 by aaljaber         ###   ########.fr       */
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
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc){_tree = ft::binary_search_tree<value_type, key_compare>(_comp);}
			explicit map(const &map x){*this = x;}
			~map(){clear();}
			map& operator=(const map& x)
			{
				clear();
				_alloc = x.get_allocator();
				// _tree = x._tree;
				return *this;
			}
			/*  			Nested class value_compare			*/
			/*
				* This class can be used to compare two elements to get whether the key of the first one goes before the second.
				? Function objects, also known as functors, are objects that can be used like functions.
				? object that can be invoked like a function, which typically acheive their goals by overloading 
				? the function call operator ().
				? They are used to encapsulate a function, or a set of functions, into a single object, which
				? can be used to costmize the behavior of other functions.
				* The arguments taken by this functor are of type value_type, which is a pair <const key_type,mapped_type>.
				* The puplic member function operator() takes two arguments of type value_type and returns a bool.
				* Notice that the value_copare has no default constructor, therfore no objects can be directly
				* created from this nested class outside the map class.					
			*/
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					typedef bool result_type;
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			// Return value comparison object
			value_compare value_comp() const{return value_compare(_comp);}

			/*				get_allocator					*/
			allocator_type get_allocator() const{return allocator_type();}
			
			private:
				// key_compare 										_comp;
				allocator_type 										_alloc;
				ft::binary_search_tree<value_type, key_compare>		_tree;
	};

}


#endif