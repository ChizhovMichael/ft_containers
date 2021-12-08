/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:24:58 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/08 20:25:04 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector.hpp"
#include "test.hpp"
#include <iomanip>
#include <vector>

static void testConstructorDefault()
{
    ft::vector<int> v1;
    std::vector<int> v1_stl;
    test_compare(v1.empty() == v1_stl.empty());
    test_compare(v1.size() == v1_stl.size());
    test_compare(v1.capacity() == v1_stl.capacity());
    test_compare(v1.max_size() == v1_stl.max_size());

    ft::vector<char> v2;
    std::vector<char> v2_stl;
    test_compare(v2.empty() == v2_stl.empty());
    test_compare(v2.size() == v2_stl.size());
    test_compare(v2.capacity() == v2_stl.capacity());
    test_compare(v2.max_size() == v2_stl.max_size());

    ft::vector< ft::vector<char> > v3;
    std::vector< std::vector<char> > v3_stl;
    test_compare(v3.empty() == v3_stl.empty());
    test_compare(v3.size() == v3_stl.size());
    test_compare(v3.capacity() == v3_stl.capacity());
}

static void testConstructorFill()
{
    ft::vector<int> v1(0);
    std::vector<int> v1s(0);
    test_compare(
        v1.empty() == v1s.empty() &&
        v1.size() == v1s.size() && 
        v1.capacity() == v1s.capacity());

    ft::vector<int> v2(3);
    std::vector<int> v2s(3);
    test_compare(
        v2.empty() == v2s.empty() &&
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        if (v2[i] != int())
            test_compare(false);
    test_compare(true);
        

    ft::vector<std::string> v3(5);
    std::vector<std::string> v3s(5);
    test_compare(
        v3.empty() == v3s.empty() &&
        v3.size() == v3s.size() &&
        v3.capacity() == v3s.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        if (v3[i] != std::string())
            test_compare(false);
    test_compare(true);

    ft::vector<float> v4(6, 42.0f);
    std::vector<float> v4s(6, 42.0f);
    test_compare(
        v4.empty() == v4s.empty() &&
        v4.size() == v4s.size() &&
        v4.capacity() == v4s.capacity());
    for (size_t i = 0; i < v4.size(); i++)
        if (v4[i] != float(42.0))
            test_compare(false);
    test_compare(true);

    ft::vector<std::string> v5(2, "bonjour");
    std::vector<std::string> v5s(2, "bonjour");
    test_compare(
        v5.empty() == v5s.empty() &&
        v5.size() == v5s.size() &&
        v5.capacity() == v5s.capacity());
    for (size_t i = 0; i < v5.size(); i++)
        if (v5[i] != std::string("bonjour"))
            test_compare(false);
    test_compare(true);

    ft::vector<char> v6(5, 'a');
    std::vector<char> v6s(5, 'a');
    test_compare(
        v6.empty() == v6s.empty() &&
        v6.size() == v6s.size() &&
        v6.capacity() == v6s.capacity());
    for (size_t i = 0; i < v6.size(); i++)
        if (v6[i] != 'a')
            test_compare(false);
    test_compare(true);

    ft::vector<int> v7(6, 5);
    std::vector<int> v7s(6, 5);
    test_compare(
        v7.empty() == v7s.empty() &&
        v7.size() == v7s.size() &&
        v7.capacity() == v7s.capacity());
    for (size_t i = 0; i < v7.size(); i++)
        if (v7[i] != 5)
            test_compare(false);
    test_compare(true);
    
    ft::vector<char> v8('6', '5');
    std::vector<char> v8s('6', '5');
    test_compare(
        v8.empty() == v8s.empty() &&
        v8.size() == v8s.size() &&
        v8.capacity() == v8s.capacity());
    for (size_t i = 0; i < v8.size(); i++)
        if (v8[i] != v8s[i])
            test_compare(false);
    test_compare(true);
}

static void testConstructorRange()
{
    int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);
    test_compare(
        v1.empty() == v1s.empty() &&
        v1.size() == v1s.size() && 
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    ft::vector<std::string> v2(arr2, arr2 + 3);
    std::vector<std::string> v2s(arr2, arr2 + 3);
    test_compare(
        v2.empty() == v2s.empty() &&
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        if (v2[i] != arr2[i])
            test_compare(false);
    test_compare(true);

    ft::vector<float> v3(arr3, arr3 + 4);
    std::vector<float> v3s(arr3, arr3 + 4);
    test_compare(
        v3.empty() == v3s.empty() &&
        v3.size() == v3s.size() &&
        v3.capacity() == v3s.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        if (v3[i] != arr3[i])
            test_compare(false);
    test_compare(true);
}

static void testConstructorCopy()
{
    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::vector<int>                 v1_copied(arr1, arr1 + 5);
    std::vector<int>                v1s_copied(arr1, arr1 + 5);
    ft::vector<std::string>         v2_copied(arr2, arr2 + 3);
    std::vector<std::string>        v2s_copied(arr2, arr2 + 3);
    ft::vector<float>               v3_copied(6, 42.0f);
    std::vector<float>              v3s_copied(6, 42.0f);
    ft::vector< ft::vector<char*> > v4_copied;
    std::vector< std::vector<char*> > v4s_copied;

    ft::vector<int> v1(v1_copied);
    std::vector<int> v1s(v1s_copied);
    test_compare(
        v1.empty() == v1s.empty() &&
        v1_copied.empty() == v1s_copied.empty() &&
        v1.size() == v1s.size() && 
        v1_copied.size() == v1s_copied.size() &&
        v1.capacity() == v1s.capacity() && 
        v1_copied.capacity() == v1s_copied.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != v1_copied[i])
            test_compare(false);
    test_compare(true);
    v1[0] = 0;
    test_compare(v1[0] == 0 && v1_copied[0] == 1);

    ft::vector<std::string> v2(v2_copied);
    std::vector<std::string> v2s(v2s_copied);
    test_compare(
        v2.empty() == v2s.empty() &&
        v2_copied.empty() == v2s_copied.empty() &&
        v2.size() == v2s.size() && 
        v2_copied.size() == v2s_copied.size() &&
        v2.capacity() == v2s.capacity() && 
        v2_copied.capacity() == v2s_copied.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        if (v2[i] != v2_copied[i])
            test_compare(false);
    test_compare(true);
        
    v2[0] = "aaa";
    test_compare(v2[0] == "aaa" && v2_copied[0] == "bonjour");
    v2[1] = "bbb";
    test_compare(v2[1] == "bbb" && v2_copied[1] == "je");
    v2[2] = "ccc";
    test_compare(v2[2] == "ccc" && v2_copied[2] == "suis");

    ft::vector<float> v3(v3_copied);
    std::vector<float> v3s(v3s_copied);
    test_compare(
        v3.empty() == v3s.empty() &&
        v3_copied.empty() == v3s_copied.empty() &&
        v3.size() == v3s.size() && 
        v3_copied.size() == v3s_copied.size() &&
        v3.capacity() == v3s.capacity() && 
        v3_copied.capacity() == v3s_copied.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        if (v3[i] != v3_copied[i])
            test_compare(false);
    test_compare(true);

    v3[5] = 19.19f;
    test_compare(v3[5] == 19.19f && v3_copied[0] == 42.0);

    ft::vector< ft::vector<char*> > v4(v4_copied);
    std::vector< std::vector<char*> > v4s(v4s_copied);
    test_compare(
        v4.empty() == v4s.empty() &&
        v4_copied.empty() == v4s_copied.empty() &&
        v4.size() == v4s.size() && 
        v4_copied.size() == v4s_copied.size() &&
        v4.capacity() == v4_copied.capacity());
}

static void testOperatorAssign()
{
    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::vector<int>                 v1_duplicated(arr1, arr1 + 5);
    ft::vector<std::string>         v2_duplicated(arr2, arr2 + 3);
    ft::vector<float>               v3_duplicated(6, 42.0f);
    ft::vector< ft::vector<char*> > v4_duplicated;

    // stl
    std::vector<int>                 v1_duplicated_stl(arr1, arr1 + 5);
    std::vector<std::string>         v2_duplicated_stl(arr2, arr2 + 3);
    std::vector<float>               v3_duplicated_stl(6, 42.0f);
    std::vector< std::vector<char*> > v4_duplicated_stl;    

    ft::vector<int>     v1;
    std::vector<int>    v1_stl;
    v1 = v1_duplicated;
    v1_stl = v1_duplicated_stl;
    test_compare(
        (v1.empty() == v1_stl.empty()) && 
        (v1_duplicated.empty() == v1_duplicated_stl.empty()) &&
        (v1.size() == v1_stl.size()) && 
        (v1_duplicated.size() == v1_duplicated_stl.size()) &&
        (v1.capacity() == v1_stl.capacity()) && 
        (v1_duplicated.capacity() == v1_duplicated_stl.capacity())
    );
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v1_stl[i])
            test_compare(false);
        if (v1_duplicated[i] != v1_duplicated_stl[i])
            test_compare(false);
    }
    test_compare(true);

    v1[0] = 0;
    test_compare(v1[0] == 0 && v1_duplicated[0] == 1);

    ft::vector<std::string> v2(10, "zzz");
    std::vector<std::string> v2_stl(10, "zzz");
    v2 = v2_duplicated;
    v2_stl = v2_duplicated_stl;
    test_compare(
        (v2.empty() == v2_stl.empty()) && 
        (v2_duplicated.empty() == v2_duplicated_stl.empty()) &&
        (v2.size() == v2_stl.size()) && 
        (v2_duplicated.size() == v2_duplicated_stl.size()) &&
        (v2.capacity() == v2_stl.capacity()) && 
        (v2_duplicated.capacity() == v2_duplicated_stl.capacity())
    );
    for (size_t i = 0; i < v2.size(); i++)
        if (v2[i] != v2_duplicated[i])
            test_compare(false);
    test_compare(true);
    v2[0] = "aaa";
    test_compare(v2[0] == "aaa" && v2_duplicated[0] == "bonjour");
    v2[1] = "bbb";
    test_compare(v2[1] == "bbb" && v2_duplicated[1] == "je");
    v2[2] = "ccc";
    test_compare(v2[2] == "ccc" && v2_duplicated[2] == "suis");

    // v2 = v2_duplicated
    ft::vector<float> v3(v3_duplicated);
    std::vector<float> v3_stl(v3_duplicated_stl);
    v3 = v3_duplicated;
    v3_stl = v3_duplicated_stl;
    test_compare(
        (v3.empty() == v3_stl.empty()) && 
        (v3_duplicated.empty() == v3_duplicated_stl.empty()) &&
        (v3.size() == v3_stl.size()) && 
        (v3_duplicated.size() == v3_duplicated_stl.size()) &&
        (v3.capacity() == v3_stl.capacity()) && 
        (v3_duplicated.capacity() == v3_duplicated_stl.capacity())
    );
    for (size_t i = 0; i < v3.size(); i++)
        if (v3[i] != v3_duplicated[i])
            test_compare(false);
    test_compare(true);
    v3[5] = 19.19f;
    test_compare(v3[5] == 19.19f && v3_duplicated[0] == 42.0f);

    ft::vector< ft::vector<char*> > v4(2, ft::vector<char*>(2, NULL));
    std::vector< std::vector<char*> > v4_stl(2, std::vector<char*>(2, NULL));
    v4 = v4_duplicated;
    v4_stl = v4_duplicated_stl;
    test_compare(
        (v4.empty() == v4_stl.empty()) && 
        (v4_duplicated.empty() == v4_duplicated_stl.empty()) &&
        (v4.size() == v4_stl.size()) && 
        (v4_duplicated.size() == v4_duplicated_stl.size()) &&
        (v4.capacity() == v4_stl.capacity()) && 
        (v4_duplicated.capacity() == v4_duplicated_stl.capacity())
    );
}

static void testBegin()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    ft::vector<int>::iterator v1_it = v1.begin();
    std::vector<int>::iterator v1s_it = v1s.begin();

    test_compare(*v1_it == *v1s_it);
    test_compare(*(int*)(v1_it.operator->()) == *(int*)(v1s_it.operator->()));
    test_compare(
        v1_it[0] == v1s_it[0] &&
        v1_it[1] == v1s_it[1] &&
        v1_it[2] == v1s_it[2] &&
        v1_it[3] == v1s_it[3] &&
        v1_it[4] == v1s_it[4]);


    test_compare(
        v1_it == v1.begin() &&
        v1_it != v1.rbegin().base() &&
        v1_it != v1.end() &&
        v1_it == v1.rend().base());

    test_compare(
        v1_it <= v1.begin() &&
        v1_it >= v1.begin() &&
        v1_it < v1.end() &&
        v1.end() > v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it + i) != arr1[i])
            test_compare(false);
    test_compare(true);

    for (size_t i = 0; v1_it != v1.end(); ++v1_it, i++)
        if (*v1_it != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(v1_it == v1.end());

    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it - 1 - i) != arr1[4 - i])
            test_compare(false);
    test_compare(true);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        if (*v1_it != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        if (*v1_it++ != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        if (*v1_it-- != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testEnd()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    ft::vector<int>::iterator v1_it = v1.end();
    std::vector<int>::iterator v1s_it = v1s.end();
    test_compare(
        v1_it[-1] == v1s_it[-1] &&
        v1_it[-2] == v1s_it[-2] &&
        v1_it[-3] == v1s_it[-3] &&
        v1_it[-4] == v1s_it[-4] &&
        v1_it[-5] == v1s_it[-5]);

    test_compare(
        v1_it == v1.end() &&
        v1_it != v1.begin() &&
        v1_it == v1.rbegin().base() &&
        v1_it != v1.rend().base());

    test_compare(
        v1_it >= v1.end() &&
        v1_it >= v1.end() &&
        v1_it <= v1.end() &&
        v1_it <= v1.end() &&
        v1_it > v1.begin() &&
        v1.begin() < v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it - i - 1) != arr1[4 - i])
            test_compare(false);
    test_compare(true);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        if (*v1_it != arr1[4 - i])
            test_compare(false);
    test_compare(true);

    test_compare(
        v1_it == v1.begin() &&
        *v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it + i) != arr1[i])
            test_compare(false);
    test_compare(true);

    for (size_t i = 0; i < v1.size(); i++)
        if (*v1_it++ != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        if (*v1_it-- != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testRbegin()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    ft::vector<int>::reverse_iterator v1_it = v1.rbegin();
    std::vector<int>::reverse_iterator v1s_it = v1s.rbegin();
    test_compare(
        v1_it[0] == v1s_it[0] &&
        v1_it[1] == v1s_it[1] &&
        v1_it[2] == v1s_it[2] &&
        v1_it[3] == v1s_it[3] &&
        v1_it[4] == v1s_it[4]);

    test_compare(
        v1_it == v1.rbegin() &&
        v1_it != v1.rend() &&
        v1_it.base() != v1.begin() &&
        v1_it.base() == v1.end());

    test_compare(
        v1_it >= v1.rbegin() &&
        v1_it >= v1.rbegin() &&
        v1_it <= v1.rbegin() &&
        v1_it <= v1.rbegin() &&
        v1_it.base() > v1.begin() &&
        v1_it.base() <= v1.end() &&
        v1_it < v1.rend());


    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it + i) != arr1[4 - i])
            test_compare(false);
    test_compare(true);

    for (size_t i = 0; i < v1.size(); i++)
        if (*v1_it++ != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(v1_it == v1.rend());
}

static void testRend()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    ft::vector<int>::reverse_iterator v1_it = v1.rend();
    std::vector<int>::reverse_iterator v1s_it = v1s.rend();
    test_compare(
        v1_it[-1] == v1s_it[-1] &&
        v1_it[-2] == v1s_it[-2] &&
        v1_it[-3] == v1s_it[-3] &&
        v1_it[-4] == v1s_it[-4] &&
        v1_it[-5] == v1s_it[-5]);

    test_compare(
        v1_it == v1.rend() &&
        v1_it != v1.rbegin() &&
        v1_it.base() == v1.begin() &&
        v1_it.base() != v1.end());

    test_compare(v1_it > v1.rbegin() && v1_it.base() < v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        if (*(v1_it - i) != arr1[i])
            test_compare(false);
    test_compare(true);
}

static void testResize()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    v1.resize(7);
    v1s.resize(7);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
    for (size_t i = 5; i < v1.size(); i++)
        if (v1[i] != int())
            test_compare(false);
    test_compare(true);

    v1.resize(10, 42);
    v1s.resize(10, 42);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
    for (size_t i = 5; i < 7; i++)
        if (v1[i] != int())
            test_compare(false);
    test_compare(true);
    for (size_t i = 7; i < v1.size(); i++)
        if (v1[i] != 42)
            test_compare(false);
    test_compare(true);

    size_t prev_capacity = v1.capacity();
    v1.resize(10);
    v1s.resize(10);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity() &&
        v1.capacity() == prev_capacity);
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
    for (size_t i = 5; i < 7; i++)
        if (v1[i] != int())
            test_compare(false);
    test_compare(true);
    for (size_t i = 7; i < v1.size(); i++)
        if (v1[i] != 42)
            test_compare(false);
    test_compare(true);

    v1.resize(6);
    v1s.resize(6);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(v1[5] == int());

    v1.resize(1);
    v1s.resize(1);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == arr1[0]);

    v1.resize(0);
    v1s.resize(0);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
}

