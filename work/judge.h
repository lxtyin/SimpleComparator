//some api for easy judge.

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

//read data from those streams.
ifstream inp("data.txt");
ifstream ans1("out1.txt");
ifstream ans2("out2.txt");

//read all chars
string readAll(ifstream& in) {
    in.clear();
    in.seekg(0, ios_base::beg);
    stringstream buf;
    buf << in.rdbuf();
    return string(buf.str());
}

#define WHITE 15
#define GREEN 10
#define RED 12
#define YELLOW 14 

//set text color
void color(int x) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

//The following api are encouraged for output.
void AC() {
    color(GREEN);
    cout << "Accepted\n";
    color(WHITE);
}
void WA() {
    color(RED);
    cout << "Wrong Answer\n";
    color(WHITE);
}
void hint(const string& str) {
    color(YELLOW);
    cout << str << '\n';
    color(WHITE);
}
void warn(const string& str) {
    color(RED);
    cout << str << '\n';
    color(WHITE);
}
//show data details;
void display() {
    color(WHITE);
    cout << "Input:\n" << readAll(inp) << "\n";
    cout << "Program1 Output:\n" << readAll(ans1) << "\n";
    cout << "Program2 Output:\n" << readAll(ans2) << "\n";
}

