/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:42 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/16 16:45:03 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TESTED_TYPE int
#include "../CONTAINERS/Vector.hpp"
#include <vector>
#include "./printSize.hpp"
// #define T_SIZE_TYPE typename ft::vector<T>::size_type
// #define T_SIZE_TYPE_STD typename std::vector<T>::size_type


// template <typename T>
// void	printSize(ft::vector<T> const &vct, bool print_content = true)
// {
// 	std::cout << "###############################################" << std::endl;
// 	std::cout << "ft::vector" << std::endl;
// 	const T_SIZE_TYPE size = vct.size();
// 	const T_SIZE_TYPE capacity = vct.capacity();
// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// 	// Cannot limit capacity's max value because it's implementation dependent

// 	std::cout << "size: " << size << std::endl;
// 	std::cout << "capacity: " << isCapacityOk << std::endl;
// 	std::cout << "max_size: " << vct.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename ft::vector<T>::const_iterator it = vct.begin();
// 		typename ft::vector<T>::const_iterator ite = vct.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << *it << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

// template <typename T>
// void	printSize(std::vector<T> const &vct, bool print_content = true)
// {
// 	std::cout << "###############################################" << std::endl;
	
// 	std::cout << "std::vector" << std::endl;
// 	const T_SIZE_TYPE_STD size = vct.size();
// 	const T_SIZE_TYPE_STD capacity = vct.capacity();
// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// 	// Cannot limit capacity's max value because it's implementation dependent

// 	std::cout << "size: " << size << std::endl;
// 	std::cout << "capacity: " << isCapacityOk << std::endl;
// 	std::cout << "max_size: " << vct.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename std::vector<T>::const_iterator it = vct.begin();
// 		typename std::vector<T>::const_iterator ite = vct.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << *it << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }


int		main(void)
{
	ft::vector<TESTED_TYPE> vct(7);  std::vector<TESTED_TYPE> vct1(7);
	ft::vector<TESTED_TYPE> vct_two(4); std::vector<TESTED_TYPE> vct_two1(4);
	ft::vector<TESTED_TYPE> vct_three; std::vector<TESTED_TYPE> vct_three1;
	ft::vector<TESTED_TYPE> vct_four; std::vector<TESTED_TYPE> vct_four1;

	// std::vector<int> vct(7);
	// std::vector<int> vct_two(4);
	// std::vector<int> vct_three;
	// std::vector<int> vct_four;
	
	// std::cout << "3 size " << vct_three.size() << std::endl;
	// std::cout << "3 capacity " << vct_three.capacity() << std::endl;
	// std::cout << "0 size " << vct.size() << std::endl;
	// std::cout << "0 capacity " << vct.capacity() << std::endl;
	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 3;
	// std::cout << "content of vct: " << std::endl;
	// for (unsigned long int i = 0; i < vct.capacity(); ++i)
	// 	std::cout << vct[i] << std::endl;
	
	// std::cout << "content of vct_three: " << std::endl;
	// for (unsigned long int i = 0; i < vct_three.capacity(); ++i)
	// 	std::cout << vct_three[i] << std::endl;

	// std::cout << "vct begin " << *vct.begin() << std::endl;
	// vct_three.assign(vct.begin(), vct.end());
	
	
	// std::cout << "3 size " << vct_three.size() << std::endl;
	// std::cout << "3 capacity " << vct_three.capacity() << std::endl;
	// std::cout << "0 size " << vct.size() << std::endl;
	// std::cout << "0 capacity " << vct.capacity() << std::endl;
	// std::cout << "content of vct_three: " << std::endl;
	// for (unsigned long int i = 0; i < vct_three.capacity(); ++i)
	// 	std::cout << vct_three[i] << std::endl;
	
	
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	
	for (unsigned long int i = 0; i < vct1.size(); ++i)
		vct1[i] = (vct1.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two1.size(); ++i)
		vct_two1[i] = (vct_two1.size() - i) * 5;
	
	
	// printSize(vct);
	// printSize(vct1);
	// std::cout << std::endl;
	
	// printSize(vct_two);
	// printSize(vct_two1);
	// std::cout << std::endl;

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	std::cout << "here" << std::endl;
	vct_four.assign(4, 21);

	vct_three1.assign(vct1.begin(), vct1.end());
	vct1.assign(vct_two1.begin(), vct_two1.end());
	vct_two1.assign(2, 42);
	vct_four1.assign(4, 21);

	// std::cout << "\t### After assign(): ###" << std::endl;

	// printSize(vct);
	// printSize(vct1);
	// std::cout << std::endl;
	
	ft::printSize(vct_two);
	ft::printSize(vct_two1);
	std::cout << std::endl;

	// printSize(vct_three);
	// printSize(vct_three1);
	// std::cout << std::endl;

	// printSize(vct_four);
	// printSize(vct_four1);
	// std::cout << std::endl;
	
	vct_four.assign(6, 84);
	// printSize(vct_four);

	vct_four1.assign(6, 84);
	// printSize(vct_four1);
	// std::cout << std::endl;

	
	// std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	vct1.assign(5, 53);
	vct_two1.assign(vct_three1.begin(), vct_three1.begin() + 3);

	// printSize(vct);
	// printSize(vct1);
	// std::cout << std::endl;

	// printSize(vct_two);
	// printSize(vct_two1);
	// std::cout << std::endl;

	return (0);
}
