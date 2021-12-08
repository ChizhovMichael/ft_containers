/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:28:22 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/08 21:28:27 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/stack.hpp"
#include "test.hpp"
#include <stack>
#include <iomanip>

static void testConstructorDefault()
{
    ft::stack<int>     s1;
    ft::stack<char>    s2;
    ft::stack<char*>   s3;
    ft::stack<char**>  s4;
    std::stack<int>     s1s;
    std::stack<char>    s2s;
    std::stack<char*>   s3s;
    std::stack<char**>  s4s;

    test_compare(
        s1.size() == s1s.size() &&
        s2.size() == s2s.size() &&
        s3.size() == s3s.size() &&
        s4.size() == s4s.size());

    test_compare(
        s1.empty() == s1s.empty() &&
        s2.empty() == s2s.empty() &&
        s3.empty() == s3s.empty() &&
        s4.empty() == s4s.empty());
}

static void testConstructorCopy()
{
    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;
    std::stack<int>     s1s_copied;
    std::stack<char>    s2s_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    s1s_copied.push(1);
    s1s_copied.push(2);
    s1s_copied.push(3);

    ft::stack<int>     s1(s1_copied);
    std::stack<int>     s1s(s1s_copied);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());

    s2_copied.push('a');
    s2_copied.push('b');
    s2s_copied.push('a');
    s2s_copied.push('b');
    ft::stack<char>     s2(s2_copied);
    std::stack<char>     s2s(s2s_copied);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s2.pop();
    s2s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
}

static void testOperatorAssign()
{
    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;
    std::stack<int>     s1s_copied;
    std::stack<char>    s2s_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    s1s_copied.push(1);
    s1s_copied.push(2);
    s1s_copied.push(3);
    ft::stack<int>     s1 = s1_copied;
    std::stack<int>     s1s = s1s_copied;
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());

    s2_copied.push('a');
    s2_copied.push('b');
    s2s_copied.push('a');
    s2s_copied.push('b');
    ft::stack<char>     s2 = s2_copied;
    std::stack<char>     s2s = s2s_copied;
    test_compare(
        s2.size() == s2s.size() && 
        s2.top() == s2s.top());
    s2.pop();
    s2s.pop();
    test_compare(
        s2.size() == s2s.size() && 
        s2.top() == s2s.top());
}

static void testTop()
{
    ft::stack<int> s1;
    std::stack<int> s1s;

    s1.push(1);
    s1s.push(1);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(2);
    s1s.push(2);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(3);
    s1s.push(3);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(4);
    s1s.push(4);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(5);
    s1s.push(5);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(6);
    s1s.push(6);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
}

static void testPush()
{
    ft::stack<int> s1;
    std::stack<int> s1s;

    s1.push(1);
    s1s.push(1);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(2);
    s1s.push(2);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(3);
    s1s.push(3);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(4);
    s1s.push(4);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(5);
    s1s.push(5);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.push(6);
    s1s.push(6);
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
}

static void testPop()
{
    ft::stack<int> s1;
    std::stack<int> s1s;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.pop();
    s1s.push(1);
    s1s.push(2);
    s1s.push(3);
    s1s.push(4);
    s1s.push(5);
    s1s.push(6);
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(
        s1.size() == s1s.size() && 
        s1.top() == s1s.top());
    s1.pop();
    s1s.pop();
    test_compare(s1.size() == s1s.size());
}

static void testOperatorEqual()
{
    ft::stack<int> s1;
    ft::stack<int> s2;
    std::stack<int> s1s;
    std::stack<int> s2s;

    test_compare(s1 == s2 && s1s == s2s);
    test_compare(s2 == s1 && s2s == s1s);
    s1.push(1);
    s1s.push(1);
    test_compare(s1 != s2 && s1s != s2s);
    test_compare(s2 != s1 && s2s != s1s);
    s2.push(1);
    s2s.push(1);
    test_compare(s1 == s2 && s1s == s2s);
    test_compare(s2 == s1 && s2s == s1s);
    s2.push(2);
    s2s.push(2);
    test_compare(s1 != s2 && s1s != s2s);
    test_compare(s2 != s1 && s2s != s1s);
}

static void testOperatorCompar()
{
    ft::stack<char> s1;
    ft::stack<char> s2;
    ft::stack<char> s3;
    std::stack<char> s1s;
    std::stack<char> s2s;
    std::stack<char> s3s;

    s1.push('a');
    s1s.push('a');

    s2.push('a');
    s2.push('a');
    s2s.push('a');
    s2s.push('a');

    s3.push('a');
    s3.push('a');
    s3.push('a');
    s3s.push('a');
    s3s.push('a');
    s3s.push('a');

    test_compare(s1 < s2 && s1s < s2s);
    test_compare(s1 < s3 && s1s < s3s);
    test_compare(s2 > s1 && s2s > s1s);
    test_compare(s2 < s3 && s2s < s3s);
    test_compare(s3 > s1 && s3s > s1s);
    test_compare(s3 > s2 && s3s > s2s);

    test_compare(s1 <= s1 && s1s <= s1s);
    test_compare(s1 >= s1 && s1s >= s1s);
    test_compare(s2 <= s2 && s2s <= s2s);
    test_compare(s2 >= s2 && s2s >= s2s);
    test_compare(s3 <= s3 && s3s <= s3s);
    test_compare(s3 >= s3 && s3s >= s3s);

    ft::stack<char> s4;
    std::stack<char> s4s;
    s4.push('a');
    s4.push('b');
    s4s.push('a');
    s4s.push('b');

    test_compare(s4 > s1 && s4s > s1s);
    test_compare(s4 > s2 && s4s > s2s);
    test_compare(s4 > s3 && s4s > s3s);
}

void test_stack()
{
    std::cout << std::left << std::setw(28) << "Test constructor (default):";
    testConstructorDefault();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (copy):";
    testConstructorCopy();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator (=):";
    testOperatorAssign();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test top:";
    testTop();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test push:";
    testPush();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test pop:";
    testPop();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test operator(==,!=): ";
    testOperatorEqual();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator(>,<, >=, <=): ";
    testOperatorCompar();
    std::cout << std::endl;
}
