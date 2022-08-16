#include "judge.h"

// sample spj for accuracy within 1e-6
// input data can be read by inp(ifstream)
// program1 output can be read by ans1(ifstream), so as ans2.
int main() {
    int n;
    inp >> n;
    vector<bool> vis(n+1, false);

    bool fg = false;
    for(int i=1;i<=n;i++){
        int x; ans1 >> x;
        if(vis[x] || x > n){
            fg = true;
        }else{
            vis[x] = true;
        }
    }
    if(fg){
        WA();
        display();
        hint("what it is?");
    }else AC();

    inp.close();
    ans1.close();
    ans2.close();
    return 0;
}
