#include "srcs/vector.hpp"
#include <vector>
#include <cassert>

static void testConstructorDefault()
{

    ft::vector<int> v1;
    assert(v1.empty());
    assert(v1.size() == 0);
    assert(v1.capacity() >= 0);
    assert(v1.max_size() > 0);

    ft::vector<char> v2;
    assert(v2.empty());
    assert(v2.size() == 0);
    assert(v2.capacity() >= 0);
    assert(v2.max_size() > 0);

    ft::vector< ft::vector<char*> > v3;
    assert(v3.empty());
    assert(v3.size() == 0);
    assert(v3.capacity() >= 0);
    assert(v3.max_size() > 0);
}

static void testConstructorFill()
{
    ft::vector<int> v1(0);
    assert(v1.empty());
    assert(v1.size() == 0);
    assert(v1.capacity() >= 0);

    ft::vector<int> v2(3);
    assert(!v2.empty());
    assert(v2.size() == 3);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        assert(v2[i] == int());

    ft::vector<std::string> v3(5);
    assert(!v3.empty());
    assert(v3.size() == 5);
    assert(v3.capacity() >= 5);
    for (size_t i = 0; i < v3.size(); i++)
        assert(v3[i] == std::string());

    ft::vector<float> v4(6, 42.0f);
    assert(!v4.empty());
    assert(v4.size() == 6);
    assert(v4.capacity() >= 6);
    for (size_t i = 0; i < v4.size(); i++)
        assert(v4[i] == float(42.0));

    ft::vector<std::string> v5(2, "bonjour");
    assert(!v5.empty());
    assert(v5.size() == 2);
    assert(v5.capacity() >= 2);
    for (size_t i = 0; i < v5.size(); i++)
        assert(v5[i] == std::string("bonjour"));

    ft::vector<char> v6(5, 'a');
    assert(!v6.empty());
    assert(v6.size() == 5);
    assert(v6.capacity() >= 5);
    for (size_t i = 0; i < v6.size(); i++)
        assert(v6[i] == 'a');

    ft::vector<int> v7(6, 5);
    assert(!v7.empty());
    assert(v7.size() == 6);
    assert(v7.capacity() >= 6);
    for (size_t i = 0; i < v7.size(); i++)
        assert(v7[i] == 5);
    
    ft::vector<char> v8('6', '5');
    std::vector<char> v8_stl('6', '5');
    assert(!v8.empty());
    assert(v8.size() == v8_stl.size());
    assert(v8.capacity() == v8_stl.capacity());
    for (size_t i = 0; i < v8.size(); i++)
        assert(v8[i] == v8_stl[i]);
}

static void testConstructorRange()
{
    int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::vector<int> v1(arr1, arr1 + 5);
    assert(!v1.empty());
    assert(v1.size() == 5);
    assert(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == arr1[i]);

    ft::vector<std::string> v2(arr2, arr2 + 3);
    assert(!v2.empty());
    assert(v2.size() == 3);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        assert(v2[i] == arr2[i]);

    ft::vector<float> v3(arr3, arr3 + 4);
    assert(!v3.empty());
    assert(v3.size() == 4);
    assert(v3.capacity() >= 4);
    for (size_t i = 0; i < v3.size(); i++)
        assert(v3[i] == arr3[i]);
}

