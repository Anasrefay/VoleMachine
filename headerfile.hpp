#ifndef HEADERFILE_HPP
#define HEADERFILE_HPP
#include <bits/stdc++.h>
using namespace std; 

class Memory 
{
private: 
  vector<string> bytes;
public: 
  Memory(); 
  void set_memory(string s, int n);
  string get_memory(int adrs);
};

class Register
{
private: 
  vector<string> regis;
public: 
  Register();
  void set_register(string s, int n);
  string get_register(int adrs);
};

class CU
{
/*
 * @brief : The class control unit controls the flow of the instructions.
 */
public:
    void load(int regAd, int memAd, Register& reg, Memory& mem);
    void load(int regAd, string val, Register&reg);
    void store(int regAd, int memAd, Register& reg, Memory& mem);
    void move(int regAd1, int regAd2, Register&reg);
    void jump(int regAd, Register&reg, int& pc , int&memAd);
    void halt();
};

class ALU 
{
public: 
  static int hexToDes(string);
  static string desToHex(string);
  static bool isEqual(int adrs, Register&);
  static bool isValid(string); 
  void add(int adrs1, int adrs2, int adrs3, Register&, bool isfloat = false);
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
  void fetch(Memory&);
  vector <string> decode(); 
  void execute(Register&, Memory&, vector<string>); 
  int get_pc(); 
  void set_pc(string x); 
  Register& returnRegister(); 
};

class Machine
{
    /*
     * @ brief: The machine class manages all the program with their classes.
     */
public:
    CPU processor; 
    Memory memory; 
    void loadProgramFile(vector<string> instructions , int pc , Memory& memory);
    void outputMemory(Memory& memory);
    void outputRegisters(Register& reg);
};

float hexTofloat(const string &hex);
string floatToHex(float num, int precision = 4);
void instLines(vector<string>& instructions);
vector<string> GetFileInstructions(fstream& file);

#endif