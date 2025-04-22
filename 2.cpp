#include <iostream>
#include <stdexcept>
using namespace std;
class Vector {
private:
    int size;
    int* data;
public:
    Vector(int n = 0) : size(n), data(n > 0 ? new int[n] : nullptr) {}
    Vector(const Vector& other) : size(other.size), data(other.size > 0 ? new int[other.size] : nullptr) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    ~Vector() {
        delete[] data;
    }
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this; 
        delete[] data;
        size = other.size;
        data = other.size > 0 ? new int[other.size] : nullptr;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            cout << "Invalid vector size!" << endl;
            exit(1);
        }
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
    int operator*(const Vector& other) const {
        if (size != other.size) {
            cout << "Invalid vector size!" << endl;
            exit(1);
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }
    friend istream& operator>>(istream& in, Vector& v) {
        for (int i = 0; i < v.size; ++i) {
            in >> v.data[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Vector& v) {
        out << "{";
        for (int i = 0; i < v.size; ++i) {
            out << v.data[i];
            if (i < v.size - 1) {
                out << ",";
            }
        }
        out << "}";
        return out;
    }
};
int main() {
    int n;
    cin >> n;
    Vector v1(n);
    cin >> v1;
    cin >> n;
    Vector v2(n);
    cin >> v2;
    Vector v;
    v = v1 + v2;
    cout << v1 << "+" << v2 << "=" << v << endl;
    int mul;
    mul = v1 * v2;
    cout << v1 << "*" << v2 << "=" << mul << endl;
    return 0;
}