#include "srcs/map.hpp"
#include <map>
#include <cassert>

static void testConstructorDefault()
{
    ft::map<std::string, int> m1;
    assert(m1.empty());
    assert(m1.size() == 0);
    assert(m1.max_size() > 0);

    ft::map<std::string, char> m2;
    assert(m2.empty());
    assert(m2.size() == 0);
    assert(m2.max_size() > 0);

    ft::map<std::string, ft::map<std::string, char*> > m3;
    assert(m3.empty());
    assert(m3.size() == 0);
    assert(m3.max_size() > 0);
}

static void testConstructorRange()
{
	ft::map<int, char> arr1;
	arr1.insert(ft::pair<int, char>(0, 'a'));
	arr1.insert(ft::pair<int, char>(1, 'b'));
	arr1.insert(ft::pair<int, char>(2, 'c'));
	arr1.insert(ft::pair<int, char>(3, 'd'));
	arr1.insert(ft::pair<int, char>(4, 'f'));

	ft::map<int, std::string> arr2;
	arr2.insert(ft::pair<int, std::string>(0, "hello"));
	arr2.insert(ft::pair<int, std::string>(1, "world"));
	arr2.insert(ft::pair<int, std::string>(2, "string"));

	ft::map<float, float> arr3;
	arr3.insert(ft::pair<float, float>(1.1f, 1.1f));
	arr3.insert(ft::pair<float, float>(2.2f, 2.2f));
	arr3.insert(ft::pair<float, float>(3.3f, 3.3f));
	arr3.insert(ft::pair<float, float>(4.4f, 4.4f));

    ft::map<int, char> m1(arr1.begin(), arr1.end());
    assert(!m1.empty());
    assert(m1.size() == 5);
    for (size_t i = 0; i < m1.size(); i++)
        assert(m1[i] == arr1[i]);

    ft::map<int, std::string> m2(arr2.begin(), arr2.end());
    assert(!m2.empty());
    assert(m2.size() == 3);
    for (size_t i = 0; i < m2.size(); i++)
        assert(m2[i] == arr2[i]);

    ft::map<float, float> m3(arr3.begin(), arr3.end());
    assert(!m3.empty());
    assert(m3.size() == 4);
    for (float i = 1.1; i < m3.size(); i += 1.1)
        assert(m3[i] == arr3[i]);
}

