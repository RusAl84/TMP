#include "pch.h"
#include <gtest/gtest.h>

using namespace std;

TEST(TestGroupName, Subtest_1) {
    //adapter4myStack st(100);
    //st.push(1);
    //st.push(2);
    //st.push(3);
    //st.push(4);
	ASSERT_TRUE(1 == 1);
}

//TEST(TestGroupName, Subtest_2) {
//	ASSERT_FALSE('b' == 'b');
//	cout << "continue test after failure" << endl;
//}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}