/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:28:56 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/12 18:28:59 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/set.hpp"
#include "test.hpp"
#include <set>
#include <iomanip>

static void testConstructorDefault()
{
    ft::set<int> m1;
    std::set<int> m1s;
    test_compare(m1.empty() == m1s.empty());
    test_compare(m1.size() == m1s.size());
    test_compare(m1.max_size() == m1s.max_size());

    ft::set<char> m2;
    std::set<char> m2s;
    test_compare(m2.empty() == m2s.empty());
    test_compare(m2.size() == m2s.size());
    test_compare(m2.max_size() == m2s.max_size());

    ft::set< ft::set<char> > m3;
    std::set< std::set<char> > m3s;
    test_compare(m3.empty() == m3s.empty());
    test_compare(m3.size() == m3s.size());
}

static void testConstructorRange()
{
	int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::set<int> m1(arr1, arr1 + 5);
    std::set<int> m1s(arr1, arr1 + 5);
    ft::set<int>::iterator it1 = m1.begin();
    std::set<int>::iterator it1s = m1s.begin();
    test_compare(
        m1.empty() == m1s.empty() &&
        m1.size() == m1s.size());
    for (size_t i = 0; i < m1.size(); i++)
        if (*it1++ != *it1s++)
            test_compare(false);
    test_compare(true);

    ft::set<std::string> m2(arr2, arr2 + 3);
    std::set<std::string> m2s(arr2, arr2 + 3);
    ft::set<std::string>::iterator it2 = m2.begin();
    std::set<std::string>::iterator it2s = m2s.begin();
    test_compare(
        m2.empty() == m2s.empty() &&
        m2.size() == m2s.size());
    for (size_t i = 0; i < m2.size(); i++)
        if (*it2++ != *it2s++)
            test_compare(false);
    test_compare(true);

    ft::set<float> m3(arr3, arr3 + 4);
    std::set<float> m3s(arr3, arr3 + 4);
    ft::set<float>::iterator it3 = m3.begin();
    std::set<float>::iterator it3s = m3s.begin();
    test_compare(
        m3.empty() == m3s.empty() &&
        m3.size() == m3s.size());
    for (size_t i = 0; i < m3.size(); i++)
        if (*it3++ != *it3s++)
            test_compare(false);
    test_compare(true);
}

static void testConstructorCopy()
{
	char		arr1[5] = {'a', 'b', 'c', 'd', 'f'};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[6] = {42.1, 42.2, 42.3, 42.4, 42.5, 42.6};

    ft::set<char>					m1_copied(arr1, arr1 + 5);
    ft::set<std::string>			m2_copied(arr2, arr2 + 3);
    ft::set<float>					m3_copied(arr3, arr3 + 6);
    ft::set<ft::set<char*> >		m4_copied;

    std::set<char>                   m1s_copied(arr1, arr1 + 5);
    std::set<std::string>            m2s_copied(arr2, arr2 + 3);
    std::set<float>                  m3s_copied(arr3, arr3 + 6);
    std::set<std::set<char*> >       m4s_copied;

    ft::set<char> m1(m1_copied);
    ft::set<char>::iterator it1 = m1.begin();
    ft::set<char>::iterator it1c = m1_copied.begin();

    std::set<char> m1s(m1s_copied);
    std::set<char>::iterator it1s = m1s.begin();
    std::set<char>::iterator it1cs = m1s_copied.begin();

    test_compare(
        m1.empty() == m1s.empty() &&
        m1_copied.empty() == m1s_copied.empty() &&
        m1.size() == m1s.size() && 
        m1_copied.size() == m1s_copied.size());
    for (size_t i = 0; i < m1.size(); i++)
    {
        if (*it1 != *it1s || *it1c != *it1cs)
            test_compare(false);
        it1++;
        it1s++;
        it1c++;
        it1cs++;
    }
    test_compare(true);


    ft::set<std::string> m2(m2_copied);
    ft::set<std::string>::iterator it2 = m2.begin();
    ft::set<std::string>::iterator it2c = m2_copied.begin();

    std::set<std::string> m2s(m2s_copied);
    std::set<std::string>::iterator it2s = m2s.begin();
    std::set<std::string>::iterator it2cs = m2s_copied.begin();

    test_compare(
        m2.empty() == m2s.empty() &&
        m2_copied.empty() == m2s_copied.empty() &&
        m2.size() == m2s.size() && 
        m2_copied.size() == m2s_copied.size());
    for (size_t i = 0; i < m2.size(); i++)
    {
        if (*it2 != *it2s || *it2c != *it2cs)
            test_compare(false);
        it2++;
        it2s++;
        it2c++;
        it2cs++;
    }
    test_compare(true);

    ft::set<float> m3(m3_copied);
    ft::set<float>::iterator it3 = m3.begin();
    ft::set<float>::iterator it3c = m3_copied.begin();

    std::set<float> m3s(m3s_copied);
    std::set<float>::iterator it3s = m3s.begin();
    std::set<float>::iterator it3cs = m3s_copied.begin();

    test_compare(
        m3.empty() == m3s.empty() &&
        m3_copied.empty() == m3s_copied.empty() &&
        m3.size() == m3s.size() && 
        m3_copied.size() == m3s_copied.size());
    for (size_t i = 0; i < m3.size(); i++)
    {
        if (*it3 != *it3s || *it3c != *it3cs)
            test_compare(false);
        it3++;
        it3s++;
        it3c++;
        it3cs++;
    }
    test_compare(true);

    ft::set<ft::set<char*> > m4(m4_copied);
    std::set<std::set<char*> > m4s(m4s_copied);
    test_compare(
        m4.empty() == m4s.empty() &&
        m4_copied.empty() == m4s_copied.empty() &&
        m4.size() == m4s.size() && 
        m4_copied.size() == m4s_copied.size());
}