static void testConstructorCopy()
{
    ft::map<int, char> arr1;
	arr1.insert(ft::pair<int, char>(0, 'a'));
	arr1.insert(ft::pair<int, char>(1, 'b'));
	arr1.insert(ft::pair<int, char>(2, 'c'));
	arr1.insert(ft::pair<int, char>(3, 'd'));
	arr1.insert(ft::pair<int, char>(4, 'f'));

	ft::map<int, std::string> arr2;
	arr2.insert(ft::pair<int, std::string>(0, "bonjour"));
	arr2.insert(ft::pair<int, std::string>(1, "je"));
	arr2.insert(ft::pair<int, std::string>(2, "suis"));

	ft::map<int, float> arr3;
	arr3.insert(ft::pair<int, float>(0, 42.0f));
	arr3.insert(ft::pair<int, float>(1, 42.0f));
	arr3.insert(ft::pair<int, float>(2, 42.0f));
	arr3.insert(ft::pair<int, float>(3, 42.0f));
	arr3.insert(ft::pair<int, float>(4, 42.0f));
	arr3.insert(ft::pair<int, float>(5, 42.0f));

    ft::map<int, char>					m1_copied(arr1.begin(), arr1.end());
    ft::map<int, std::string>			m2_copied(arr2.begin(), arr2.end());
    ft::map<int, float>					m3_copied(arr3.begin(), arr3.end());
    ft::map<int, ft::map<int, char*> >	m4_copied;

    ft::map<int, char> m1(m1_copied);
    assert(m1.empty() == m1_copied.empty());
    assert(m1.size() == m1_copied.size());
    for (size_t i = 0; i < m1.size(); i++)
        assert(m1[i] == m1_copied[i]);
    m1[0] = 'z';
    assert(m1[0] == 'z');
    assert(m1_copied[0] == 'a');

    ft::map<int, std::string> m2(m2_copied);
    assert(m2.empty() == m2_copied.empty());
    assert(m2.size() == m2_copied.size());
    for (size_t i = 0; i < m2.size(); i++)
        assert(m2[i] == m2_copied[i]);
    m2[0] = "aaa";
    assert(m2[0] == "aaa");
    assert(m2_copied[0] == "bonjour");
    m2[1] = "bbb";
    assert(m2[1] == "bbb");
    assert(m2_copied[1] == "je");
    m2[2] = "ccc";
    assert(m2[2] == "ccc");
    assert(m2_copied[2] == "suis");

    ft::map<int, float> m3(m3_copied);
    assert(m3.empty() == m3_copied.empty());
    assert(m3.size() == m3_copied.size());
    for (size_t i = 0; i < m3.size(); i++)
        assert(m3[i] == m3_copied[i]);
    m3[5] = 19.19f;
    assert(m3[5] == 19.19f);
    assert(m3_copied[0] == 42.0);

    ft::map<int, ft::map<int, char*> > m4(m4_copied);
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
	ft::map<int, int, more> m1;
	ft::map<int, int, less> m2;
	int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    for (int i = 0; i < 5; i++)
    	m2.insert(ft::pair<int, int>(i, arr1[i]));


    ft::map<int, int, more>::const_iterator it_m1 = m1.begin();
    ft::map<int, int, less>::const_iterator it_m2 = m2.begin();
    for (int i = 0; i < 5; i++)
    {
		assert(it_m1->first == (4 - i));
		assert(it_m1->second == arr1[4 - i]);

		assert(it_m2->first == i);
		assert(it_m2->second == arr1[i]);
		it_m1++;
		it_m2++;
    }
}

static void testConstructorFunc()
{
	bool(*fnmore_pt)(int, int) = fnmore;
	bool(*fnless_pt)(int, int) = fnless;
	ft::map<int, int, bool(*)(int, int)> m1(fnmore_pt);
	ft::map<int, int, bool(*)(int, int)> m2(fnless_pt);
	int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    for (int i = 0; i < 5; i++)
    	m2.insert(ft::pair<int, int>(i, arr1[i]));


    ft::map<int, int, more>::const_iterator it_m1 = m1.begin();
    ft::map<int, int, less>::const_iterator it_m2 = m2.begin();
    for (int i = 0; i < 5; i++)
    {
		assert(it_m1->first == (4 - i));
		assert(it_m1->second == arr1[4 - i]);

		assert(it_m2->first == i);
		assert(it_m2->second == arr1[i]);
		it_m1++;
		it_m2++;
    }	
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
        assert(m1[i] == m1_stl[i]);
        assert(m1_duplicated[i] == m1_duplicated_stl[i]);
    }
    m1[0] = 'z';
    assert(m1[0] == 'z');
    assert(m1_duplicated[0] == 'a');

    ft::map<int, std::string> m2;
    std::map<int, std::string> m2_stl;
    for (int i = 0; i < 10; ++i)
    	m2.insert(ft::pair<int, std::string>(i, "zzz"));
    for (int i = 0; i < 10; ++i)
    	m2_stl.insert(std::pair<int, std::string>(i, "zzz"));
    m2 = m2_duplicated;
    m2_stl = m2_duplicated_stl;
    assert(
        (m2.empty() == m2_stl.empty()) && 
        (m2_duplicated.empty() == m2_duplicated_stl.empty())
    );
    assert(
        (m2.size() == m2_stl.size()) && 
        (m2_duplicated.size() == m2_duplicated_stl.size())
    );
    for (size_t i = 0; i < m2.size(); i++)
        assert(m2[i] == m2_duplicated[i]);
    m2[0] = "aaa";
    assert(m2[0] == "aaa");
    assert(m2_duplicated[0] == "bonjour");
    m2[1] = "bbb";
    assert(m2[1] == "bbb");
    assert(m2_duplicated[1] == "je");
    m2[2] = "ccc";
    assert(m2[2] == "ccc");
    assert(m2_duplicated[2] == "suis");

    ft::map<int, float> m3(m3_duplicated);
    std::map<int, float> m3_stl(m3_duplicated_stl);
    m3 = m3_duplicated;
    m3_stl = m3_duplicated_stl;
    assert(
        (m3.empty() == m3_stl.empty()) && 
        (m3_duplicated.empty() == m3_duplicated_stl.empty())
    );
    assert(
        (m3.size() == m3_stl.size()) && 
        (m3_duplicated.size() == m3_duplicated_stl.size())
    );
    for (size_t i = 0; i < m3.size(); i++)
        assert(m3[i] == m3_duplicated[i]);
    m3[5] = 19.19f;
    assert(m3[5] == 19.19f);
    assert(m3_duplicated[0] == 42.0f);
}

