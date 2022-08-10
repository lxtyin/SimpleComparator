#include "judge.h"

// default judge: check ans1 == ans2
int main(){
	string sc;

    string s1 = "", s2 = "";
    while(getline(ans1, sc)) {
        while(!sc.empty() && (sc.back() == ' ' || sc.back() == '\n')) sc.pop_back(); //ignore enter and space
        s1 = s1 + sc + '\n';
    }
    while(getline(ans2, sc)) {
        while(!sc.empty() && (sc.back() == ' ' || sc.back() == '\n')) sc.pop_back(); //ignore enter and space
        s2 = s2 + sc + '\n';
    }

    if(s1 == s2) AC();
    else {
        WA();
        display();
    }

    inp.close();
    ans1.close();
    ans2.close();
    return 0;
}
