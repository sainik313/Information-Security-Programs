#include<iostream>
#include<string.h>
using namespace std;

int isInverse(int);

int main(){
	
	string s;
	int key[2][2];
	cout<<"Enter your message:\t";
	cin>>s;
	cout<<"Enter 2*2 key matrix:\t";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>key[i][j];
		}
	}
	
	//s="codeisready";
	int len=s.length();
	
	//float key[2][2]={{2,1},{1,1}};
	/*for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<key[i][j];
		}
	}*/
	
	int n=2;
	int l=2;
	int m;
	
	
	int t=len%n;
	if(t!=0){
		for(int i=0;i<t;i++){
			s.append("x");
		}
	}
	 
	len=s.length();
	
	m=(len/n);
	int a[m][n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j]=(int)s[(i*n)+j]-96;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//cout<<a[i][j]<<" ";
		}
	}
	
	int det=key[0][0]*key[1][1]-key[0][1]*key[1][0];
	//cout<<det;
	
	int check= isInverse(det);
	
	if(check==-1){
		cout<<"no inverse";
		return 0;
	}
	
	int b[m][n];
	int c[m][n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
				b[i][j]=0;
			for(int k=0;k<l;k++){
				
				b[i][j]=b[i][j]+(a[i][k]*key[k][j]);
				
			}
			 
		}
	}
	
	cout<<"Enc msg: \n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<(char)(b[i][j]%26+96);
		}
		 
	}
	
	//key matrix inverse
	
	int key1[2][2]={{0,0},{0,0}};
	
	key1[0][0]=key[1][1]/det;
	key1[1][1]=key[0][0]/det;
	key1[0][1]=-key[0][1]/det;
	key1[1][0]=-key[1][0]/det;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
				c[i][j]=0;
			for(int k=0;k<l;k++){
				
				c[i][j]=c[i][j]+(b[i][k]*key1[k][j]);
				
			}
			 
		}
	}
	
	cout<<"\nDec msg: \n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<(char)(c[i][j]%26+96);
		}
		 
	}
	
}

int isInverse(int d){
	int temp=1;
	for(int i=1;i<=26;i++){
		if((i*d)%26==1){
			temp=1;
			break;
		}
	}
	return temp;
}