static void testConstructorCopy()
{
    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::vector<int>                 v1_copied(arr1, arr1 + 5);
    ft::vector<std::string>         v2_copied(arr2, arr2 + 3);
    ft::vector<float>               v3_copied(6, 42.0f);
    ft::vector< ft::vector<char*> > v4_copied;

    ft::vector<int> v1(v1_copied);
    assert(v1.empty() == v1_copied.empty());
    assert(v1.size() == v1_copied.size());
    assert(v1.capacity() == v1_copied.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == v1_copied[i]);
    v1[0] = 0;
    assert(v1[0] == 0);
    assert(v1_copied[0] == 1);

    ft::vector<std::string> v2(v2_copied);
    assert(v2.empty() == v2_copied.empty());
    assert(v2.size() == v2_copied.size());
    assert(v2.capacity() == v2_copied.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        assert(v2[i] == v2_copied[i]);
    v2[0] = "aaa";
    assert(v2[0] == "aaa");
    assert(v2_copied[0] == "bonjour");
    v2[1] = "bbb";
    assert(v2[1] == "bbb");
    assert(v2_copied[1] == "je");
    v2[2] = "ccc";
    assert(v2[2] == "ccc");
    assert(v2_copied[2] == "suis");

    ft::vector<float> v3(v3_copied);
    assert(v3.empty() == v3_copied.empty());
    assert(v3.size() == v3_copied.size());
    assert(v3.capacity() == v3_copied.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        assert(v3[i] == v3_copied[i]);
    v3[5] = 19.19f;
    assert(v3[5] == 19.19f);
    assert(v3_copied[0] == 42.0);

    ft::vector< ft::vector<char*> > v4(v4_copied);
    assert(v4.empty() == v4_copied.empty());
    assert(v4.size() == v4_copied.size());
    assert(v4.capacity() == v4_copied.capacity());
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
    assert(
        (v1.empty() == v1_stl.empty()) && 
        (v1_duplicated.empty() == v1_duplicated_stl.empty())
    );
    assert(
        (v1.size() == v1_stl.size()) && 
        (v1_duplicated.size() == v1_duplicated_stl.size())
    );
    assert(
        (v1.capacity() == v1_stl.capacity()) && 
        (v1_duplicated.capacity() == v1_duplicated_stl.capacity())
    );
    for (size_t i = 0; i < v1.size(); i++)
    {
        assert(v1[i] == v1_stl[i]);
        assert(v1_duplicated[i] == v1_duplicated_stl[i]);
    }
    v1[0] = 0;
    assert(v1[0] == 0);
    assert(v1_duplicated[0] == 1);

    ft::vector<std::string> v2(10, "zzz");
    std::vector<std::string> v2_stl(10, "zzz");
    v2 = v2_duplicated;
    v2_stl = v2_duplicated_stl;
    assert(
        (v2.empty() == v2_stl.empty()) && 
        (v2_duplicated.empty() == v2_duplicated_stl.empty())
    );
    assert(
        (v2.size() == v2_stl.size()) && 
        (v2_duplicated.size() == v2_duplicated_stl.size())
    );
    assert(
        (v2.capacity() == v2_stl.capacity()) && 
        (v2_duplicated.capacity() == v2_duplicated_stl.capacity())
    );   
    for (size_t i = 0; i < v2.size(); i++)
        assert(v2[i] == v2_duplicated[i]);
    v2[0] = "aaa";
    assert(v2[0] == "aaa");
    assert(v2_duplicated[0] == "bonjour");
    v2[1] = "bbb";
    assert(v2[1] == "bbb");
    assert(v2_duplicated[1] == "je");
    v2[2] = "ccc";
    assert(v2[2] == "ccc");
    assert(v2_duplicated[2] == "suis");

    // v2 = v2_duplicated
    ft::vector<float> v3(v3_duplicated);
    std::vector<float> v3_stl(v3_duplicated_stl);
    v3 = v3_duplicated;
    v3_stl = v3_duplicated_stl;
    assert(
        (v3.empty() == v3_stl.empty()) && 
        (v3_duplicated.empty() == v3_duplicated_stl.empty())
    );
    assert(
        (v3.size() == v3_stl.size()) && 
        (v3_duplicated.size() == v3_duplicated_stl.size())
    );
    assert(
        (v3.capacity() == v3_stl.capacity()) && 
        (v3_duplicated.capacity() == v3_duplicated_stl.capacity())
    );
    for (size_t i = 0; i < v3.size(); i++)
        assert(v3[i] == v3_duplicated[i]);
    v3[5] = 19.19f;
    assert(v3[5] == 19.19f);
    assert(v3_duplicated[0] == 42.0f);


    ft::vector< ft::vector<char*> > v4(2, ft::vector<char*>(2, NULL));
    std::vector< std::vector<char*> > v4_stl(2, std::vector<char*>(2, NULL));
    v4 = v4_duplicated;
    v4_stl = v4_duplicated_stl;
    assert(
        (v4.empty() == v4_stl.empty()) && 
        (v4_duplicated.empty() == v4_duplicated_stl.empty())
    );
    assert(
        (v4.size() == v4_stl.size()) && 
        (v4_duplicated.size() == v4_duplicated_stl.size())
    );
    assert(
        (v4.capacity() == v4_stl.capacity()) && 
        (v4_duplicated.capacity() == v4_duplicated_stl.capacity())
    );
}

static void testBegin()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    ft::vector<int>::iterator v1_it = v1.begin();

    assert(*v1_it == 1);
    assert(*(int*)(v1_it.operator->()) == 1);
    assert(v1_it[0] == 1);
    assert(v1_it[1] == 2);
    assert(v1_it[2] == 3);
    assert(v1_it[3] == 4);
    assert(v1_it[4] == 5);


    assert(v1_it == v1.begin());
    assert(v1_it != v1.rbegin().base());
    assert(v1_it != v1.end());
    assert(v1_it == v1.rend().base());

    assert(v1_it <= v1.begin());
    assert(v1_it >= v1.begin());
    assert(v1_it < v1.end());
    assert(v1.end() > v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it + i) == arr1[i]);

    for (size_t i = 0; v1_it != v1.end(); ++v1_it, i++)
        assert(*v1_it == arr1[i]);
    assert(v1_it == v1.end());

    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it - 1 - i) == arr1[4 - i]);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        assert(*v1_it == arr1[4 - i]);
    assert(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*v1_it++ == arr1[i]);
    assert(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        assert(*v1_it-- == arr1[4 - i]);
}

