/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:31:56 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/19 23:24:42 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	// equal
	/*
		*Compares the elements in the range [first1,last1) with those of [first2,last2).
		*Returns true if all of the elements in both ranges match, and false otherwise.
		*The function uses operator== to compare the individual elements.
	*/
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
	/*
		*BinaryPredicate is a binary predicate that accepts two elements as arguments and returns a value convertible to bool.
		*The value returned indicates whether the elements are considered equal.
		*The function returns true if all of the elements in both ranges match according to this predicate, and false otherwise.
		
	*/
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
	// lexicographical_compare
	/*
		*Compares the elements in the range [first1,last1) with those of [first2,last2) in lexicographical order.
		*Returns true if the first range is lexicographically less than the second, and false otherwise.
		*The function uses operator< to compare the individual elements.
	*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) // if it's ended or the second is less than the first
				return (false);
			else if (*first1<*first2) // if the first is less than the second 
				return (true);
			++first1; // if they are equal
			++first2;
		}
		return (first2!=last2);
	}
	/*
		*Compares the elements in the range [first1,last1) with those of [first2,last2) in lexicographical order.
		*Returns true if the first range is lexicographically less than the second, and false otherwise.
		*The function uses comp to compare the individual elements.
	*/
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2,*first1))
				return (false);
			else if (comp(*first1,*first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
}

#endif