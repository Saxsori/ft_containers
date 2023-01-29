/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:28 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/29 23:06:03 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_REVERSE_ITERATOR_HPP
#define RANDOM_REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
	template <class Iterator> class random_reverse_iterator
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
			random_reverse_iterator() : _current() {}
			// initialization constructor
			random_reverse_iterator(iterator_type it) : _current(it) {}
			// copy assignment operator
			random_reverse_iterator& operator= (const random_reverse_iterator& rev_it)
			{
				if (this != &rev_it)
					_current = rev_it._current;
				return (*this);
			}
			// copy constructor
			// random_reverse_iterator(const reverse_iterator& rev_it){*this = rev_it;}
			template <class Iter> random_reverse_iterator(const random_reverse_iterator<Iter>& rev_it){_current = rev_it.base();}
			// destructor
			~random_reverse_iterator() {}
			// dereference operator
			reference	operator*() const {iterator_type temp = _current; return (*--temp);}
			pointer		operator->() const{return (&(operator*()));} //Returns a pointer to the element pointed to by the iterator
			reference operator[] (difference_type n) const {return (*(*this + n));}
			random_reverse_iterator operator+ (difference_type n) const{return (_current - n);}
			random_reverse_iterator operator- (difference_type n) const{return (_current + n);}
			random_reverse_iterator& operator++() {_current--; return (*this);}
			random_reverse_iterator operator++(int) {random_reverse_iterator temp = *this; _current--; return (temp);}
			random_reverse_iterator& operator--() {_current++; return (*this);}
			random_reverse_iterator operator--(int) {random_reverse_iterator temp = *this; _current++; return (temp);}
			random_reverse_iterator& operator+= (difference_type n) {_current -= n; return (*this);}
			random_reverse_iterator& operator-= (difference_type n) {_current += n; return (*this);}
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
		bool operator==(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (lhs.base() == rhs.base());}
		template <class Iter1, class Iter2>
		bool operator==(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (lhs.base() == rhs.base());}

		template <class Iterator>
		bool operator!=(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (!(lhs.base() == rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator!=(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (!(lhs.base() == rhs.base()));}

		template <class Iterator>
		bool operator<(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (lhs.base() > rhs.base());}
		template <class Iter1, class Iter2>
		bool operator<(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (lhs.base() > rhs.base());}

		template <class Iterator>
		bool operator>(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (lhs.base() < rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (lhs.base() < rhs.base());}

		template <class Iterator>
		bool operator<=(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return ((lhs.base() >= rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator<=(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return ((lhs.base() >= rhs.base()));}

		template <class Iterator>
		bool operator>=(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (lhs.base() <= rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>=(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (lhs.base() <= rhs.base());}

		template <class Iterator>
		ft::random_reverse_iterator<Iterator> operator+(typename ft::random_reverse_iterator<Iterator>::difference_type n, const ft::random_reverse_iterator<Iterator>& rev_it){return (rev_it + n);}
		template <class Iterator>
		typename ft::random_reverse_iterator<Iterator>::difference_type operator-(const ft::random_reverse_iterator<Iterator>& lhs, const ft::random_reverse_iterator<Iterator>& rhs){return (rhs.base() - lhs.base());}
		template <class Iter1, class Iter2>
		typename ft::random_reverse_iterator<Iter1>::difference_type operator-(const ft::random_reverse_iterator<Iter1>& lhs, const ft::random_reverse_iterator<Iter2>& rhs){return (rhs.base() - lhs.base());}
}






#endif

