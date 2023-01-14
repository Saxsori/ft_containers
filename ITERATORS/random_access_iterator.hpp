/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:43:38 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/14 21:19:21 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <class T>
	class random_access_iterator : public ft::iterator<T, ft::random_access_iterator_tag>
	{
		public:			
			/*						CONSTRUCTORS						*/
			random_access_iterator(void):_ptr(NULL){}
			random_access_iterator(pointer ptr):_ptr(ptr){}
			~random_access_iterator(void){}
			pointer		getPointer(void){return _ptr;}
			/*						OVERLOADS						*/
			// * Dereference operator
			reference	operator[](int pos){return (*(_ptr + pos));}
			pointer		operator->(void){return _ptr;}
			reference	operator*(void){return *_ptr;}
			// * Increment/decrement operators
			random_access_iterator&	operator++(void){_ptr++; return *this;}
			random_access_iterator&	operator--(void){_ptr--; return *this;}
			random_access_iterator	operator++(int){random_access_iterator *temp = this; _ptr++; return (*temp);}
			random_access_iterator	operator--(int){random_access_iterator *temp = this; _ptr--; return (*temp);}
			
			random_access_iterator	operator-(difference_type n){_ptr = _ptr - n; return (*this);}
			random_access_iterator	operator+(difference_type n){_ptr = _ptr + n; return (*this);}
				
		private:
			pointer	_ptr;
	};
}

#endif
