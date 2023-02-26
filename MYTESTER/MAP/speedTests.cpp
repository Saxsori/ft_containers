/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speedTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:59:17 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 19:40:23 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/map.hpp"
#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <sys/time.h>


#ifndef NAMESPACE
#define NAMESPACE std
#endif


int main(int argc, char *argv[])
{
	(void) argc;
	struct timeval start, end;
    NAMESPACE::map<int, int> testMap;
	int SIZE = std::atoi(argv[1]);
   
    // Test the insert() operation	
	gettimeofday(&start, NULL);
    for (int i = 0; i < SIZE; ++i)
		testMap.insert(NAMESPACE::pair<const int, int>(i, i + 1));
	
    testMap.erase(testMap.begin(), testMap.end());
	
	gettimeofday(&end, NULL);
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    std::cout << std::fixed << std::setprecision(6) << elapsed_time << "s" << std::endl;
    return 0;
}