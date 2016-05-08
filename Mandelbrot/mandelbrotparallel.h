#ifndef MANDELBROTPARALLEL
#define MANDELBROTPARALLEL

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
                 IterationMap itmap = [](int n, complex<T> z, int bailout) {return n;});

template<typename T>
float normalized_iterations(int n, complex<T> zn, int bailout);

template <typename T, typename U>
inline std::complex<T> operator*(const std::complex<T>& lhs, const U& rhs);

template <typename T, typename U>
inline complex<T> operator*(const U& lhs, const complex<T>& rhs);

void parallelMandelbrot();



#endif // MANDELBROTPARALLEL

