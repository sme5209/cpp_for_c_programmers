#include <iostream>
#include <vector>
#include <complex>

const int N = 40;

// meta variable is named "summable" for readability
template<class summable> inline summable sum(const std::vector<summable> d, summable p=0) {
    // for a complex type, this assignment sets both real
    //  and complex values to 0
    for (const summable &val : d) {
        p += val;
        /// NOTE: += must work for summable
    }
    return p;
}

int main() {
    std::vector<std::complex<double>> data(N);

    for (int i = 0; i < data.size(); ++i) {
        data.at(i) = {static_cast<double>(i), static_cast<double>(i)};
    }

    std::complex<double> init_value(100, 100);

    std::complex<double> accum = sum(data, init_value);

    std::cout << "sum is " << accum << std::endl;
}