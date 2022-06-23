#include <iostream>
#include <vector>
#include <complex>

const int N = 40;

// Iterates over input array and subtracts all values
/// NOTE: meta variable is named "subtractable" for readability
template<class subtractable> inline subtractable diff(std::vector<subtractable> d, subtractable p=0) {
    // for a complex type, this assignment sets both real
    //  and complex values to 0
    for (const subtractable &val : d) {
        p -= val;
        /// NOTE: += must work for subtractable
    }
    return p;
}

int main() {
    std::vector<std::complex<double>> data(N);

    for (int i = 0; i < data.size(); ++i) {
        data.at(i) = {static_cast<double>(i), static_cast<double>(i)};
    }

    std::complex<double> init_value(-100, 100);

    std::complex<double> sub = diff(data, init_value);

    std::cout << "Difference is " << sub << std::endl;
}