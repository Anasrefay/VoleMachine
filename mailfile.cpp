#include <bits/stdc++.h>
#include "headerfile.hpp"
using namespace std; 
#define endl '\n' 

int main()
{
  cout << "welcome back ya user, nwrt w 4rft" << endl; 
  cout << "this is a vole machine similator" << endl; 
  cout << "you can input the instructions for the machine either as a file or as a normal input (from the terminal)" << endl; 
  cout << "to end the similator you must enter the instruction C000 (halt)" << endl; 
  cout << "so, do you want to give the instructoins as a txt file or from the terminal ?" << endl; 
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
    regex txtPattern(R"(\.txt$)", regex::icase);
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
    cout << "please start entering the instructions " << endl; 

  }


  return 0; 
}