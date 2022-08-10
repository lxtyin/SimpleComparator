#include <bits/stdc++.h>
using namespace std;

int rd(int x, int y){
    int r = 1ll*rand()*rand()%INT_MAX;
    return r%(y - x + 1) + x;
}

int main(int argc, char *argv[]){
    srand((int)time(0) * stoi(string(argv[1])));
    
    //-------
    //Write your construction output in this area
    //Do not modify the seed above.

    cout << rd(2, 10) << '\n';

    //--------
}
