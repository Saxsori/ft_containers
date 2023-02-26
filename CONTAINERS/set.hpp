/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:29:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 10:42:22 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include <memory>
#include "./TOOLS/utility.hpp"
#include "../ITERATORS/set_iterator.hpp"
#include "./TOOLS/binary_search_tree_set.hpp"
#include "../ITERATORS/bidirectional_reverse_iterator.hpp"
#define MIN 1
#define MAX 2
#include "./Vector.hpp"
namespace ft
{
	/*
	set is 
	*/
    template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> > class set
	{
		public:
			typedef T																				key_type;
			typedef T																				value_type;
			typedef Compare																			key_compare;
			typedef Allocator																		allocator_type;
			typedef	value_type&																		reference;
			typedef	const value_type&																const_reference;
			typedef	value_type*																		pointer;
			typedef	const value_type*																const_pointer;
			typedef std::ptrdiff_t																	difference_type;
			typedef std::size_t																		size_type;
			typedef ft::node<value_type>															node_type;	
			typedef ft::binary_search_tree_set<value_type, key_compare, allocator_type>				tree_type;
			typedef ft::set_iterator<value_type, key_compare, tree_type, allocator_type, true>		iterator;
			typedef ft::set_iterator<value_type, key_compare, tree_type, allocator_type, true>		const_iterator;
			typedef ft::bidirectional_reverse_iterator<iterator>									reverse_iterator;
			typedef ft::bidirectional_reverse_iterator<const_iterator>								const_reverse_iterator;
			
			/*  			Constructors and destructor			*/
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc),_tree(){}
            set(const set& x)
            {
                *this = x;
            }
			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
			{
				for (InputIterator it = first; it != last; it++)
					this->insert(*it);
			}
            set& operator=(const set& x)
            {
                if (size())
                    erase(begin(), end());
                insert(x.begin(), x.end()); 
				return *this;        
            }
			~set(){}
			/*  			Nested class value_compare			*/
			/*
				* This class can be used to compare two elements to get whether the key of the first one goes before the second.
				? Function objects, also known as functors, are objects that can be used like functions.
				? object that can be invoked like a function, which typically acheive their goals by overloading 
				? the function call operator ().
				? They are used to encapsulate a function, or a set of functions, into a single object, which
				? can be used to costmize the behavior of other functions.
				* The arguments taken by this functor are of type value_type, which is a pair <const key_type,setped_type>.
				* The puplic member function operator() takes two arguments of type value_type and returns a bool.
				* Notice that the value_copare has no default constructor, therfore no objects can be directly
				* created from this nested class outside the set class.					
			*/
			class value_compare
			{
				friend class set;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x, y);
					}
			};
			/*					Capacity						*/
			bool							empty(void)const{return (_tree.root()==NULL || _tree.root() == _tree.getPastTheEnd());}
			size_type						size(void)const{return _tree.size();}
			size_type						max_size(void)const{return _tree.max_size();}
			/*					Iterator						*/
			iterator						begin(void)
			{
				if (_tree.root() == NULL)
					return iterator(_tree, _tree.getPastTheEnd());
				return iterator(_tree, _tree.getNode(_tree.root(), MIN));
			}
			const_iterator					begin(void)const
			{
				if (_tree.root() == NULL)
					return const_iterator(_tree, _tree.getPastTheEnd());
				return const_iterator(_tree, _tree.getNode(_tree.root(), MIN));
			}
				
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
            void                            clear(void)
            {
				if (size())
                	erase(begin(), end());
            }
			
			ft::pair<iterator,bool>			insert(const value_type& val)
			{
				if (_tree.find(val) == NULL || _tree.find(val) == _tree.getPastTheEnd())
				{
					_tree.insert(val);
					return ft::pair<iterator, bool>(iterator(_tree, _tree.find(val)), true);
				}
				else
					return ft::pair<iterator, bool>(iterator(_tree, _tree.find(val)), false);
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
				ft::vector<key_type> keys;
				for (iterator it = first; it != last; it++)
					keys.push_back(*it);
				for (size_t i = 0; i < keys.size(); i++)
					_tree.erase(_tree.find(keys[i])->data);
				
			}
			void							swap(set& x)
			{
				set temp;
				
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
			/*
			Lower bound: 
			Returns an iterator pointing to the first element in the container 
			that is not less than the given key. 
			
			Edge cases include:
			Key not found: Return first element > given key 
			Empty map: Returns the end iterator.
			Key less than all elements: Returns the begin iterator.
			Key greater than all elements: Returns the end iterator.
			Key equal to an element: Returns an iterator pointing to that element.

			*/
			iterator						lower_bound(const key_type& k)
			{				
				if (this->empty() || _comp(_tree.getNode(_tree.root(), MAX)->data, k))
					return (iterator(_tree, _tree.getPastTheEnd()));
				else if (_comp(k, _tree.getNode(_tree.root(), MIN)->data))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_tree.find(k))
					return iterator(_tree, _tree.find(k));
				else
				{
					ft::node<value_type> *node = _tree.getNode(_tree.root(), 1);
					if (!_tree.find(k))
					{
						while (true)
						{
							if (_comp(k, node->data))
								break ;
							node = _tree.incrementNodeByOne(node);
						}
					}
					return(iterator(_tree, node));
				}
			}
			const_iterator					lower_bound(const key_type& k) const
			{
				if (this->empty() || _comp(_tree.getNode(_tree.root(), MAX)->data, k))
					return (const_iterator(_tree, _tree.getPastTheEnd()));
				else if (_comp(k, _tree.getNode(_tree.root(), MIN)->data))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_tree.find(k))
					return const_iterator(_tree, _tree.find(k));
				else
				{
					ft::node<value_type> *node = _tree.getNode(_tree.root(), 1);
					if (!_tree.find(k))
					{
						while (true)
						{
							if (_comp(k, node->data))
								break ;
							node = _tree.incrementNodeByOne(node);
						}
					}
					return(const_iterator(_tree, node));
				}
			}
			/*
				Upper bound: 
				Returns an iterator pointing to the first element in the container 
				that is greater than the given key. 
				
				
				Edge cases include:
				Key is not found: Returns first element > the given key. 
				Empty map: Returns the end iterator.
				Key greater than all elements: Returns the end iterator.
				Key less than all elements: Returns the begin iterator.
				Key equal to an element: Returns an iterator pointing to the next element.

			*/
			iterator						upper_bound(const key_type& k)
			{
				if (this->empty() || _comp(_tree.getNode(_tree.root(), MAX)->data, k))
					return (iterator(_tree, _tree.getPastTheEnd()));
				else if (_comp(k, _tree.getNode(_tree.root(), MIN)->data))
					return (iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_tree.find(k))
					return iterator(_tree, _tree.incrementNodeByOne(_tree.find(k)));
				else
				{
					ft::node<value_type> *node = _tree.getNode(_tree.root(), 1);
					if (!_tree.find(k))
					{
						while (true)
						{
							if (_comp(k, node->data))
								break ;
							node = _tree.incrementNodeByOne(node);
						}
					}
					return(iterator(_tree, node));
				}
			}
			const_iterator					upper_bound(const key_type& k)const
			{
				if (this->empty() || _comp(_tree.getNode(_tree.root(), MAX)->data, k))
					return (const_iterator(_tree, _tree.getPastTheEnd()));
				else if (_comp(k, _tree.getNode(_tree.root(), MIN)->data))
					return (const_iterator(_tree, _tree.getNode(_tree.root(), MIN)));
				else if (_tree.find(k))
					return const_iterator(_tree, _tree.incrementNodeByOne(_tree.find(k)));
				else
				{
					ft::node<value_type> *node = _tree.getNode(_tree.root(), 1);
					if (!_tree.find(k))
					{
						while (true)
						{
							if (_comp(k, node->data))
								break ;
							node = _tree.incrementNodeByOne(node);
						}
					}
					return(const_iterator(_tree, node));
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
		private:
			key_compare 				_comp;
			allocator_type				_alloc;
			tree_type					_tree;
	};

	/*		Non-member function overloads		*/
	template <class T, class compare, class allocator>
	bool operator==(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class compare, class allocator>
	bool	operator!=(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs){return !(lhs == rhs);}
	template <class T, class compare, class allocator>
	bool	operator<(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs){return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
	template <class T, class compare, class allocator>
	bool	operator>(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs){return (rhs < lhs);}
	template <class T, class compare, class allocator>
	bool	operator<=(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs)
	{
		if (lhs.size() == rhs.size())
			return true;
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class compare, class allocator>
	bool	operator>=(const ft::set<T, compare, allocator>& lhs, const ft::set<T, compare, allocator>& rhs){return !(lhs < rhs);}
}


#endif