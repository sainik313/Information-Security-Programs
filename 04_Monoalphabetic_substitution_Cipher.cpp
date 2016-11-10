#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s;
	
	cout<<"Enter message :\t";
	cin>>s;
	
	int len=s.length();
	char enc[len];
	
	char key[26]={'N','O','A','T','R','B','E','C','F','U','X','D','Q','G','Y','L','K','H','V','I','J','M','P','Z','S','W'};

	//encrypting code
	cout<<"Encrypt message:\t";
	for(int i=0;i<len;i++){
		
		int p=(s[i]-97);
		enc[i]=key[p];
		cout<<enc[i];
		
	}
	
	//Decrypting Code
	cout<<endl;
	cout<<"Decrpt message:\t";
	int pos=0;
	for(int i=0;i<len;i++){
		
		for(int j=0;j<26;j++){	
			if(enc[i]==key[j]){
				pos=j;
				break;
			}	
		}
		cout<<(char)(pos+96+1);
	}
	
}
