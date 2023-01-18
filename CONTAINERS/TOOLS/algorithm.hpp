/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:31:56 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/18 19:13:58 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}