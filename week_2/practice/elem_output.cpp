#include <iostream>
#include <vector>
#include <complex>

const int N = 40;

// Iterates over input array and prints all values
/// NOTE: meta variable is named "printable" for readability
template<class printable> inline void output(std::vector<printable> d) {
    for (const printable &val : d) {
        std::cout << val << std::endl;
    }
}

int main() {
    std::vector<std::complex<double>> data(N);

    for (int i = 0; i < data.size(); ++i) {
        data.at(i) = {static_cast<double>(i), static_cast<double>(i)};
    }

    std::cout << "Array contents:" << std::endl;
    output(data);
}