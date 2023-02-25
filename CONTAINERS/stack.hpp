/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:49:50 by aaljaber          #+#    #+#             */
/*   Updated: 2023/02/25 15:51:19 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Vector.hpp"

namespace ft
{
    /*
        * stack is an adaptor container
        ? container adapter is a type of container that simplifies or modifies 
        ? the interface to an underlying container.
        
        ! Container adapters do not implement their own data structures but rely 
        ! on an existing container to manage the elements.
        
        ? Container adapters make it easier to use an existing container 
        ? by providing a specific interface, such as LIFO or FIFO, without directly 
        ? accessing the underlying container
    */
    template <typename T, typename Container = ft::vector<T> >
    class stack
    {
        private:
            Container   c;
        public:
            typedef T                                       value_type;
            typedef Container                               container_type;
            typedef typename Container::size_type           size_type;
            
            explicit stack (const container_type& ctnr = container_type()):c(ctnr){}
            stack( const stack& other ) {c = other.c;}
            stack& operator=( const stack& other ) {c = other.c; return *this;}
            bool empty() const {return (c.empty());}
            size_type size() const {return (c.size());}
            value_type& top() {return(c.back());}
            const value_type& top() const {return(*c.back());}
            void push (const value_type& val){c.push_back(val);}
            void pop() {c.pop_back();}
            ~stack() {};
            // Define the relational operator overloads inside the class definition
            friend bool operator==(const stack& lhs, const stack& rhs){return lhs.c == rhs.c;}
            friend bool operator!=(const stack& lhs, const stack& rhs){return !(lhs == rhs);}
            friend bool operator<(const stack& lhs, const stack& rhs){return lhs.c < rhs.c;}
            friend bool operator<=(const stack& lhs, const stack& rhs){return !(rhs < lhs);}
            friend bool operator>(const stack& lhs, const stack& rhs){return rhs < lhs;}
            friend bool operator>=(const stack& lhs, const stack& rhs){return !(lhs < rhs);}
    };
    template <class T, class Container>
      bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c == rhs.c;}
    template <class T, class Container>
      bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(lhs == rhs);}
    template <class T, class Container>
      bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c < rhs.c;}
    template <class T, class Container>
      bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(rhs < lhs);}
    template <class T, class Container>
      bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return rhs < lhs;}
    template <class T, class Container>
      bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){return !(lhs < rhs);}

}
