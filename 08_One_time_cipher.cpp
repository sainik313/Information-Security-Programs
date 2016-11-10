#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s, key;
	
	cout<<"Enter your message:\t";
	cin>>s;
 	
	cout<<"Enter Key1:\t";
	cin>>key;
	
	//s="cometoday";
	//key="ncbtzqarx";
	
	int len=s.length();
	int len1=key.length();
	
	if(len!=len1){
		cout<<"Key length must be same as message length";
		return 0;
	}
	
		int enc[len],dec[len];
//encrypting code	
	for(int i=0;i<len;i++){
		enc[i]=((s[i]-96)+(key[i]-96))%26;
		//cout<<enc[i];
	}
	
	cout<<"\n\nEncrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(enc[i]+97);
	}

//encrypting code

	for(int i=0;i<len;i++){
		dec[i]=(enc[i])-(key[i]-96);
		if(dec[i]>0)
			dec[i]=dec[i]%26;
		else
			dec[i]=dec[i]+26;
		//cout<<dec[i];
	}
	
	cout<<"\n\nDecrpt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(dec[i]+96);
	}	
}
