#include<iostream>
#include<math.h>
using namespace std;

int inverse(int r1, int r2){
	
	int t1,t2,t,q,r,l1,l2;
	t1=0; t2=1;
	l1=r1; l2=r2;
	
	while(r2>0){
		
		q=r1/r2;
		r=r1-(q*r2);
		r1=r2;
		r2=r;
		t=t1-(q*t2);
		t1=t2;
		t2=t;
		
	}
	if(r1==1){
		if(t1<0)
		t1+=l1;
		return t1;
	}
	
}

int ch_rem(int x1,int x2, int m1, int m2){
	
int f;
int M,M1,M2;

M=m1*m2;
M1= M/m1;
M2= M/m2;

int m1i= inverse(m1,M1);
int m2i= inverse(m2,M2);

f= ((x1*m1i*M1)+(x2*m2i*M2))%M;
return f;
	
}

int main(){
	
	int plain,p,q;
	
	cout<<"Enter the message(Integer):\t";
    cin>>plain;
    cout<<"Enter value of p:\t";
    cin>>p;
    cout<<"Enter value of q:\t";
	cin>>q;
	
	double a1,a2,b1,b2;
	int p1,p2,p3,p4;
	
	 
	
	int n=p*q;
	
	//enc
	
	int enc= (plain*plain)%n;
	cout<<"\nEnrypted Message:\n";
	cout<<enc;
	
	//dec
	
	a1= pow(enc,(p+1)/4);
	a1= fmod(a1,p);
	
	a2= -pow(enc,(p+1)/4);
	a2= fmod(a2,p);
	a2+=p;
	
	b1= pow(enc,(q+1)/4);
	b1= fmod(b1,q);
	
	b2= -pow(enc,(q+1)/4);
	b2= fmod(b2,q);
	b2+=q;
	
	p1= ch_rem(a1,b1,p,q);
	p2= ch_rem(a1,b2,p,q);
	p3= ch_rem(a2,b1,p,q);
	p4= ch_rem(a2,b2,p,q);
	
	cout<<"\nDecrypted Message:\n";
	cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4;
	
}
