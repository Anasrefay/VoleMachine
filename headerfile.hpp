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
  Memory(); 
  void set_momery(vector<string> s, int n);
  string get_momery();
};

class Register
{
private: 
  vector<string> regis;
public: 
  Register();
  void set_momery(vector<string> s, int n);
  string get_momery();
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
  void fetch(Memory);
  vector <string> decode(); 
  void execute(Register&, Memory&, vector<string>); 
};

class CU 
{
public: 
  void load(int regAd, int memAd, Register&, Memory&);
  void load(int regAd, int val, Register&);
  void store(int regAd, int memAd, Register&, Memory&);
  void move(int regAd1, int regAd2, Register&);
  void jump(int regAd, Register, int& pc);
  void halt();
};

class ALU 
{
public: 
  string hexToDes(string);
  string desToHex(string);
  bool isEqual(int adrs, Register);
  bool isValid(string); 
  void add(int adrs1, int adrs2, int adrs3, Register&);
};