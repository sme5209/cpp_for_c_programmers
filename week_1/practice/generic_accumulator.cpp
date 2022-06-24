#include <iostream>
#include <vector>

const int N = 40;

// This function sums all values of an input vector and returns the result
// Note the use of pass-by-reference instead of pointer
template<class summable> inline void sum(const std::vector<summable> &d, summable &p=0) {
    // below is a condensed C++ format for iterating over a vector
    for (const int &val : d) {
        p += val;
    }
    /// NOTE: type must be able to use += operator
}

int main() {
    int accum = 0;
    std::vector<int> data(N);

    for (int i = 0; i < data.size(); i++) {
        // using ".at" indexes into a vector and throws an exception 
        //  if out of bounds
        data.at(i) = i;
    }

    sum(data, accum);

    std::cout << "sum is " << accum << std::endl;
}