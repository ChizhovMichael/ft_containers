#include "srcs/set.hpp"
#include <set>
#include <cassert>

static void testConstructorDefault()
{
    ft::set<int> m1;
    assert(m1.empty());
    assert(m1.size() == 0);
    assert(m1.max_size() > 0);

    ft::set<char> m2;
    assert(m2.empty());
    assert(m2.size() == 0);
    assert(m2.max_size() > 0);

    ft::set<ft::set<std::string, char*> > m3;
    assert(m3.empty());
    assert(m3.size() == 0);
    assert(m3.max_size() > 0);
}

static void testConstructorRange()
{
	int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::set<int> m1(arr1, arr1 + 5);
    ft::set<int>::iterator it1 = m1.begin();
    assert(!m1.empty());
    assert(m1.size() == 5);
    for (size_t i = 0; i < m1.size(); i++)
        assert(*it1++ == arr1[i]);

    ft::set<std::string> m2(arr2, arr2 + 3);
    ft::set<std::string>::iterator it2 = m2.begin();
    assert(!m2.empty());
    assert(m2.size() == 3);
    for (size_t i = 0; i < m2.size(); i++)
        assert(*it2++ == arr2[i]);

    ft::set<float> m3(arr3, arr3 + 4);
    ft::set<float>::iterator it3 = m3.begin();
    assert(!m3.empty());
    assert(m3.size() == 4);
    for (size_t i = 0; i < m3.size(); i++)
        assert(*it3++ == arr3[i]);
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

    ft::set<char> m1(m1_copied);
    ft::set<char>::iterator it1 = m1.begin();
    ft::set<char>::iterator it1c = m1_copied.begin();

    assert(m1.empty() == m1_copied.empty());
    assert(m1.size() == m1_copied.size());
    for (size_t i = 0; i < m1.size(); i++)
        assert(*it1++ == *it1c++);

    ft::set<std::string> m2(m2_copied);
    ft::set<std::string>::iterator it2 = m2.begin();
    ft::set<std::string>::iterator it2c = m2_copied.begin();

    assert(m2.empty() == m2_copied.empty());
    assert(m2.size() == m2_copied.size());
    for (size_t i = 0; i < m2.size(); i++)
        assert(*it2++ == *it2c++);

    ft::set<float> m3(m3_copied);
    ft::set<float>::iterator it3 = m3.begin();
    ft::set<float>::iterator it3c = m3_copied.begin();

    assert(m3.empty() == m3_copied.empty());
    assert(m3.size() == m3_copied.size());
    for (size_t i = 0; i < m3.size(); i++)
        assert(*it3++ == *it3c++);

    ft::set<ft::set<char*> > m4(m4_copied);
    assert(m4.empty() == m4_copied.empty());
    assert(m4.size() == m4_copied.size());
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
	int arr1[5] = {100, 200, 300, 400, 500};
	ft::set<int, more> m1(arr1, arr1 + 5);
	ft::set<int, less> m2(arr1, arr1 + 5);
	
    ft::set<int, more>::const_iterator it_m1 = m1.begin();
    ft::set<int, less>::const_iterator it_m2 = m2.begin();
    for (int i = 0; i < 5; i++)
    {
		assert(*it_m1 == arr1[4 - i]);
		assert(*it_m2 == arr1[i]);
		it_m1++;
		it_m2++;
    }
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

    for (int i = 0; i < 5; i++)
    	m1.insert(arr1[i]);

    for (int i = 0; i < 5; i++)
    	m2.insert(arr1[i]);


    ft::set<int, more>::const_iterator it_m1 = m1.begin();
    ft::set<int, less>::const_iterator it_m2 = m2.begin();
    ft::set<int, more>::const_iterator it_m3 = m3.begin();
    ft::set<int, less>::const_iterator it_m4 = m4.begin();
    for (int i = 0; i < 5; i++)
    {
		assert(*it_m1 == arr1[4 - i]);
		assert(*it_m2 == arr1[i]);
		assert(*it_m3 == arr1[4 - i]);
		assert(*it_m4 == arr1[i]);
		it_m1++;
		it_m2++;
		it_m3++;
		it_m4++;
    }	
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
    std::set<char>    m1_stl;
    m1 = m1_duplicated;
    m1_stl = m1_duplicated_stl;
    //
    ft::set<char>::const_iterator it1 = m1.begin();
    ft::set<char>::const_iterator it1d = m1_duplicated.begin();
    std::set<char>::const_iterator it1_stl = m1_stl.begin();
    std::set<char>::const_iterator it1d_stl = m1_duplicated_stl.begin();
    //
    assert(
        (m1.empty() == m1_stl.empty()) && 
        (m1_duplicated.empty() == m1_duplicated_stl.empty())
    );
    assert(
        (m1.size() == m1_stl.size()) && 
        (m1_duplicated.size() == m1_duplicated_stl.size())
    );
    for (size_t i = 0; i < m1.size(); i++)
    {
    	assert(*it1++ == *it1_stl++);
    	assert(*it1d++ == *it1d_stl++);
    }

    ft::set<std::string> m2;
    std::set<std::string> m2_stl;
    for (int i = 0; i < 10; ++i)
    	m2.insert("zzz");
    for (int i = 0; i < 10; ++i)
    	m2_stl.insert("zzz");
    m2 = m2_duplicated;
    m2_stl = m2_duplicated_stl;
    //
    ft::set<std::string>::const_iterator it2 = m2.begin();
    ft::set<std::string>::const_iterator it2d = m2_duplicated.begin();
    //
    assert(
        (m2.empty() == m2_stl.empty()) && 
        (m2_duplicated.empty() == m2_duplicated_stl.empty())
    );
    assert(
        (m2.size() == m2_stl.size()) && 
        (m2_duplicated.size() == m2_duplicated_stl.size())
    );
    for (size_t i = 0; i < m2.size(); i++)
        assert(*it2++ == *it2d++);

    ft::set<float> m3(m3_duplicated);
    std::set<float> m3_stl(m3_duplicated_stl);
    m3 = m3_duplicated;
    m3_stl = m3_duplicated_stl;
    //
    ft::set<float>::const_iterator it3 = m3.begin();
    ft::set<float>::const_iterator it3d = m3_duplicated.begin();
    //
    assert(
        (m3.empty() == m3_stl.empty()) && 
        (m3_duplicated.empty() == m3_duplicated_stl.empty())
    );
    assert(
        (m3.size() == m3_stl.size()) && 
        (m3_duplicated.size() == m3_duplicated_stl.size())
    );
    for (size_t i = 0; i < m3.size(); i++)
        assert(*it3++ == *it3d++);
}

