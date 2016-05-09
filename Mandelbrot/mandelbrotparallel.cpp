/*#include <vector>
#include <limits>
#include <complex>
#include <chrono>
#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

template <typename T, typename U>
inline std::complex<T> operator*(const std::complex<T>& lhs, const U& rhs)
{
    return lhs * T(rhs);
}

template <typename T, typename U>
inline std::complex<T> operator*(const U& lhs, const std::complex<T>& rhs)
{
    return T(lhs) * rhs;
}

template<typename Iterate, typename IterationMap, typename T>
int boundedorbit(Iterate f, std::complex<T> seed, int bound, int bailout=100,
                 IterationMap itmap = [](int n, std::complex<T> z, int bailout) { return n; })
{
    auto z = f(seed);

    vector<int> bailoutRange;
    for (int i = 1; i <= bailout; i++)
        bailoutRange.push_back(i);

    for (auto k : bailoutRange) {
        if (abs(z) > bound)
            return itmap(k, z, bailout);
        z = f(z);
    }
    return std::numeric_limits<int>::min();
}

template<typename T>
float normalized_iterations(int n, std::complex<T> zn, int bailout)
{
    return n + (log(log(bailout))-log(log(abs(zn))))/log(2);
}

void parallelMandelbrot()
{
    // allow complex literal
    using namespace std::complex_literals;

    // allocate storage
    // TODO don't leak memory
    unsigned char* iteration_counts = new unsigned char[2000*1250];

    vector<int> range1;
    for (int i = 0; i < 2000; i++)
        range1.push_back(i);

    vector<int> range2;
    for (int i = 0; i < 1250; i++)
        range2.push_back(i);

    auto start = std::chrono::high_resolution_clock::now();

    for (auto j : range1 ) {
        cout << j << endl;
        for (auto k :range2 ) {
            auto c = (-2.5 + k*3.5/2000.0) + (-1.25i + j*2.5i/1250.0);
            iteration_counts[2000*j + k] = boundedorbit([&c](auto z) { return z*z + c; }, 0.0i, 2, 200, &normalized_iterations<double>);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "computation took " << elapsed_seconds.count() << "s" << std::endl;

    stbi_write_png("mandelbrot_serial.png", 2000, 1250, 1, iteration_counts, 2000);

} */
