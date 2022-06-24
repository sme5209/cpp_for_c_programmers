#include <iostream>

class point {
    private:
        double x;
        double y;

    public:
        point() {
            this->x = 0;
            this->y = 0;
        }

        point(const double &x, const double &y) {
            this->x = x;
            this->y = y;
        }

        double getx() {
            return x;
        }

        void setx(double v) {
            x = v;
        }

        friend point operator+ (point &p1, point &p2) {
            point sum = {p1.x + p2.x, p1.y + p2.y};
            return sum;
        }

        friend std::ostream &operator<< (std::ostream &out, const point &p) {
            out << "(" << p.x << ", " << p.y << ")";
            return out;
        }
};

int main() {
    point p1 = {5, 5};
    point p2 = {10, 0};
    point p3 = p1 + p2;

    std::cout << "Value of point p3 = " << p3 << std::endl;

    return 0;
}