#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s) {}
    Time& operator++() { ++seconds; return *this; }
    Time operator++(int) { Time old=*this; ++seconds; return old; }
    bool operator==(const Time& t) const { return seconds==t.seconds; }
    bool operator<(const Time& t) const { return seconds<t.seconds; }
    int value() const { return seconds; }
};
class Playlist {
    std::vector<std::string> tracks;
public:
    Playlist(std::initializer_list<std::string> x):tracks(x){}
    std::string& operator[](int i) { if(i<0||i>=static_cast<int>(tracks.size())) throw std::out_of_range("track index out of range"); return tracks[i]; }
    const std::string& operator[](int i) const { if(i<0||i>=static_cast<int>(tracks.size())) throw std::out_of_range("track index out of range"); return tracks[i]; }
    int size() const { return static_cast<int>(tracks.size()); }
};
int main() {
    Time t(5); Time a=t++; Time b=++t;
    std::cout << "a=" << a.value() << ", b=" << b.value() << ", t=" << t.value() << '\n';
    Playlist p{"Track One","Track Two"};
    std::cout << p[0] << " | " << p[1] << '\n';
    try { std::cout << p[2]; } catch(const std::out_of_range& e) { std::cout << "Checked: " << e.what() << '\n'; }
}