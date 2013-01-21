#include <iostream>
#include<stdio.h>
#include <string>
#include <stack>
using namespace std;
 
int main(){
  int num,i;
  cin>>num;
  if ( num < 1 || num > 100 ){
    return 0;
  }
  cin.ignore();

  string output;
  stack<char> stk;
  char t;
  char array[400];

  while ( num > 0 ){
    scanf("%s",array);
    output.clear();
    i=0;
    while( array[i] != '\0' ) {
	    //cout<<"processing array[ "<<i<<"]"<<endl;
      if ( i > 400 ) return 0;
      if ( array[i] == ' ' || array[i] == '\t' ){
         i++;
         continue;
      }
   
      if( array[i] == '('){
        stk.push(array[i]);
      }
      else if (array[i] == ')' ){
        while((t=stk.top()) != '('){
          stk.pop();
             output.push_back(t);
        }
        stk.pop(); //discard '('
      }
      else if( array[i] < 'a' || array[i] > 'z' ){
        stk.push(array[i]);
      }
      else{
        output.push_back(array[i]);
      }

      i++;
    }
    while(!stk.empty()){
      output.push_back(stk.top());
      stk.pop();
    }
    num--;
    cout<<output<<endl;
    }
  return 0;
}