static void testConstructorCompare()
{
	int arr1[5] = {100, 200, 300, 400, 500};
	ft::set<int, more> m1(arr1, arr1 + 5);
	ft::set<int, less> m2(arr1, arr1 + 5);
    std::set<int, more> m1s(arr1, arr1 + 5);
    std::set<int, less> m2s(arr1, arr1 + 5);
	
    ft::set<int, more>::const_iterator it_m1 = m1.begin();
    ft::set<int, less>::const_iterator it_m2 = m2.begin();
    std::set<int, more>::const_iterator it_m1s = m1s.begin();
    std::set<int, less>::const_iterator it_m2s = m2s.begin();
    for (int i = 0; i < 5; i++)
    {
        if (*it_m1 != arr1[4 - i] || *it_m1 != *it_m1s)
            test_compare(false);
        if (*it_m2 != arr1[i] || *it_m2 != *it_m2s)
            test_compare(false);
		it_m1++;
		it_m2++;
        it_m1s++;
        it_m2s++;
    }
    test_compare(true);
    test_compare(true);
    test_compare(true);
    test_compare(true);
}

static void testConstructorFunc()
{
	bool(*fnmore_pt)(int, int) = fnmore;
	bool(*fnless_pt)(int, int) = fnless;

	int arr1[5] = {100, 200, 300, 400, 500};
	ft::set<int, bool(*)(int, int)> m1(fnmore_pt);
	ft::set<int, bool(*)(int, int)> m2(fnless_pt);
	ft::set<int, bool(*)(int, int)> m3(arr1, arr1 + 5, fnmore_pt);
	ft::set<int, bool(*)(int, int)> m4(arr1, arr1 + 5, fnless_pt);

    std::set<int, bool(*)(int, int)> m1s(fnmore_pt);
    std::set<int, bool(*)(int, int)> m2s(fnless_pt);
    std::set<int, bool(*)(int, int)> m3s(arr1, arr1 + 5, fnmore_pt);
    std::set<int, bool(*)(int, int)> m4s(arr1, arr1 + 5, fnless_pt);

    for (int i = 0; i < 5; i++)
    {
    	m1.insert(arr1[i]);
        m1s.insert(arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
    	m2.insert(arr1[i]);
        m2s.insert(arr1[i]);
    }


    ft::set<int, more>::const_iterator it_m1 = m1.begin();
    ft::set<int, less>::const_iterator it_m2 = m2.begin();
    ft::set<int, more>::const_iterator it_m3 = m3.begin();
    ft::set<int, less>::const_iterator it_m4 = m4.begin();

    std::set<int, more>::const_iterator it_m1s = m1s.begin();
    std::set<int, less>::const_iterator it_m2s = m2s.begin();
    std::set<int, more>::const_iterator it_m3s = m3s.begin();
    std::set<int, less>::const_iterator it_m4s = m4s.begin();
    for (int i = 0; i < 5; i++)
    {
        if (*it_m1 != arr1[4 - i] || *it_m1 != *it_m1s)
            test_compare(false);
        if (*it_m2 != arr1[i] || *it_m2 != *it_m2s)
            test_compare(false);
		if (*it_m3 != arr1[4 - i] || *it_m3 != *it_m3s)
            test_compare(false);
		if (*it_m4 != arr1[i] || *it_m4 != *it_m4s)
            test_compare(false);
		it_m1++;
		it_m2++;
		it_m3++;
		it_m4++;
        it_m1s++;
        it_m2s++;
        it_m3s++;
        it_m4s++;
    }
    test_compare(true);
    test_compare(true);
    test_compare(true);
    test_compare(true);
}

static void testOperatorAssign()
{
	char		arr1[5] = {'a', 'b', 'c', 'd', 'f'};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[6] = {42.1, 42.2, 42.3, 42.4, 42.5, 42.6};
    
    ft::set<char>					m1_duplicated(arr1, arr1 + 5);
    ft::set<std::string>			m2_duplicated(arr2, arr2 + 3);
    ft::set<float>					m3_duplicated(arr3, arr3 + 6);

    // stl
    std::set<char>					m1_duplicated_stl(arr1, arr1 + 5);
    std::set<std::string>			m2_duplicated_stl(arr2, arr2 + 3);
    std::set<float>					m3_duplicated_stl(arr3, arr3 + 6);

    ft::set<char>     m1;
    std::set<char>    m1s;
    m1 = m1_duplicated;
    m1s = m1_duplicated_stl;
    //
    ft::set<char>::const_iterator it1 = m1.begin();
    ft::set<char>::const_iterator it1d = m1_duplicated.begin();
    std::set<char>::const_iterator it1_stl = m1s.begin();
    std::set<char>::const_iterator it1d_stl = m1_duplicated_stl.begin();
    //
    test_compare(
        (m1.empty() == m1s.empty()) && 
        (m1_duplicated.empty() == m1_duplicated_stl.empty()) &&
        (m1.size() == m1s.size()) && 
        (m1_duplicated.size() == m1_duplicated_stl.size())
    );
    for (size_t i = 0; i < m1.size(); i++)
    {
        if (*it1++ != *it1_stl++)
            test_compare(false);
        if (*it1d++ != *it1d_stl++)
            test_compare(false);
    }
    test_compare(true);

    ft::set<std::string> m2;
    std::set<std::string> m2s;
    for (int i = 0; i < 10; ++i)
    	m2.insert("zzz");
    for (int i = 0; i < 10; ++i)
    	m2s.insert("zzz");
    m2 = m2_duplicated;
    m2s = m2_duplicated_stl;
    //
    ft::set<std::string>::const_iterator it2 = m2.begin();
    ft::set<std::string>::const_iterator it2d = m2_duplicated.begin();
    //
    test_compare(
        (m2.empty() == m2s.empty()) && 
        (m2_duplicated.empty() == m2_duplicated_stl.empty()) &&
        (m2.size() == m2s.size()) && 
        (m2_duplicated.size() == m2_duplicated_stl.size())
    );
    for (size_t i = 0; i < m2.size(); i++)
        if (*it2++ != *it2d++)
            test_compare(false);
    test_compare(true);

    ft::set<float> m3(m3_duplicated);
    std::set<float> m3s(m3_duplicated_stl);
    m3 = m3_duplicated;
    m3s = m3_duplicated_stl;
    //
    ft::set<float>::const_iterator it3 = m3.begin();
    ft::set<float>::const_iterator it3d = m3_duplicated.begin();
    //
    test_compare(
        (m3.empty() == m3s.empty()) && 
        (m3_duplicated.empty() == m3_duplicated_stl.empty()) &&
        (m3.size() == m3s.size()) && 
        (m3_duplicated.size() == m3_duplicated_stl.size())
    );
    for (size_t i = 0; i < m3.size(); i++)
        if (*it3++ != *it3d++)
            test_compare(false);
    test_compare(true);
}

static void testBegin()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);

    ft::set<int>::iterator m1_it = m1.begin();

    std::set<int>    m1s(arr1, arr1 + 5);

    std::set<int>::iterator m1_its = m1s.begin();

    test_compare(
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++
    );

    m1_it = m1.begin();
    m1_its = m1s.begin();

    test_compare(
        *m1_it++ == 1 &&
        *m1_it++ == 2 &&
        *m1_it++ == 3 &&
        *m1_it++ == 4 &&
        *m1_it++ == 5
    );

    test_compare(
        m1_it == m1.end() &&
        m1_it == m1.rbegin().base() &&
        m1_it == m1.end() &&
        m1_it != m1.rend().base()
    );

    m1_it = m1.begin();

    for (size_t i = 0; m1_it != m1.end(); ++m1_it, i++)
        if (*m1_it != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        if (*m1_it != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(*m1_it == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it++ != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it-- != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testEnd()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);
    std::set<int>   m1s(arr1, arr1 + 5);

    ft::set<int>::iterator m1_it = m1.end();
    std::set<int>::iterator m1_its = m1s.end();

    --m1_it;
    --m1_its;
    test_compare(
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its--
    );
    m1_it = m1.end();
    m1_its = m1s.end();
    
    --m1_it;
    --m1_its;
    test_compare(
        *m1_it-- == 5 &&
        *m1_it-- == 4 &&
        *m1_it-- == 3 &&
        *m1_it-- == 2 &&
        *m1_it == 1
    );

    test_compare(
        m1_it == m1.begin() &&
        m1_it != m1.end() &&
        m1_it == m1.rend().base() &&
        m1_it != m1.rbegin().base()
    );

    m1_it = m1.end();

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        if (*m1_it != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.begin() && *m1_it == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it++ != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it-- != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testRbegin()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);
    std::set<int>    m1s(arr1, arr1 + 5);

    ft::set<int>::reverse_iterator m1_it = m1.rbegin();
    std::set<int>::reverse_iterator m1_its = m1s.rbegin();

    test_compare(
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++ &&
        *m1_it++ == *m1_its++
    );

    m1_it = m1.rbegin();
    m1_its = m1s.rbegin();

    test_compare(
        *m1_it++ == 5 &&
        *m1_it++ == 4 &&
        *m1_it++ == 3 &&
        *m1_it++ == 2 &&
        *m1_it++ == 1
    );

    test_compare(
        m1_it == m1.rend() &&
        m1_it != m1.rbegin() &&
        m1_it.base() == m1.begin() &&
        m1_it.base() != m1.end()
    );

    m1_it = m1.rbegin();
    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it++ != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.rend());
}

