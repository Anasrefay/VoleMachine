#include <bits/stdc++.h>
#include "headerfile.hpp"
using namespace std; 

bool ALU::isEqual(int adrs, Register& regist)
{
  if(regist.get_register(adrs) == regist.get_register(0))
    return true;
  else 
    return false; 
}

void ALU::add(int adrs1, int adrs2, int adrs3, Register& regist)
{
//   regist.set_register(to_string(adrs2+adrs3),adrs1);
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