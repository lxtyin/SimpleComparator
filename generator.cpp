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

    int n = rd(3, 5), m = rd(3, 5);
    cout << n << ' ' << m << '\n';
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << rd(0, 1);
        }
        cout << '\n';
    }

    //--------
}
