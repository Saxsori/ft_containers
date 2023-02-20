/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:43:23 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/20 02:55:27 by aaljaber         ###   ########.fr       */
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
#include <vector>
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
			map(const map& x){*this = x;}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
			{
				for (InputIterator it = first; it != last; it++)
					this->insert(*it);
			}
			map& operator=(const map& x)
			{
				_alloc = x.get_allocator();
				_tree = x._tree;
				return *this;
			}
			~map(){}
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
			bool							empty(void)const{return (_tree.root()==NULL || _tree.root() == _tree.getPastTheEnd());}
			size_type						size(void)const{return _tree.size();}
			size_type						max_size(void)const{return _tree.max_size();}
			/*					Iterator						*/
			iterator						begin(void){return iterator(_tree, _tree.getNode(_tree.root(), MIN));}
			const_iterator					begin(void)const{return const_iterator(_tree, _tree.getNode(_tree.root(), MIN));}
				
			iterator						end(void){return iterator(_tree, _tree.getPastTheEnd());}
			const_iterator					end(void)const{return const_iterator(_tree, _tree.getPastTheEnd());}
			reverse_iterator				rbegin(void){return reverse_iterator(end());}
			const_reverse_iterator			rbegin(void)const{return const_reverse_iterator(end());}
			reverse_iterator				rend(void){return reverse_iterator(begin());}
			const_reverse_iterator			rend(void)const{return const_reverse_iterator(begin());}
			/*					Observers						*/
			value_compare					value_comp(void)const{return value_compare(key_compare());}
			key_compare						key_comp(void)const{return (key_compare());}
			/*					get_allocator					*/
			allocator_type					get_allocator(void) const{return allocator_type();}
			/* 					Modifiers						*/
			void 							clear(void){_tree.clear();}
			
			ft::pair<iterator,bool>			insert(const value_type& val)
			{
				if (_tree.find(val.first) == NULL || _tree.find(val.first) == _tree.getPastTheEnd())
				{
					_tree.insert(val);
					return ft::pair<iterator, bool>(iterator(_tree, _tree.find(val.first)), true);
				}
				else
					return ft::pair<iterator, bool>(iterator(_tree, _tree.find(val.first)), false);
			}
			iterator						insert(iterator position, const value_type& val)
			{
				(void)position;
				return(this->insert(val).first);
			}
			template <class InputIterator>
			void							insert(InputIterator first, InputIterator last)
			{
				for (InputIterator it = first; it != last; it++)
					this->insert(*it);
			}
			void							erase(iterator position)
			{
				if (position == this->end())
					return ;
				_tree.erase(*position);
			}
			size_type						erase(const key_type& k)
			{
				if (!_tree.find(k))
					return 0;
				_tree.erase(_tree.find(k)->data);
				return 1;
			}
			void							erase(iterator first, iterator last)
			{
				std::vector<key_type> keys;
				for (iterator it = first; it != last; it++)
					keys.push_back(it->first);
				for (size_t i = 0; i < keys.size(); i++)
				{
					_tree.erase(_tree.find(keys[i])->data);
				}
				
			}
			void							swap(map& x)
			{
				map temp;
				
				temp._alloc = _alloc;
				temp._comp = _comp;
				
				_comp = x._comp;
				_alloc = x._alloc;

				x._comp = temp._comp;
				x._alloc = temp._alloc;
				_tree.swap(x._tree);
			}
			/*					Operations						*/
			iterator						find(const key_type& k)
			{
				if (_tree.find(k))
					return iterator(_tree, _tree.find(k));
				return iterator(_tree, _tree.getPastTheEnd());
			}
			const_iterator					find(const key_type& k)const
			{
				if (_tree.find(k))
					return const_iterator(_tree, _tree.find(k));
				return const_iterator(_tree, _tree.getPastTheEnd());
			}
			size_type 						count(const key_type& k) const
			{
				if (_tree.find(k))
					return 1;
				return 0;
			}
			iterator						lower_bound(const key_type& k)
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->data.first))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->data.first, k))
					return (iterator(_tree, _tree.getPastTheEnd()));
				else
					return iterator(_tree, _tree.find(k));
			}
			const_iterator					lower_bound(const key_type& k) const
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->data.first))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->data.first, k))
					return (const_iterator(_tree, _tree.getPastTheEnd()));
				else
					return iterator(_tree, _tree.find(k));
			}
			iterator						upper_bound(const key_type& k)
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->data.first))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->data.first, k) || _tree.getNode(_tree.root(), MAX)->data.first == k)
					return (iterator(_tree, _tree.getPastTheEnd()));
				else
				{
					if (_tree.find(k)->pos == _tree.getNode(_tree.root(), MAX)->pos)

						return iterator(_tree, _tree.find(k));
					else
						return iterator(_tree, _tree.search_node(_tree.find(k)->pos + 1));
				}
			}
			const_iterator					upper_bound(const key_type& k)const
			{
				if (_comp(k, _tree.getNode(_tree.root(), MIN)->data.first))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_comp(_tree.getNode(_tree.root(), MAX)->data.first, k) ||  _tree.getNode(_tree.root(), MAX)->data.first == k)
					return (const_iterator(_tree, _tree.getPastTheEnd()));
				else
				{
					if (_tree.find(k)->pos == _tree.getNode(_tree.root(), MAX)->pos)
						return const_iterator(_tree, _tree.find(k));
					else
						return const_iterator(_tree, _tree.search_node(_tree.find(k)->pos + 1));
				}	
			}
			ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				return (ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}
			ft::pair<iterator,iterator>		equal_range(const key_type& k)
			{
				return (ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}
			/*					Element access					*/
			mapped_type&					operator[](const key_type& k)
			{
				if (_tree.find(k))
					return(_tree.find(k)->data.second);
				else
				{
					_tree.insert(ft::pair<const key_type, mapped_type>(k, mapped_type()));
					return (_tree.find(k)->data.second);
				}
			}		
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