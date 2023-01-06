/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:37:18 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/06 22:31:37 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iterator.hpp>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T>>
	class Vector
	{
		public:
			/*						MEMBER 	TYPES							*/
			typedef	T										value_type;
			typedef	Alloc									allocator_type;
			typedef value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef	size_t									size_type;
			typedef	ft::iterator<value_type>				iterator;
		private:
			size_type			_size;
			pointer				_data;
			static size_type	_max_size = 1073741823;
			void				_resize(int newSize)
			{
				pointer	temp = new value_type [newSize];
				if (newSize > _size)
				{
					for (size_t i = 0; i < _size; i++)
						temp[i] = _data[i];
				}
				else
				{
					for (size_t i = 0; i < _size; i++)
						temp[i] = _data[i];	
				}
			}
		public:
			/*						MEMBER 	FUNCTIONS						*/
			// ? iterators
			iterator	begin(){return iterator(_data);}
			iterator	end(){return iterator(_data + _size);}
			// ? capacity
			size_type	size()const{return _size;}
			size_type	max_size()const{return _size;}
			size_type	capacity()const{return _size;}
			bool		empty()const{if(!_size)return(true);return(false);}
			// ? 
			void push_back(const value_type& val)
			{
				_size++;
				// take a copy in a temp
				// resize the array
				// copy the content and add the val
			}
			
			Vector():_data(NULL), _size(0){}
			~Vector(){delete _data;}
	};
}

#endif
