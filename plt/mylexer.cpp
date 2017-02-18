#include <iostream>
using namespace std;
bool test_number(string input, int num);
bool test_hex(string input, int num);
bool key_word(string input, int num);
bool test_ident(string input, int num);
bool test_email(string input, int num);

int main(){

  int count;
  string input;

  cin >> count;
  cout << count<< endl;

  for(int i =0; i<count; i++){
    cin >> input;
    if(!key_word(input,i)){
      if(!test_number(input,i)){
        if (!test_hex(input,i)){
          if (!test_ident(input,i)) {
            if(!test_email(input,i)){
              cout<< i+1<< ": " << "INVALID!"<<endl;;
            }
          }
        }
      }
    }
  }
  return 0;
}

bool test_email(string input, int num){

  int state = 0;
  for(int i =0; i<input.size(); i++){
    switch(state){
      case 0:
        if(input[i]>='A' && input[i]<='z'){
          state = 1;
        }
        else
          return false;
        break;
      case 1:
        if(input[i]>='A' && input[i]<='z' || input[i]=='_'){
          state = 1;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 1;
        }
        else if(input[i]=='.')
          state = 0;
        else if(input[i]=='@')
          state = 2;
        else
          return false;
        break;
     case 2:
        if(input[i]>='A' && input[i]<='z'){
          state = 3;
        }
        else
          return false;
        break;
     case 3:
        if(input[i]>='A' && input[i]<='z' || input[i]=='_'){
          state = 3;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 3;
        }
        else if(input[i]=='.')
          state = 4;
        else
           return false; 
        break;
     case 4:
        if(input[i]=='c')
          state = 5;
        else if(input[i]=='e')
          state = 7;
        else if(input[i]=='n')
          state = 9;
        else
          return false;
       break;
     case 5:
        if(input[i]=='o')
          state = 6;
        else
          return false;
       break;
      case 6:
        if(input[i]=='m')
          state = 20;
        else
          return false;
       break;
      case 7:
        if(input[i]=='d')
          state = 8;
        else
          return false;
       break;
      case 8:
        if(input[i]=='u')
          state = 20;
        else
          return false;
       break;
      case 9:
        if(input[i]=='e')
          state = 10;
        else
          return false;
       break;
      case 10:
        if(input[i]=='t')
          state = 20;
        else
          return false;
       break;
      case 20:
        return false;
       break;
 
     case 100:
        return false;
      break;
    }
  }
  if(state == 20){
    cout<< num +1 << ": Email."<< endl;
    return true;
  }
  return false;
}


bool key_word(string input, int num){
 if(input == "while"||input == "else"||input == "if"||input == "print"){
   cout << num +1 << ": Keyword."<<endl;
   return true;
 }
 return false;
}

bool test_ident(string input, int num){
  int state = 0;
  for(int i =0; i<input.size(); i++){
    switch(state){
      case 0:
        if(input[i]>='A' && input[i]<='z'){
          state = 1;
        }
        else
          return false;
        break;
      case 1:
        if(input[i]>='A' && input[i]<='z' || input[i]=='_'){
          state = 1;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 1;
        }
        else
          return false;
        break;
     case 100:
        return false;
      break;
    }
  }
  if(state == 1){
    cout<< num +1 << ": Identifire."<< endl;
    return true;
  }
  return false;
}

bool test_hex(string input, int num){

  int state = 0;
  for(int i =0; i<input.size(); i++){
    switch(state){
      case 0:
        if(input[i]>='A' && input[i]<='F'){
          state = 1;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 2;
        }
        else
          return false;
        break;
      case 1:
        if(input[i]>='A' && input[i]<='F'){
          state = 1;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 2;
        }
        else if(input[i] == 'H')
          state = 3;
        else
          return false;
        break;
      case 2:
        if(input[i]>='A' && input[i]<='F'){
          state = 1;
        }
        else if(input[i]>='0' && input[i]<='9'){
          state = 2;
        }
        else if(input[i] == 'H')
          state = 3;
        else
          return false;
        break;
      case 3:
        return false;
        break;
      case 100:
        return false;
      break;
    }
  }
  if(state == 3){
    cout<< num +1 << ": Hexadecimal"<< endl;
    return true;
  }
  return false;
}

bool test_number(string input, int num){
  int state =0;
  for(int i =0; i<input.size(); i++){
    switch(state){
    case 0://start of int check
      if(input[i]=='+'||input[i]=='-'){
        state = 1;
      }
      else if(input[i]=='0'){
        state = 2;
      }
      else if(input[i]>='1' && input[i]<='9'){
        state = 3;
      }
      else
        state = 100;
      break;
    case 1:
      if(input[i]=='+'||input[i]=='-'){
        state = 100;
      }
      else if(input[i]=='0'){
        state = 2;
      }
      else if(input[i]>='1' && input[i]<='9'){
        state = 3;
      }
      else
        state = 100;
      break;
    case 2://oops
      if(input[i]=='0'){
        state = 2;
      }
      else if(input[i]>='1' && input[i]<='9'){
        state = 3;
      }
      else
        state = 100;
      break;
    case 3://end of int
      if(input[i]=='+'||input[i]=='-'){
        state = 100;
      }
      else if(input[i]>='0' && input[i]<='9'){
        state = 3;
      }
      else if(input[i]=='.'){
        state = 4;
      }
      else
        state = 100;
     break;
    case 4://start of decimal check
      if(input[i]>='0' && input[i]<='9'){
        state = 5;
      }
      else
        state = 100;
      break;
    case 5://end of decimal
      if(input[i]>='0' && input[i]<='9'){
        state = 5;
      }
      else if(input[i]=='E'){
        state = 6;
      }
      else
        state = 100;
      break;
    case 6:// scientific check
       if(input[i]=='+'||input[i]=='-'){
        state = 7;
      }
      else if(input[i]>='0' && input[i]<='9'){
        state = 8;
      }
      else
        state = 100;
      break;
    case 7:
      if(input[i]=='+'||input[i]=='-'){
        state = 100;
      }
      else if(input[i]>='0' && input[i]<='9'){
        state = 8;
      }
      else
        state = 100;
      break;
    case 8:
      if(input[i]>='0' && input[i]<='9'){
        state = 8;
      }
      else
        state = 100;
      break;
    case 100:
      return false;
    break;
    }
  }
  if(state == 3 || state == 2){
    cout<<num+1<<": Integer."<<endl;
  }
  else if(state == 5){
    cout<<num+1<<": Decimal."<<endl;
  }
  else if(state == 8){
    cout<<num+1<<": Scientific."<<endl;
  }
 return true;
}
