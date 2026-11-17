#include <cstring>
#include <iostream>
class Text {
    char* data;
public:
    Text(const char* s="") { data=new char[std::strlen(s)+1]; std::strcpy(data,s); }
    Text(const Text& o) { data=new char[std::strlen(o.data)+1]; std::strcpy(data,o.data); }
    Text& operator=(const Text& o) {
        if(this!=&o) { char* fresh=new char[std::strlen(o.data)+1]; std::strcpy(fresh,o.data); delete[] data; data=fresh; }
        return *this;
    }
    ~Text() { delete[] data; }
    Text operator+(const Text& o) const {
        std::size_t n=std::strlen(data)+std::strlen(o.data);
        char* temp=new char[n+1]; std::strcpy(temp,data); std::strcat(temp,o.data);
        Text result(temp); delete[] temp; return result;
    }
    bool operator==(const Text& o) const { return std::strcmp(data,o.data)==0; }
    bool operator!=(const Text& o) const { return !(*this==o); }
    friend std::ostream& operator<<(std::ostream& out,const Text& t) { return out << t.data; }
};
int main() {
    Text a("Hello "), b("World"), c("!");
    Text message=a+b+c;
    std::cout << message << '\n';
    Text empty; std::cout << "Empty=[" << empty << "]\n";
    message=message;
    std::cout << std::boolalpha << (message!=a) << '\n';
}