static void testEnd()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    ft::vector<int>::iterator v1_it = v1.end();
    assert(v1_it[-1] == 5);
    assert(v1_it[-2] == 4);
    assert(v1_it[-3] == 3);
    assert(v1_it[-4] == 2);
    assert(v1_it[-5] == 1);

    assert(v1_it == v1.end());
    assert(v1_it != v1.begin());
    assert(v1_it == v1.rbegin().base());
    assert(v1_it != v1.rend().base());

    assert(v1_it >= v1.end());
    assert(v1_it >= v1.end());
    assert(v1_it <= v1.end());
    assert(v1_it <= v1.end());
    assert(v1_it > v1.begin());
    assert(v1.begin() < v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it - i - 1) == arr1[4 - i]);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        assert(*v1_it == arr1[4 - i]);
    assert(v1_it == v1.begin());
    assert(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it + i) == arr1[i]);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*v1_it++ == arr1[i]);
    assert(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        assert(*v1_it-- == arr1[4 - i]);
}

static void testRbegin()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    ft::vector<int>::reverse_iterator v1_it = v1.rbegin();
    assert(v1_it[0] == 5);
    assert(v1_it[1] == 4);
    assert(v1_it[2] == 3);
    assert(v1_it[3] == 2);
    assert(v1_it[4] == 1);

    assert(v1_it == v1.rbegin());
    assert(v1_it != v1.rend());
    assert(v1_it.base() != v1.begin());
    assert(v1_it.base() == v1.end());

    assert(v1_it >= v1.rbegin());
    assert(v1_it >= v1.rbegin());
    assert(v1_it <= v1.rbegin());
    assert(v1_it <= v1.rbegin());
    assert(v1_it.base() > v1.begin());
    assert(v1_it.base() <= v1.end());
    assert(v1_it < v1.rend());


    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it + i) == arr1[4 - i]);

    for (size_t i = 0; i < v1.size(); i++)
        assert(*v1_it++ == arr1[4 - i]);
    assert(v1_it == v1.rend());
}

static void testRend()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    ft::vector<int>::reverse_iterator v1_it = v1.rend();
    assert(v1_it[-1] == 1);
    assert(v1_it[-2] == 2);
    assert(v1_it[-3] == 3);
    assert(v1_it[-4] == 4);
    assert(v1_it[-5] == 5);

    assert(v1_it == v1.rend());
    assert(v1_it != v1.rbegin());
    assert(v1_it.base() == v1.begin());
    assert(v1_it.base() != v1.end());

    assert(v1_it > v1.rbegin());
    assert(v1_it.base() < v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        assert(*(v1_it - i) == arr1[i]);
}

static void testResize()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    v1.resize(7);
    assert(v1.size() == 7);
    assert(v1.capacity() >= 7);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
    for (size_t i = 5; i < v1.size(); i++)
        assert(v1[i] == int());

    v1.resize(10, 42);
    assert(v1.size() == 10);
    assert(v1.capacity() >= 10);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
    for (size_t i = 5; i < 7; i++)
        assert(v1[i] == int());
    for (size_t i = 7; i < v1.size(); i++)
        assert(v1[i] == 42);

    size_t prev_capacity = v1.capacity();
    v1.resize(10);
    assert(v1.size() == 10);
    assert(v1.capacity() == prev_capacity);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
    for (size_t i = 5; i < 7; i++)
        assert(v1[i] == int());
    for (size_t i = 7; i < v1.size(); i++)
        assert(v1[i] == 42);

    v1.resize(6);
    assert(v1.size() == 6);
    assert(v1.capacity() >= 6);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
    assert(v1[5] == int());

    v1.resize(1);
    assert(v1.size() == 1);
    assert(v1.capacity() >= 1);
    assert(v1[0] == arr1[0]);

    v1.resize(0);
    assert(v1.size() == 0);
    assert(v1.capacity() >= 0);
}