static void testBegin()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    ft::map<int, int>::iterator m1_it = m1.begin();

    assert(m1_it++->second == 1);
    assert(m1_it++->second == 2);
    assert(m1_it++->second == 3);
    assert(m1_it++->second == 4);
    assert(m1_it++->second == 5);

    assert(m1_it == m1.end());
    assert(m1_it == m1.rbegin().base());
    assert(m1_it == m1.end());
    assert(m1_it != m1.rend().base());

    m1_it = m1.begin();

    for (size_t i = 0; m1_it != m1.end(); ++m1_it, i++)
        assert(m1_it->second == arr1[i]);
    assert(m1_it == m1.end());

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        assert(m1_it->second == arr1[4 - i]);
    assert(m1_it->second == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it++->second == arr1[i]);
    assert(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it--->second == arr1[4 - i]);
}

static void testEnd()
{
    int					arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    ft::map<int, int>::iterator m1_it = m1.end();

    --m1_it;
    assert(m1_it--->second == 5);
    assert(m1_it--->second == 4);
    assert(m1_it--->second == 3);
    assert(m1_it--->second == 2);
    assert(m1_it->second == 1);

    assert(m1_it == m1.begin());
    assert(m1_it != m1.end());
    assert(m1_it == m1.rend().base());
    assert(m1_it != m1.rbegin().base());

    m1_it = m1.end();

    --m1_it;
    for (size_t i = 0; m1_it != m1.begin(); --m1_it, i++)
        assert(m1_it->second == arr1[4 - i]);
    assert(m1_it == m1.begin());
    assert(m1_it->second == arr1[0]);

    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it++->second == arr1[i]);
    assert(m1_it == m1.end());

    m1_it--;
    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it--->second == arr1[4 - i]);
}

static void testRbegin()
{
    int					arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    ft::map<int, int>::reverse_iterator m1_it = m1.rbegin();
    
    assert(m1_it++->second == 5);
    assert(m1_it++->second == 4);
    assert(m1_it++->second == 3);
    assert(m1_it++->second == 2);
    assert(m1_it++->second == 1);

    assert(m1_it == m1.rend());
    assert(m1_it != m1.rbegin());
    assert(m1_it.base() == m1.begin());
    assert(m1_it.base() != m1.end());

    m1_it = m1.rbegin();
    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it++->second == arr1[4 - i]);
    assert(m1_it == m1.rend());
}

static void testRend()
{
    int					arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>	m1;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    ft::map<int, int>::reverse_iterator m1_it = m1.rend();
    
    --m1_it;
    assert(m1_it--->second == 1);
    assert(m1_it--->second == 2);
    assert(m1_it--->second == 3);
    assert(m1_it--->second == 4);
    assert(m1_it->second == 5);

    assert(m1_it != m1.rend());
    assert(m1_it == m1.rbegin());
    assert(m1_it.base() != m1.begin());
    assert(m1_it.base() == m1.end());

    for (size_t i = 0; i < m1.size(); i++)
        assert(m1_it++->second == arr1[4 - i]);
    assert(m1_it.base() == m1.begin());
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

    assert(m1.size() == m2.size());   
    assert(m1[0] == m2[0]);
    assert(m1[1] == m2[1]);
    assert(m1[2] == m2[2]);
    assert(m1[3] == m2[3]);
    assert(m1[4] == m2[4]);

    assert(m2[0] == 1);
    assert(m2[1] == 2);
    assert(m2[2] == 3);
    assert(m2[3] == 4);
    assert(m2[4] == 5);

    int&       mut  = m2[4];
    const int& imut = m2[4];
    assert(mut == 5);
    assert(imut == 5);
}

