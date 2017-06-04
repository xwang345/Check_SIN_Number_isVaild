//
// Created by Xiaochen Wang on 2017-06-03.
//

#include <iostream>
using namespace std;

int main() {
    int m_sin = 629464811;
    bool sinTF;
    int tempSin = m_sin;
    int alternateNum[4];
    int sumDigits1[4];
    int sumDigits2 [4];
    int lessTenTotal = 0;
    int greaterThenTotal = 0;
    int otherTotal =0;
    int Total =0;

    if (m_sin >= 999999999 && m_sin <= 1000000000) {
        sinTF = false;
    } else {

        int sinArray[9];
        for (int i = 0; i <= 9; i++) {
            sinArray[i] = tempSin % 10;
            tempSin /= 10;
        }


        alternateNum[0] = sinArray[7] * 2; // Convert single array into  one new array.
        alternateNum[1] = sinArray[5] * 2;
        alternateNum[2] = sinArray[3] * 2;
        alternateNum[3] = sinArray[1] * 2;
        alternateNum[4] = '\0';

        //cout << alternateNum [0] << ", " << alternateNum[1] << ", " << alternateNum[2] << ", " << alternateNum[3] << endl;

        for (int j = 0; j < 4; j++) {
            if (alternateNum[j] > 10) {
                sumDigits1[j] = alternateNum[j] % 10 +1; //calculate less the 10 even number.
                greaterThenTotal += sumDigits1[j];
            }else if (alternateNum[j] == 10){
                sumDigits2[j] = 1;
                lessTenTotal += sumDigits2[j];
            }else if (alternateNum[j] < 10){
                sumDigits2[j] = alternateNum[j];
                lessTenTotal += sumDigits2[j];
            }else{
                sumDigits2[j] = '\0';
            }
        }


        otherTotal = sinArray[8] + sinArray[6] + sinArray[4] + sinArray[2];
//        cout << otherTotal << endl;
//        cout <<"less: "<< lessTenTotal << endl;
//        cout << greaterThenTotal <<endl;
        Total = (greaterThenTotal + lessTenTotal)  + otherTotal;

//        cout << Total << endl;
        int checkNum = (Total / 10 + 1) * 10 - Total;
//        cout << checkNum << endl;
//        cout << sinArray[0] << endl;
        if(checkNum == sinArray[0]){
            sinTF = true;
            cout << sinTF << endl;
        }else{
            sinTF = false;
            cout << sinTF << endl;
        }
    }
    return sinTF;
}