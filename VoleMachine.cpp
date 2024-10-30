#include <bits/stdc++.h>
using namespace std;

class Machine
{
private:
    CPU prossecor;
    Memory memory;

public:
    void loadProgramFile();
    void outputState();
};

class Memory
{
private:
    vector<string> bytes;

public:
    Memory(){
        for (int i = 0; i < 256; i++)
        {
            bytes.push_back("00");
        }
    };
    void set_momery(string s, int n){
        bytes[n] = s;
    };
    string get_momery(int n){
        return bytes[n];
    };
};

class Register
{
private:
    vector<string> regis;
public:
    Register(){
        for (int i = 0; i < 16; i++)
        {
            regis.push_back("00");
        }
    };
    void set_register(string s, int n){
        regis[n] = s;
    };
    string get_register(int n){
        return regis[n];
    }
};

class CPU
{
private:
    int programCounter;
    string instructionRegister;
    Register regist;
    ALU alu;
    CU cu;

public:
    void fetch(Memory& memo) {
        instructionRegister = memo.get_momery(programCounter)+memo.get_momery(programCounter+1);
        programCounter+=2;
    };
    vector<string> decode(){
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
    void execute(Register &, Memory &, vector<string>);
};

class CU
{
public:
    void load(int regAd, int memAd, Register &, Memory &);
    void load(int regAd, int val, Register &);
    void store(int regAd, int memAd, Register &, Memory &);
    void move(int regAd1, int regAd2, Register &);
    void jump(int regAd, Register, int &pc);
    void halt(){
        return ;
    };
};

class ALU
{
public:
    string hexToDes(string);
    string desToHex(string);
    bool isEqual(int adrs, Register);
    bool isValid(string);
    void add(int adrs1, int adrs2, int adrs3, Register &);
};

int main()
{
    CPU cpu;
    ifstream file("word.txt");
    vector<string> save;
    while (!file.eof())
    {
        string s1, save1, save2;
        file >> s1;
        //cpu.fetch();

    }
}
