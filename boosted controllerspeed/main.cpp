#include <iostream>

using namespace std;
int fromcode2human(int hexnum) {
    hexnum = hexnum >> 16;
    hexnum = hexnum + (-128 - 384);
    return hexnum;
}

int wanagetspeed(int sp) {
    if (sp<-384||sp>384)
    {
        return 0x80<<16;
    }

    sp += (128 + 384);
    sp=sp << 16;
    return sp;
}

int powerButton_on(int num) {
    int seged = 0x1;
    seged = seged << 8;
    num = num | seged;
    return num;
}

int throttleButton_on(int num) {
    int seged = 0x1;
    seged = seged << 9;
    num = num | seged;
    return num;
}

int powerButton_off(int num) {

    int seged = 0x000001;
    seged = seged << 8;
    seged = ~seged;
    num = num & seged;
    return num;
}
int throttleButton_off(int num) {

    int seged = 0x000001;
    seged = seged << 9;
    seged = ~seged;
    num = num & seged;
    return num;
}


int main() {

    cout << fromcode2human(0x3800300)<<"\n";
    cout << hex<<wanagetspeed(384) << "\n";
    cout << hex << powerButton_on(wanagetspeed(384)) << "\n";
    cout << hex << throttleButton_on( powerButton_on(wanagetspeed(384))) << "\n";
    cout <<hex<< powerButton_off(powerButton_on(wanagetspeed(384))) << "\n";
    cout <<hex<< throttleButton_off(throttleButton_on(powerButton_on(wanagetspeed(384))));


    return 0;
}