static void testReserve()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    v1.reserve(0);
    v1s.reserve(0);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    v1.reserve(5);
    v1s.reserve(5);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    v1.reserve(6);
    v1s.reserve(6);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    v1.reserve(30);
    v1s.reserve(30);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < v1.size(); i++)
         if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
}

static void testOperatorBracket()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    test_compare(v1[0] == v1s[0]);
    test_compare(v1[1] == v1s[1]);
    test_compare(v1[2] == v1s[2]);
    test_compare(v1[3] == v1s[3]);
    test_compare(v1[4] == v1s[4]);

    int&       mut  = v1[0];
    const int& imut = v1[0];
    test_compare(mut == 1);
    test_compare(imut == 1);
}

static void testAt()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    try
    {
        test_compare(v1.at(0) == v1s.at(0));
        test_compare(v1.at(1) == v1s.at(1));
        test_compare(v1.at(2) == v1s.at(2));
        test_compare(v1.at(3) == v1s.at(3));
        test_compare(v1.at(4) == v1s.at(4));

        int&       mut  = v1.at(0);
        const int& imut = v1.at(0);
        test_compare(mut == 1 && imut == 1);
    }
    catch (const std::exception& e) { test_compare(false); }

    try { v1.at(5); }
    catch (const std::out_of_range& e) { test_compare(true); }
    catch (const std::exception& e)    { test_compare(false); }

    try { v1.at(-1); }
    catch (const std::out_of_range& e) { test_compare(true); }
    catch (const std::exception& e)    { test_compare(false); }
}

