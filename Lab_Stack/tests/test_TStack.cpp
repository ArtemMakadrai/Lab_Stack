#include <gtest.h>

#include "TStack.h"

TEST(TStack, DefaultConstructorTest) {
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, InitializeConstructorTest) {
	ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, Throws_InitializeConstructorTest_ZeroSize) {
	ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, Throws_InitializeConstructorTest_NegativeSize) {
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, IsFullTest_Empty) {
	TStack<int> s(2);
	EXPECT_FALSE(s.IsFull());
}

TEST(TStack, IsFullTest_NotEmpty) {
	TStack<int> s(2);
	s.Push(1);
	EXPECT_FALSE(s.IsFull());
}

TEST(TStack, IsFullTest_Full) {
	TStack<int> s(2);
	s.Push(1);
	s.Push(2);
	EXPECT_TRUE(s.IsFull());
}

TEST(TStack, IsEmptyTest_Empty) {
	TStack<int> s(3);
	EXPECT_TRUE(s.IsEmpty());
}

TEST(TStack, IsEmptyTest_NotEmpty) {
	TStack<int> s(3);
	s.Push(1);
	EXPECT_FALSE(s.IsEmpty());
}

TEST(TStack, IsEmptyTest_Full) {
	TStack<int> s(2);
	s.Push(1);
	s.Push(2);
	EXPECT_FALSE(s.IsEmpty());
}

TEST(TStack, PushTest_StackIsEmpty) {
	TStack<int> s(2);
	ASSERT_NO_THROW(s.Push(1));
}

TEST(TStack, PushTest_StackIsNotEmpty) {
	TStack<int> s(2);
	s.Push(1);
	ASSERT_NO_THROW(s.Push(2));
}

TEST(TStack, Throws_PushTest_StackIsFull) {
	TStack<int> s(2);
	s.Push(1);
	s.Push(2);
	ASSERT_ANY_THROW(s.Push(3));
}

//Pop()
TEST(TStack, Throws_PopTest_StackIsEmpty) {
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, PopTest_StackIsNotEmpty) {
	TStack<int> s(3);
	s.Push(1);
	s.Push(2);
	ASSERT_NO_THROW(s.Pop());
}

TEST(TStack, PopTest_StackIsFull) {
	TStack<int> s(3);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	ASSERT_NO_THROW(s.Pop());
}

TEST(TStack, Throws_TopTest_StackIsEmpty) {
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, TopTest_StackIsNotEmpty) {
	TStack<int> s(3);
	s.Push(1);
	EXPECT_EQ(1, s.Top());
}

TEST(TStack, Throws_GetTopIndTest_StackIsEmpty) {
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.GetTopInd());
}

TEST(TStack, GetTopIndTest_StackIsNotEmpty) {
	TStack<int> s(3);
	s.Push(1);
	EXPECT_EQ(0, s.GetTopInd());
}