static void testReserve()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    v1.reserve(0);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == arr1[i]);

    v1.reserve(5);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == arr1[i]);

    v1.reserve(6);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 6);
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == arr1[i]);

    v1.reserve(30);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 30);
    for (size_t i = 0; i < v1.size(); i++)
        assert(v1[i] == arr1[i]);
}

static void testOperatorBracket()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);
    assert(v1[4] == 5);

    int&       mut  = v1[0];
    const int& imut = v1[0];
    assert(mut == 1);
    assert(imut == 1);
}

static void testAt()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    try
    {
        assert(v1.at(0) == 1);
        assert(v1.at(1) == 2);
        assert(v1.at(2) == 3);
        assert(v1.at(3) == 4);
        assert(v1.at(4) == 5);

        int&       mut  = v1.at(0);
        const int& imut = v1.at(0);
        assert(mut == 1);
        assert(imut == 1);
    }
    catch (const std::exception& e) { assert(false); }

    try { v1.at(5); }
    catch (const std::out_of_range& e) { assert(true); }
    catch (const std::exception& e)    { assert(false); }

    try { v1.at(-1); }
    catch (const std::out_of_range& e) { assert(true); }
    catch (const std::exception& e)    { assert(false); }
}

static void testFront()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    int&       mut  = v1.front();
    const int& imut = v1.front();
    assert(mut == 1);
    assert(imut == 1);
}

static void testBack()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    int&       mut  = v1.back();
    const int& imut = v1.back();
    assert(mut == 5);
    assert(imut == 5);
}

static void testAssign()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    v1.assign(arr1 + 1, arr1 + 4);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v1[i] == arr1[i + 1]);

    v1.assign((size_t)6, (int)42);
    assert(v1.size() == 6);
    assert(v1.capacity() >= 6);
    for (size_t i = 0; i < 6; i++)
        assert(v1[i] == 42);

    // fml
    std::vector< std::vector<int>::size_type > ve(arr1, arr1 + 5);
    ve.assign(6, 42);
    assert(ve.size() == 6);
    assert(ve.capacity() >= 6);
    for (size_t i = 0; i < 6; i++)
        assert(ve[i] == 42);
}

static void testPushBack()
{
    ft::vector<int> v1;

    v1.push_back(1);
    assert(v1.size() == 1);
    assert(v1.capacity() >= 1);
    assert(v1[0] == 1);

    v1.push_back(2);
    assert(v1.size() == 2);
    assert(v1.capacity() >= 2);
    assert(v1[0] == 1);
    assert(v1[1] == 2);

    v1.push_back(3);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);

    v1.push_back(4);
    assert(v1.size() == 4);
    assert(v1.capacity() >= 4);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);

    v1.push_back(5);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 5);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);
    assert(v1[4] == 5);
}

static void testPopBack()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);

    v1.pop_back();
    assert(v1.size() == 4);
    assert(v1.capacity() >= 4);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);

    v1.pop_back();
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);

    v1.pop_back();
    assert(v1.size() == 2);
    assert(v1.capacity() >= 2);
    assert(v1[0] == 1);
    assert(v1[1] == 2);

    v1.pop_back();
    assert(v1.size() == 1);
    assert(v1.capacity() >= 1);
    assert(v1[0] == 1);

    v1.pop_back();
    assert(v1.size() == 0);
    assert(v1.capacity() >= 0);
}

static void testInsert()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1;
    ft::vector<int>::iterator it;

    it = v1.insert(v1.end(), 1);
    assert(v1.size() == 1);
    assert(v1.capacity() >= 1);
    assert(v1[0] == 1);
    assert(*it == 1);

    it = v1.insert(v1.end(), 2);
    assert(v1.size() == 2);
    assert(v1.capacity() >= 2);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(*it == 2);

    it = v1.insert(v1.begin(), 0);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    assert(v1[0] == 0);
    assert(v1[1] == 1);
    assert(v1[2] == 2);
    assert(*it == 0);

    v1.insert(v1.begin() + 1, arr1 + 1, arr1 + 4);
    assert(v1.size() == 6);
    assert(v1.capacity() >= 6);
    assert(v1[0] == 0);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);
    assert(v1[4] == 1);
    assert(v1[5] == 2);

    v1.insert(v1.begin() + 2, (size_t)3, (int)-1);
    assert(v1.size() == 9);
    assert(v1.capacity() >= 9);
    assert(v1[0] == 0);
    assert(v1[1] == 2);
    assert(v1[2] == -1);
    assert(v1[3] == -1);
    assert(v1[4] == -1);
    assert(v1[5] == 3);
    assert(v1[6] == 4);
    assert(v1[7] == 1);
    assert(v1[8] == 2);
}