static void testFront()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);
    int&       mut  = v1.front();
    const int& imut = v1.front();
    int&       muts  = v1s.front();
    const int& imuts = v1s.front();
    test_compare(mut == muts);
    test_compare(imut == imuts);
    test_compare(mut == 1);
    test_compare(imut == 1);
}

static void testBack()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);
    int&       mut  = v1.back();
    const int& imut = v1.back();
    int&       muts  = v1s.back();
    const int& imuts = v1s.back();
    test_compare(mut == muts);
    test_compare(imut == imuts);
    test_compare(mut == 5);
    test_compare(imut == 5);
}

static void testAssign()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    v1.assign(arr1 + 1, arr1 + 4);
    v1s.assign(arr1 + 1, arr1 + 4);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v1[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);

    v1.assign((size_t)6, (int)42);
    v1s.assign((size_t)6, (int)42);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 6; i++)
        if (v1[i] != 42)
            test_compare(false);
    test_compare(true);

    // fml
    ft::vector< ft::vector<int>::size_type > ve(arr1, arr1 + 5);
    std::vector< std::vector<int>::size_type > ves(arr1, arr1 + 5);
    ve.assign(6, 42);
    ves.assign(6, 42);
    test_compare(
        ve.size() == ves.size() &&
        ve.capacity() == ves.capacity());
    for (size_t i = 0; i < 6; i++)
        if (ve[i] != ves[i])
            test_compare(false);
    test_compare(true);
}

