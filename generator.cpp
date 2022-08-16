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

    cout << 100 << ' ' << 5 << '\n';
    for(int i=1;i<=5;i++){
        cout << rd(1, 100) << ' ' << rd(1, 100) << '\n';
    }

    //--------
}
