#include <gtest.h>
#include "list.h"

int main(int argc, char **argv)
{
    const int size = 5;
    List<int> l1(size);
    l1[0] = 43; l1[1] = 0; l1[2] = 432;  l1[3] = 2;

	std::cout << l1;
    //l1.sort();
    std::cout << l1;

    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