static void testPushBack()
{
    ft::vector<int> v1;
    std::vector<int> v1s;

    v1.push_back(1);
    v1s.push_back(1);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == v1s[0] && v1[0] == 1);

    v1.push_back(2);
    v1s.push_back(2);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2);

    v1.push_back(3);
    v1s.push_back(3);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == 3);

    v1.push_back(4);
    v1s.push_back(4);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == 3 &&
        v1[3] == v1s[3] && v1[3] == 4);
}

static void testPopBack()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);

    v1.pop_back();
    v1s.pop_back();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == 3 &&
        v1[3] == v1s[3] && v1[3] == 4);

    v1.pop_back();
    v1s.pop_back();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == 3);

    v1.pop_back();
    v1s.pop_back();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2);

    v1.pop_back();
    v1s.pop_back();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == v1s[0] && v1[0] == 1);

    v1.pop_back();
    v1s.pop_back();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
}

static void testInsert()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1;
    ft::vector<int>::iterator it;
    std::vector<int> v1s;
    std::vector<int>::iterator its;

    it = v1.insert(v1.end(), 1);
    its = v1s.insert(v1s.end(), 1);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(*it == 1 && v1[0] == v1s[0] && v1[0] == 1);

    it = v1.insert(v1.end(), 2);
    its = v1s.insert(v1s.end(), 2);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        *it == 2 &&
        v1[0] == v1s[0] && v1[0] == 1 &&
        v1[1] == v1s[1] && v1[1] == 2);

    it = v1.insert(v1.begin(), 0);
    its = v1s.insert(v1s.begin(), 0);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        *it == 0 &&
        v1[0] == v1s[0] && v1[0] == 0 &&
        v1[1] == v1s[1] && v1[1] == 1 &&
        v1[2] == v1s[2] && v1[2] == 2);

    v1.insert(v1.begin() + 1, arr1 + 1, arr1 + 4);
    v1s.insert(v1s.begin() + 1, arr1 + 1, arr1 + 4);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 0 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == 3 &&
        v1[3] == v1s[3] && v1[3] == 4 &&
        v1[4] == v1s[4] && v1[4] == 1 &&
        v1[5] == v1s[5] && v1[5] == 2);

    v1.insert(v1.begin() + 2, (size_t)3, (int)-1);
    v1s.insert(v1s.begin() + 2, (size_t)3, (int)-1);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(
        v1[0] == v1s[0] && v1[0] == 0 &&
        v1[1] == v1s[1] && v1[1] == 2 &&
        v1[2] == v1s[2] && v1[2] == -1 &&
        v1[3] == v1s[3] && v1[3] == -1 &&
        v1[4] == v1s[4] && v1[4] == -1 &&
        v1[5] == v1s[5] && v1[5] == 3 &&
        v1[6] == v1s[6] && v1[6] == 4 &&
        v1[7] == v1s[7] && v1[7] == 1 &&
        v1[8] == v1s[8] && v1[8] == 2);
}

