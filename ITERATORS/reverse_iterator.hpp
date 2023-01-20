/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:28 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/20 12:25:27 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
	template <class Iterator> class reverse_iterator 
	{
		public:
		typedef Iterator														iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
		typedef typename ft::iterator_traits<Iterator>::reference				reference;
		
		public:
			iterator_type base() const {return _current;}
			// default constructor
			reverse_iterator() : _current() {}
			// initialization constructor
			reverse_iterator (iterator_type it) : _current(it) {}
			// copy assignment operator
			reverse_iterator& operator= (const reverse_iterator& rev_it)
			{
				if (this != &rev_it)
					_current = rev_it._current;
				return (*this);
			}
			// copy constructor
			// reverse_iterator (const reverse_iterator& rev_it){*this = rev_it;}
			template <class Iter> reverse_iterator (const reverse_iterator<Iter>& rev_it){_current = rev_it.base();}
			// destructor
			~reverse_iterator() {}
			// dereference operator
			reference	operator*() const {iterator_type temp = _current; return (*--temp);}
			pointer		operator->() const{return (&(operator*()));} //Returns a pointer to the element pointed to by the iterator
			reference operator[] (difference_type n) const {return (*(*this + n));}
			reverse_iterator operator+ (difference_type n) const{return (_current - n);}
			reverse_iterator operator- (difference_type n) const{return (_current + n);}
			reverse_iterator& operator++() {_current--; return (*this);}
			reverse_iterator operator++(int) {reverse_iterator temp = *this; _current--; return (temp);}
			reverse_iterator& operator--() {_current++; return (*this);}
			reverse_iterator operator--(int) {reverse_iterator temp = *this; _current++; return (temp);}
			reverse_iterator& operator+= (difference_type n) {_current -= n; return (*this);}
			reverse_iterator& operator-= (difference_type n) {_current += n; return (*this);}
		private:
			iterator_type _current;
	};
		//Non-member function overloads

		/*
			same concept used from the vector iterator since the reverse iterator is a wrapper around the vector iterator
			having a template class with two template parameters will allow the reverse iterator to be compared with any other
			reverse iterator regardless of the type of the iterator it is wrapping 
		*/
		template <class Iterator>
		bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (lhs.base() == rhs.base());}
		template <class Iter1, class Iter2>
		bool operator==(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (lhs.base() == rhs.base());}

		template <class Iterator>
		bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (!(lhs.base() == rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator!=(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (!(lhs.base() == rhs.base()));}

		template <class Iterator>
		bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (lhs.base() > rhs.base());}
		template <class Iter1, class Iter2>
		bool operator<(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (lhs.base() > rhs.base());}

		template <class Iterator>
		bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (lhs.base() < rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (lhs.base() < rhs.base());}

		template <class Iterator>
		bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return ((lhs.base() >= rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator<=(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return ((lhs.base() >= rhs.base()));}

		template <class Iterator>
		bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (lhs.base() <= rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>=(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (lhs.base() <= rhs.base());}

		template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it){return (rev_it + n);}
		template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs){return (rhs.base() - lhs.base());}
		template <class Iter1, class Iter2>
		typename ft::reverse_iterator<Iter1>::difference_type operator-(const ft::reverse_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>& rhs){return (rhs.base() - lhs.base());}
}






#endif

