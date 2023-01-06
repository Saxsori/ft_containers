/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:51 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/06 18:38:47 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	template <typename T>
	class iterator
	{
		private:
			T	*_data;
		public:
			iterator(T *data)_data(data){};
			~iterator(){};
	};
}

#endif
