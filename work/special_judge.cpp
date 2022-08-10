#include "judge.h"

// sample spj for accuracy within 1e-6
// input data can be read by inp(ifstream)
// program1 output can be read by ans1(ifstream), so as ans2.
int main() {
    double as1, as2;
    ans1 >> as1;
    ans2 >> as2;

    if(abs(as1 - as2) / as2 < 1e-6) AC();
    else {
        WA();
        display();
        color(YELLOW);
        printf("The accuracy is %.10f\n", abs(as1 - as2) / as2);
        color(WHITE);
    }

    inp.close();
    ans1.close();
    ans2.close();
    return 0;
}