static void testInsert()
{
    ft::map<int, int> m1;
    ft::map<char, int> m2;
    ft::map<char, int> m3;
    int arr1[5] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

    int i = 0;
    ft::map<int, int>::const_iterator it = m1.begin();
    while (it != m1.end())
    	assert(it++->second == arr1[i++]);

    // first insert function version (single parameter):
	m2.insert(ft::pair<char, int>('a', 100));
	m2.insert(ft::pair<char, int>('z', 200));

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = m2.insert(ft::pair<char, int>('z', 500));
	assert(ret.second == false);

	// second insert function version (with hint position):
	ft::map<char,int>::iterator n_it = m2.begin();
	m2.insert(n_it, ft::pair<char, int>('b', 300));
	m2.insert(n_it, ft::pair<char, int>('c', 400));

	// third insert function version (range insertion):
	m3.insert(m2.begin(),m2.find('c'));

	assert(m2['a'] == 100);
	assert(m2['b'] == 300);
	assert(m2['c'] == 400);
	assert(m2['z'] == 200);

	assert(m3['a'] == 100);
	assert(m3['b'] == 300);
}

static void testErase()
{
	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::map<int, int>	m1;
	ft::map<char, int> 	m2;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
    ft::map<int, int>::iterator	it;
    ft::map<char, int>::iterator 	it_m2;
    int 							i;

    m1.erase(m1.begin());
    assert(m1.size() == 4);
    it = m1.begin(), i = 1;
    while (it != m1.end())
    	assert(it++->second == arr1[i++]);
    assert(it == m1.end() && i == 5);

    m1.erase(--m1.end());
    assert(m1.size() == 3);
 	it = m1.begin(), i = 1;
    while (it != m1.end())
    	assert(it++->second == arr1[i++]);
    assert(it == m1.end() && i == 4);

    m1.erase(--m1.end());
    assert(m1.size() == 2);
    assert(m1[0] != 1);
    assert(m1[1] == 2);
    assert(m1[2] == 3);
    assert(m1[3] != 4);
    assert(m1[4] != 5);

    m1.clear();

    for (int i = 0; i < 5; i++)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));
    m1.erase(m1.begin(), m1.end());
    assert(m1.size() == 0);

	m2['a'] = 10;
	m2['b'] = 20;
	m2['c'] = 30;
	m2['d'] = 40;
	m2['e'] = 50;
	m2['f'] = 60;

	it_m2 = m2.find('b');
	m2.erase(it_m2);
  	assert(m2.erase('c') == 1);
  	it_m2 = m2.find('e');
  	m2.erase(it_m2, m2.end());

	for (it_m2 = m2.begin(); it_m2 != m2.end(); ++it_m2)
		assert(it_m2->second == 10 || it_m2->second == 40);
}

static void testSwap()
{
	ft::map<char,int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

  	foo.swap(bar);

  	assert(foo.size() == 3);
  	assert(bar.size() == 2);

  	for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
  	{
  		assert(it->first == 'a' || it->first == 'b' || it->first == 'c');
  		assert(it->second == 11 || it->second == 22 || it->second == 33);
  	}

  	for (ft::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
  	{
  		assert(it->first == 'x' || it->first == 'y');
  		assert(it->second == 100 || it->second == 200);
  	}
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
		assert(it->second == arr1[i]);
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
		assert(it->second == arr1[i]);
		it++;
		i++;
	}
}

