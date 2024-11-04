#include <bits/stdc++.h>
#include "headerfile.hpp"
using namespace std;



Memory::Memory() {
    for (int i = 0; i < 256; i++)
    {
        bytes.push_back("00");
    }
}
string Memory::get_momery(int n) {
    return bytes[n];
}

void Memory::set_momery(string s, int n) {
    bytes[n] = s;
}

void Machine::loadProgramFile(vector<string> instructions , int pc , Memory& memory) {
    for(int i = pc; i < pc+instructions.size(); i+=2) {
        string first = instructions[i].substr(0, 2);
        string second = instructions[i].substr(2,2);
        memory.set_momery(first , i);
        memory.set_momery(second , i+1);
    }
}
void Machine::outputMemory(Memory& memory) {
   for(int i = 0; i < 256; i++) {
       if(i%16 == 0 ) {
           cout << endl;
       }
       cout << memory.get_momery(i) << ' ';
   }
    cout << endl;
}
void Machine::outputRegisters(Register &reg) {
    for(int i =0 ; i< 16; i++) {
        cout << reg.get_register(i)<< endl;
    }
    cout << endl;
}
void CU::load(int regAd, int memAd, Register & reg, Memory &mem) {
    string memContent = mem.get_momery(memAd);
    reg.set_register(memContent , regAd);
}


void CU::load(int regAd, string val, Register &reg) {
    reg.set_register(val, regAd);
}


void CU::store(int regAd, int memAd, Register& reg, Memory& mem) {
    string regContent = reg.get_register(regAd);
    mem.set_momery(regContent , regAd);
}


void CU::move(int regAd1, int regAd2, Register & reg) {
    string copyFromAddress2 = reg.get_register(regAd1);
    reg.set_register(copyFromAddress2, regAd2);
    reg.set_register("00", regAd1);
}


void CU::jump(int regAd, Register& reg, int &pc , int& memAd) {
    string regZero = reg.get_register(0);
    string regWanted = reg.get_register(regAd);
    if (regZero == regWanted) {
        pc = memAd;
    }
}


void CU::halt() {
    return;
}

bool ALU::isEqual(int adrs, Register& regist)
{
    if(regist.get_register(adrs) == regist.get_register(0))
        return true;
    else
        return false;
}

void ALU::add(int adrs1, int adrs2, int adrs3, Register& regist, bool isfloat)
{
  if (!isfloat)
    regist.set_register(to_string(adrs2+adrs3),adrs1);
  else 
  {
    string num1 = regist.get_register(adrs2); 
    string num2 = regist.get_register(adrs3);
    float num3 = hexTofloat(num1) + hexTofloat(num2); 
    regist.set_register(to_string(num3),adrs1); 
  }
}

bool ALU::isValid(string s)
{
    if (!((s[0] >= 1 && s[0] <= 6) || (s[0] >= 'B' && s[0] <= 'C')))
        return false;

    for (int i = 1; i < 4; i++)
        if (!((s[i] >= '0' && s[i] <= '9') || s[i] >= 'A' && s[i] <= 'F'))
        {
            return false;
        }
    return true;
}

string ALU::hexToDes(string s)
{
    int ans = stoi(s, nullptr, 16);
    return to_string(ans);
}

string ALU::desToHex(string s)
{
    stringstream ss;
    ss << hex << s;
    string ans = ss.str();
    return ans;
}
int CPU::get_pc()
{
    return programCounter;
}
void CPU::fetch(Memory &memo) {
    instructionRegister = memo.get_momery(programCounter)+memo.get_momery(programCounter+1);
    programCounter+=2;
}
vector<string> CPU::decode() {
    string save = to_string(instructionRegister[0]);
    vector<string>instructions;
    if(save == "1" || save == "2" || save == "B" || save == "3"){
        instructions.push_back(save);
        instructions.push_back(to_string(instructionRegister[1]));
        instructions.push_back(instructionRegister.substr(2,2));
    }
    else if(save == "4" || save == "5" || save == "6"){
        instructions.push_back(save);
        instructions.push_back(to_string(instructionRegister[1]));
        instructions.push_back(to_string(instructionRegister[2]));
        instructions.push_back(to_string(instructionRegister[3]));
    }
    else if(save == "C"){

    }
    return instructions;
}

