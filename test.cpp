#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, age;

    getline(cin, name);
    getline(cin, age);
    cout << name << "\t" << age;
}