/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:43:38 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/27 21:37:56 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"
/*
	random_access_iterator is a derived class of iterator
	which is a derived class of std::iterator
	it allows to iterate over a container in a random access manner
	which means that it can be incremented and decremented by any number
	which is not the case with bidirectional_iterator
*/
namespace ft
{
	template <class T>
	class random_access_iterator : public ft::iterator<T, ft::random_access_iterator_tag>
	{
		public:
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::ptrdiff_t							difference_type;
			typedef ft::random_access_iterator_tag			iterator_category;
		public:			
			/*						CONSTRUCTORS						*/
			random_access_iterator(void):_ptr(NULL){}
			random_access_iterator(pointer ptr):_ptr(ptr){}
			/*
				to solve the compilation error when trying to construct a random_access_iterator from a const_iterator
				and vice versa 
				this solved the problem I had on the following line:
				ft::vector<TESTED_TYPE>::const_iterator it_bar(foo.begin());
				and 
				ft::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
			*/
			template <class U> random_access_iterator(const random_access_iterator<U> &other):_ptr(NULL){_ptr = other.getPointer();}
			random_access_iterator(const random_access_iterator &other):_ptr(NULL){*this = other;}
			/*						OPERATORS						*/
			random_access_iterator&	operator=(const random_access_iterator &other)
			{
				if (this != &other)
					_ptr = other.getPointer();
				return (*this);
			}
			~random_access_iterator(void){}
			/*						MEMBERS						*/
			pointer		getPointer(void)const{return _ptr;}
			/*						OVERLOADS						*/
			// * Dereference operator
			reference	operator[](int pos){return (*(_ptr + pos));}
			pointer		operator->(void)const{return _ptr;}
			reference	operator*(void)const{return *_ptr;}
			// * Increment/decrement operators
			random_access_iterator&	operator++(void){_ptr++; return *this;}
			random_access_iterator&	operator--(void){_ptr--; return *this;}
			random_access_iterator	operator++(int){random_access_iterator temp = *this; _ptr++; return (temp);}
			random_access_iterator	operator--(int){random_access_iterator temp = *this; _ptr--; return (temp);}
			// * Arithmetic operators	
			random_access_iterator	operator-(difference_type n)const{return (_ptr - n);}
			random_access_iterator	operator+(difference_type n)const{return (_ptr + n);}
			// * Compound assignment operators
			random_access_iterator& operator+=(difference_type n) {_ptr += n; return (*this);}
			random_access_iterator& operator-=(difference_type n) {_ptr -= n; return (*this);}
			// * Comparison operators
			bool operator==(const random_access_iterator &other){return (_ptr == other._ptr);}
			bool operator!=(const random_access_iterator &other){return (_ptr != other._ptr);}
			bool operator<(const random_access_iterator &other){return (_ptr < other._ptr);}
			bool operator>(const random_access_iterator &other){return (_ptr > other._ptr);}
			bool operator<=(const random_access_iterator &other){return (_ptr <= other._ptr);}
			bool operator>=(const random_access_iterator &other){return (_ptr >= other._ptr);}	
		private:
			pointer			_ptr;
	};
	
	/*						NON-MEMBER OVERLOADS						*/
	// int + iterator
	template<typename T1>
	ft::random_access_iterator<T1> operator+(typename ft::random_access_iterator<T1>::difference_type val, const ft::random_access_iterator<T1> rhs){return (val + rhs.getPointer());}
	// int - iterator
	template<typename T1>
	ft::random_access_iterator<T1> operator-(typename ft::random_access_iterator<T1>::difference_type val, const ft::random_access_iterator<T1> rhs){return (val - rhs.getPointer());}
	template<typename T>
	bool operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs){return (lhs.getPointer() == rhs.getPointer());}
	/*
		these 3 overloads are needed to solve the compilation error when trying to compare a iterator with a const_iterator
		and vice versa 
		this solved the problem I had on the following line:
		ft::vector<TESTED_TYPE>::const_iterator == ft::vector<TESTED_TYPE>::iterator
	*/	
	template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator-(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() - rhs.getPointer());}
	template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator+(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() + rhs.getPointer());}
	template<typename T1, typename T2>
    bool operator!=(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (!(lhs.getPointer() == rhs.getPointer()));}
	template<typename T1, typename T2>
    bool operator==(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() == rhs.getPointer());}
	template<typename T1, typename T2>
	bool operator<(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() < rhs.getPointer());}
	template<typename T1, typename T2>
	bool operator>(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() > rhs.getPointer());}
	template<typename T1, typename T2>
	bool operator<=(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() <= rhs.getPointer());}
	template<typename T1, typename T2>
	bool operator>=(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){return (lhs.getPointer() >= rhs.getPointer());}

}

#endif
