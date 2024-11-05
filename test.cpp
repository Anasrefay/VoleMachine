#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// float hexTofloat(const string &hex)
// {
//     string hexUpper = hex;
//     transform(hexUpper.begin(), hexUpper.end(), hexUpper.begin(), ::toupper);

//     int decimalValue;
//     stringstream ss;
//     ss << hex << hexUpper;
//     ss >> decimalValue;

//     bitset<8> binary(decimalValue);

//     string binarynum = binary.to_string();

//     string binarynumExp = binarynum.substr(1, 3);
//     int decimalExp = stoi(binarynumExp, nullptr, 2);
//     decimalExp -= 4;
//     string mantisa = binarynum.substr(4);
//     int intmantisa = stoi(mantisa, nullptr, 2);
//     int sign = (binarynum[0] == '1') ? -1 : 1;
//     return intmantisa * pow(2, -4) * pow(2, decimalExp) * sign;
// }

// string floatToHex(float num, int precision = 4)
// {
//     bool isNegative = num < 0;
//     if (isNegative)
//     {
//         num = -num;
//     }

//     int integerPart = int(num);
//     float fractionalPart = num - integerPart;

//     string binaryInteger = "";
//     if (integerPart == 0)
//     {
//         binaryInteger = "0";
//     }
//     else
//     {
//         while (integerPart > 0)
//         {
//             binaryInteger = (integerPart % 2 == 0 ? "0" : "1") + binaryInteger;
//             integerPart /= 2;
//         }
//     }

//     string binaryFractional = ".";
//     while (precision-- > 0 && fractionalPart != 0.0f)
//     {
//         fractionalPart *= 2;
//         if (fractionalPart >= 1.0f)
//         {
//             binaryFractional += "1";
//             fractionalPart -= 1.0f;
//         }
//         else
//         {
//             binaryFractional += "0";
//         }
//     }

//     string binaryRepresentation = binaryInteger + binaryFractional;
//     while (binaryRepresentation.length() <= 4)
//         binaryRepresentation += "0";
//     int exp = binaryRepresentation.find('.');
//     string mantisa = "";
//     for (int i = 0; i < binaryRepresentation.length(); i++)
//     {
//         if (binaryRepresentation[i] == '.')
//             continue;
//         mantisa += binaryRepresentation[i];
//     }
//     exp += 4;
//     string expbinary = "";
//     if (exp == 0)
//     {
//         expbinary = "0";
//     }
//     else
//     {
//         while (exp > 0)
//         {
//             expbinary = (exp % 2 == 0 ? "0" : "1") + expbinary;
//             exp /= 2;
//         }
//     }
//     string ieee = ((isNegative) ? "1" : "0") + expbinary + mantisa;
//     bitset<8> bits(ieee);
//     unsigned int decimalValue = bits.to_ulong();

//     stringstream ss;
//     ss << hex << uppercase << decimalValue;

//     return ss.str();
// }

vector<string> GetFileInstructions(fstream& file){

    vector<string>instruct;
    fstream file("word.txt");
    while (!file.eof())
    {
        string x;
        file >> x;
        instruct.push_back(x);
    }
    for (int i = 0; i < instruct.size(); i++)
    {
        cout<<instruct[i]<<'\n';
    }
    return instruct;
}

int main()
{
    fstream file("C:\\Users\\original\\Desktop\\ay_7aga.txt"); 
    GetFileInstructions(file);
}
