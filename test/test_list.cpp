#include "list.h"

#include <gtest.h>

TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(List<int> l());
}

TEST(List, can_create_list_with_positive_length)
{
	ASSERT_NO_THROW(List<int> l(5));
}

TEST(List, throws_when_create_list_with_negative_length)
{
	ASSERT_ANY_THROW(List<int> l(-5));
}

TEST(List, can_create_list_by_size_and_value)
{
    ASSERT_NO_THROW(List<int> l1(5,5));
}

TEST(List, can_create_copied_list)
{
	List<int> l(5);

	ASSERT_NO_THROW(List<int> l1(l));
}

TEST(List, copied_list_is_equal_to_source_one)
{
	const int size = 5;
	List<int> l1(size);
	l1[0] = 0; l1[1] = 1; l1[2] = 2;

	List<int> l2(l1);

	EXPECT_EQ(l1, l2);
}

TEST(List, can_get_size)
{
	List<int> l(40);

	EXPECT_EQ(40, l.size());
}

TEST(List, can_assign_list_to_itself)
{
	const int size = 10;
	List<int> l1(size);

	EXPECT_EQ(l1, l1);
}

TEST(List, can_assign_lists_of_equal_size)
{
    const int size = 5;
    List<int> l1(size);
    for (int i = 0; i < size; i++)
        l1[i] = i;
    List<int> l2(size);

    EXPECT_EQ(l2 = l1, l1);
}

TEST(List, assign_operator_change_size_of_list)
{
    const int size = 5;
    List<int> l1(size * 2);
    List<int> l2(size);

    l2 = l1;

    EXPECT_NE(l2.size(), size);
}

TEST(List, compare_equal_lists_return_true)
{
    const int size = 10;
    List<int> l1(size);
    List<int> l2(size);
    l1[0] = l2[0] = size;

    ASSERT_EQ(l1 == l2, 1);
}

TEST(List, compare_lists_with_itself_return_true)
{
    const int size = 10;
    List<int> l1(size);

    ASSERT_EQ(l1 == l1, 1);
}

TEST(List, lists_with_different_size_are_not_equal)
{
    const int size = 10;
    List<int> l1(size);
    List<int> l2(size + 1);

    ASSERT_NE(l1 == l2, 1);
}

TEST(List, can_insert_element_in_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 0; l1[1] = 1; l1[2] = 2;
    List<int> l2(size+1);
    l2[0] = 0; l2[1] = 2; l2[2] = 1;  l2[3] = 2;

    l1.insert(2, l1.Get_First());

    ASSERT_EQ(l1 == l2, 1);
}

TEST(List, can_insert_element_in_the_start_of_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 0; l1[1] = 1; l1[2] = 2;
    List<int> l2(size+1);
    l2[0] = 0; l2[1] = 0; l2[2] = 1;  l2[3] = 2;

    l1.insert_front(0);

    ASSERT_EQ(l1 == l2, 1);
}

TEST(List, can_erase_element_in_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 0; l1[1] = 1; l1[2] = 2;
    List<int> l2(size + 1);
    l2[0] = 0; l2[1] = 2; l2[2] = 1;  l2[3] = 2;

    l2.erase(l2.Get_First());

    ASSERT_EQ(l1 == l2, 1);
}

TEST(List, can_erase_element_in_the_start_of_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 0; l1[1] = 1; l1[2] = 2;
    List<int> l2(size + 1);
    l2[0] = 0; l2[1] = 0; l2[2] = 1;  l2[3] = 2;

    l2.erase_front();

    ASSERT_EQ(l1 == l2, 1);
}

TEST(List, can_find_element_in_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 100; l1[1] = 1; l1[2] = 2;

    ASSERT_EQ(l1.find(100), l1.Get_First());
}

TEST(List, iterator_implication)
{
    const int size = 5;
    List<int> l1(size);
    l1[1] = 1; l1[2] = 2;
    auto first = l1.begin();

    first++;

    ASSERT_EQ(l1[1], *first);
}

TEST(List, returning_iterator_data)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 100;
    auto first = l1.begin();

    int res = *first;

    ASSERT_EQ(l1[0], res);
}
/*
TEST(List, returning_link_on_iterator_data)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 100;
    auto first = l1.begin();

    l1.begin()->;

    ASSERT_EQ(l1[0], res);
}*/

TEST(List, equal_iterators_are_equal)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 100;
    auto first1 = l1.begin();
    auto first2 = l1.begin();

    ASSERT_EQ(first1==first2, true);
}

TEST(List, non_equal_iterators_are_equal)
{
    const int size = 5;
    List<int> l1(size);
    List<int> l2(size);
    l1[0] = 100;
    l1[0] = 1;
    auto first1 = l1.begin();
    auto first2 = l2.begin();

    ASSERT_EQ(first1 == first2, false);
}

TEST(List, no_error_while_sorting_list)
{
    const int size = 10;
    List<int> l1(size);
    l1[0] = 43; l1[1] = 243; l1[2] = 32;  l1[3] = 9022;

    ASSERT_NO_THROW(sort(l1));
}

TEST(List, no_error_while_sorting_list_of_length_one)
{
    const int size = 1;
    List<int> l1(size);
    l1[0] = 43;

    ASSERT_NO_THROW(sort(l1));
}

TEST(List, correctly_sorting_list)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 43; l1[1] = 0; l1[2] = 432;  l1[3] = 2;
    List<int> l2(size);
    l2[0] = 0; l2[1] = 0; l2[2] = 2;  l2[3] = 43;  l2[4] = 432;
    
    sort(l1);
    
    ASSERT_EQ(l1, l2);
}