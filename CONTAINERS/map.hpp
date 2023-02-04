/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:43:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/04 17:11:56 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "./TOOLS/utility.hpp"
#include "../ITERATORS/bidirectional_iterator.hpp"
#include "./TOOLS/binary_search_tree.hpp"
#include "../ITERATORS/bidirectional_reverse_iterator.hpp"
#define MIN 1
#define MAX 2
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
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > class map
	{
		public:
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef ft::pair<const Key, T>															value_type;
			typedef Compare																			key_compare;
			typedef Allocator																		allocator_type;
			typedef	value_type&																		reference;
			typedef	const value_type&																const_reference;
			typedef	value_type*																		pointer;
			typedef	const value_type*																const_pointer;
			typedef ft::bidirectional_iterator<value_type, key_compare, allocator_type, false>		iterator;
			typedef ft::bidirectional_iterator<value_type, key_compare, allocator_type, true>		const_iterator;
			typedef ft::bidirectional_reverse_iterator<iterator>									reverse_iterator;
			typedef ft::bidirectional_reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef std::ptrdiff_t																	difference_type;
			typedef std::size_t																		size_type;
			typedef ft::node<value_type>															node_type;	
			typedef ft::binary_search_tree<value_type, key_compare, allocator_type>					tree_type;
			
			/*  			Constructors and destructor			*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc){_tree = tree_type();}
			explicit map(const map& x){*this = x;}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
			{
				for (InputIterator it = first; it != last; it++)
					_tree.insert(*it);
			}
			~map(){}
			map& operator=(const map& x)
			{
				_alloc = x.get_allocator();
				_tree = x._tree;
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
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			/*					Capacity						*/
			bool						empty()const{return (_tree.root()==NULL);}
			size_type					size()const{return _tree.size();}
			size_type					max_size()const{return _tree.max_size();}
			/*					Iterator						*/
			iterator					begin(void){return iterator(_tree, _tree.getNode(_tree.root(), MIN));}
			const_iterator				begin()const{return const_iterator(_tree, _tree.getNode(_tree.root(), MIN));}
			iterator					end(){return iterator(_tree, _tree.getNode(_tree, _tree.root(), MAX));}
			const_iterator				end()const{return const_iterator(_tree, _tree.getNode(_tree.root(), MAX));}
			// reverse_iterator			rbegin(){return reverse_iterator(end());}
			// const_reverse_iterator		rbegin()const{return const_reverse_iterator(end());}
			// reverse_iterator			rend(){return reverse_iterator(begin());}
			// const_reverse_iterator		rend()const{return const_reverse_iterator(begin());}
			/*					Observers						*/
			value_compare				value_comp()const{return value_compare(_comp);}
			key_compare					key_comp()const{return _comp;}
			/*					get_allocator					*/
			allocator_type				get_allocator() const{return allocator_type();}
			/* 					Modifiers						*/
			// void 						clear(){_tree.clear();}
			/*					Operations						*/
			// iterator					find(const key_type& k){return iterator(_tree, _tree.find(k));}
			// const_iterator				find(const key_type& k)const{return const_iterator(_tree, _tree.find(k));}
			// size_type 					count(const key_type& k) const{(void)k; return 1;}
			iterator					lower_bound(const key_type& k)
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->first))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->first, k))
					return (iterator(_tree, _tree.getNode(_tree.root(), MAX)));
				else
					return iterator(_tree, _tree.find(k));
			}
			const_iterator				lower_bound(const key_type& k) const
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->first))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->first, k))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MAX)));
				else
					return const_iterator(_tree, _tree.find(k));
			}
			iterator					upper_bound(const key_type& k)
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->first))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->first, k))
					return (iterator(_tree, _tree.getNode(_tree.root(), MAX)));
				else
				{
					if (_tree.find(k)->pos == _tree.getNode(_tree.root(), MAX)->pos)
						return iterator(_tree, _tree.find(k));
					else
						return iterator(_tree, _tree.search_node(_tree.find(k)->pos + 1));
				}
			}
			const_iterator				upper_bound(const key_type& k)const
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->first))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->first, k))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MAX)));
				else
				{
					if (_tree.find(k)->pos == _tree.getNode(_tree.root(), MAX)->pos)
						return const_iterator(_tree, _tree.find(k));
					else
						return const_iterator(_tree, _tree.search_node(_tree.find(k)->pos + 1));
				}	
			}
			
			
			/*					Element access					*/
			
			
			
		private:
			key_compare 				_comp;
			allocator_type				_alloc;
			tree_type					_tree;
	};

	/*		Non-member function overloads		*/
	template <class key, class T, class compare, class allocator>
	bool operator==(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class key, class T, class compare, class allocator>
	bool	operator!=(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs){return !(lhs == rhs);}
	template <class key, class T, class compare, class allocator>
	bool	operator<(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs){return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
	template <class key, class T, class compare, class allocator>
	bool	operator>(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs){return (rhs < lhs);}
	template <class key, class T, class compare, class allocator>
	bool	operator<=(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs)
	{
		if (lhs.size() == rhs.size())
			return true;
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class key, class T, class compare, class allocator>
	bool	operator>=(const ft::map<key, T, compare, allocator>& lhs, const ft::map<key, T, compare, allocator>& rhs){return !(lhs < rhs);}
}


#endif