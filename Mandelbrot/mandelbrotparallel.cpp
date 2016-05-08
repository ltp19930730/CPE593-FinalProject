#include <complex>
#include <vector>
#include <limits>

#include <string>
#include <sstream>
#include <vector>
#include <QObject>

using namespace std;

template<typename Iterate, typename IterationMap, typename T>
int boundedorbit(Iterate f, complex<T> seed, int bound, int bailout=100,
                 IterationMap itmap = [](int n, complex<T> z, int bailout) {return n;})
{
    auto z = f(seed);
    vector<int> bailoutRange;
    for (int i = 1; i <= bailout; i++)
        bailoutRange.push_back(i);
    for(auto k : bailoutRange) {
        if (abs(z) > bound)
            return itmap(k,z,bailout);
        z = f(z);
    }

    return numeric_limits<int>::min();
}

template<typename T>
float normalized_iterations(int n, complex<T> zn, int bailout) {
    return n + (log(log(bailout)) - log(log(abs(zn))))/log(2);
}

template <typename T, typename U>
inline std::complex<T> operator*(const std::complex<T>& lhs, const U& rhs)
{
    return lhs * T(rhs);
}

template <typename T, typename U>
inline complex<T> operator*(const U& lhs, const complex<T>& rhs)
{
    return T(lhs) * rhs;
}

void parallelMandelbrot() {

    using namespace literals;

    unsigned char* iteration_counts = new unsigned char[3500*2500];

    vector<int> range1;
    for (int i = 0; i < 3500; i++)
        range1.push_back(i);

    vector<int> range2;
    for (int i = 0; i < 2500; i++)
        range2.push_back(i);

    for (auto j : range1) {
        for(auto k : range2) {
            auto c = (-2.5 + k*3.5/3500.0) + (-1.25i + j*2.5i/2500.0);
            iteration_counts[3500*j + k] = boundedorbit([&c](auto z) { return z*z + c; }, 0.0i, 2, 200, &normalized_iterations<double>);
        }
    }

}