static void testBegin()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);

    ft::set<int>::iterator m1_it = m1.begin();

    assert(*m1_it++ == 1);
    assert(*m1_it++ == 2);
    assert(*m1_it++ == 3);
    assert(*m1_it++ == 4);
    assert(*m1_it++ == 5);

    assert(m1_it == m1.end());
    assert(m1_it == m1.rbegin().base());
    assert(m1_it == m1.end());
    assert(m1_it != m1.rend().base());

    m1_it = m1.begin();

    for (size_t i = 0; m1_it != m1.end(); ++m1_it, i++)
        assert(*m1_it == arr1[i]);
    assert(m1_it == m1.end());

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        assert(*m1_it == arr1[4 - i]);
    assert(*m1_it == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it++ == arr1[i]);
    assert(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it-- == arr1[4 - i]);
}

static void testEnd()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);

    ft::set<int>::iterator m1_it = m1.end();

    --m1_it;
    assert(*m1_it-- == 5);
    assert(*m1_it-- == 4);
    assert(*m1_it-- == 3);
    assert(*m1_it-- == 2);
    assert(*m1_it == 1);

    assert(m1_it == m1.begin());
    assert(m1_it != m1.end());
    assert(m1_it == m1.rend().base());
    assert(m1_it != m1.rbegin().base());

    m1_it = m1.end();

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        assert(*m1_it == arr1[4 - i]);
    assert(m1_it == m1.begin());
    assert(*m1_it == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it++ == arr1[i]);
    assert(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it-- == arr1[4 - i]);
}

static void testRbegin()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);

    ft::set<int>::reverse_iterator m1_it = m1.rbegin();
    
    assert(*m1_it++ == 5);
    assert(*m1_it++ == 4);
    assert(*m1_it++ == 3);
    assert(*m1_it++ == 2);
    assert(*m1_it++ == 1);

    assert(m1_it == m1.rend());
    assert(m1_it != m1.rbegin());
    assert(m1_it.base() == m1.begin());
    assert(m1_it.base() != m1.end());

    m1_it = m1.rbegin();
    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it++ == arr1[4 - i]);
    assert(m1_it == m1.rend());
}

