#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string data = "This is a sample string.";
    // convert string to upper case
    std::for_each(data.begin(), data.end(), [](char & c) {
        c = ::toupper(c);
    });
}