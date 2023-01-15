/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:56:53 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/15 15:01:56 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft 
{
	/*
		states that a compiler should not fail to compile 
		a program just because it cannot substitute a template parameter
	*/
	template <bool B, class T = void>
	struct enable_if {};
	
}