static void testRend()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);
    std::set<int>    m1s(arr1, arr1 + 5);

    ft::set<int>::reverse_iterator m1_it = m1.rend();
    std::set<int>::reverse_iterator m1_its = m1s.rend();
    
    --m1_it;
    --m1_its;
    test_compare(
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its-- &&
        *m1_it-- == *m1_its--
    );

    m1_it = m1.rend();
    m1_its = m1s.rend();
    
    --m1_it;
    --m1_its;
    test_compare(
        *m1_it-- == 1 &&
        *m1_it-- == 2 &&
        *m1_it-- == 3 &&
        *m1_it-- == 4 &&
        *m1_it == 5
    );

    test_compare(
        m1_it != m1.rend() &&
        m1_it == m1.rbegin() &&
        m1_it.base() != m1.begin() &&
        m1_it.base() == m1.end()
    );

    for (size_t i = 0; i < m1.size(); i++)
        if (*m1_it++ != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it.base() == m1.begin());
}

static void testInsert()
{
    ft::set<int> m1;
    ft::set<char> m2;
    ft::set<int> m3;
    std::set<int> m1s;
    int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    {
    	m1.insert(arr1[i]);
        m1s.insert(arr1[i]);
    }

    int i = 0;
    ft::set<int>::const_iterator it = m1.begin();
    std::set<int>::const_iterator its = m1s.begin();
    while (it != m1.end())
    {
        if (*it != arr1[i++] || *it != *its)
    	   test_compare(false);
        it++;
        its++;
    }
    test_compare(true);

    // first insert function version (single parameter):
	m2.insert('a');
	m2.insert('z');

	ft::pair<ft::set<char>::iterator,bool> ret;
	ret = m2.insert('z');
	test_compare(ret.second == false);

	// second insert function version (with hint position):
	ft::set<char>::iterator n_it = m2.begin();
	m2.insert(n_it, 'b');
	m2.insert(n_it, 'c');

	// third insert function version (range insertion):
	m3.insert(arr1, arr1 + 3);
	ft::set<int>::const_iterator it_3 = m3.begin();

	test_compare(
        *n_it++ == 'a' &&
        *n_it++ == 'b' &&
        *n_it++ == 'c' &&
        *n_it == 'z');

	test_compare(
        *it_3++ == 100 &&
        *it_3++ == 200 &&
        *it_3 == 300);
}