static void testRend()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
    ft::set<int>	m1(arr1, arr1 + 5);

    ft::set<int>::reverse_iterator m1_it = m1.rend();
    
    --m1_it;
    assert(*m1_it-- == 1);
    assert(*m1_it-- == 2);
    assert(*m1_it-- == 3);
    assert(*m1_it-- == 4);
    assert(*m1_it == 5);

    assert(m1_it != m1.rend());
    assert(m1_it == m1.rbegin());
    assert(m1_it.base() != m1.begin());
    assert(m1_it.base() == m1.end());

    for (size_t i = 0; i < m1.size(); i++)
        assert(*m1_it++ == arr1[4 - i]);
    assert(m1_it.base() == m1.begin());
}

static void testInsert()
{
    ft::set<int> m1;
    ft::set<char> m2;
    ft::set<int> m3;
    int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    	m1.insert(arr1[i]);

    int i = 0;
    ft::set<int>::const_iterator it = m1.begin();
    while (it != m1.end())
    	assert(*it++ == arr1[i++]);

    // first insert function version (single parameter):
	m2.insert('a');
	m2.insert('z');

	ft::pair<ft::set<char>::iterator,bool> ret;
	ret = m2.insert('z');
	assert(ret.second == false);

	// second insert function version (with hint position):
	ft::set<char>::iterator n_it = m2.begin();
	m2.insert(n_it, 'b');
	m2.insert(n_it, 'c');

	// third insert function version (range insertion):
	m3.insert(arr1, arr1 + 3);
	ft::set<int>::const_iterator it_3 = m3.begin();

	assert(*n_it++ == 'a');
	assert(*n_it++ == 'b');
	assert(*n_it++ == 'c');
	assert(*n_it == 'z');

	assert(*it_3++ == 100);
	assert(*it_3++ == 200);
	assert(*it_3 == 300);
}

static void testErase()
{
	int				arr1[5] = {1, 2, 3, 4, 5};
	char			arr2[5] = {'a', 'b', 'c', 'd', 'e'};
	ft::set<int>	m1(arr1, arr1 + 5);
	ft::set<char> 	m2(arr2, arr2 + 5);

    ft::set<int>::iterator	it;
    ft::set<char>::iterator it_m2;
    int 					i;

    m1.erase(m1.begin());
    assert(m1.size() == 4);
    it = m1.begin(), i = 1;
    while (it != m1.end())
    	assert(*it++ == arr1[i++]);
    assert(it == m1.end() && i == 5);

    m1.erase(--m1.end());
    assert(m1.size() == 3);
 	it = m1.begin(), i = 1;
    while (it != m1.end())
    	assert(*it++ == arr1[i++]);
    assert(it == m1.end() && i == 4);

    m1.erase(--m1.end());
    assert(m1.size() == 2);
    assert(m1.count(1) == 0);
    assert(m1.count(2) == 1);
    assert(m1.count(3) == 1);
    assert(m1.count(4) == 0);
    assert(m1.count(5) == 0);

    m1.clear();

    for (int i = 0; i < 5; i++)
    	m1.insert(arr1[i]);
    m1.erase(m1.begin(), m1.end());
    assert(m1.size() == 0);


	it_m2 = m2.find('b');
	m2.erase(it_m2);
  	assert(m2.erase('c') == 1);
  	it_m2 = m2.find('e');
  	m2.erase(it_m2, m2.end());

	for (it_m2 = m2.begin(); it_m2 != m2.end(); ++it_m2)
		assert(*it_m2 == 'a' || *it_m2 == 'd');
}

static void testSwap()
{
	int				arr1[5] = {100, 200, 11, 22, 33};
	ft::set<int> 	foo(arr1, arr1 + 2), bar(arr1 + 2, arr1 + 5);
  	
  	foo.swap(bar);

  	assert(foo.size() == 3);
  	assert(bar.size() == 2);

  	for (ft::set<int>::iterator it = foo.begin(); it != foo.end(); ++it)
  		assert(*it == 11 || *it == 22 || *it == 33);

  	for (ft::set<int>::iterator it = bar.begin(); it != bar.end(); ++it)
  		assert(*it == 100 || *it == 200);
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
		assert(*it == arr1[i]);
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
		assert(*it == arr1[i]);
		it++;
		i++;
	}
}

