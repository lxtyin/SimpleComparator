#include <iostream>
#include <fstream>
using namespace std;

string s1 = "", s2 = "";

int main(){
    char c;

    ifstream fin;

    fin.open("out1.txt");
    while(fin >> c) s1 += c;
    fin.seekg(0, ios_base::beg);
    fin.close();
    fin.open("out2.txt");
    while(fin >> c) s2 += c;
    fin.seekg(0, ios_base::beg);
    fin.close();

    if(s1 == s2) cout << "[Accepted]\n";
    else{
        cout << "[Wrong Answer]\n";
        fin.open("data.txt");
        string si = "";
        while(fin >> c) si += c;
        cout << "Input:\n" << si << "\n\n";
        cout << "Program1 Output:\n" << s1 << "\n\n";
        cout << "Program2 Output:\n" << s2 << "\n\n";
    }
    cout << "-------------------------------------\n";
}
