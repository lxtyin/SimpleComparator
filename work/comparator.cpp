#include <iostream>
#include <fstream>
using namespace std;

string s1 = "", s2 = "";

int main(){
	string sc;

    ifstream fin;

    fin.open("out1.txt");
    while(getline(fin, sc)) s1 = s1 + sc + '\n';
    fin.seekg(0, ios_base::beg);
    fin.close();
    fin.open("out2.txt");
    while(getline(fin, sc)) s2 = s2 + sc + '\n';
    fin.seekg(0, ios_base::beg);
    fin.close();

    if(s1 == s2) cout << "[Accepted]\n";
    else{
        cout << "[Wrong Answer]\n";
        fin.open("data.txt");
        string si = "";
         while(getline(fin, sc)) si = si + sc + '\n';
        cout << "Input:\n" << si << "\n\n";
        cout << "Program1 Output:\n" << s1 << "\n\n";
        cout << "Program2 Output:\n" << s2 << "\n\n";
    }
    cout << "-------------------------------------\n";
}