static void testErase()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
	char			arr2[5] = {'a', 'b', 'c', 'd', 'e'};
	ft::set<int>	m1(arr1, arr1 + 5);
	ft::set<char> 	m2(arr2, arr2 + 5);
    std::set<int>   m1s(arr1, arr1 + 5);

    ft::set<int>::iterator	it;
    std::set<int>::iterator  its;
    ft::set<char>::iterator it_m2;
    int 					i;

    m1.erase(m1.begin());
    m1s.erase(m1s.begin());
    test_compare(m1.size() == m1s.size());
    it = m1.begin(), its = m1s.begin(), i = 1;
    while (it != m1.end())
    {
        if (*it != arr1[i++] || *it != *its)
           test_compare(false);
        it++;
        its++;
    }
    test_compare(it == m1.end() && i == 5);

    m1.erase(--m1.end());
    m1s.erase(--m1s.end());
    test_compare(m1.size() == m1s.size());
 	it = m1.begin(), its = m1s.begin(), i = 1;
    while (it != m1.end())
    {
    	if (*it != arr1[i++] || *it != *its)
           test_compare(false);
        it++;
        its++;
    }
    test_compare(it == m1.end() && i == 4);

    m1.erase(--m1.end());
    m1s.erase(--m1s.end());
    test_compare(m1.size() == m1s.size());
    test_compare(
        m1.count(1) == m1s.count(1) &&
        m1.count(2) == m1s.count(2) &&
        m1.count(3) == m1s.count(3) &&
        m1.count(4) == m1s.count(4) &&
        m1.count(5) == m1s.count(5)
    );

    m1.clear();

    for (int i = 0; i < 5; i++)
    	m1.insert(arr1[i]);
    m1.erase(m1.begin(), m1.end());
    test_compare(m1.size() == 0);


	it_m2 = m2.find('b');
	m2.erase(it_m2);
  	test_compare(m2.erase('c') == 1);
  	it_m2 = m2.find('e');
  	m2.erase(it_m2, m2.end());

	for (it_m2 = m2.begin(); it_m2 != m2.end(); ++it_m2)
		test_compare(*it_m2 == 'a' || *it_m2 == 'd');
}

