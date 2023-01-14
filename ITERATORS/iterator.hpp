/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:51 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/14 21:14:26 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
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
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};
	
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	
	template <class Iterator>
	struct iterator_traits 
	{
		typedef typename	Iterator::iterator_category			iterator_category;
		typedef typename	Iterator::value_type				value_type;
		typedef typename	Iterator::difference_type			difference_type;
		typedef 			difference_type						distance_type;
		typedef typename	Iterator::pointer					pointer;
		typedef typename	Iterator::reference					reference;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef random_access_iterator_tag		iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*> 
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T&						reference;
		typedef const T*						pointer;
		typedef random_access_iterator_tag		iterator_category;
	};

}

#endif
