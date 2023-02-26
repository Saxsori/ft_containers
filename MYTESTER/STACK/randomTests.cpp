/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:59:22 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/26 19:08:24 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../CONTAINERS/stack.hpp"
#include <iostream>
#include <stack>

#ifndef NAMESPACE
#define NAMESPACE std
#endif

int main() {
    NAMESPACE::stack<int> myStack;

    // push elements onto stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // top element of stack
    std::cout << "Top element of stack: " << myStack.top() << std::endl;

    // pop element from stack
    myStack.pop();

    // size of stack
    std::cout << "Size of stack: " << myStack.size() << std::endl;

    // check if stack is empty
    std::cout << "Is stack empty: " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // create another stack and swap contents
    NAMESPACE::stack<int> myStack2;
    myStack2.push(4);
    myStack2.push(5);
    myStack2.push(6);
    std::swap(myStack, myStack2);

    // iterate through stack
    std::cout << "Stack elements: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}