static void testFind()
{
	char arr[4] = {'a', 'b', 'c', 'd'};
	ft::set<char> 	m1(arr, arr + 4);
	ft::set<char>::iterator	it;

	it = m1.find('b');
	if (it != m1.end())
		m1.erase (it);

	assert(m1.size() == 3);
	assert(m1.count('b') == 0);
	assert(m1.count('a') == 1);
	assert(m1.count('c') == 1);
	assert(m1.count('d') == 1);

	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m2(arr1, arr1 + 5);

	assert(*m2.find(1) == 1);
	assert(*m2.find(2) == 2);
	assert(*m2.find(3) == 3);
	assert(*m2.find(4) == 4);
	assert(*m2.find(5) == 5);    
}

static void testCount()
{
	char arr[3] = {'a', 'c', 'f'};
	ft::set<char> m1(arr, arr + 3);

	assert(m1.count('a') == 1);
	assert(m1.count('c') == 1);
	assert(m1.count('d') == 0);
	assert(m1.count('e') == 0);
	assert(m1.count('f') == 1);
}

static void testLowerAndUpperBound()
{
	ft::set<char> mymap;
	ft::set<char>::iterator itlow, itup;

	mymap.insert('a');
	mymap.insert('b');
	mymap.insert('c');
	mymap.insert('d');
	mymap.insert('e');

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	mymap.erase(itlow, itup);

	assert(mymap.size() == 2);
	for (ft::set<char>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		assert(*it == 'a' || *it == 'e');
}

static void testEqualRange()
{
	ft::set<char> mymap;

	mymap.insert('a');
	mymap.insert('b');
	mymap.insert('c');

	ft::pair<ft::set<char>::const_iterator, ft::set<char>::const_iterator> ret;
  	ret = mymap.equal_range('b');

  	assert(*ret.first == 'b');
  	assert(*ret.second == 'c');
}

static void testSwapFunc()
{
	int				arr1[5] = {100, 200, 11, 22, 33};
	ft::set<int> 	foo(arr1, arr1 + 2), bar(arr1 + 2, arr1 + 5);
  	
  	ft::swap(foo, bar);

  	assert(foo.size() == 3);
  	assert(bar.size() == 2);

  	for (ft::set<int>::iterator it = foo.begin(); it != foo.end(); ++it)
  		assert(*it == 11 || *it == 22 || *it == 33);

  	for (ft::set<int>::iterator it = bar.begin(); it != bar.end(); ++it)
  		assert(*it == 100 || *it == 200);
}

static void testClear()
{
    int					arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(arr1[i]);
    m1.clear();
    assert(m1.empty());
    assert(m1.size() == 0);
}

static void testOperatorEqual()
{
    int				arr1[5] = {1, 2, 3, 4, 5};
	ft::set<int>	m1;
	ft::set<int>	m2;

    for (int i = 0; i < 5; ++i)
    	m1.insert(arr1[i]);
    for (int i = 1; i < 4; ++i)
    	m2.insert(arr1[i]);

    ft::set<int>	m3(m1);

    assert(m1 != m2);
    assert(m1 == m3);
    assert(m2 != m1);
    assert(m2 != m3);
    assert(m3 == m1);
    assert(m3 != m2);

    m3.insert(100);
    assert(m1 != m3);
    assert(m3 != m1);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::set<char>	m1;
	ft::set<char>	m2;
	ft::set<char>	m3;

    for (int i = 0; s1[i]; ++i)
    	m1.insert(s1[i]);
    for (int i = 0; s2[i]; ++i)
    	m2.insert(s2[i]);
    for (int i = 0; s3[i]; ++i)
    	m3.insert(s3[i]);

    assert(m1 > m2);
    assert(m1 < m3);
    assert(m1 >= m2);
    assert(m1 <= m3);
    assert(m1 >= m1);
    assert(m1 <= m1);

    assert(m2 < m1);
    assert(m2 < m3);
    assert(m2 <= m1);
    assert(m2 <= m3);
    assert(m2 >= m2);
    assert(m2 <= m2);

    assert(m3 > m1);
    assert(m3 > m2);
    assert(m3 >= m1);
    assert(m3 >= m2);
    assert(m3 >= m3);
    assert(m3 <= m3);
}

void set_test()
{
    testConstructorDefault();
    testConstructorRange();
    testConstructorCopy();
    testConstructorCompare();
    testConstructorFunc();
    testOperatorAssign();

    testBegin();
    testEnd();
    testRbegin();
    testRend();

    testInsert();
    testErase();
    testSwap();

    testKeyComp();
    testValueComp();

    testFind();
    testCount();
    testLowerAndUpperBound();
    testEqualRange();
    testSwapFunc();

    testClear();
    testOperatorEqual();
    testOperatorCompar();
}