static void testSwap()
{
	int				arr1[5] = {100, 200, 11, 22, 33};
	ft::set<int> 	foo(arr1, arr1 + 2), bar(arr1 + 2, arr1 + 5);
    std::set<int>    foos(arr1, arr1 + 2), bars(arr1 + 2, arr1 + 5);
  	
  	foo.swap(bar);
    foos.swap(bars);

  	test_compare(foo.size() == foos.size());
  	test_compare(bar.size() == bars.size());

    ft::set<int>::iterator it;
    std::set<int>::iterator its;
  	for (it = foo.begin(), its = foos.begin(); it != foo.end(); ++it, ++its)
        if (*it != *its)
  		    test_compare(false);
    test_compare(true);

  	for (it = bar.begin(), its = bars.begin(); it != bar.end(); ++it, ++its)
  		if (*it != *its)
            test_compare(false);
    test_compare(true);
}

static void testKeyComp()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1(arr1, arr1 + 5);

	ft::set<int>::key_compare comp 	= m1.key_comp();
	int highest 					= *m1.rbegin();     // key value of last element
	ft::set<int>::iterator it 		= m1.begin();
	size_t i 						= 0;	

	while (comp(*it, highest))
	{
		test_compare(*it == arr1[i]);
		it++;
		i++;
	}
}

static void testValueComp()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1(arr1, arr1 + 5);

	ft::set<int>::value_compare comp 	= m1.value_comp();
	int highest							= *m1.rbegin();     // key value of last element
	ft::set<int>::iterator it 			= m1.begin();
	size_t i 							= 0;	

	while (comp(*it, highest))
	{
		test_compare(*it == arr1[i]);
		it++;
		i++;
	}
}

