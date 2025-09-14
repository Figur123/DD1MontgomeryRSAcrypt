#include <iostream>
#include <string>
#include <cmath>
#include <vector>


//comppuute n
std::string nString = "00 ED A4 09 63 53 D8 48 87 6D AC F4 CA D2 5E 80 D5 AF 26 0E 3B 16 F1 3D 69 82 D4 49 F7 0E 8C 15 9D";
//std::vector<unsigned short int> n{0x00, 0xED, 0xA4, 0x09, 0x63, 0x53, 0xD8, 0x48, 0x87, 0x6D, 0xAC, 0xF4, 0xCA, 0xD2, 0x5E, 0x80, 0xD5, 0xAF, 0x26, 0x0E, 0x3B, 0x16, 0xF1, 0x3D, 0x69, 0x82, 0xD4, 0x49, 0xF7, 0x0E, 0x8C, 0x15, 0x9D};


//publc keys
//unsigned long e = 0x01 00 01;

//private keys
//unsigned long int = 0x00 93 30 56 E0 3E BE 67 AD FA 30 76 2E 69 BE 3E EC E9 D4 4A F9 A1 C5 89 31 1F AF 6B B4 A0 21 95 C1; 
//unsigned long int p = 0x00 F6 E6 96 D9 B1 F2 B2 66 9E 36 A6 87 36 A0 8A 4F;
//unsigned long int q = 0x00 F6 66 15 4F F5 4B C4 B0 17 F9 4A 69 69 63 62 53;

//unsigned long publicKey = 10; //make some primenumber

std::vector<unsigned char>stringToVector(std::string stringToConvert){
    std::vector<unsigned char>hexVector;
    hexVector.reserve(((stringToConvert.size()+1))/3 ); // impies that its written on the format "XX XX XX"
for(char& c : stringToConvert) {
    if (c != ' '){
        if(0 <= c <= 9){
            hexVector.push_back(c);    
        }
        else if('A' <= c <= 'F'){
            c = c - 'A' + 10;
            hexVector.push_back(c);
        }
    }
}
    return hexVector;
}

unsigned long int encrypton(unsigned long int e, unsigned long int n, unsigned long int message){
    long int C = int(pow(message, e)) % n;
    return C;
}
unsigned long int decryption(unsigned long int d, unsigned long int n, unsigned long int encryptedMessage){
    unsigned long int message = int(pow(encryptedMessage, d)) % n;
    return message; 
}

int main(){
    std::vector<unsigned char>hexVector = stringToVector(nString);
    for(char c:hexVector){
        std::cout << c-10 << ' ';
    }

    return 0;
}
