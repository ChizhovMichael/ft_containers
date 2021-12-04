#include "srcs/stack.hpp"
#include <stack>
#include <cassert>

static void testConstructorDefault()
{
    ft::stack<int>     s1;
    ft::stack<char>    s2;
    ft::stack<char*>   s3;
    ft::stack<char**>  s4;

    assert(s1.size() == 0);
    assert(s2.size() == 0);
    assert(s3.size() == 0);
    assert(s4.size() == 0);

    assert(s1.empty());
    assert(s2.empty());
    assert(s3.empty());
    assert(s4.empty());
}

static void testConstructorCopy()
{
    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    ft::stack<int>     s1(s1_copied);
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    s1.pop();
    assert(s1.top() == 2);
    s1.pop();
    assert(s1.top() == 1);

    s2_copied.push('a');
    s2_copied.push('b');
    ft::stack<char>     s2(s2_copied);
    assert(s2.size() == 2);
    assert(s2.top() == 'b');
    s2.pop();
    assert(s2.top() == 'a');
}

static void testOperatorAssign()
{
    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    ft::stack<int>     s1 = s1_copied;
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    s1.pop();
    assert(s1.top() == 2);
    s1.pop();
    assert(s1.top() == 1);

    s2_copied.push('a');
    s2_copied.push('b');
    ft::stack<char>     s2 = s2_copied;
    assert(s2.size() == 2);
    assert(s2.top() == 'b');
    s2.pop();
    assert(s2.top() == 'a');
}

static void testTop()
{
    ft::stack<int> s1;

    s1.push(1);
    assert(s1.size() == 1);
    assert(s1.top() == 1);
    s1.push(2);
    assert(s1.size() == 2);
    assert(s1.top() == 2);
    s1.push(3);
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    s1.push(4);
    assert(s1.size() == 4);
    assert(s1.top() == 4);
    s1.push(5);
    assert(s1.size() == 5);
    assert(s1.top() == 5);
    s1.push(6);
    assert(s1.size() == 6);
    assert(s1.top() == 6);
}

static void testPush()
{
    ft::stack<int> s1;

    s1.push(1);
    assert(s1.size() == 1);
    assert(s1.top() == 1);
    s1.push(2);
    assert(s1.size() == 2);
    assert(s1.top() == 2);
    s1.push(3);
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    s1.push(4);
    assert(s1.size() == 4);
    assert(s1.top() == 4);
    s1.push(5);
    assert(s1.size() == 5);
    assert(s1.top() == 5);
    s1.push(6);
    assert(s1.size() == 6);
    assert(s1.top() == 6);
}

static void testPop()
{
    ft::stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.pop();
    assert(s1.size() == 5);
    assert(s1.top() == 5);
    s1.pop();
    assert(s1.size() == 4);
    assert(s1.top() == 4);
    s1.pop();
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    s1.pop();
    assert(s1.size() == 2);
    assert(s1.top() == 2);
    s1.pop();
    assert(s1.size() == 1);
    assert(s1.top() == 1);
    s1.pop();
    assert(s1.size() == 0);
}

static void testOperatorEqual()
{
    ft::stack<int> s1;
    ft::stack<int> s2;

    assert(s1 == s2);
    assert(s2 == s1);
    s1.push(1);
    assert(s1 != s2);
    assert(s2 != s1);
    s2.push(1);
    assert(s1 == s2);
    assert(s2 == s1);
    s2.push(2);
    assert(s1 != s2);
    assert(s2 != s1);
}

static void testOperatorCompar()
{
    ft::stack<char> s1;
    ft::stack<char> s2;
    ft::stack<char> s3;

    s1.push('a');

    s2.push('a');
    s2.push('a');

    s3.push('a');
    s3.push('a');
    s3.push('a');

    assert(s1 < s2);
    assert(s1 < s3);
    assert(s2 > s1);
    assert(s2 < s3);
    assert(s3 > s1);
    assert(s3 > s2);

    assert(s1 <= s1);
    assert(s1 >= s1);
    assert(s2 <= s2);
    assert(s2 >= s2);
    assert(s3 <= s3);
    assert(s3 >= s3);

    ft::stack<char> s4;
    s4.push('a');
    s4.push('b');

    assert(s4 > s1);
    assert(s4 > s2);
    assert(s4 > s3);

    assert(s4 <= s4);
    assert(s4 >= s4);
}

void test_stack()
{
    testConstructorDefault();
    testConstructorCopy();
    testOperatorAssign();

    testTop();
    testPush();
    testPop();

    testOperatorEqual();
    testOperatorCompar();
}