Register:: Register() {
    for (int i = 0; i < 16; i++)
    {
        regis.push_back("00");
    }
}
void Register :: set_register(string s, int n) {
    regis[n] = s;
}
string Register :: get_register(int n ) {
    return regis[n];
}
void CPU::execute(Register& regist, Memory& memory, vector<string> instruction)
{
    if (instruction[0] == "1")
    {
        cu.load(stoi(alu.hexToDes(instruction[1])),stoi(alu.hexToDes(instruction[2])), regist, memory);
    }
    else if (instruction[0] == "2")
    {
        cu.load(stoi(alu.hexToDes(instruction[1])),instruction[2], regist);
    }
    else if (instruction[0] == "3" && instruction[2] != "00")
    {
        cu.store(stoi(alu.hexToDes(instruction[1])),stoi(alu.hexToDes(instruction[2])), regist, memory);
    }
    else if (instruction[0] == "3" && instruction[2] == "00")
    {
        cout << regist.get_register(stoi(alu.hexToDes(instruction[1])));
    }
    else if (instruction[0] == "4")
    {
        cu.move(stoi(alu.hexToDes(instruction[2])), stoi(alu.hexToDes(instruction[3])), regist);
    }
    else if (instruction[0] == "5")
    {
        alu.add(stoi(alu.hexToDes(instruction[1])), stoi(alu.hexToDes(instruction[2])), stoi(alu.hexToDes(instruction[3])), regist);
    }
    else if (instruction[0] == "6")
    {
        alu.add(stoi(alu.hexToDes(instruction[1])), stoi(alu.hexToDes(instruction[2])), stoi(alu.hexToDes(instruction[3])), regist);
    }
    else if (instruction[0] == "B")
    {
        if (alu.isEqual(stoi(alu.hexToDes(instruction[1])), regist))
            programCounter = stoi(alu.hexToDes(instruction[2]));
    }
    else if (instruction[0] == "C")
        cu.halt();
}

float hexTofloat(const string &hex)
{
    string hexUpper = hex;
    transform(hexUpper.begin(), hexUpper.end(), hexUpper.begin(), ::toupper);

    int decimalValue;
    stringstream ss;
    ss << hex << hexUpper;
    ss >> decimalValue;

    bitset<8> binary(decimalValue);

    string binarynum = binary.to_string();

    string binarynumExp = binarynum.substr(1, 3);
    int decimalExp = stoi(binarynumExp, nullptr, 2);
    decimalExp -= 4;
    string mantisa = binarynum.substr(4);
    int intmantisa = stoi(mantisa, nullptr, 2);
    int sign = (binarynum[0] == '1') ? -1 : 1;
    return intmantisa * pow(2, -4) * pow(2, decimalExp) * sign;
}

string floatToHex(float num, int precision = 4)
{
    bool isNegative = num < 0;
    if (isNegative)
    {
        num = -num;
    }

    int integerPart = int(num);
    float fractionalPart = num - integerPart;

    string binaryInteger = "";
    if (integerPart == 0)
    {
        binaryInteger = "0";
    }
    else
    {
        while (integerPart > 0)
        {
            binaryInteger = (integerPart % 2 == 0 ? "0" : "1") + binaryInteger;
            integerPart /= 2;
        }
    }

    string binaryFractional = ".";
    while (precision-- > 0 && fractionalPart != 0.0f)
    {
        fractionalPart *= 2;
        if (fractionalPart >= 1.0f)
        {
            binaryFractional += "1";
            fractionalPart -= 1.0f;
        }
        else
        {
            binaryFractional += "0";
        }
    }

    string binaryRepresentation = binaryInteger + binaryFractional;
    while (binaryRepresentation.length() <= 4)
        binaryRepresentation += "0";
    int exp = binaryRepresentation.find('.');
    string mantisa = "";
    for (int i = 0; i < binaryRepresentation.length(); i++)
    {
        if (binaryRepresentation[i] == '.')
            continue;
        mantisa += binaryRepresentation[i];
    }
    exp += 4;
    string expbinary = "";
    if (exp == 0)
    {
        expbinary = "0";
    }
    else
    {
        while (exp > 0)
        {
            expbinary = (exp % 2 == 0 ? "0" : "1") + expbinary;
            exp /= 2;
        }
    }
    string ieee = ((isNegative) ? "1" : "0") + expbinary + mantisa;
    bitset<8> bits(ieee);
    unsigned int decimalValue = bits.to_ulong();

    stringstream ss;
    ss << hex << uppercase << decimalValue;

    return ss.str();
}
