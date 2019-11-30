#include "stack.h"
#include <gtest.h>




TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> lst);
}


TEST(List, new_list_is_empty)
{
	List<int> lst;
	EXPECT_EQ(0, lst.getsize());
}

TEST(List, two_empty_lists_are_eq)
{
	List<int> lst1;
	List<int> lst2;
	EXPECT_TRUE(lst1 == lst2);
}

TEST(List, list_eq_itself) {
	List<int> lst;
	lst.push_back(10);
	lst.push_back(11);
	EXPECT_TRUE(lst == lst);
}
TEST(List, eq_no_empty_lists_are_eq) {
	List<int> lst, lst1;
	lst.push_begin(1);
	lst1.push_begin(1);
	EXPECT_TRUE(lst == lst1);
}

TEST(List, can_insert_no_empty_list)
{
	List<int> lst(3);
	List<int>::iterator it = lst.begin();
	lst.insert(it, 4);

}

TEST(List, can_remove_in_no_empty_list)
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	List<int>::iterator it = lst.begin();
	lst.remove(it);
	EXPECT_EQ(1, *it);
}

TEST(List, can_push_begin_in_empty_list)
{
	List<int> lst;
	lst.push_begin(2);
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(*it, 2);
}

TEST(List, can_push_begin_in_no_empty_list)
{
	List<int> lst;
	lst.push_begin(2);
	lst.push_begin(3);
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(3, *it);
}

TEST(List, can_push_back_in_empty_list)
{
	List<int> lst;
	lst.push_back(2);
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(*it, 2);
}

TEST(List, can_push_back_in_no_empty_list)
{
	List<int> lst;
	lst.push_back(2);
	lst.push_back(3);
	List<int>::iterator it = lst.begin();
	it++;
	EXPECT_EQ(3, *it);
}

TEST(List, cant_delete_begin_empty_list)
{
	List<int> lst;
	ASSERT_ANY_THROW(lst.delete_begin());
}

TEST(List, can_delete_begin_no_empty_list)
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.delete_begin();
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(2, *it);
}

TEST(List, cant_delete_back_empty_list)
{
	List<int> lst;
	ASSERT_ANY_THROW(lst.delete_back());
}

TEST(List, can_delete_back_no_empty_list)
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.delete_back();
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(1, *it);
}

TEST(List, can_get_size) {
	List<int> lst;
	lst.push_back(1);
	List<int>::iterator it = lst.begin();
	EXPECT_EQ(1, *it);
}
TEST(List, copied_list_equal_origin) {
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	List<int> lst1(lst);
	EXPECT_TRUE(lst == lst1);
}
TEST(List, copied_list_has_its_own_memory) {
	List<int> lst1;
	lst1.push_back(9);
	List<int> lst2(lst1);
	lst2.push_begin(8);
	List<int>::iterator it1 = lst1.begin();
	List<int>::iterator it2 = lst2.begin();
	EXPECT_FALSE(*it1 == *it2);

}