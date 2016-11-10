#include<iostream>
#include<string.h>
using namespace std;
 int main(){
 
    char msg[20];
    char key[20];
    char enkey[20];
    char dkey[20];
  
      cout<<"\nEnter the message: \n";
      cin>>msg;

      cout<<"\nEnter the key: \n";
      cin>>key;

      int len = strlen(msg);
      int keylen = strlen(key);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){

        enkey[i] = msg[i]^key[i%keylen];

        cout<<enkey[i];
      }
      cout<<endl;
      
    len = strlen(msg);
	keylen = strlen(key);
        cout<<"Encrypted Message is: ";
        for(int i=0;i<len;i++){

          dkey[i] = enkey[i]^key[i%keylen];

          cout<<dkey[i];
        }
        cout<<endl;

}
