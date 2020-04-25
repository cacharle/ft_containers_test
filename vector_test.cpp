/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:34:52 by charles           #+#    #+#             */
/*   Updated: 2020/04/25 11:40:15 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"
#include <vector>

static void testConstructorDefault()
{
    ft::Vector<int> v1;
    ASSERT(v1.empty());
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);
    ASSERT(v1.max_size() > 0);

    ft::Vector<char> v2;
    ASSERT(v2.empty());
    ASSERT(v2.size() == 0);
    ASSERT(v2.capacity() >= 0);
    ASSERT(v2.max_size() > 0);

    ft::Vector< ft::Vector<char*> > v3;
    ASSERT(v3.empty());
    ASSERT(v3.size() == 0);
    ASSERT(v3.capacity() >= 0);
    ASSERT(v3.max_size() > 0);
}

static void testConstructorFill()
{
    ft::Vector<int> v1(0);
    ASSERT(v1.empty());
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);

    ft::Vector<int> v2(3);
    ASSERT(!v2.empty());
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == int());

    ft::Vector<std::string> v3(5);
    ASSERT(!v3.empty());
    ASSERT(v3.size() == 5);
    ASSERT(v3.capacity() >= 5);
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == std::string());

    ft::Vector<float> v4(6, 42.0f);
    ASSERT(!v4.empty());
    ASSERT(v4.size() == 6);
    ASSERT(v4.capacity() >= 6);
    for (size_t i = 0; i < v4.size(); i++)
        ASSERT(v4[i] == float(42.0));

    ft::Vector<std::string> v5(2, "bonjour");
    ASSERT(!v5.empty());
    ASSERT(v5.size() == 2);
    ASSERT(v5.capacity() >= 2);
    for (size_t i = 0; i < v5.size(); i++)
        ASSERT(v5[i] == std::string("bonjour"));
}

static void testConstructorRange()
{
    int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::Vector<int> v1(arr1, arr1 + 5);
    ASSERT(!v1.empty());
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);

    ft::Vector<std::string> v2(arr2, arr2 + 3);
    ASSERT(!v2.empty());
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == arr2[i]);

    ft::Vector<float> v3(arr3, arr3 + 4);
    ASSERT(!v3.empty());
    ASSERT(v3.size() == 4);
    ASSERT(v3.capacity() >= 4);
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == arr3[i]);
}

static void testConstructorCopy()
{
    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::Vector<int>                 v1_copied(arr1, arr1 + 5);
    ft::Vector<std::string>         v2_copied(arr2, arr2 + 3);
    ft::Vector<float>               v3_copied(6, 42.0f);
    ft::Vector< ft::Vector<char*> > v4_copied;

    ft::Vector<int> v1(v1_copied);
    ASSERT(v1.empty() == v1_copied.empty());
    ASSERT(v1.size() == v1_copied.size());
    ASSERT(v1.capacity() == v1_copied.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == v1_copied[i]);
    v1[0] = 0;
    ASSERT(v1[0] == 0);
    ASSERT(v1_copied[0] == 1);

    ft::Vector<std::string> v2(v2_copied);
    ASSERT(v2.empty() == v2_copied.empty());
    ASSERT(v2.size() == v2_copied.size());
    ASSERT(v2.capacity() == v2_copied.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == v2_copied[i]);
    v2[0] = "aaa";
    ASSERT(v2[0] == "aaa");
    ASSERT(v2_copied[0] == "bonjour");
    v2[1] = "bbb";
    ASSERT(v2[1] == "bbb");
    ASSERT(v2_copied[1] == "je");
    v2[2] = "ccc";
    ASSERT(v2[2] == "ccc");
    ASSERT(v2_copied[2] == "suis");

    ft::Vector<float> v3(v3_copied);
    ASSERT(v3.empty() == v3_copied.empty());
    ASSERT(v3.size() == v3_copied.size());
    ASSERT(v3.capacity() == v3_copied.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == v3_copied[i]);
    v3[5] = 19.19f;
    ASSERT(v3[5] == 19.19f);
    ASSERT(v3_copied[0] == 42.0);

    ft::Vector< ft::Vector<char*> > v4(v4_copied);
    ASSERT(v4.empty() == v4_copied.empty());
    ASSERT(v4.size() == v4_copied.size());
    ASSERT(v4.capacity() == v4_copied.capacity());
}

static void testOperatorEqual()
{
    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::Vector<int>                 v1_duplicated(arr1, arr1 + 5);
    ft::Vector<std::string>         v2_duplicated(arr2, arr2 + 3);
    ft::Vector<float>               v3_duplicated(6, 42.0f);
    ft::Vector< ft::Vector<char*> > v4_duplicated;

    ft::Vector<int> v1;
    v1 = v1_duplicated;
    ASSERT(v1.empty() == v1_duplicated.empty());
    ASSERT(v1.size() == v1_duplicated.size());
    ASSERT(v1.capacity() == v1_duplicated.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == v1_duplicated[i]);
    v1[0] = 0;
    ASSERT(v1[0] == 0);
    ASSERT(v1_duplicated[0] == 1);

    ft::Vector<std::string> v2(10, "zzz");
    v2 = v2_duplicated;
    ASSERT(v2.empty() == v2_duplicated.empty());
    ASSERT(v2.size() == v2_duplicated.size());
    ASSERT(v2.capacity() == v2_duplicated.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == v2_duplicated[i]);
    v2[0] = "aaa";
    ASSERT(v2[0] == "aaa");
    ASSERT(v2_duplicated[0] == "bonjour");
    v2[1] = "bbb";
    ASSERT(v2[1] == "bbb");
    ASSERT(v2_duplicated[1] == "je");
    v2[2] = "ccc";
    ASSERT(v2[2] == "ccc");
    ASSERT(v2_duplicated[2] == "suis");

    ft::Vector<float> v3(v3_duplicated);
    v3 = v3_duplicated;
    ASSERT(v3.empty() == v3_duplicated.empty());
    ASSERT(v3.size() == v3_duplicated.size());
    ASSERT(v3.capacity() == v3_duplicated.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == v3_duplicated[i]);
    v3[5] = 19.19f;
    ASSERT(v3[5] == 19.19f);
    ASSERT(v3_duplicated[0] == 42.0f);

    ft::Vector< ft::Vector<char*> > v4(2, ft::Vector<char*>(2, NULL));
    v4 = v4_duplicated;
    ASSERT(v4.empty() == v4_duplicated.empty());
    ASSERT(v4.size() == v4_duplicated.size());
    ASSERT(v4.capacity() == v4_duplicated.capacity());
}

static void testBegin()
{
    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ft::Vector<int>::iterator v1_it = v1.begin();
    ASSERT(*v1_it == 1);
    ASSERT(*(int*)(v1_it.operator->()) == 1);
    ASSERT(v1_it[0] == 1);
    ASSERT(v1_it[1] == 2);
    ASSERT(v1_it[2] == 3);
    ASSERT(v1_it[3] == 4);
    ASSERT(v1_it[4] == 5);

    ASSERT(v1_it == v1.begin());
    ASSERT(v1_it != v1.rbegin());
    ASSERT(v1_it != v1.end());
    ASSERT(v1_it != v1.rend());

    ASSERT(v1_it <= v1.begin());
    ASSERT(v1_it >= v1.begin());
    ASSERT(v1_it < v1.end());
    ASSERT(v1.end() > v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it + i) == arr1[i]);

    for (size_t i = 0; v1_it != v1.end(); ++v1_it, i++)
        ASSERT(*v1_it == arr1[i]);
    ASSERT(v1_it == v1.end());

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it - 1 - i) == arr1[4 - i]);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        ASSERT(*v1_it == arr1[4 - i]);
    ASSERT(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it++ == arr1[i]);
    ASSERT(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it-- == arr1[4 - i]);
}

void vectorTest()
{
    testConstructorDefault();
    testConstructorFill();
    testConstructorRange();
    testConstructorCopy();
    testOperatorEqual();

    testBegin();

}
