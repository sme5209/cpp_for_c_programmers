#include <iostream>

class point {
    private:
        double x;
        double y;

    public:

        // constructors

        // default constructor
        point() {
            /// NOTE: this is valid syntax
            this->x = this->y = 0;
        }
        
        // copy constructor
        //  Passes x and y values by reference,
        //  copies both values for respective x and y
        //  data members of object
        /// NOTE: allows assignment of form "point p = {x, y}" 
        point(const double &x, const double &y) {
            this->x = x;
            this->y = y;
        }

        double getx() {
            return this->x;
        }

        void setx(double v) {
            this->x = v;
        }

        /// NOTE: when overloading an operator as a class method,
        //  the implicit first argument is a pointer to the class
        //  object (this)
        // It may be best to avoid this type of overloading
        //  implementation since it does not match the signature
        //  of every commonly overloaded operator

        /*
        point operator+=(point &p2) {
            const point sum = {this->x + p2.x, this->y + p2.y};
            return sum;
        }
        */

        // This is a better alternative:
        friend point operator+=(point &p1, point &p2) {
            const point sum = {p1.x + p2.x, p1.y + p2.y};
            return sum;
        }

        friend point operator+(point &p1, point &p2) {
            point sum = {p1.x + p2.x, p1.y + p2.y};
            return sum;
        }

        friend std::ostream &operator<<(std::ostream &out, const point &p) {
            out << "(" << p.x << ", " << p.y << ")";
            return out;
        }
};

int main() {
    point p1 = {5, 5};
    point p2 = {10, 0};
    p2 += p1;

    std::cout << "Sum of p1 and p2 = " << p1 + p2 << std::endl;

    return 0;
}