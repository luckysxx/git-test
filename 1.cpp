#include <bits/stdc++.h>
using namespace std;
class Fractor {
private:
    int fz;
    int fm; 
public:
    Fractor(int a, int b) : fz(a), fm(b) {
        if (fm < 0) { 
            fz = -fz;
            fm = -fm;
        }
        if (fz == 0) { 
            fm = 1;
        }
    }
    Fractor operator+(const Fractor &f) const {
        int m = fm * f.fm; 
        int z = fz * f.fm + f.fz * fm; 
        return Fractor(z, m);
    }
    operator double() const {
        return static_cast<double>(fz) / fm;
    }
    friend ostream &operator<<(ostream &out, const Fractor &f) {
        out << f.fz << "/" << f.fm;
        return out;
    }
};
int main() {
    int fz1, fm1, fz2, fm2;
    cin >> fz1 >> fm1 >> fz2 >> fm2;
    Fractor f1(fz1, fm1);
    Fractor f2(fz2, fm2);
    Fractor f3 = f1 + f2; 
    cout << f3 << "\n"; 
    cout << double(f3) << "\n";
    return 0;
}