static void testErase()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int>::iterator it;
    std::vector<int> v1s(arr1, arr1 + 5);
    std::vector<int>::iterator its;

    it = v1.erase(v1.begin());
    its = v1s.erase(v1s.begin());
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 4; i++)
        if (v1[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);
    test_compare(*it == 2);

    it = v1.erase(v1.end() - 1);
    its = v1s.erase(v1s.end() - 1);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v1[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);
    test_compare(it == v1.end());

    it = v1.erase(v1.end() - 2);
    its = v1s.erase(v1s.end() - 2);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == v1s[0]);
    test_compare(v1[1] == v1s[1]);
    test_compare(*it == 4);

    v1.assign(arr1, arr1 + 5);
    v1s.assign(arr1, arr1 + 5);
    it = v1.erase(v1.begin() + 1, v1.begin() + 3);
    its = v1s.erase(v1s.begin() + 1, v1s.begin() + 3);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == v1s[0]);
    test_compare(v1[1] == v1s[1]);
    test_compare(v1[2] == v1s[2]);
    test_compare(*it == 4);

    it = v1.erase(v1.begin() + 1, v1.end());
    its = v1s.erase(v1s.begin() + 1, v1s.end());
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    test_compare(v1[0] == v1s[0]);
    test_compare(it == v1.end());
}

