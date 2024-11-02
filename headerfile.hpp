#include <bits/stdc++.h>
using namespace std; 

class Machine
{
    /*
     * @ brief: The machine class manages all the program with their classes.
     */
public:
    void loadProgramFile(vector<string> instructions , int pc , Memory& memory);
    void outputMemory(Memory& memory);
    void outputRegisters(Register& reg);
};


class Memory 
{
private: 
  vector<string> bytes;
public: 
  Memory(); 
  void set_momery(string s, int n);
  string get_momery(int adrs);
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
  string hexToDes(string);
  string desToHex(string);
  bool isEqual(int adrs, Register&);
  bool isValid(string); 
  void add(int adrs1, int adrs2, int adrs3, Register&, bool isfloat);
};