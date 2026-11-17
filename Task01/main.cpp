#include <iostream>
#include <string>
#include <stdexcept>
class Book {
    std::string title;
    int copies;
public:
    Book() : Book("Untitled", 0) {}
    explicit Book(const std::string& t) : Book(t, 1) {}
    Book(const std::string& t, int c) : title(t), copies(c) {
        if (c < 0) throw std::invalid_argument("copies cannot be negative");
    }
    void show() const { std::cout << "Title: " << title << ", copies: " << copies << '\n'; }
};
int main() {
    try {
        Book empty;
        Book donated("C++ Primer");
        Book full("Data Structures", 5);
        empty.show(); donated.show(); full.show();
        try { Book invalid("Invalid book", -2); }
        catch (const std::invalid_argument& e) { std::cout << "Rejected: " << e.what() << '\n'; }
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}