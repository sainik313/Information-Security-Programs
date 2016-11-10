#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	string s,key;
	int n,m;
	cout<<"Enter your message:\t";
	cin>>s;
	cout<<"Enter key (string):\t";
	cin>>key;
	//s="kapil";
	//key="xy";
	int len=s.length();
	n=key.length();
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
	char dec[m][n];
	char dec1[len];
	
	int l=key.length();
	char key1[l];
	char key2[l];
	
	for(int i=0;i<l;i++){
		key1[i]=key[i];
	}
	
	int temp;
	for (int i = 1; i < l; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (key1[j] < key1[j-1])
            {
                temp = key1[j];
                key1[j] = key1[j-1];
                key1[j-1] = temp;
            }
            else
                break;
        }
    }
	
	for(int i=0;i<l;i++){
		char t=key1[i];
		for(int j=0;j<l;j++){
			if(t==key[j]){
				key2[i]=j;
				break;
			}
		}
	}

//encrypting code	
	int k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			enc[i][j]=s[k];
			k++;
		}
	}
	k=0;
	for(int i=0;i<n;i++){
		int i1=key2[i];
		for(int j=0;j<m;j++){
			enc1[k]=enc[j][i1];
			//cout<<enc1[k]<<endl;
			k++;
		}
	}
	
	cout<<"\n\nEncrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<enc1[i];
	}
	
//decrypting code
	
	k=0;
	for(int i=0;i<n;i++){
		int i1=key2[i];
		for(int j=0;j<m;j++){
			dec[j][i1]=enc1[k];
			
			k++;
		}
	}

	k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dec1[k]=dec[i][j];
			k++;
		}
	}
	
	cout<<"\n\nDecrypt message:\t";
	for(int i=0;i<len;i++){
		cout<<dec1[i];
	}
		
}