static void testFind()
{
	char arr[4] = {'a', 'b', 'c', 'd'};
	ft::set<char> 	m1(arr, arr + 4);
    std::set<char>   m1s(arr, arr + 4);
	ft::set<char>::iterator	it;
    std::set<char>::iterator its;

	it = m1.find('b');
    its = m1s.find('b');
	if (it != m1.end())
		m1.erase (it);

    if (its != m1s.end())
        m1s.erase (its);

	test_compare(m1.size() == m1s.size());
	test_compare(
        m1.count('b') == m1s.count('b') &&
        m1.count('a') == m1s.count('a') &&
        m1.count('c') == m1s.count('c') &&
        m1.count('d') == m1s.count('d'));
    test_compare(
        m1.count('b') == 0 &&
        m1.count('a') == 1 &&
        m1.count('c') == 1 &&
        m1.count('d') == 1);

	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m2(arr1, arr1 + 5);
    std::set<int>    m2s(arr1, arr1 + 5);

    test_compare(
        *m2.find(1) == *m2.find(1) &&
        *m2.find(2) == *m2.find(2) &&
        *m2.find(3) == *m2.find(3) &&
        *m2.find(4) == *m2.find(4) &&
        *m2.find(5) == *m2.find(5)
    );
	test_compare(
        *m2.find(1) == 1 &&
        *m2.find(2) == 2 &&
        *m2.find(3) == 3 &&
        *m2.find(4) == 4 &&
        *m2.find(5) == 5
    );
}

static void testCount()
{
	char arr[3] = {'a', 'c', 'f'};
	ft::set<char> m1(arr, arr + 3);
    std::set<char> m1s(arr, arr + 3);

	test_compare(m1.count('a') == m1s.count('a'));
	test_compare(m1.count('c') == m1s.count('c'));
	test_compare(m1.count('d') == m1s.count('d'));
	test_compare(m1.count('e') == m1s.count('e'));
	test_compare(m1.count('f') == m1s.count('f'));
}

static void testLowerAndUpperBound()
{
	ft::set<char> mymap;
	ft::set<char>::iterator itlow, itup;

    std::set<char> mymaps;
    std::set<char>::iterator itlows, itups;

	mymap.insert('a');
	mymap.insert('b');
	mymap.insert('c');
	mymap.insert('d');
	mymap.insert('e');

    mymaps.insert('a');
    mymaps.insert('b');
    mymaps.insert('c');
    mymaps.insert('d');
    mymaps.insert('e');

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

    itlows = mymaps.lower_bound('b');
    itups = mymaps.upper_bound('d');

	mymap.erase(itlow, itup);
    mymaps.erase(itlows, itups);

	test_compare(mymap.size() == mymaps.size());
	ft::set<char>::iterator it;
    std::set<char>::iterator its;
    for (it = mymap.begin(), its = mymaps.begin(); it != mymap.end(); ++it, ++its)
		test_compare(*it == *its);
}

static void testEqualRange()
{
	ft::set<char> mymap;
    std::set<char> mymaps;

	mymap.insert('a');
	mymap.insert('b');
	mymap.insert('c');

    mymaps.insert('a');
    mymaps.insert('b');
    mymaps.insert('c');

	ft::pair<ft::set<char>::const_iterator, ft::set<char>::const_iterator> ret;
    std::pair<std::set<char>::const_iterator, std::set<char>::const_iterator> rets;
  	ret = mymap.equal_range('b');
    rets = mymaps.equal_range('b');

    test_compare(*ret.first == *rets.first);
    test_compare(*ret.second == *rets.second);

  	test_compare(*ret.first == 'b');
  	test_compare(*ret.second == 'c');
}

static void testSwapFunc()
{
	int                arr1[5] = {100, 200, 11, 22, 33};
    ft::set<int>    foo(arr1, arr1 + 2), bar(arr1 + 2, arr1 + 5);
    std::set<int>    foos(arr1, arr1 + 2), bars(arr1 + 2, arr1 + 5);
    
    ft::swap(foo, bar);
    ft::swap(foos, bars);

    test_compare(foo.size() == foos.size());
    test_compare(bar.size() == bars.size());

    ft::set<int>::iterator it;
    std::set<int>::iterator its;
    for (it = foo.begin(), its = foos.begin(); it != foo.end(); ++it, ++its)
        if (*it != *its)
            test_compare(false);
    test_compare(true);

    for (it = bar.begin(), its = bars.begin(); it != bar.end(); ++it, ++its)
        if (*it != *its)
            test_compare(false);
    test_compare(true);
}

