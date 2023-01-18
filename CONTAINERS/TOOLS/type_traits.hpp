/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:56:53 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/18 18:32:23 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft 
{
	/*
		SFINAE: Substitution Failure Is Not An Error
		states that a compiler should not fail to compile 
		a program just because it cannot substitute a template parameter
		to fix this, we use enable_if to prevent instantiation of templates
		with certain types.
	*/

	/*
		enable_if is a template that can be used to conditionally enable or disable
		a function template or a class template.
		it takes two template parameters:
		- a boolean value that determines whether the template is enabled or not.
		- a type that is the return type of the template if the boolean value is true.
		
		Note: the second template parameter is optional, and if it's not provided,
		the default type is void.
		
		If the boolean value is true, the template is enabled and the type is set to the
		second template parameter, otherwise (flase) the template is disabled and the type is set to void,
		which means that the template is not instantiated.
		
		it can be used in this way : 
		template <class = typename enable_if<is_integral<T>::value>::type> 
	*/
	template <bool B, class T = void> struct enable_if {};
	template <class T> struct enable_if<true, T> { typedef T type; };
	
	
	/*
		Type trait that determines whether a type is an integral type.
		Used to prevent instantiation of templates with non-integral types.
		Used to preform compile-time checks and select certain template specializations
		based on the type of the template parameter.
		
		The value of the static member constant is true if T is an integral type,
		and false otherwise.

		In c++98, this can't be preformed at compile-time since constexpt is not supported,
		so we use template specialization to define the value of the static member constant 
		for each integral type and this will be preformed at run-time.
		
		Note: this is not the best way to do it, but it's the only way to do it in c++98.
		
		Using inhertiance way from constant_integral (false_type , and true type) to define 
		the value of the static member constant for each integral type is not the only way to do it,
		so imo this way is more readable and understandable, since both are the same.		
	*/
	template <class T> struct is_integral{ static const bool value = false; };
	// template specialization //
	template <> struct is_integral<bool>{ static const bool value = true; };
	template <> struct is_integral<char>{ static const bool value = true; };
	template <> struct is_integral<signed char>{ static const bool value = true; };
	template <> struct is_integral<unsigned char>{ static const bool value = true; };
	template <> struct is_integral<wchar_t>{ static const bool value = true; };
	template <> struct is_integral<short>{ static const bool value = true; };
	template <> struct is_integral<unsigned short>{ static const bool value = true; };
	template <> struct is_integral<int>{ static const bool value = true; };
	template <> struct is_integral<unsigned int>{ static const bool value = true; };
	template <> struct is_integral<long>{ static const bool value = true; };
	template <> struct is_integral<unsigned long>{ static const bool value = true; };
	template <> struct is_integral<long long>{ static const bool value = true; };
	template <> struct is_integral<unsigned long long>{ static const bool value = true; };
}