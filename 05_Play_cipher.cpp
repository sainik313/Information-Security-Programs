#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s;
	cout<<"Enter your message:\t";
	cin>>s;
	//s="themeetingisattrefforest";
	//s="hello";
	char key[5][5]={{'l','g','d','b','a'},{'q','m','h','e','c'},{'u','r','n','i','f'},{'x','v','s','o','k'},{'z','y','w','t','p'}};
	int len=s.length();
	int len1=len;
	//cout<<len;
	
	
	for(int i=1;i<len1;i++){
		
		if(s[i-1]==s[i]){
			
			len1++;
			s.append(" ");
			for(int j=len1;j>i;j--){
				s[j]=s[j-1];
			}
			s[i]='x';
		}	
	}
	if(len1%2!=0){
		s.append("x");
	}
	len1=s.length();
	
	char enc[len1];
	char dec[len1];
	
//encrypting code
	
	for(int i=0;i<len1;i=i+2){
		int r1=-1,c1=-1,r2=-1,c2=-1;
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				
				if(s[i]==key[j][k]){
					//cout<<j<<"  "<<k<<endl;
					r1=j;
					c1=k;
					//cout<<key[j][k];
				}
				if(s[i+1]==key[j][k]){
					//cout<<j<<"  "<<k<<endl;
					r2=j;
					c2=k;
				//	cout<<key[j][k];
				}
				
				
			}
		}
		//cout<<r1<<c1<<endl<<r2<<c2<<endl;
		if(r1==r2){
			if(c1==4)
				enc[i]=key[r1][0];
				else
				enc[i]=key[r1][c1+1];
			if(c2==4)
				enc[i+1]=key[r2][0];
				else
				enc[i+1]=key[r2][c2+1];
			
		}
		else if(c1==c2){
			
			if(r1==4)
				enc[i]=key[0][c1];
				else
				enc[i]=key[r1+1][c1];
			if(r2==4)
				enc[i+1]=key[0][c2];
				else
				enc[i+1]=key[r2+1][c2];
			
		}
		else{
			enc[i]=key[r1][c2];
			enc[i+1]=key[r2][c1];
		}
		
	}
	cout<<"\nEncrypt message:\t";
	for(int i=0;i<len1;i++){
		cout<<enc[i];
	}
	
//Decrypting Code

	for(int i=0;i<len1;i=i+2){
		int r1=-1,c1=-1,r2=-1,c2=-1;
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				
				if(enc[i]==key[j][k]){
					//cout<<j<<"  "<<k<<endl;
					r1=j;
					c1=k;
					//cout<<key[j][k];
				}
				if(enc[i+1]==key[j][k]){
					//cout<<j<<"  "<<k<<endl;
					r2=j;
					c2=k;
				//	cout<<key[j][k];
				}
				
				
			}
		}
		//cout<<r1<<c1<<endl<<r2<<c2<<endl;
		if(r1==r2){
			if(c1==0)
				dec[i]=key[r1][4];
				else
				dec[i]=key[r1][c1-1];
			if(c2==0)
				dec[i+1]=key[r2][4];
				else
				dec[i+1]=key[r2][c2-1];
			
		}
		else if(c1==c2){
			
			if(r1==0)
				dec[i]=key[4][c1];
				else
				dec[i]=key[r1-1][c1];
			if(r2==0)
				dec[i+1]=key[4][c2];
				else
				dec[i+1]=key[r2-1][c2];
			
		}
		else{
			dec[i]=key[r1][c2];
			dec[i+1]=key[r2][c1];
		}
		
	}
	cout<<"\n\nDecrpt message:\t";
	for(int i=0;i<len1;i++){
		cout<<dec[i];
	}
	char dec1[len];
	
	int j=0;
	for(int i=0;i<len1;i++){
		if(dec[i]!='x'){
			dec1[j]=dec[i];
			j++;
		}
	}
	cout<<"\n\nYour message may be:\t";
	for(int i=0;i<len;i++){
		cout<<dec1[i];
	}
}