static void testFind()
{
	ft::map<char, int> 			m1;
	ft::map<char, int>::iterator	it;

	m1['a'] = 50;
	m1['b'] = 100;
	m1['c'] = 150;
	m1['d'] = 200;

	it = m1.find('b');
	if (it != m1.end())
		m1.erase (it);

	assert(m1.find('a')->second == 50);
	assert(m1.find('c')->second == 150);
	assert(m1.find('d')->second == 200);

	int					arr1[5] = {1, 2, 3, 4, 5};
	ft::map<int, int>	m2;

    for (int i = 0; i < 5; ++i)
    	m1.insert(ft::pair<int, int>(i, arr1[i]));

	assert(m1.find(0)->second == 1);
	assert(m1.find(1)->second == 2);
	assert(m1.find(2)->second == 3);
	assert(m1.find(3)->second == 4);
	assert(m1.find(4)->second == 5);    
}

static void testCount()
{
	ft::map<char,int> m1;

	m1['a'] = 101;
	m1['c'] = 202;
	m1['f'] = 303;

	assert(m1.count('a') == 1);
	assert(m1.count('c') == 1);
	assert(m1.count('d') == 0);
	assert(m1.count('e') == 0);
	assert(m1.count('f') == 1);
}

static void testLowerAndUpperBound()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	mymap.erase(itlow, itup);

	assert(mymap.size() == 2);
	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		assert(it->second == 20 || it->second == 100);
}

static void testEqualRange()
{
	ft::map<char,int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
  	ret = mymap.equal_range('b');

  	assert(ret.first->first == 'b');
  	assert(ret.first->second == 20);

  	assert(ret.second->first == 'c');
  	assert(ret.second->second == 30);
}

static void testSwapFunc()
{
    ft::map<char,int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

  	ft::swap(foo, bar);

  	assert(foo.size() == 3);
  	assert(bar.size() == 2);

  	for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
  	{
  		assert(it->first == 'a' || it->first == 'b' || it->first == 'c');
  		assert(it->second == 11 || it->second == 22 || it->second == 33);
  	}

  	for (ft::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
  	{
  		assert(it->first == 'x' || it->first == 'y');
  		assert(it->second == 100 || it->second == 200);
  	}
}

static void testClear()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;

    for (int i = 0; i < 5; ++i)
        m1.insert(ft::pair<int, int>(i, arr1[i]));
    m1.clear();
    assert(m1.size() == 0);
}

static void testOperatorEqual()
{
    int                 arr1[5] = {1, 2, 3, 4, 5};
    ft::map<int, int>   m1;
    ft::map<int, int>   m2;

    for (int i = 0; i < 5; ++i)
        m1.insert(ft::pair<int, int>(i, arr1[i]));
    for (int i = 1; i < 4; ++i)
        m2.insert(ft::pair<int, int>(i, arr1[i]));

    ft::map<int, int>   m3(m1);

    assert(m1 != m2);
    assert(m1 == m3);
    assert(m2 != m1);
    assert(m2 != m3);
    assert(m3 == m1);
    assert(m3 != m2);

    m3[0] = 100;
    assert(m1 != m3);
    assert(m3 != m1);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::map<int, char>  m1;
    ft::map<int, char>  m2;
    ft::map<int, char>  m3;

    for (int i = 0; s1[i]; ++i)
        m1.insert(ft::pair<int, char>(i, s1[i]));
    for (int i = 0; s2[i]; ++i)
        m2.insert(ft::pair<int, char>(i, s2[i]));
    for (int i = 0; s3[i]; ++i)
        m3.insert(ft::pair<int, char>(i, s3[i]));

    assert(m1 < m2);
    assert(m1 > m3);
    assert(m1 <= m2);
    assert(m1 >= m3);
    assert(m1 <= m1);
    assert(m1 >= m1);

    assert(m2 > m1);
    assert(m2 > m3);
    assert(m2 >= m1);
    assert(m2 >= m3);
    assert(m2 <= m2);
    assert(m2 >= m2);

    assert(m3 < m1);
    assert(m3 < m2);
    assert(m3 <= m1);
    assert(m3 <= m2);
    assert(m3 <= m3);
    assert(m3 >= m3);
}

void test_map()
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

    testOperatorBracket();
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