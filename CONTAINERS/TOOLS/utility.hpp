/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:37:21 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/05 20:47:37 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	// pair
	/*
		*  Class pair is a simple container class whose instances can hold two elements
		*  of arbitrary types T1 and T2.
		*  The individual elements can be accessed through its public members first and second.
	*/
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
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return (lhs.first == rhs.first && lhs.second == rhs.second);}
	template <class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return !(lhs == rhs);}
	template <class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));}
	template <class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second <= rhs.second));}
	template <class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return (rhs < lhs);}
	template <class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){return (rhs.first < lhs.first || (!(lhs.first < rhs.first) && rhs.second <= lhs.second));}
	
	// make_ft::pair
	/*
		* Constructs a pair object with its elements initialized to x and y, respectively.
		pair objects can be constructed from other pair objects containing different types, if the respective types are implicitly convertible.
	*/
	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y){return (ft::pair<T1,T2>(x,y));}
}
#endif