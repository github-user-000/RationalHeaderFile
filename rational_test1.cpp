#include "Rational.hpp"

int main()
{
        Rational r1 = Rational(1, 6), r2 = Rational(10000, 60000);
        std::cout << (r1 + r2) << std::endl;
        std::cout << (r1 - r2) << std::endl;
        std::cout << (r1 / r2) << std::endl;
        std::cout << (r1 * r2) << std::endl;
        std::cout << (r1 += r2) << std::endl;
        std::cout << (r1 -= r2) << std::endl;
        std::cout << (r1 /= r2) << std::endl;
        std::cout << (r1 *= r2) << std::endl;
        std::cout << (++r1) << std::endl;
        std::cout << (--r1) << std::endl;
        std::cout << (r1 == r2) << std::endl;
        std::cout << (r1 != r2) << std::endl;
        std::cout << (r1 > r2) << std::endl;
        std::cout << (r1 < r2) << std::endl;
        std::cout << (r1 >= r2) << std::endl;
        std::cout << (r1 <= r2) << std::endl;
        std::cout << r2.simplified() << std::endl;
        std::cout << r2.to_decimal() << std::endl;

}
