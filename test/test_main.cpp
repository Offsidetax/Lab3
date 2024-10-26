#include <gtest.h>
#include "list.h"

int main(int argc, char **argv)
{
    /*
    const int size = 5;
    List<int> l1(size);
    for (int i = 0; i < size; i++)
        l1[i] = i;
    List<int> l2(size);

	std::cout<<l1;
    std::cout << l2;*/
    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
