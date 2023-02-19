/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:41:20 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/19 00:29:39 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <memory>
#include <list>
#include "../../CONTAINERS/map.hpp"

int main ()
{
	ft::map<int, int> mapp;
	
	// mapp.insert(ft::pair<const int, int>(1,1));
	mapp.insert(ft::pair<const int, int>(4,1));
	// mapp.insert(ft::pair<const int, int>(5,1));

	// ft::map<int, int> mapp2;

	// mapp2 = mapp;
	return 0;
}