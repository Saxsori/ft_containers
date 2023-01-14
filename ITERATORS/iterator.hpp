/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:51 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/12 20:18:03 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	template <typename T>
	class iterator
	{
		private:
			typedef T					value_type;
			typedef	T*					pointer;
			typedef	T&					reference;
			typedef std::ptrdiff_t		difference_type;
			
		public:
			/*						CONSTRUCTORS						*/
			iterator(void):_ptr(NULL){}
			iterator(pointer ptr):_ptr(ptr){}
			~iterator(void){}
			pointer		getPointer(void){return _ptr;}
			/*						OVERLOADS						*/
			// * Dereference operator
			reference	operator[](int pos){return (*(_ptr + pos));}
			pointer		operator->(void){return _ptr;}
			reference	operator*(void){return *_ptr;}
			// * Increment/decrement operators
			iterator&	operator++(void){_ptr++; return *this;}
			iterator&	operator--(void){_ptr--; return *this;}
			iterator	operator++(int){iterator *temp = this; _ptr++; return (*temp);}
			iterator	operator--(int){iterator *temp = this; _ptr--; return (*temp);}
			
			iterator	operator-(difference_type n){_ptr = _ptr - n; return (*this);}
			iterator	operator+(difference_type n){_ptr = _ptr + n; return (*this);}
			
		private:
			pointer	_ptr;
	};
}

// ft::iterator	operator!=(difference_type n){_ptr = _ptr + n; return (*this);}


#endif
