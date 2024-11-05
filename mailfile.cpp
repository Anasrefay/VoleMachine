#include <bits/stdc++.h>
#include "headerfile.hpp"
using namespace std;
#define endl '\n'


int main()
{
    Machine machine;
    vector<string> instructions;
    cout << "welcome back ya user, nwrt w 4rft" << endl
         << "this is a vole machine similator" << endl
         << "you can input the instructions for the machine either as a file or as a normal input (from the Console)" << endl
         << "to end the similator you must enter the instruction C000 (halt)" << endl
         << "so, do you want to give the instructoins as a txt file or from the terminal ?" << endl;
    char inputChoice;
    cout << "enter a for file or b to enter manually : ";
    cin >> inputChoice;
    while (inputChoice != 'a' && inputChoice != 'b')
    {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid choice!, please try again : ";
        cin >> inputChoice;
    }
    if (inputChoice == 'a')
    {
        string filename;
        cout << "please enter the file name with a .txt extension : ";
        cin >> filename;
        fstream instFile(filename);
        regex txtPattern(R"(^[a-zA-Z0-9_\-]+\.txt$)");
        while (!regex_match(filename, txtPattern))
        {
            cout << "please enter a right file name with .txt extension : ";
            cin >> filename;
        }
        while (instFile.fail())
        {
            cout << "please enter a right directory to the file or a right file name : ";
            cin >> filename;
            instFile.open(filename);
        }
        
    }
    else if (inputChoice == 'b')
    {
        instLines(instructions);
    }
    string pc;
    cout << "Please enter the beginning value of the program counter as a 2-digit hexa number : ";
    cin >> pc;
    bool isAvalidHexa = true;
    do 
    {
      isAvalidHexa = true;
      for (int i = 0; i < pc.length(); i++)
      {
        pc[i] = toupper(pc[i]); 
      }
      for (int i = 0; i < pc.length(); i++)
        if (!((pc[i] >= '0' && pc[i] <= '9') || pc[i] >= 'A' && pc[i] <= 'F'))
        {
          isAvalidHexa = false;
          break;
        }
        if (pc.length() > 2) isAvalidHexa = false; 
        if (!isAvalidHexa)
        {
          cout << "please enter a valid hexa number : "; 
          cin >> pc; 
        }
    } while (!isAvalidHexa);

    machine.processor.set_pc(pc); 
    machine.loadProgramFile(instructions , machine.processor.get_pc() , machine.memory);
    vector <string> screen; 
    while (machine.processor.get_pc() <= 256)
    {
      machine.processor.fetch(machine.memory); 
      vector <string> temp =  machine.processor.decode();
      if (temp[0] == "3" && temp[2] == "00")
        screen.push_back(machine.processor.returnRegister().get_register(ALU::hexToDes(temp[1]))); 
      machine.processor.execute(machine.processor.returnRegister(), machine.memory, machine.processor.decode()); 
      if (temp[0] == "C" && temp[1] == "000")
        break;
    }

    // machine.outputMemory(machine.memory);
    // machine.outputRegisters(machine.processor.returnRegister());
    // for (int i = 0; i < screen.size(); i++)
    //   cout << screen[i] << ' '; 

    for(int i = machine.processor.get_pc() ; i < 256; i++) {
        machine.memory.get_memory(machine.processor.get_pc());
    }
    return 0;
}