/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printSize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:53 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/16 15:10:31 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTSIZE_HPP
# define PRINTSIZE_HPP

#define TESTED_TYPE int
#include "../CONTAINERS/Vector.hpp"
#include <vector>
#define T_SIZE_TYPE typename ft::vector<T>::size_type
#define T_SIZE_TYPE_STD typename std::vector<T>::size_type

namespace ft
{
	template <typename T>
	void	printSize(ft::vector<T> const &vct, bool print_content = true)
	{
		std::cout << "###############################################" << std::endl;
		std::cout << "ft::vector" << std::endl;
		const T_SIZE_TYPE size = vct.size();
		const T_SIZE_TYPE capacity = vct.capacity();
		const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
		// Cannot limit capacity's max value because it's implementation dependent

		std::cout << "size: " << size << std::endl;
		std::cout << "capacity: " << isCapacityOk << std::endl;
		std::cout << "max_size: " << vct.max_size() << std::endl;
		if (print_content)
		{
			typename ft::vector<T>::const_iterator it = vct.begin();
			typename ft::vector<T>::const_iterator ite = vct.end();
			std::cout << std::endl << "Content is:" << std::endl;
			for (; it != ite; ++it)
				std::cout << "- " << *it << std::endl;
		}
		std::cout << "###############################################" << std::endl;
	}

	template <typename T>
	void	printSize(std::vector<T> const &vct, bool print_content = true)
	{
		std::cout << "###############################################" << std::endl;
		
		std::cout << "std::vector" << std::endl;
		const T_SIZE_TYPE_STD size = vct.size();
		const T_SIZE_TYPE_STD capacity = vct.capacity();
		const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
		// Cannot limit capacity's max value because it's implementation dependent

		std::cout << "size: " << size << std::endl;
		std::cout << "capacity: " << isCapacityOk << std::endl;
		std::cout << "max_size: " << vct.max_size() << std::endl;
		if (print_content)
		{
			typename std::vector<T>::const_iterator it = vct.begin();
			typename std::vector<T>::const_iterator ite = vct.end();
			std::cout << std::endl << "Content is:" << std::endl;
			for (; it != ite; ++it)
				std::cout << "- " << *it << std::endl;
		}
		std::cout << "###############################################" << std::endl;
	}	
}

#endif