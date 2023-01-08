/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:37:18 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/08 23:32:04 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator.hpp>

namespace ft
{
	/*
	? 'T' is the type of the elements stored in the vector
	? 'Alloc' is the allocator type that specifies how the vector should allocate memory for its elements
	? it's an object that is responsible for allocating and deallocating memory for the elements of the vector.
	* The meaning and purpose of the second template parameter, 'Alloc',
	* is to specify the allocator type to be used by the std::vector class.
	* This allows the std::vector class to be flexible and generic,
	* as it can be used with a wide range of allocator types.
	* By default, the std::allocator class is used, 
	* which is a simple allocator that uses the global new and delete operators 
	* to allocate and deallocate memory.
	
	? The reason why the std::alocator is included as a template param rather than
	? being declared later in the class definition:
	* By default, std::vector uses std::allocator<T> as its allocator type. 
	* However, std::vector allows u to specify a different allocator type as the 
	* second template parameter if u need to use a different memory management strategy.
	* meaning if u want to use a custom allocator, if u need to allocate memory from a specific memory pool, 
	* or if u want to use a custom memory allocation algorithm. 

	*/
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
			allocator_type		_allocator;
			size_type			_size;
			size_type			_capacity; // ? amount of storage space that has been allocated
			pointer				_data;
		public:
			/*						MEMBER 	FUNCTIONS						*/
			// ? iterators
			iterator	begin(){return iterator(_data);}
			iterator	end(){return iterator(_data + _size);}
			// ? capacity
			size_type	size()const{return _size;}
			size_type	max_size()const{return std::allocator_traits<allocator_type>::max_size(_allocator);} // * std::allocator_traits used to obtain the max_size value for the allocator_type used by ft::vector
			size_type	capacity()const{return _capacity;}
			bool		empty()const{return (_size == 0) ? true : false;}
			// ? 
			void push_back(const_reference val)
			{
				// ? if the vector is full, to reallocate
				if (_size == _capacity)
				{
					/*
						* the vector could be empty ,, so it does need to be allocated for the first time for one 1 block of memory
						* otherwise the capacity will be doubled,, this technique used to avoid the overhead of repeatedly 
						* allocating and the deallocating small blocks of memory in each time of adding or removing an element in the vector,
						* since this process can be a time-consuming 
						* so it will improve the performance by reducing the time and resources required to manage the memory used by the vector
					*/
					pointer newData = _allocator.allocate((_capacity == 0) ? 1 : (_capacity * 2));
					std::copy(_data, _data + _size, newData);
					_allocator.deallocate(_data, ((_capacity == 0) ? 1 : _capacity));
					_data = newData;
					_capacity = (_capacity == 0) ? 1 : (_capacity * 2);
				}
				// ? adding the val
				_allocator.construct(_data + _size, val);
				_size++;
			}	
			/*
				* the 'explicit' used to prevent implicit type conversions, which it can lead to unintended behavior
				* ex. ft::Vector<int> myvector = 5; this will run and compile without any error 
				* so without the explicit keyword, the class allows implicit type conversions from int to vector
			*/
			/*						CONSTRUCTORS						*/
			// ? default constructor
			explicit vector (const allocator_type& alloc):_data(NULL), _size(0),_capacity(0),_allocator(alloc){};
			~Vector(){_allocator.deallocate(_data, ((_capacity == 0) ? 1 : _capacity));}
	};
}

#endif