static void testErase()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int>::iterator it;

    it = v1.erase(v1.begin());
    assert(v1.size() == 4);
    assert(v1.capacity() >= 4);
    for (size_t i = 0; i < 4; i++)
        assert(v1[i] == arr1[i + 1]);
    assert(*it == 2);

    it = v1.erase(v1.end() - 1);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v1[i] == arr1[i + 1]);
    assert(it == v1.end());

    it = v1.erase(v1.end() - 2);
    assert(v1.size() == 2);
    assert(v1.capacity() >= 2);
    assert(v1[0] == 2);
    assert(v1[1] == 4);
    assert(*it == 4);

    v1.assign(arr1, arr1 + 5);
    it = v1.erase(v1.begin() + 1, v1.begin() + 3);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    assert(v1[0] == 1);
    assert(v1[1] == 4);
    assert(v1[2] == 5);
    assert(*it == 4);

    it = v1.erase(v1.begin() + 1, v1.end());
    assert(v1.size() == 1);
    assert(v1.capacity() >= 1);
    assert(v1[0] == 1);
    assert(it == v1.end());
}

static void testSwap()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);

    v1.swap(v2);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v1[i] == arr1[i + 1]);
    assert(v2.size() == 5);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        assert(v2[i] == arr1[i]);

    v2.swap(v1);
    assert(v2.size() == 3);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v2[i] == arr1[i + 1]);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
}

static void testClear()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    v1.clear();
    assert(v1.size() == 0);
}

static void testOperatorEqual()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);
    ft::vector<int> v3(v1);

    assert(v1 != v2);
    assert(v1 == v3);
    assert(v2 != v1);
    assert(v2 != v3);
    assert(v3 == v1);
    assert(v3 != v2);

    v3[0] = 0;
    assert(v1 != v3);
    assert(v3 != v1);
}

static void testOperatorCompar()
{
    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::vector<char> v1(s1.begin(), s1.end());
    ft::vector<char> v2(s2.begin(), s2.end());
    ft::vector<char> v3(s3.begin(), s3.end());

    assert(v1 < v2);
    assert(v1 > v3);
    assert(v1 <= v2);
    assert(v1 >= v3);
    assert(v1 <= v1);
    assert(v1 >= v1);

    assert(v2 > v1);
    assert(v2 > v3);
    assert(v2 >= v1);
    assert(v2 >= v3);
    assert(v2 <= v2);
    assert(v2 >= v2);

    assert(v3 < v1);
    assert(v3 < v2);
    assert(v3 <= v1);
    assert(v3 <= v2);
    assert(v3 <= v3);
    assert(v3 >= v3);
}

static void testSwapFunc()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::vector<int> v1(arr1, arr1 + 5);
    ft::vector<int> v2(arr1 + 1, arr1 + 4);

    ft::swap(v1, v2);
    assert(v1.size() == 3);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v1[i] == arr1[i + 1]);
    assert(v2.size() == 5);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        assert(v2[i] == arr1[i]);

    ft::swap(v1, v2);
    assert(v2.size() == 3);
    assert(v2.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        assert(v2[i] == arr1[i + 1]);
    assert(v1.size() == 5);
    assert(v1.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        assert(v1[i] == arr1[i]);
}

static void testData()
{
    ft::vector<float>   v1(6, 42.0f);
    const float*        p;
    size_t              size;

    p = v1.data();
    size = v1.size();
    for (size_t i = 0; i < size; ++i)
        assert(p[i] == v1[i]);
}

void test_vector()
{
	testConstructorDefault();
    testConstructorFill();
    testConstructorRange();
    testConstructorCopy();
    testOperatorAssign();

    testBegin();
    testEnd();
    testRbegin();
    testRend();

    testResize();
    testReserve();

    testOperatorBracket();
    testAt();
    testFront();
    testBack();
    testAssign();

    testPushBack();
    testPopBack();

    testInsert();
    
    testErase();
    testSwap();
    testClear();

    testOperatorEqual();
    testOperatorCompar();
    testSwapFunc();

    testData();
}