/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:52:30 by tgildero          #+#    #+#             */
/*   Updated: 2021/12/12 15:53:20 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map.hpp"
#include "test.hpp"
#include <map>
#include <iomanip>

static void testConstructorDefault()
{
    ft::map<std::string, int> m1;
    std::map<std::string, int> m1s;
    test_compare(
        m1.empty() == m1s.empty() &&
        m1.size() == m1s.size() &&
        m1.max_size() == m1s.max_size()
    );

    ft::map<std::string, char> m2;
    std::map<std::string, char> m2s;
    test_compare(
        m2.empty() == m2s.empty() &&
        m2.size() == m2s.size() &&
        m2.max_size() == m2s.max_size()
    );

    ft::map<std::string, ft::map<std::string, char*> > m3;
    std::map<std::string, std::map<std::string, char*> > m3s;
    test_compare(
        m3.empty() == m3s.empty() &&
        m3.size() == m3s.size()
    );
}

static void testConstructorRange()
{
	ft::map<int, char> arr1;
	arr1.insert(ft::pair<int, char>(0, 'a'));
	arr1.insert(ft::pair<int, char>(1, 'b'));
	arr1.insert(ft::pair<int, char>(2, 'c'));
	arr1.insert(ft::pair<int, char>(3, 'd'));
	arr1.insert(ft::pair<int, char>(4, 'f'));

    std::map<int, char> arr1s;
    arr1s.insert(std::pair<int, char>(0, 'a'));
    arr1s.insert(std::pair<int, char>(1, 'b'));
    arr1s.insert(std::pair<int, char>(2, 'c'));
    arr1s.insert(std::pair<int, char>(3, 'd'));
    arr1s.insert(std::pair<int, char>(4, 'f'));

	ft::map<int, std::string> arr2;
	arr2.insert(ft::pair<int, std::string>(0, "hello"));
	arr2.insert(ft::pair<int, std::string>(1, "world"));
	arr2.insert(ft::pair<int, std::string>(2, "string"));

    std::map<int, std::string> arr2s;
    arr2s.insert(std::pair<int, std::string>(0, "bonjour"));
    arr2s.insert(std::pair<int, std::string>(1, "je"));
    arr2s.insert(std::pair<int, std::string>(2, "suis"));

	ft::map<float, float> arr3;
	arr3.insert(ft::pair<float, float>(1.1f, 1.1f));
	arr3.insert(ft::pair<float, float>(2.2f, 2.2f));
	arr3.insert(ft::pair<float, float>(3.3f, 3.3f));
	arr3.insert(ft::pair<float, float>(4.4f, 4.4f));

    std::map<int, float> arr3s;
    arr3s.insert(std::pair<float, float>(1.1f, 1.1f));
    arr3s.insert(std::pair<float, float>(2.2f, 2.2f));
    arr3s.insert(std::pair<float, float>(3.3f, 3.3f));
    arr3s.insert(std::pair<float, float>(4.4f, 4.4f));


    ft::map<int, char> m1(arr1.begin(), arr1.end());
    std::map<int, char> m1s(arr1s.begin(), arr1s.end());
    test_compare(
        m1.empty() == m1s.empty() &&
        m1.size() == m1s.size());
    for (size_t i = 0; i < m1.size(); i++)
        if (m1[i] != arr1[i])
            test_compare(false);
    test_compare(true);

    ft::map<int, std::string> m2(arr2.begin(), arr2.end());
    std::map<int, std::string> m2s(arr2s.begin(), arr2s.end()); 
    test_compare(
        m2.empty() == m2s.empty() &&
        m2.size() == m2s.size());
    for (size_t i = 0; i < m2.size(); i++)
        if (m2[i] != arr2[i])
            test_compare(false);
    test_compare(true);

    ft::map<float, float> m3(arr3.begin(), arr3.end());
    std::map<float, float> m3s(arr3s.begin(), arr3s.end());
    test_compare(
        m3.empty() == m3s.empty() &&
        m3.size() == m3s.size());
    for (float i = 1.1; i < m3.size(); i += 1.1)
        if (m3[i] != arr3[i])
            test_compare(false);
    test_compare(true);
}

static void testConstructorCopy()
{
    ft::map<int, char> arr1;
	arr1.insert(ft::pair<int, char>(0, 'a'));
	arr1.insert(ft::pair<int, char>(1, 'b'));
	arr1.insert(ft::pair<int, char>(2, 'c'));
	arr1.insert(ft::pair<int, char>(3, 'd'));
	arr1.insert(ft::pair<int, char>(4, 'f'));

    std::map<int, char> arr1s;
    arr1s.insert(std::pair<int, char>(0, 'a'));
    arr1s.insert(std::pair<int, char>(1, 'b'));
    arr1s.insert(std::pair<int, char>(2, 'c'));
    arr1s.insert(std::pair<int, char>(3, 'd'));
    arr1s.insert(std::pair<int, char>(4, 'f'));

	ft::map<int, std::string> arr2;
	arr2.insert(ft::pair<int, std::string>(0, "bonjour"));
	arr2.insert(ft::pair<int, std::string>(1, "je"));
	arr2.insert(ft::pair<int, std::string>(2, "suis"));

    std::map<int, std::string> arr2s;
    arr2s.insert(std::pair<int, std::string>(0, "bonjour"));
    arr2s.insert(std::pair<int, std::string>(1, "je"));
    arr2s.insert(std::pair<int, std::string>(2, "suis"));

	ft::map<int, float> arr3;
	arr3.insert(ft::pair<int, float>(0, 42.0f));
	arr3.insert(ft::pair<int, float>(1, 42.0f));
	arr3.insert(ft::pair<int, float>(2, 42.0f));
	arr3.insert(ft::pair<int, float>(3, 42.0f));
	arr3.insert(ft::pair<int, float>(4, 42.0f));
	arr3.insert(ft::pair<int, float>(5, 42.0f));

    std::map<int, float> arr3s;
    arr3s.insert(std::pair<int, float>(0, 42.0f));
    arr3s.insert(std::pair<int, float>(1, 42.0f));
    arr3s.insert(std::pair<int, float>(2, 42.0f));
    arr3s.insert(std::pair<int, float>(3, 42.0f));
    arr3s.insert(std::pair<int, float>(4, 42.0f));
    arr3s.insert(std::pair<int, float>(5, 42.0f));

    ft::map<int, char>					m1_copied(arr1.begin(), arr1.end());
    ft::map<int, std::string>			m2_copied(arr2.begin(), arr2.end());
    ft::map<int, float>					m3_copied(arr3.begin(), arr3.end());
    ft::map<int, ft::map<int, char*> >	m4_copied;

    std::map<int, char>                  m1s_copied(arr1s.begin(), arr1s.end());
    std::map<int, std::string>           m2s_copied(arr2s.begin(), arr2s.end());
    std::map<int, float>                 m3s_copied(arr3s.begin(), arr3s.end());
    std::map<int, std::map<int, char*> > m4s_copied;

    ft::map<int, char> m1(m1_copied);
    std::map<int, char> m1s(m1s_copied);
    test_compare(
        m1.empty() == m1s.empty() &&
        m1_copied.empty() == m1s_copied.empty() &&
        m1.size() == m1s.size() && 
        m1_copied.size() == m1s_copied.size());
    for (size_t i = 0; i < m1.size(); i++)
        if (m1[i] != m1_copied[i])
            test_compare(false);
    test_compare(true);
    m1[0] = 'z';
    test_compare(m1[0] == 'z' && m1_copied[0] == 'a');

    ft::map<int, std::string> m2(m2_copied);
    std::map<int, std::string> m2s(m2s_copied);
    test_compare(
        m2.empty() == m2s.empty() &&
        m2_copied.empty() == m2s_copied.empty() &&
        m2.size() == m2s.size() && 
        m2_copied.size() == m2s_copied.size());
    for (size_t i = 0; i < m1.size(); i++)
        if (m2[i] != m2_copied[i])
            test_compare(false);
    test_compare(true);
    m2[0] = "aaa";
    test_compare(m2[0] == "aaa" && m2_copied[0] == "bonjour");
    m2[1] = "bbb";
    test_compare(m2[1] == "bbb" && m2_copied[1] == "je");
    m2[2] = "ccc";
    test_compare(m2[2] == "ccc" && m2_copied[2] == "suis");

    ft::map<int, float> m3(m3_copied);
    std::map<int, float> m3s(m3s_copied);
    test_compare(
        m3.empty() == m3s.empty() &&
        m3_copied.empty() == m3s_copied.empty() &&
        m3.size() == m3s.size() && 
        m3_copied.size() == m3s_copied.size());
    for (size_t i = 0; i < m3.size(); i++)
        if (m3[i] != m3_copied[i])
            test_compare(false);
    test_compare(true);
    m3[5] = 19.19f;
    test_compare(m3[5] == 19.19f && m3_copied[0] == 42.0);

    ft::map<int, ft::map<int, char*> > m4(m4_copied);
    std::map<int, std::map<int, char*> > m4s(m4s_copied);
    test_compare(
        m4.empty() == m4s.empty() &&
        m4_copied.empty() == m4s_copied.empty() &&
        m4.size() == m4s.size() && 
        m4_copied.size() == m4s_copied.size());
}

struct more
{
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};

struct less
{
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs < rhs;
	}
};

bool fnmore(int lhs, int rhs)
{
	return lhs > rhs;
}

bool fnless(int lhs, int rhs)
{
	return lhs < rhs;
}

static void testConstructorCompare()
{
	ft::map<int, int, more> m1;
	ft::map<int, int, less> m2;
    std::map<int, int, more> m1s;
    std::map<int, int, less> m2s;
	int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    {
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
        m2.insert(ft::pair<int, int>(i, arr1[i]));
        m2s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int, more>::const_iterator it_m1 = m1.begin();
    ft::map<int, int, less>::const_iterator it_m2 = m2.begin();
    std::map<int, int, more>::const_iterator it_m1s = m1s.begin();
    std::map<int, int, less>::const_iterator it_m2s = m2s.begin();
    for (int i = 0; i < 5; i++)
    {
        if (it_m1->first != (4 - i) || it_m1->first != it_m1s->first)
            test_compare(false);
        if (it_m1->second != arr1[4 - i] || it_m1->second != it_m1s->second)
            test_compare(false);

        if (it_m2->first != i || it_m2->first != it_m2s->first)
            test_compare(false);
        if (it_m2->second != arr1[i] || it_m2->second != it_m2s->second)
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
	ft::map<int, int, bool(*)(int, int)> m1(fnmore_pt);
	ft::map<int, int, bool(*)(int, int)> m2(fnless_pt);
    std::map<int, int, bool(*)(int, int)> m1s(fnmore_pt);
    std::map<int, int, bool(*)(int, int)> m2s(fnless_pt);
	int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
        m2.insert(ft::pair<int, int>(i, arr1[i]));
        m2s.insert(std::pair<int, int>(i, arr1[i]));
    }


    ft::map<int, int, more>::const_iterator it_m1 = m1.begin();
    ft::map<int, int, less>::const_iterator it_m2 = m2.begin();
    std::map<int, int, more>::const_iterator it_m1s = m1s.begin();
    std::map<int, int, less>::const_iterator it_m2s = m2s.begin();
    for (int i = 0; i < 5; i++)
    {
		// test_compare(it_m1->first == (4 - i));
		// test_compare(it_m1->second == arr1[4 - i]);

		// test_compare(it_m2->first == i);
		// test_compare(it_m2->second == arr1[i]);
		// it_m1++;
		// it_m2++;

        if (it_m1->first != (4 - i) || it_m1->first != it_m1s->first)
            test_compare(false);
        if (it_m1->second != arr1[4 - i] || it_m1->second != it_m1s->second)
            test_compare(false);

        if (it_m2->first != i || it_m2->first != it_m2s->first)
            test_compare(false);
        if (it_m2->second != arr1[i] || it_m2->second != it_m2s->second)
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

static void testOperatorAssign()
{
	char a = 'a';
	ft::map<int, char> arr1;
	for (int i = 0; i < 5; ++i)
		arr1.insert(ft::pair<int, char>(i, a++));

	char a_stl = 'a';
	std::map<int, char> arr1_stl;
	for (int i = 0; i < 5; ++i)
		arr1_stl.insert(std::pair<int, char>(i, a_stl++));

	ft::map<int, std::string> arr2;
	arr2.insert(ft::pair<int, std::string>(0, "bonjour"));
	arr2.insert(ft::pair<int, std::string>(1, "je"));
	arr2.insert(ft::pair<int, std::string>(2, "suis"));

	std::map<int, std::string> arr2_stl;
	arr2_stl.insert(std::pair<int, std::string>(0, "bonjour"));
	arr2_stl.insert(std::pair<int, std::string>(1, "je"));
	arr2_stl.insert(std::pair<int, std::string>(2, "suis"));

	ft::map<int, float> arr3;
	for (int i = 0; i < 3; ++i)
		arr3.insert(ft::pair<int, float>(i, 42.0f));

	std::map<int, float> arr3_stl;
	for (int i = 0; i < 3; ++i)
		arr3_stl.insert(std::pair<int, float>(i, 42.0f));

    
    ft::map<int, char>					m1_duplicated(arr1.begin(), arr1.end());
    ft::map<int, std::string>			m2_duplicated(arr2.begin(), arr2.end());
    ft::map<int, float>					m3_duplicated(arr3.begin(), arr3.end());

    // stl
    std::map<int, char>						m1_duplicated_stl(arr1_stl.begin(), arr1_stl.end());
    std::map<int, std::string>				m2_duplicated_stl(arr2_stl.begin(), arr2_stl.end());
    std::map<int, float>					m3_duplicated_stl(arr3_stl.begin(), arr3_stl.end());

    ft::map<int, char>     m1;
    std::map<int, char>    m1_stl;
    m1 = m1_duplicated;
    m1_stl = m1_duplicated_stl;
    test_compare(
        (m1.empty() == m1_stl.empty()) && 
        (m1_duplicated.empty() == m1_duplicated_stl.empty()) &&
        (m1.size() == m1_stl.size()) && 
        (m1_duplicated.size() == m1_duplicated_stl.size())
    );
    for (size_t i = 0; i < m1.size(); i++)
    {
        if (m1[i] != m1_stl[i])
            test_compare(false);
        if (m1_duplicated[i] != m1_duplicated_stl[i])
            test_compare(false);
    }
    test_compare(true);
    m1[0] = 'z';
    test_compare(m1[0] == 'z' && m1_duplicated[0] == 'a');

    ft::map<int, std::string> m2;
    std::map<int, std::string> m2_stl;
    for (int i = 0; i < 10; ++i)
    	m2.insert(ft::pair<int, std::string>(i, "zzz"));
    for (int i = 0; i < 10; ++i)
    	m2_stl.insert(std::pair<int, std::string>(i, "zzz"));
    m2 = m2_duplicated;
    m2_stl = m2_duplicated_stl;
    test_compare(
        (m2.empty() == m2_stl.empty()) && 
        (m2_duplicated.empty() == m2_duplicated_stl.empty()) &&
        (m2.size() == m2_stl.size()) && 
        (m2_duplicated.size() == m2_duplicated_stl.size())
    );
    for (size_t i = 0; i < m1.size(); i++)
    {
        if (m2[i] != m2_stl[i])
            test_compare(false);
        if (m2_duplicated[i] != m2_duplicated_stl[i])
            test_compare(false);
    }
    test_compare(true);
    m2[0] = "aaa";
    test_compare(m2[0] == "aaa" && m2_duplicated[0] == "bonjour");
    m2[1] = "bbb";
    test_compare(m2[1] == "bbb" && m2_duplicated[1] == "je");
    m2[2] = "ccc";
    test_compare(m2[2] == "ccc" && m2_duplicated[2] == "suis");

    ft::map<int, float> m3(m3_duplicated);
    std::map<int, float> m3_stl(m3_duplicated_stl);
    m3 = m3_duplicated;
    m3_stl = m3_duplicated_stl;
    test_compare(
        (m3.empty() == m3_stl.empty()) && 
        (m3_duplicated.empty() == m3_duplicated_stl.empty()) &&
        (m3.size() == m3_stl.size()) && 
        (m3_duplicated.size() == m3_duplicated_stl.size())
    );
    for (size_t i = 0; i < m1.size(); i++)
    {
        if (m3[i] != m3_stl[i])
            test_compare(false);
        if (m3_duplicated[i] != m3_duplicated_stl[i])
            test_compare(false);
    }
    test_compare(true);
    m3[5] = 19.19f;
    test_compare(m3[5] == 19.19f && m3_duplicated[0] == 42.0f);
}

static void testBegin()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>	m1;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>::iterator m1_it = m1.begin();
    std::map<int, int>::iterator m1_its = m1s.begin();

    test_compare(
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second
    );

    m1_it = m1.begin();
    m1_its = m1s.begin();

    test_compare(
        m1_it++->second == 1 &&
        m1_it++->second == 2 &&
        m1_it++->second == 3 &&
        m1_it++->second == 4 &&
        m1_it++->second == 5
    );

    test_compare(
        m1_it == m1.end() &&
        m1_it == m1.rbegin().base() &&
        m1_it == m1.end() &&
        m1_it != m1.rend().base()
    );

    m1_it = m1.begin();

    for (size_t i = 0; m1_it != m1.end(); ++m1_it, i++)
        if (m1_it->second != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        if (m1_it->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it->second == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it++->second != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it--->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testEnd()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>::iterator m1_it = m1.end();
    std::map<int, int>::iterator m1_its = m1s.end();

    --m1_it;
    --m1_its;
    test_compare(
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second
    );

    m1_it = m1.end();
    m1_its = m1s.end();
    
    --m1_it;
    --m1_its;
    test_compare(
        m1_it--->second == 5 &&
        m1_it--->second == 4 &&
        m1_it--->second == 3 &&
        m1_it--->second == 2 &&
        m1_it->second == 1
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
        if (m1_it->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.begin() && m1_it->second == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it++->second != arr1[i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it--->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
}

static void testRbegin()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>::reverse_iterator m1_it = m1.rbegin();
    std::map<int, int>::reverse_iterator m1_its = m1s.rbegin();

    test_compare(
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second &&
        m1_it++->second == m1_its++->second
    );

    m1_it = m1.rbegin();
    m1_its = m1s.rbegin();

    test_compare(
        m1_it++->second == 5 &&
        m1_it++->second == 4 &&
        m1_it++->second == 3 &&
        m1_it++->second == 2 &&
        m1_it++->second == 1
    );

    test_compare(
        m1_it == m1.rend() &&
        m1_it != m1.rbegin() &&
        m1_it.base() == m1.begin() &&
        m1_it.base() != m1.end()
    );

    m1_it = m1.rbegin();
    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it++->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it == m1.rend());
}

static void testRend()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>::reverse_iterator m1_it = m1.rend();
    std::map<int, int>::reverse_iterator m1_its = m1s.rend();

    --m1_it;
    --m1_its;
    test_compare(
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second &&
        m1_it--->second == m1_its--->second
    );

    m1_it = m1.rend();
    m1_its = m1s.rend();
    
    --m1_it;
    --m1_its;
    test_compare(
        m1_it--->second == 1 &&
        m1_it--->second == 2 &&
        m1_it--->second == 3 &&
        m1_it--->second == 4 &&
        m1_it->second == 5
    );

    test_compare(
        m1_it != m1.rend() &&
        m1_it == m1.rbegin() &&
        m1_it.base() != m1.begin() &&
        m1_it.base() == m1.end()
    );

    for (size_t i = 0; i < m1.size(); i++)
        if (m1_it++->second != arr1[4 - i])
            test_compare(false);
    test_compare(true);
    test_compare(m1_it.base() == m1.begin());
}

static void testOperatorBracket()
{
    std::map<int, int> m1;
    ft::map<int, int> m2;

    m1[0] = 1;
    m1[1] = 2;
    m1[2] = 3;
    m1[3] = 4;
    m1[4] = 5;

    m2[0] = 1;
    m2[1] = 2;
    m2[2] = 3;
    m2[3] = 4;
    m2[4] = 5;

    test_compare(
        m1.size() == m2.size() &&
        m1[0] == m2[0] &&
        m1[1] == m2[1] &&
        m1[2] == m2[2] &&
        m1[3] == m2[3] &&
        m1[4] == m2[4]
    );

    test_compare(
        m2[0] == 1 &&
        m2[1] == 2 &&
        m2[2] == 3 &&
        m2[3] == 4 &&
        m2[4] == 5
    );

    int&       mut  = m2[4];
    const int& imut = m2[4];
    test_compare(mut == 5 && imut == 5);
}

static void testInsert()
{
    ft::map<int, int> m1;
    ft::map<char, int> m2;
    ft::map<char, int> m3;
    std::map<int, int> m1s;
    int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    {
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    int i = 0;
    ft::map<int, int>::const_iterator it = m1.begin();
    std::map<int, int>::const_iterator its = m1s.begin();
    while (it != m1.end())
    {
        if (it->second != arr1[i] || it->second != its->second)
            test_compare(false);
        it++;
        its++;
        i++;
    }
    test_compare(true);

    // first insert function version (single parameter):
	m2.insert(ft::pair<char, int>('a', 100));
	m2.insert(ft::pair<char, int>('z', 200));

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = m2.insert(ft::pair<char, int>('z', 500));
	test_compare(ret.second == false);

	// second insert function version (with hint position):
	ft::map<char,int>::iterator n_it = m2.begin();
	m2.insert(n_it, ft::pair<char, int>('b', 300));
	m2.insert(n_it, ft::pair<char, int>('c', 400));

	// third insert function version (range insertion):
	m3.insert(m2.begin(),m2.find('c'));

	test_compare(
        m2['a'] == 100 &&
        m2['b'] == 300 &&
        m2['c'] == 400 &&
        m2['z'] == 200 &&
        m3['a'] == 100 &&
        m3['b'] == 300);
}

static void testErase()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::map<int, int>	m1;
	ft::map<char, int> 	m2;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>::iterator	    it;
    std::map<int, int>::iterator     its;
    ft::map<char, int>::iterator 	it_m2;
    int 							i;

    m1.erase(m1.begin());
    m1s.erase(m1s.begin());
    test_compare(m1.size() == m1s.size());
    it = m1.begin(), its = m1s.begin(), i = 1;
    while (it != m1.end())
    {
        if (it->second != arr1[i] || it->second != its->second)
            test_compare(false);
        it++;
        its++;
        i++;
    }
    test_compare(it == m1.end() && i == 5);

    m1.erase(--m1.end());
    m1s.erase(--m1s.end());
    test_compare(m1.size() == m1s.size());
 	it = m1.begin(), its = m1s.begin(), i = 1;
    while (it != m1.end())
    {
        if (it->second != arr1[i] || it->second != its->second)
            test_compare(false);
        it++;
        its++;
        i++;
    }
    test_compare(it == m1.end() && i == 4);

    m1.erase(--m1.end());
    m1s.erase(--m1s.end());
    test_compare(m1.size() == m1s.size());
    test_compare(
        m1[0] != 1 &&
        m1[1] == 2 &&
        m1[2] == 3 &&
        m1[3] != 4 &&
        m1[4] != 5);

    m1.clear();

    for (int i = 0; i < 5; i++)
    {
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }
    m1.erase(m1.begin(), m1.end());
    m1s.erase(m1s.begin(), m1s.end());
    test_compare(m1.size() == m1s.size());

	m2['a'] = 10;
	m2['b'] = 20;
	m2['c'] = 30;
	m2['d'] = 40;
	m2['e'] = 50;
	m2['f'] = 60;

	it_m2 = m2.find('b');
	m2.erase(it_m2);
  	test_compare(m2.erase('c') == 1);
  	it_m2 = m2.find('e');
  	m2.erase(it_m2, m2.end());

	for (it_m2 = m2.begin(); it_m2 != m2.end(); ++it_m2)
        if (it_m2->second != 10 && it_m2->second != 40)
            test_compare(false);
    test_compare(true);
}

static void testSwap()
{
	ft::map<char,int> foo, bar;
    std::map<char,int> foos, bars;

	foo['x'] = 100;
	foo['y'] = 200;
    foos['x'] = 100;
    foos['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;
    bars['a'] = 11;
    bars['b'] = 22;
    bars['c'] = 33;

  	foo.swap(bar);
    foos.swap(bars);

  	test_compare(foo.size() == foos.size() && bar.size() == bars.size());
    
    ft::map<char,int>::iterator it;
    std::map<char,int>::iterator its;
  	for (it = foo.begin(), its = foos.begin(); it != foo.end(); ++it, ++its)
  	{
        if (it->first != its->first)
            test_compare(false);
        if (it->second != its->second)
            test_compare(false);
  	}
    test_compare(true);
    test_compare(true);

  	for (it = bar.begin(), its = bars.begin(); it != bar.end(); ++it, ++its)
  	{
  		if (it->first != its->first)
            test_compare(false);
        if (it->second != its->second)
            test_compare(false);
  	}
    test_compare(true);
    test_compare(true);
}

static void testKeyComp()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

	ft::map<int, int>::key_compare comp = m1.key_comp();
	int highest 						= m1.rbegin()->first;     // key value of last element
	ft::map<int, int>::iterator it 		= m1.begin();
	size_t i 							= 0;	

	while (comp((*it).first, highest))
	{
		test_compare(it->second == arr1[i]);
		it++;
		i++;
	}
}

static void testValueComp()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

	ft::pair<int, int> highest			= *m1.rbegin();     // key value of last element
	ft::map<int, int>::iterator it 		= m1.begin();
	size_t i 							= 0;	

	while (m1.value_comp()(*it, highest))
	{
		test_compare(it->second == arr1[i]);
		it++;
		i++;
	}
}

static void testFind()
{
	ft::map<char, int> 			m1;
	ft::map<char, int>::iterator	it;
    std::map<char, int>          m1s;
    std::map<char, int>::iterator    its;

	m1['a'] = 50;
	m1['b'] = 100;
	m1['c'] = 150;
	m1['d'] = 200;

    m1s['a'] = 50;
    m1s['b'] = 100;
    m1s['c'] = 150;
    m1s['d'] = 200;

	it = m1.find('b');
    its = m1s.find('b');
	if (it != m1.end())
		m1.erase (it);

    if (its != m1s.end())
        m1s.erase (its);

    test_compare(
        m1.find('a')->second == m1s.find('a')->second &&
        m1.find('c')->second == m1s.find('c')->second &&
        m1.find('d')->second == m1s.find('d')->second
    );
	test_compare(
        m1.find('a')->second == 50 &&
        m1.find('c')->second == 150 &&
        m1.find('d')->second == 200
    );

	int					arr1[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
    {
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
    }

    test_compare(
        m1.find(0)->second == m1s.find(0)->second &&
        m1.find(1)->second == m1s.find(1)->second &&
        m1.find(2)->second == m1s.find(2)->second &&
        m1.find(3)->second == m1s.find(3)->second &&
        m1.find(4)->second == m1s.find(4)->second
    );

	test_compare(
        m1.find(0)->second == 1 &&
        m1.find(1)->second == 2 &&
        m1.find(2)->second == 3 &&
        m1.find(3)->second == 4 &&
        m1.find(4)->second == 5
    );
}

static void testCount()
{
	ft::map<char,int> m1;
    std::map<char,int> m1s;

	m1['a'] = 101;
	m1['c'] = 202;
	m1['f'] = 303;

    m1s['a'] = 101;
    m1s['c'] = 202;
    m1s['f'] = 303;

    test_compare(
        m1.count('a') == m1.count('a') &&
        m1.count('c') == m1.count('c') &&
        m1.count('d') == m1.count('d') &&
        m1.count('e') == m1.count('e') &&
        m1.count('f') == m1.count('f')
    );

	test_compare(
        m1.count('a') == 1 &&
        m1.count('c') == 1 &&
        m1.count('d') == 0 &&
        m1.count('e') == 0 &&
        m1.count('f') == 1
    );
}

static void testLowerAndUpperBound()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow, itup;

    std::map<char,int> mymaps;
    std::map<char,int>::iterator itlows, itups;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;
    
    mymaps['a'] = 20;
    mymaps['b'] = 40;
    mymaps['c'] = 60;
    mymaps['d'] = 80;
    mymaps['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

    itlows = mymaps.lower_bound('b');
    itups = mymaps.upper_bound('d');

	mymap.erase(itlow, itup);
    mymaps.erase(itlows, itups);

    ft::map<char,int>::iterator it;
    std::map<char,int>::iterator its;
	test_compare(mymap.size() == mymaps.size());
	for (it = mymap.begin(), its = mymaps.begin(); it != mymap.end(); ++it, ++its)
        if (it->second != its->second)
            test_compare(false);
	test_compare(true);
}

static void testEqualRange()
{
	ft::map<char,int> mymap;
    std::map<char,int> mymaps;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

    mymaps['a'] = 10;
    mymaps['b'] = 20;
    mymaps['c'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> rets;
  	ret = mymap.equal_range('b');
    rets = mymaps.equal_range('b');

    test_compare(
        ret.first->first == rets.first->first &&
        ret.first->second == rets.first->second
    );

  	test_compare(
        ret.first->first == 'b' &&
        ret.first->second == 20
    );

  	test_compare(
        ret.second->first == 'c' &&
        ret.second->second == 30
    );

    test_compare(
        ret.second->first == rets.second->first &&
        ret.second->second == rets.second->second
    );
  	
}

static void testSwapFunc()
{
    ft::map<char,int> foo, bar;
    std::map<char,int> foos, bars;

    foo['x'] = 100;
    foo['y'] = 200;
    foos['x'] = 100;
    foos['y'] = 200;

    bar['a'] = 11;
    bar['b'] = 22;
    bar['c'] = 33;
    bars['a'] = 11;
    bars['b'] = 22;
    bars['c'] = 33;

    ft::swap(foo, bar);
    ft::swap(foos, bars);

    test_compare(foo.size() == foos.size() && bar.size() == bars.size());
    
    ft::map<char,int>::iterator it;
    std::map<char,int>::iterator its;
    for (it = foo.begin(), its = foos.begin(); it != foo.end(); ++it, ++its)
    {
        if (it->first != its->first)
            test_compare(false);
        if (it->second != its->second)
            test_compare(false);
    }
    test_compare(true);
    test_compare(true);

    for (it = bar.begin(), its = bars.begin(); it != bar.end(); ++it, ++its)
    {
        if (it->first != its->first)
            test_compare(false);
        if (it->second != its->second)
            test_compare(false);
    }
    test_compare(true);
    test_compare(true);
}

static void testClear()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    std::map<int, int>   m1s;

    for (int i = 0; i < 5; ++i)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }
    m1.clear();
    m1s.clear();
    test_compare(m1.size() == m1s.size());
}

static void testOperatorEqual()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    ft::map<int, int>   m2;
    std::map<int, int>   m1s;
    std::map<int, int>   m2s;

    for (int i = 0; i < 5; ++i)
    {
        m1.insert(ft::pair<int, int>(i, arr1[i]));
        m1s.insert(std::pair<int, int>(i, arr1[i]));
    }
    for (int i = 1; i < 4; ++i)
    {
        m2.insert(ft::pair<int, int>(i, arr1[i]));
        m2s.insert(std::pair<int, int>(i, arr1[i]));
    }

    ft::map<int, int>   m3(m1);
    std::map<int, int>   m3s(m1s);

    test_compare(m1 != m2 && m1s != m2s);
    test_compare(m1 == m3 && m1s == m3s);
    test_compare(m2 != m1 && m2s != m1s);
    test_compare(m2 != m3 && m2s != m3s);
    test_compare(m3 == m1 && m3s == m1s);
    test_compare(m3 != m2 && m3s != m2s);

    m3[0] = 100;
    m3s[0] = 100;
    test_compare(m1 != m3 && m1s != m3s);
    test_compare(m3 != m1 && m3s != m1s);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::map<int, char>  m1;
    ft::map<int, char>  m2;
    ft::map<int, char>  m3;
    std::map<int, char>  m1s;
    std::map<int, char>  m2s;
    std::map<int, char>  m3s;

    for (int i = 0; s1[i]; ++i)
    {
        m1.insert(ft::pair<int, char>(i, s1[i]));
        m1s.insert(std::pair<int, char>(i, s1[i]));
    }
    for (int i = 0; s2[i]; ++i)
    {
        m2.insert(ft::pair<int, char>(i, s2[i]));   
        m2s.insert(std::pair<int, char>(i, s2[i]));
    }
    for (int i = 0; s3[i]; ++i)
    {
        m3.insert(ft::pair<int, char>(i, s3[i]));
        m3s.insert(std::pair<int, char>(i, s3[i]));
    }

    test_compare(m1 < m2 && m1s < m2s);
    test_compare(m1 > m3 && m1s > m3s);
    test_compare(m1 <= m2 && m1s <= m2s);
    test_compare(m1 >= m3 && m1s >= m3s);
    test_compare(m1 <= m1 && m1s <= m1s);
    test_compare(m1 >= m1 && m1s >= m1s);

    test_compare(m2 > m1 && m2s > m1s);
    test_compare(m2 > m3 && m2s > m3s);
    test_compare(m2 >= m1 && m2s >= m1s);
    test_compare(m2 >= m3 && m2s >= m3s);
    test_compare(m2 <= m2 && m2s <= m2s);
    test_compare(m2 >= m2 && m2s >= m2s);

    test_compare(m3 < m1 && m3s < m1s);
    test_compare(m3 < m2 && m3s < m2s);
    test_compare(m3 <= m1 && m3s <= m1s);
    test_compare(m3 <= m2 && m3s <= m2s);
    test_compare(m3 <= m3 && m3s <= m3s);
    test_compare(m3 >= m3 && m3s >= m3s);
}

void test_map()
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

    std::cout << std::left << std::setw(28) << "Test operator ([]):";
    testOperatorBracket();
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