static void testSwap()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);
    std::vector<int> v1s(arr1, arr1 + 5);
    std::vector<int> v2s(arr1 + 1, arr1 + 4);

    v1.swap(v2);
    v1s.swap(v2s);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v1[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);

    test_compare(
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v2[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    v2.swap(v1);
    v2s.swap(v1s);
    test_compare(
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v2[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);

    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
}

static void testClear()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    std::vector<int> v1s(arr1, arr1 + 5);
    v1.clear();
    v1s.clear();
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
}

static void testOperatorEqual()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);
    ft::vector<int> v3(v1);
    std::vector<int> v1s(arr1, arr1 + 5);
    std::vector<int> v2s(arr1 + 1, arr1 + 4);
    std::vector<int> v3s(v1s);

    test_compare(v1 != v2 && v1 == v3 && v1s != v2s && v1s == v3s);
    test_compare(v2 != v1 && v2 != v3 && v2s != v1s && v2s != v3s);
    test_compare(v3 == v1 && v3 != v2 && v3s == v1s && v3s != v2s);

    v3[0] = 0;
    v3s[0] = 0;
    test_compare(v1 != v3 && v3 != v1 && v1s != v3s && v3s != v1s);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::vector<char> v1(s1.begin(), s1.end());
    ft::vector<char> v2(s2.begin(), s2.end());
    ft::vector<char> v3(s3.begin(), s3.end());
    std::vector<char> v1s(s1.begin(), s1.end());
    std::vector<char> v2s(s2.begin(), s2.end());
    std::vector<char> v3s(s3.begin(), s3.end());

    test_compare(v1 < v2 && v1 > v3 && v1s < v2s && v1s > v3s);
    test_compare(v1 <= v2 && v1 >= v3 && v1s <= v2s && v1s >= v3s);
    test_compare(v1 <= v1 && v1 >= v1 && v1s <= v1s && v1s >= v1s);

    test_compare(v2 > v1 && v2 > v3 && v2s > v1s && v2s > v3s);
    test_compare(v2 >= v1 && v2 >= v3 && v2s >= v1s && v2s >= v3s);
    test_compare(v2 <= v2 && v2 >= v2 && v2s <= v2s && v2s >= v2s);

    test_compare(v3 < v1 && v3 < v2 && v3s < v1s && v3s < v2s);
    test_compare(v3 <= v1 && v3 <= v2 && v3s <= v1s && v3s <= v2s);
    test_compare(v3 <= v3 && v3 >= v3 && v3s <= v3s && v3s >= v3s);
}

