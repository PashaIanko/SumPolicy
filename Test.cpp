#include "pch.h"
#include "test.h"
#include "gtest\gtest.h"




TEST(CHAR_ARR, char_arr)
{
	const char hello[] = "hello!";
	const bool res = test_func(hello, hello);
	EXPECT_TRUE(res);
}

TEST(CHAR_ARR, empty_char_arr)
{
	const char str[] = "";
	const bool res = test_func(str, str);
	EXPECT_TRUE(res);
}

TEST(VECT, int_v)
{
	const std::vector<int> v = {1,2,3};
	const bool res = test_func(v, v);
	EXPECT_TRUE(res);
}

TEST(VECT, empty_int_v)
{
	const std::vector<int> v = { };
	EXPECT_EQ(test_func(v, v), true);
}

TEST(VECT, double_v)
{
	const std::vector<double> v = { 1.1, 2.2, 3.3 };
	EXPECT_EQ(test_func(v, v), true);
}

TEST(VECT, empty_double_v)
{
	const std::vector<double> v = {};
	EXPECT_EQ(test_func(v, v), true);
}

TEST(VECT, empty_char_v)
{
	const std::vector<char> v = {};
	EXPECT_EQ(test_func(v, v), true);
}

TEST(VECT, char_v)
{
	const std::vector<char> v = {'a','b','c'};
	EXPECT_EQ(test_func(v, v), true);
}


TEST(STRINGS, regular)
{
	std::string str = "hello";
	const bool res = test_func(str, str);
	EXPECT_TRUE(res);
}

TEST(STRINGS, empty_string)
{
	std::string str = "";
	const bool res = test_func(str, str);
	EXPECT_TRUE(res); 
}



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}
