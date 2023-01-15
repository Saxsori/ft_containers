/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:51 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/15 19:20:37 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	/*
		This is a base class template that can be used to derive iterator classes from it. 
		It is not an iterator class and does not provide any of the functionality 
		an iterator is expected to have.
	*/
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};
	
	struct input_iterator_tag {}; // used to read the elements of a container, but not to modify them.
	struct output_iterator_tag {}; // used to write the elements of a container, but not to read them.
	struct forward_iterator_tag : public input_iterator_tag {}; // used to read and write the elements of a container, and can be incremented (but not decremented).
	struct bidirectional_iterator_tag : public forward_iterator_tag {}; // used to read and write the elements of a container, and can be incremented and decremented.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {}; // used to read and write the elements of a container, and can be incremented, decremented and moved to a specific position in constant time.
	
	/*
		std::iterator_traits is a template class that provides a way to obtain information 
		about the properties of an iterator, such as its value type, difference type, and category. 
		It is typically used as a base class for other iterator-related templates, such as std::distance.
		It can be used to obtain the type information of an iterator by providing the type of the iterator 
		as a template argument
	*/

	/*
		The primary template of std::iterator_traits. It provides a general way to obtain information about an iterator of any type. 
		It uses template specialization to handle the cases where the iterator class does not provide the required information, 
		for example, for built-in pointers or for older-style iterators.
	*/
	template <class Iterator>
	struct iterator_traits 
	{
		typedef typename	Iterator::iterator_category			iterator_category;
		typedef typename	Iterator::value_type				value_type;
		typedef typename	Iterator::difference_type			difference_type;
		typedef 			difference_type				distance_type;
		typedef typename	Iterator::pointer				pointer;
		typedef typename	Iterator::reference				reference;
	};

	/*
		A template specialization of std::iterator_traits for pointer to const types.
		It provides information about iterators of type const T*, such as the type of the elements 
		the pointer points to, the difference type, reference type, pointer type, and iterator category.
	*/
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T						value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T&						reference;
		typedef T*						pointer;
		typedef random_access_iterator_tag			iterator_category;
	};

	/*
		Another template specialization of std::iterator_traits for pointer types. It provides information about iterators of type T*
	*/
	template <class T>
	struct iterator_traits<const T*> 
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T&						reference;
		typedef const T*						pointer;
		typedef random_access_iterator_tag		iterator_category;
	};

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		InputIterator tmp(first);
		for (typename iterator_traits<InputIterator>::difference_type i = 0; tmp != last; ++tmp, ++i)
			return (i);
		return (0);
	}

}

#endif
