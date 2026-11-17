#include <iomanip>
#include <iostream>
class Money {
    long long paise;
public:
    Money(long long rupees=0, int p=0) : paise(rupees*100+p) {}
    Money operator+(const Money& other) const { Money result; result.paise=paise+other.paise; return result; }
    Money operator-(const Money& other) const { Money result; result.paise=paise-other.paise; return result; }
    Money& operator+=(const Money& other) { paise+=other.paise; return *this; }
    bool operator==(const Money& other) const { return paise==other.paise; }
    bool operator<(const Money& other) const { return paise<other.paise; }
    friend std::ostream& operator<<(std::ostream& out,const Money& m) {
        long long a=m.paise<0 ? -m.paise : m.paise;
        if(m.paise<0) out << "-";
        return out << "Rs " << a/100 << '.' << std::setw(2) << std::setfill('0') << a%100 << std::setfill(' ');
    }
};
int main() {
    Money a(120,75), b(79,25);
    Money c=a+b;
    std::cout << c << '\n' << std::boolalpha << (c==Money(200)) << '\n';
    std::cout << Money(0,75)+Money(0,50) << '\n';
    std::cout << Money(1,0)-Money(2,25) << '\n';
}