static void testClear()
{
    int					arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1;
    std::set<int>    m1s;

    for (int i = 0; i < 5; ++i)
    {
    	m1.insert(arr1[i]);
        m1s.insert(arr1[i]);
    }
    m1.clear();
    m1s.clear();
    test_compare(m1.empty() == m1s.empty());
    test_compare(m1.size() == m1s.size());
}

static void testOperatorEqual()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1;
	ft::set<int>	m2;
    std::set<int>    m1s;
    std::set<int>    m2s;

    for (int i = 0; i < 5; ++i)
    {
    	m1.insert(arr1[i]);
        m1s.insert(arr1[i]);
    }
    for (int i = 1; i < 4; ++i)
    {
    	m2.insert(arr1[i]);
        m2s.insert(arr1[i]);
    }

    ft::set<int>	m3(m1);
    std::set<int>    m3s(m1s);

    test_compare(m1 != m2 && m1s != m2s);
    test_compare(m1 == m3 && m1s == m3s);
    test_compare(m2 != m1 && m2s != m1s);
    test_compare(m2 != m3 && m2s != m3s);
    test_compare(m3 == m1 && m3s == m1s);
    test_compare(m3 != m2 && m3s != m2s);

    m3.insert(100);
    m3s.insert(100);
    test_compare(m1 != m3 && m1s != m3s);
    test_compare(m3 != m1 && m3s != m1s);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::set<char>	m1;
	ft::set<char>	m2;
	ft::set<char>	m3;
    std::set<char>   m1s;
    std::set<char>   m2s;
    std::set<char>   m3s;

    for (int i = 0; s1[i]; ++i)
    {
    	m1.insert(s1[i]);
        m1s.insert(s1[i]);
    }
    for (int i = 0; s2[i]; ++i)
    {
    	m2.insert(s2[i]);
        m2s.insert(s2[i]);
    }
    for (int i = 0; s3[i]; ++i)
    {
    	m3.insert(s3[i]);
        m3s.insert(s3[i]);
    }

    test_compare(m1 > m2 && m1s > m2s);
    test_compare(m1 < m3 && m1s < m3s);
    test_compare(m1 >= m2 && m1s >= m2s);
    test_compare(m1 <= m3 && m1s <= m3s);
    test_compare(m1 >= m1 && m1s >= m1s);
    test_compare(m1 <= m1 && m1s <= m1s);

    test_compare(m2 < m1 && m2s < m1s);
    test_compare(m2 < m3 && m2s < m3s);
    test_compare(m2 <= m1 && m2s <= m1s);
    test_compare(m2 <= m3 && m2s <= m3s);
    test_compare(m2 >= m2 && m2s >= m2s);
    test_compare(m2 <= m2 && m2s <= m2s);

    test_compare(m3 > m1 && m3s > m1s);
    test_compare(m3 > m2 && m3s > m2s);
    test_compare(m3 >= m1 && m3s >= m1s);
    test_compare(m3 >= m2 && m3s >= m2s);
    test_compare(m3 >= m3 && m3s >= m3s);
    test_compare(m3 <= m3 && m3s <= m3s);
}

void test_set()
{
    std::cout << std::left << std::setw(28) << "Test constructor (default):";
    testConstructorDefault();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (range):";
    testConstructorRange();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (copy):";
    testConstructorCopy();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (compare):";
    testConstructorCompare();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test constructor (func):";
    testConstructorFunc();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator (=):";
    testOperatorAssign();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test begin:";
    testBegin();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test end:";
    testEnd();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test rbegin:";
    testRbegin();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test rend:";
    testRend();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test insert:";
    testInsert();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test erase:";
    testErase();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test swap:";
    testSwap();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test key compare:";
    testKeyComp();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test value compare:";
    testValueComp();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test find:";
    testFind();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test count:";
    testCount();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test lower and upper bound:";
    testLowerAndUpperBound();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test equal range:";
    testEqualRange();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test swap:";
    testSwapFunc();
    std::cout << std::endl;

    std::cout << std::left << std::setw(28) << "Test clear:";
    testClear();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator(==,!=):";
    testOperatorEqual();
    std::cout << std::endl;
    std::cout << std::left << std::setw(28) << "Test operator(>,<, >=, <=):";
    testOperatorCompar();
    std::cout << std::endl;
}
