/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:51 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/10 07:42:36 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			iterator&	operator++(void){_ptr++; return *this;}
			iterator&	operator--(void){_ptr--; return *this;}
			iterator	operator++(int){iterator *temp = this; _ptr++; return (*temp);}
			iterator	operator--(int){iterator *temp = this; _ptr--; return (*temp);}
			iterator	operator-(int pos){_ptr = _ptr - pos; return (*this);}
			iterator	operator+(int pos){_ptr = _ptr + pos; return (*this);}
			reference	operator[](int pos){return (*(_ptr + pos));}
			pointer		operator->(void){return _ptr;}
			reference		operator*(void){return *_ptr;}
		private:
			pointer	_ptr;
	};
}

#endif
