/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:28 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/17 18:19:38 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
	

	template <class Iterator> class reverse_iterator 
	{
		typedef Iterator														iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
		typedef typename ft::iterator_traits<Iterator>::reference				reference;

		public:
			iterator_type base() const {return (iterator_type(_current));}
			// default constructor
			reverse_iterator() : _current() {}
			// initialization constructor
			explicit reverse_iterator (iterator_type it) : _current(it) {}
			// copy assignment operator
			reverse_iterator& operator= (const reverse_iterator& rev_it)
			{
				if (this != &rev_it)
					_current = rev_it._current;
				return (*this);
			}
			// copy constructor
			reverse_iterator (const reverse_iterator& rev_it){*this = rev_it;}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it){*this = rev_it;}
			// destructor
			~reverse_iterator() {}

			// dereference operator
			reference	operator*() const {iterator_type temp = _current; return (*--temp);}
			pointer		operator->() const{return (&(operator*()));} //Returns a pointer to the element pointed to by the iterator
			reference operator[] (difference_type n) const {return (*(*this + n));}
			reverse_iterator operator+ (difference_type n) const{return (reverse_iterator(_current - n));}
			reverse_iterator operator- (difference_type n) const{return (reverse_iterator(_current + n));}
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

		template <class Iterator>
		bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (lhs.base() == rhs.base());}

		template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (!(lhs.base() == rhs.base()));}

		template <class Iterator>
		bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (lhs.base() > rhs.base());}

		template <class Iterator>
		bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (lhs.base() < rhs.base());}

		template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (!(lhs.base() > rhs.base()));}

		template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (!(lhs.base() < rhs.base()));}

		template <class Iterator>
		reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it){return (rev_it + n);}

		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){return (rhs.base() - lhs.base());}
}






#endif

