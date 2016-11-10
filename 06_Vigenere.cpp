#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s, key;
	/*
	cout<<"Enter your message:\t";
	cin>>s;
 	
	cout<<"Enter Key1:\t";
	cin>>key;
	*/
	s="sheislistening";
	key="pascal";
	cout<<s;
	int len=s.length();
	int len1=key.length();
	
	if(len<len1){
		cout<<"Key must be <= message";
		return 0;
	}
int dif= len-len1;
	
		int enc[len],dec[len];
		int pos1=0;
		
//encrypting code
		int j=0,x=0,pos2=0;
	while(x<len){
		j=0;
		pos2=pos1+len1;
		//cout<<"pos2 "<<pos2;
		for(int i=pos1;i<pos2;i++){
			enc[i]=((s[i]-97)+(key[j]-97))%26;
			j++;
		}
	pos1=pos1+len1;
	x=x+len1;
	}
	cout<<"\n\nEncrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(enc[i]+97);
	}
	
//decrypting code
pos1=0;
	j=0,x=0,pos2=0;
	while(x<len){
		j=0;
		pos2=pos1+len1;
		//cout<<"pos2 "<<pos2;
		for(int i=pos1;i<pos2;i++){
			dec[i]=((enc[i])-(key[j]-97));
			if(dec[i]>0)
				dec[i]=dec[i]%26;
			else
				dec[i]=dec[i]+26;
			//cout<<"\nhere "<<enc[i];
			j++;
		}
	pos1=pos1+len1;
	x=x+len1;
	}
	cout<<"\n\nEncrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(dec[i]+97);
		//cout<<(dec[i]);
		
	}

}
