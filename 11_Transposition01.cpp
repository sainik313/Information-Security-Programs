#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s;
	int n,m;
	cout<<"Enter your message:\t";
	cin>>s;
	cout<<"Enter Column size:\t";
	cin>>n;
	
	//s="mynameiskapil";
	//n=3;
	int len=s.length();
	
	if(len%n==0)
		m=len/n;
	else
		m=(len/n)+1;
	
	if(m*n>len){
		for(int i=len;i<m*n;i++){
			s.append("x");
		}
	}

	len=s.length();
 
	
	char enc[m][n];
	char enc1[len];
	char dec[n][m];
	char dec1[len];
	
//encrypting code		
	int k=0;
	cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			enc[i][j]=s[k];
			//cout<<enc[i][j];
			k++;
		}
		//cout<<endl;
	}
	 
	k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			enc1[k]=enc[j][i];
			k++;
		}
	}
	
	cout<<"\n\nEncrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<enc1[i];
	}
	
//decrypting code	
	k=0;
	//cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dec[i][j]=enc1[k];
			//cout<<dec[i][j];
			k++;
		}
		//cout<<endl;
	}
	//cout<<endl;
	k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dec1[k]=dec[j][i];
			//cout<<dec1[k];
			k++;
		}
	}
	
	cout<<"\n\nDecrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<dec1[i];
	}
		
}
