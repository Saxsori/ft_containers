/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_reverse_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:03:41 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/30 04:28:10 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template <class Iterator> class bidirectional_reverse_iterator
	{
		public:
		typedef Iterator														iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
		typedef typename ft::iterator_traits<Iterator>::reference				reference;
		
		public:
			iterator_type base()const{return _current;}
			// default constructor
			bidirectional_reverse_iterator():_current(){}
			// initialization constructor
			bidirectional_reverse_iterator(iterator_type it):_current(it){}
			// copy assignment operator
			bidirectional_reverse_iterator& operator=(const bidirectional_reverse_iterator& rev_it)
			{
				if (this != &rev_it)
					_current = rev_it._current;
				return (*this);
			}
			// copy constructor
			template <class Iter> bidirectional_reverse_iterator(const bidirectional_reverse_iterator<Iter>& rev_it){_current = rev_it.base();}
			// destructor
			~bidirectional_reverse_iterator() {}
			// dereference operator
			reference									operator*()const{iterator_type temp = _current; return (*--temp);}
			pointer										operator->()const{return (&(operator*()));} //Returns a pointer to the element pointed to by the iterator
			bidirectional_reverse_iterator&				operator++(){_current--; return (*this);}
			bidirectional_reverse_iterator				operator++(int){bidirectional_reverse_iterator temp = *this; _current--; return (temp);}
			bidirectional_reverse_iterator&				operator--(){_current++; return (*this);}
			bidirectional_reverse_iterator				operator--(int){bidirectional_reverse_iterator temp = *this; _current++; return (temp);}
		private:
			iterator_type	_current;
	};

		template <class Iterator>
		bool operator==(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return (lhs.base() == rhs.base());}
		template <class Iter1, class Iter2>
		bool operator==(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return (lhs.base() == rhs.base());}

		template <class Iterator>
		bool operator!=(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return (!(lhs.base() == rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator!=(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return (!(lhs.base() == rhs.base()));}

		template <class Iterator>
		bool operator<(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return (lhs.base() > rhs.base());}
		template <class Iter1, class Iter2>
		bool operator<(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return (lhs.base() > rhs.base());}

		template <class Iterator>
		bool operator>(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return (lhs.base() < rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return (lhs.base() < rhs.base());}

		template <class Iterator>
		bool operator<=(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return ((lhs.base() >= rhs.base()));}
		template <class Iter1, class Iter2>
		bool operator<=(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return ((lhs.base() >= rhs.base()));}

		template <class Iterator>
		bool operator>=(const ft::bidirectional_reverse_iterator<Iterator>& lhs, const ft::bidirectional_reverse_iterator<Iterator>& rhs){return (lhs.base() <= rhs.base());}
		template <class Iter1, class Iter2>
		bool operator>=(const ft::bidirectional_reverse_iterator<Iter1>& lhs, const ft::bidirectional_reverse_iterator<Iter2>& rhs){return (lhs.base() <= rhs.base());}

}