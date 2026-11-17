#include <iostream>
#include <vector>
#include <string>
class Event {
    std::string name;
    int rows, seats;
    char** map;
public:
    Event(std::string n, int r, int s) : name(std::move(n)), rows(r), seats(s), map(nullptr) {
        if (rows < 0 || seats < 0) throw std::invalid_argument("negative dimensions");
        if (rows) {
            map = new char*[rows];
            int made=0;
            try { for (; made<rows; ++made) map[made]=new char[seats ? seats : 1]; }
            catch (...) { while(made) delete[] map[--made]; delete[] map; throw; }
            for(int i=0;i<rows;++i) for(int j=0;j<seats;++j) map[i][j]='O';
        }
        std::cout << "Created " << name << " (" << rows << "x" << seats << ")\n";
    }
    bool book(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||map[r][s]=='X') return false; map[r][s]='X'; return true; }
    bool cancel(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||map[r][s]=='O') return false; map[r][s]='O'; return true; }
    ~Event() { for(int i=0;i<rows && map;++i) delete[] map[i]; delete[] map; std::cout << "Closed " << name << '\n'; }
};
int main() {
    Event morning("Morning",2,3);
    std::cout << "Book seat: " << std::boolalpha << morning.book(0,1) << '\n';
    { Event afternoon("Afternoon",1,2); afternoon.book(0,0); }
    Event* evening = new Event("Evening",1,4);
    evening->book(0,3); delete evening;
    Event empty("Empty",0,0);
}