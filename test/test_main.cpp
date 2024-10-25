#include <gtest.h>
#include "tmatrix.h"

int main(int argc, char **argv)
{/*
    const int size = 3;
    TDynamicVector<int> v(size);
    v[0] = 1; v[1] = 2; v[2] = 3;

    TDynamicMatrix<int> m1(size);
    TDynamicMatrix<int> m2(size);
    for (int i = 0; i < size; i++)
        m1[i] = m2[i] = v;

	std::cout << "m:\n " << m1 << std::endl;

	std::cout << "m1 * m2:\n " << m1 * m2 << std::endl;
    */
    const int size = 3;
    TDynamicVector<double> v1(size);
    v1[0] = 0.123; v1[1] = 1.32; v1[2] = 2.1;

    TDynamicVector<double> v2(v1);

    double* p1 = v1.data();
    double* p2 = v2.data();

    std::cout << &p1 << std::endl;
    std::cout << &p2 << std::endl;

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
