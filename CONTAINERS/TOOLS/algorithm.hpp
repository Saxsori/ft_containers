/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:31:56 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/18 18:29:19 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	// pair
	template <class T1, class T2> struct pair
	{
		typedef	T1	first_type;
		typedef	T2	second_type;
		
		first_type	first;
		second_type	second;
		
		//default constructor
		pair() : first(), second() {}
		// initialization constructor
		pair(const first_type& a, const second_type& b) : first(a), second(b) {}
		// copy constructor
		template<class U, class V> pair (const pair<U,V>& pr){*this = pr;}
		// destructor
		~pair() {}
		// assignment operator
		pair& operator=(const pair& other)
		{
			if (this != &other)
			{
				first = other.first;
				second = other.second;
			}
			return (*this);
		}
	};
	// relational operators
	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return (lhs.first == rhs.first && lhs.second == rhs.second);}
	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(lhs == rhs);}
	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));}
	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second <= rhs.second));}
	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return (rhs < lhs);}
	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return (rhs.first < lhs.first || (!(lhs.first < rhs.first) && rhs.second <= lhs.second));}
	// make_pair
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y){return (pair<T1,T2>(x,y));}

	// equal
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1)
		{
			if (!pred(*first1,*first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
}