static void testSwapFunc()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);
    std::vector<int> v1s(arr1, arr1 + 5);
    std::vector<int> v2s(arr1 + 1, arr1 + 4);

    ft::swap(v1, v2);
    std::swap(v1s, v2s);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v1[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);
    test_compare(
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v2[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    ft::swap(v1, v2);
    std::swap(v1s, v2s);
    test_compare(
        v2.size() == v2s.size() &&
        v2.capacity() == v2s.capacity());
    for (size_t i = 0; i < 3; i++)
        if (v2[i] != arr1[i + 1])
            test_compare(false);
    test_compare(true);
    test_compare(
        v1.size() == v1s.size() &&
        v1.capacity() == v1s.capacity());
    for (size_t i = 0; i < 5; i++)
        if (v1[i] != arr1[i])
            test_compare(false);
    test_compare(true);
}

static void testData()
{
    ft::vector<float>   v1(6, 42.0f);
    const float*        p;
    size_t              size;

    p = v1.data();
    size = v1.size();
    for (size_t i = 0; i < size; ++i)
        test_compare(p[i] == v1[i]);
}

void test_vector()
{
    std::cout << std::left << std::setw(28) << "Test constructor (default):";
	testConstructorDefault();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (fill):";
    testConstructorFill();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (range):";
    testConstructorRange();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (copy):";
    testConstructorCopy();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator (=):";
    testOperatorAssign();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test begin: ";
    testBegin();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test end: ";
    testEnd();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test rbegin: ";
    testRbegin();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test rend: ";
    testRend();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test resize: ";
    testResize();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test reverse: ";
    testReserve();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test operator ([]): ";
    testOperatorBracket();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test at: ";
    testAt();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test front: ";
    testFront();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test back: ";
    testBack();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test assign: ";
    testAssign();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test push back: ";
    testPushBack();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test pop back: ";
    testPopBack();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test insert: ";
    testInsert();
    std::cout << std::endl;
    
    std::cout << std::left << std::setw(28) << "Test erase: ";
    testErase();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test swap: ";
    testSwap();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test clear: ";
    testClear();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test operator(==,!=): ";
    testOperatorEqual();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator(>,<, >=, <=): ";
    testOperatorCompar();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test swap: ";
    testSwapFunc();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test data: ";
    testData();
    std::cout << std::endl;
}
