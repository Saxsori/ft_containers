/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:19 by aaljaber          #+#    #+#             */
/*   Updated: 2023/01/18 14:10:31 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CONTAINERS/Vector.hpp"
#include "../ITERATORS/iterator.hpp"
#include <vector>
#include "./printSize.hpp"
#include <iostream>
#define TYPE std::string

void	checkErase(ft::vector<TYPE> const &vct,
					ft::vector<TYPE>::iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "ft::erase: " << it - vct.begin() << std::endl;
	ft::printSize(vct);
}

void	checkErase(std::vector<TYPE> const &vct,
					std::vector<TYPE>::iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "std::erase: " << it - vct.begin() << std::endl;
	ft::printSize(vct);
}

int		main(void)
{
	// ft::vector<TYPE> vct(10);
	// std::vector<TYPE> vct1(10);

	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = std::string((vct.size() - i), i + 65);
	// for (unsigned long int i = 0; i < vct1.size(); ++i)
	// 	vct1[i] = std::string((vct1.size() - i), i + 65);
	// ft::printSize(vct);
	// ft::printSize(vct1);

	// checkErase(vct, vct.erase(vct.begin() + 2));
	// checkErase(vct1, vct1.erase(vct1.begin() + 2));

	// checkErase(vct, vct.erase(vct.begin()));
	// checkErase(vct1, vct1.erase(vct1.begin()));
	
	// checkErase(vct, vct.erase(vct.end() - 1));
	// checkErase(vct1, vct1.erase(vct1.end() - 1));

	// checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	// checkErase(vct1, vct1.erase(vct1.begin(), vct1.begin() + 3));

	// checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));
	// checkErase(vct1, vct1.erase(vct1.end() - 3, vct1.end() - 1));

	// vct.push_back("Hello");
	// vct1.push_back("Hello");
	// vct.push_back("Hi there");
	// vct1.push_back("Hi there");
	// ft::printSize(vct);
	// ft::printSize(vct1);
	// checkErase(vct, vct.erase(vct.end() - 3, vct.end()));
	// checkErase(vct1, vct1.erase(vct1.end() - 3, vct1.end()));

	// vct.push_back("ONE");
	// vct.push_back("TWO");
	// vct.push_back("THREE");
	// vct.push_back("FOUR");
	// vct1.push_back("ONE");
	// vct1.push_back("TWO");
	// vct1.push_back("THREE");
	// vct1.push_back("FOUR");
	// ft::printSize(vct);
	// ft::printSize(vct1);
	
	// checkErase(vct, vct.erase(vct.begin(), vct.end()));
	// checkErase(vct1, vct1.erase(vct.begin(), vct1.end()));
	
	ft::vector<TESTED_TYPE> lol(10);
	ft::vector<TESTED_TYPE> lol2;
	ft::vector<TESTED_TYPE> lol3;
	std::vector<TESTED_TYPE> boo(10);
	std::vector<TESTED_TYPE> boo2;
	std::vector<TESTED_TYPE> boo3;

	for (unsigned long int i = 0; i < lol.size(); ++i)
		lol[i] = (lol.size() - i) * 3;
	// ft::printSize(lol);
	
	for (unsigned long int i = 0; i < boo.size(); ++i)
		boo[i] = (boo.size() - i) * 3;
	// ft::printSize(boo);
	
	boo2.insert(boo2.end(), 42);
	boo2.insert(boo2.begin(), 2, 21);
	// ft::printSize(boo2);
	
	lol2.insert(lol2.end(), 42);
	lol2.insert(lol2.begin(), 2, 21);
	// ft::printSize(lol2);
	
	boo2.insert(boo2.end() - 2, 42);
	// ft::printSize(boo2);
	
	lol2.insert(lol2.end() - 2, 42);
	// ft::printSize(lol2);
	
	
	boo2.insert(boo2.end(), 2, 84);
	// ft::printSize(boo2);
	
	lol2.insert(lol2.end(), 2, 84);
	// ft::printSize(lol2);
	
	
	lol2.resize(4);
	// ft::printSize(lol2);

	boo2.resize(4);
	// ft::printSize(boo2);

	lol2.insert(lol2.begin() + 2, lol.begin(), lol.end());
	// std::cout << "HEEEEEEREEEEEEE" << std::endl;
	// lol2.insert(lol2.begin() + 2, 10, 30);
	lol.clear();
	// ft::printSize(lol2);
	
	// boo2.insert(boo2.begin() + 2, 10, 30);
	boo2.insert(boo2.begin() + 2, boo.begin(), boo.end());
	boo.clear();
	// ft::printSize(boo2);



	// ft::printSize(lol);
	// ft::printSize(boo);


	for (int i = 0; i < 5; ++i)
		lol3.insert(lol3.end(), i);
	
	for (int i = 0; i < 5; ++i)
		boo3.insert(boo3.end(), i);
		
	lol3.insert(lol3.begin() + 1, 2, 111);
	// ft::printSize(lol3);

	boo3.insert(boo3.begin() + 1, 2, 111);
	// ft::printSize(boo3);

	ft::vector<TESTED_TYPE> vvct(5);
	ft::vector<TESTED_TYPE> vvct2;
	std::vector<TESTED_TYPE> vvct1(5);
	std::vector<TESTED_TYPE> vvct21;
	const int cut = 3;

	for (unsigned long int i = 0; i < vvct.size(); ++i)
		vvct[i] = (vvct.size() - i) * 7;
	// ft::printSize(vvct);
	for (unsigned long int i = 0; i < vvct1.size(); ++i)
		vvct1[i] = (vvct1.size() - i) * 7;
	// ft::printSize(vvct1);

	vvct2.insert(vvct2.begin(), vvct.begin(), vvct.begin() + cut);
	// ft::printSize(vvct2);
	
	vvct21.insert(vvct21.begin(), vvct1.begin(), vvct1.begin() + cut);
	// ft::printSize(vvct21);
	
	//
	vvct2.insert(vvct2.begin(), vvct.begin() + cut, vvct.end());
	// ft::printSize(vvct2);
	
	vvct21.insert(vvct21.begin(), vvct1.begin() + cut, vvct1.end());
	// ft::printSize(vvct21);
	
	//
	vvct2.insert(vvct2.end(), vvct.begin(), vvct.begin() + cut);
	// ft::printSize(vvct2);
	
	vvct21.insert(vvct21.end(), vvct1.begin(), vvct1.begin() + cut);
	// ft::printSize(vvct21);
	
	std::cout << "insert return:" << std::endl;

	std::cout << *vvct2.insert(vvct2.end(), 42) << std::endl;
	// std::cout << "lool" << std::endl;
	std::cout << *vvct21.insert(vvct21.end(), 42) << std::endl;

	std::cout << *vvct2.insert(vvct2.begin() + 5, 84) << std::endl;
	std::cout << *vvct21.insert(vvct21.begin() + 5, 84) << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	// ft::printSize(vvct2);
	// ft::printSize(vvct21);
	return (0);
}
