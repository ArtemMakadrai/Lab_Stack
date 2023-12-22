#include <gtest.h>
#include "TQueue.h"
#include "gtest.h"

TEST(TQueue, can_create_empty_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, cannot_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> q(-7));
}

TEST(TQueue, can_create_copied_queue) {
	TQueue<int> q(4);
	ASSERT_NO_THROW(TQueue<int> B(q));
}

TEST(TQueue, check_full_queue_true)
{
	TQueue<int> q(1);
	q.Push(1);
	EXPECT_EQ(1, q.isFull());
}
TEST(TQueue, check_empty_queue_true) {
	TQueue<int> q(7);
	EXPECT_EQ(1, q.isEmpty());
}
TEST(TQueue, can_push_element) {
	TQueue<int> q(4);

	ASSERT_NO_THROW(q.Push(7));
}

TEST(TQueue, can_pop_element) {
	TQueue<int> A(4);
	A.Push(7);

	EXPECT_EQ(7, A.Pop());
}
TEST(TQueue, check_get_end_put_in_queue)
{
	TQueue <int> q(5);
	for (int i = 1; i < 6; i++)
		q.Push(i); // 1 2 3 4 5

	q.Pop(); // 2 3 4 5 
	q.Pop(); // 3 4 5
	q.Pop(); // 4 5

	q.Push(10); // 4 5 10 
	q.Push(6); // 4 5 10 6
	q.Pop(); // 5 10 6
	ASSERT_EQ(5, q.Pop());
}

TEST(TQueue, can_get_Value_element)
{
	TQueue<int> q(2);
	q.Push(5);
	q.Push(12);
	EXPECT_EQ(q.Top(), 5);
}
TEST(TQueue, correct_ostream)
{
	TQueue<int> Qu(3);
	Qu.Push(1), Qu.Push(2), Qu.Push(3);
	ASSERT_EQ(Qu.Pop(), 1);
	ASSERT_EQ(Qu.Pop(), 2);
	ASSERT_EQ(Qu.Pop(), 3);
}