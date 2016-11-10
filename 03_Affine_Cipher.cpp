#include<iostream>
#include<string.h>
using namespace std;

int inverse(int);
int checkKey(int);
int main(){
	
	string s;
	int k1,k2;
	
	cout<<"Enter your message:\t";
	cin>>s;
 	
	cout<<"Enter multiplicative Key1:\t";
	cin>>k1;
	cout<<"Enter additive Key2:\t";
	cin>>k2;
	
	int len=s.length();
	int enc[len], dec[len];
	
	int temp=checkKey(k1);
	if(temp==-1){
		cout<<"No Encryption possible choose other value";
		return 0;
	}
	
	//encrypting code
	for(int i=0;i<len;i++){
		if(s[i]>=97&&s[i]<=122){
			enc[i]=((s[i]-96)*k1+k2)%26;
			//cout<<enc[i];
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
	int knew= inverse(k1);
	for(int i=0;i<len;i++){
	 	
	 	if((enc[i]-k2)*knew>=0)
			dec[i]=((enc[i]-k2)*knew)%26;
		else
			dec[i]=((enc[i]-k2)*knew)+26;
		 
	}
	cout<<endl;
	cout<<"Decrpt message:\t";
	for(int i=0;i<len;i++){
		cout<<(char)(dec[i]+96);
	}
}
int inverse(int k){
	
	for(int i=1;i<=26;i++)
	{
		
		if((k*i)%26==1)
		return i;
		
	}
	
}
int checkKey(int k){
	
	for(int i=2;i<=k;i++)
	{
		if(k%i==0 && 26%i==0)
		{
		
		return -1;
		}
	}
	
}
