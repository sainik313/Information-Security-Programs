#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s;
	int k;
	
	cout<<"Enter your message:\t";
	cin>>s;
	cout<<"Enter Key:\t";
	cin>>k;
	int len=s.length();
	int enc[len], dec[len];
	
	//encrypting code
	for(int i=0;i<len;i++){
		if(s[i]>=97&&s[i]<=122){
			enc[i]=((s[i]-96)+k)%26;
			
		}
		else{
			cout<<"Wrong Message";
			return 0;
		}
	}
	cout<<endl;
	cout<<"Encrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(enc[i]+96);
	}
	
	//Decrypting Code
	for(int i=0;i<len;i++){
		if(enc[i]>=k)
		dec[i]=(enc[i]-k)%26;
		else
		dec[i]=(enc[i]+26-k)%26;
	}
	
	cout<<endl;
	cout<<"Decrpt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(dec[i]+96);
	}
}
