#include <iostream>
#include <string>
#include <cmath>
#include <vector>

//publc keys
std::string nString = "00 84 F9 42 8F 7C 0C 85 F0 87 17 92 8D 86 D0 6D 04 9E D8 F5 19 9C 59 1B 2E 99 C8 68 D2 D4 BF 91 23 28 6F 50 17 50 46 8F 13 03 B8 1F A6 82 87 A5 6D CB 06 30 4A A5 A8 42 28 16 6B AB BB 56 A3 70 5D";
std::string eString = "01 00 01";

//private keys
std::string pString = "00 E5 2E D7 63 6E FE E7 87 3B AD AB B2 B7 94 7C 95 7C 8A 19 14 F1 C5 6D C0 9A 53 D1 63 19 34 53 D9";
std::string qString = "00 94 88 79 ED 4A B6 5A 05 53 AE 8A 55 38 BF 8C AA 36 E1 74 A5 57 43 69 28 D4 50 EC EA 0E A4 A2 25";
std::string dString = "35 D4 BE A8 5D 9C A8 40 66 40 19 B9 27 A1 8A F0 BA E9 B3 D7 A9 5E BD 4D 51 3E 3B 89 56 4D 33 10 C2 AD 83 FB 9B 0A B9 AA BB C2 55 C2 37 07 A3 AB 59 2C E5 B0 B1 7E 6C 29 12 3C CA F3 B7 07 8B 21";

//message
std::string messageString = "DEADBABE";

std::vector<char>stringToVector(std::string stringToConvert){
    std::vector<char>hexVector;
    hexVector.reserve(((stringToConvert.size()+1))/3 ); // impies that its written on the format "XX XX XX"
    for(char& c : stringToConvert) {
        if (c != ' '){
            if ('0'<= c && c <= '9'){
                c -= '0'; // so c stores the value instead of the symbol
            }
            else if ('A' <= c && c <= 'F'){
                c -= 'A'; // so c stores the value instead of the symbol
                c += 10;    
            }
            hexVector.push_back(c);//pushing value into vector
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
    //creating public keyVectors
    std::vector<char>n_vector = stringToVector(nString);
    std::vector<char>e_vector = stringToVector(eString);
    
    //creating private keyVectors
    std::vector<char>p_vector = stringToVector(pString);
    std::vector<char>q_vector = stringToVector(qString);
    std::vector<char>d_vector = stringToVector(dString);

    //messageVector
    std::vector<char>message_vector = stringToVector(messageString);

    std

    
    for(char c:n_vector){
        unsigned short int number = static_cast<unsigned short int>(c);
        std::cout << std::hex << number;
    }
    std::cout<<'\n'<<'\n';

    for(char c:e_vector){
        unsigned short int number = static_cast<unsigned short int>(c);
        std::cout << std::hex << number;
    }
    std::cout<<'\n'<<'\n';

    for(char c:p_vector){
        unsigned short int number = static_cast<unsigned short int>(c);
        std::cout << std::hex << number;
    }

    return 0;
}