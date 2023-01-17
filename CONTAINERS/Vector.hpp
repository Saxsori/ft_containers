/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:37:18 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/17 17:25:28 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <algorithm>
#include "../ITERATORS/random_access_iterator.hpp"
#include "./container_utils.hpp"
#include "../ITERATORS/reverse_iterator.hpp"

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
	template <class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			/*						MEMBER 	TYPES							*/
			typedef	T													value_type;
			typedef	Alloc												allocator_type;
			typedef	 size_t												size_type;
			typedef  std::ptrdiff_t										difference_type;
			typedef value_type&											reference;
			typedef	const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef	ft::random_access_iterator<value_type>				iterator;
			typedef	ft::random_access_iterator<const value_type>		const_iterator;
			typedef	ft::reverse_iterator<iterator>						reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			allocator_type		_allocator;
			pointer				_data;
			size_type			_size;
			size_type			_capacity; // ? amount of storage space that has been allocated
			void				_refill(size_type n, const_reference val)
			{
				for (size_t i = 0; i < n; i++)
				{
					_allocator.destroy(_data + i);
					_allocator.construct(_data + i, val);
				}
			}
			void				_refill(size_type n, pointer new_data, pointer old_data)
			{
				for (size_type i = 0; i < n; i++)
				{
					_allocator.construct(new_data + i, old_data[i]);
					_allocator.destroy(old_data + i);
				}
			}
			template <class InputIterator>
			void				_refill(InputIterator begin, InputIterator end)
			{
				int i = 0;for (InputIterator it = begin; it != end; it++)
				{
					_allocator.destroy(_data);
					_allocator.construct(&_data[i++], *it);
				}
			}
			void				_destroy(pointer data, size_type size)
			{
				for (size_type i = 0; i < size; i++)
					_allocator.destroy(data + i);
			}
		public:
			/*						MEMBER 	FUNCTIONS						*/
			// !						ITERATORS						// 
			iterator							begin(void){return iterator(&_data[0]);}
			iterator							end(void){return iterator(&_data[_size]);}
			const_iterator						begin(void)const{return const_iterator(&_data[0]);}
			const_iterator						end(void)const{return const_iterator(&_data[_size]);}
			reverse_iterator					rbegin(void){return reverse_iterator(end());}
			reverse_iterator					rend(void){return reverse_iterator(begin());}			
			// !						CAPACITY						//
			size_type		size(void)const{return _size;}
			size_type		max_size(void)const{return _allocator.max_size();} // * std::allocator_traits used to obtain the max_size value for the allocator_type used by ft::vector
			size_type		capacity(void)const{return _capacity;}
			bool			empty(void)const{return (_size == 0) ? true : false;}
			void			reserve(size_type n)
			{
				pointer new_data;
				if (n > _capacity)
				{
					new_data = _allocator.allocate(n);
					_refill(_size, new_data, _data);
					_allocator.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = n;
				}
			}
			void			resize(size_type n, value_type val = value_type())
			{
				if (n < _capacity)
				{
					if (n > _size)
					{
						for (size_t i = _size - 1; i < n; i++)
							this->push_back(val);						
					}
					else if (n < _size)
					{
						for (size_t i = n - 1; i < _size; i++)
							this->pop_back();
					}
				}
				else
				{
					reserve(n);
					for (size_t i = _size - 1; i < n; i++)
						this->push_back(val);
				}
				_size = n;
			}
			
			// !						MODIFIERS						//
			void 			push_back(const_reference val) // todo : this can be short using reserve
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
					// pointer newData = _allocator.allocate((_capacity == 0) ? 1 : (_capacity * 2));
					// std::copy(_data, _data + _size, newData);
					// _allocator.deallocate(_data, ((_capacity == 0) ? 1 : _capacity));
					// _data = newData;
					// _capacity = (_capacity == 0) ? 1 : (_capacity * 2);
					reserve((_capacity == 0) ? 1 : (_capacity * 2));
				}
				// ? adding the val
				_allocator.construct(_data + _size, val); // construct a new object that holds the same state as the old one
				_size++;
			}
			void 			pop_back(void)
			{
				// * the destroy is used to remove the element (calling the destructor) with keeping the memory
				if (_size > 0)
					_allocator.destroy(_data + (_size - 1));
				_size--;
			}
			void			assign(size_type n, const_reference val)
			{
				// todo the loop of using destroy then construct can be in another func
				if (n <= _size)
					_refill(n, val);
				else
				{
					reserve(n);
					_refill(n, val);
				}
				_size = n;
			}
			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type assign(InputIterator first, InputIterator last)
			{
				// todo the loop of using destroy then construct can be in another func
				if ((size_type)(ft::distance(first, last)) <= _size)
					_refill(first, last);
				else
				{
					InputIterator *begin = &first;
					reserve(ft::distance(first, last));
					_refill(*begin, last);
				}
				_size = ft::distance(first, last);
			}
			void			clear(void)
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_size = 0;
			}
			void swap(vector& x)
			{
				vector temp = *this;
				*this = x;
				x = temp;
			}
			iterator 		insert(iterator position, const_reference val)
			{
				size_type pos_num;
				for (pos_num = 0; pos_num < _size; pos_num++)
				{
					if (_data + pos_num == position.getPointer())
						break;
				}
				if (pos_num >= _size)
					reserve(pos_num);
				if (pos_num == _size)
					push_back(val);
				else
				{
					for (size_t i = 0; i < pos_num; i++)
					{
						if (i == pos_num)
							_allocator.construct(_data + i, val);
						else
							_allocator.construct(_data + i, _data[i + 1]);
					}
				}
				return (iterator(_data + pos_num));
			}
			void			insert(iterator position, size_type n, const value_type& val)
			{
				for (size_t i = 0; i < n; i++)
					insert(position, val);
			}
			template <class InputIterator>
    		void			insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				InputIterator temp = first;
				for (size_type i = 0; temp != last; i++, temp++)
					insert(position, *temp);
			}
			iterator		erase(iterator position)
			{
				size_type pos_num;
				for (pos_num = 0; pos_num < _size; pos_num++)
				{
					if (_data + pos_num == position.getPointer())
						break;
				}
				_allocator.destroy(_data + pos_num);
				return (iterator(_data + pos_num));
			}
			iterator 		erase(iterator first, iterator last)
			{
				for (iterator *begin = &first; *begin != last;)
					erase((*begin++));
				return (iterator(_data + _size));
			}
			// !						ELEMENT ACCESS						//
			reference operator[] (size_type n)
			{
				if (n >= _capacity)
					throw std::out_of_range("ft::vector::operator[]: position is out of range");
				return (_data[n]);
			}
			const_reference operator[] (size_type n) const
			{
				if (n >= _capacity)
					throw std::out_of_range("ft::vector::operator[]: position is out of range");
				return (_data[n]);
			}
			reference at (size_type n)
			{
				if (n >= _capacity)
					throw std::out_of_range("ft::vector::operator[]: position is out of range");
				return (_data[n]);
			}
			const_reference at (size_type n) const
			{
				if (n >= _capacity)
					throw std::out_of_range("ft::vector::operator[]: position is out of range");
				return (_data[n]);
			}
			reference front(void){return _data[0];}
			const_reference front(void) const{return _data[0];}
			reference back(void){return _data[_size - 1];}
			const_reference back(void) const{return _data[_size - 1];}
			
			// !						ALLOCATOR						//
			allocator_type get_allocator(void) const{return _allocator;}
			
			// !						CONSTRUCTORS						//
			/*
				* the 'explicit' used to prevent implicit type conversions, which it can lead to unintended behavior
				* ex. ft::Vector<int> myvector = 5; this will run and compile without any error 
				* so without the explicit keyword, the class allows implicit type conversions from int to vector
			*/
			// ? default constructor
			explicit vector (const allocator_type& alloc):_allocator(alloc), _data(NULL), _size(0), _capacity(0){}
			explicit vector (void):_data(NULL), _size(0), _capacity(0){}
			// ? fill constructor
			explicit vector(size_type count, const_reference value = T(), const allocator_type& alloc = allocator_type()):_data(NULL), _size(0), _capacity(0)
			{
				_allocator = alloc;
				_data = _allocator.allocate(count);
				// std::cout << "value constructor" << std::endl;
				for (size_t i = 0; i < count; i++)
				{
					_allocator.construct(_data + i, value);
					// _data[i] = value; // todo: use constrcut instead
				}
				_size = count;
				_capacity = count;
			}
			// ? copy constructor
			explicit vector(const vector& other){*this = other;}
			vector	&operator=(const vector& other)
			{
				_allocator = other.get_allocator();
				_data = _allocator.allocate(other.capacity());
				for (size_t i = 0; i < other.size(); i++)
					_allocator.construct(_data + i, other[i]);
				_size = other.size();
				_capacity = other.capacity();
				return (*this);
			}
			// ? range constructor
			template <class InputIterator>
			explicit vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()):_data(NULL),_size(0),_capacity(0)
			{
				(void)alloc;
				InputIterator it = first;
				_capacity = ft::distance(first, last);
				_data = _allocator.allocate(_capacity);
				for (size_t i = 0; it != last;)
					_allocator.construct(&_data[i++], *(it++)); 
				_size = _capacity;
			}

			// !						DESTRUCTOR						//
			~vector(void)
			{
				if (_size)
				{
					for (size_t i = 0; i < _size; i++)
						_allocator.destroy(_data + i);
				}
				if (_data)
					_allocator.deallocate(_data, _capacity);
			}
	};
	
	// !						NON-MEMBER FUNCTION OVERLOADS						//
	// ? relational operators
	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}
	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){return !(lhs == rhs);}
	template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		return (false);
	}
	template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){return !(rhs < lhs);}
	template <class T, class Alloc>
	bool operator<= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (lhs.size() <= rhs.size())
			return (true);
		return (false);
	}
	template <class T>
	bool operator>= (const ft::vector<T>& lhs, const ft::vector<T>& rhs){return !(rhs <= lhs);}
	
	// ? swap
	template <class T>
	void swap (ft::vector<T>& x, ft::vector<T>& y)
	{
		ft::vector<T> tmp = x;
		x = y;
		y = tmp;
	}
}


#endif
