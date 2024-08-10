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

void digitcutting(uint8_t* arrPtr,int number) {
    uint8_t byte1 = (number >> 24) & 0xFF; // Extract the highest 8 bits
    uint8_t byte2 = (number >> 16) & 0xFF; // Extract the next 8 bits
    uint8_t byte3 = (number >> 8) & 0xFF; // Extract the next 8 bits
    uint8_t byte4 = number & 0xFF; // Extract the lowest 8 bits
    arrPtr[0] = byte1;
    arrPtr[1] = byte2;
    arrPtr[2] = byte3;
    arrPtr[3] = byte4;
    
}

int main() {

    cout << fromcode2human(0x3800300)<<"\n";
    cout << hex<<wanagetspeed(384) << "\n";
    cout << hex << powerButton_on(wanagetspeed(384)) << "\n";
    cout << hex << throttleButton_on( powerButton_on(wanagetspeed(384))) << "\n";
    cout <<hex<< powerButton_off(powerButton_on(wanagetspeed(384))) << "\n";
    cout <<hex<< throttleButton_off(throttleButton_on(powerButton_on(wanagetspeed(384)))) << "\n";

    
    uint8_t arr[] = { 0x44,0x44,0x44,0x44 };
    digitcutting(arr, wanagetspeed(384));

    for (int  i = 0; i < 4; i++)
    {
        cout << "Byte "<<i<<": " << hex << static_cast<int>(arr[i]) << endl;
    }

    


    return 0;
}