#include<iostream>
#include<string.h>
#include<process.h>
#include<math.h>
using namespace std;

int count=0; 
string new_key(string key);
string hex_to_bin(string ini);
string bin_to_hex(string ini);
string ini_key(string key);
string final_key(string key);
string ini_cipher(string code);
string des(string code,string key);

int main()
{
	string key,initial,cipher,left,right,bin_cipher,bin_key;
	key="";
	initial="";
	cipher="";
	bin_cipher="";
	bin_key="";
	
	int check;
	
	key="AABB09182736CCDD";
	initial="123456ABCD132536";
	//key="133457799BBCDFF1";
	//initial="0123456789ABCDEF";
	
	cout<<"Enter Key(in 16 bit hex)---(enter 1 to get default or 0 to give new)---:\n";
	cin>>check;
	if(check==0)
		cin>>key;
	else
		cout<<"key:\t"<<key<<endl;
	
	cout<<"Enter plaintext(in 16 bit hex)---(enter 1 to get default or 0 to give new)---:\n";
	cin>>check;
	if(!check)
		cin>>initial;
	else
		cout<<"initial:\t"<<initial<<endl;
	
	if(key.length()!=16||initial.length()!=16)
	{
		cout<"Enter valid 16 character key and plaintext please...\n";
		exit(0);
	}
	else
	{
		bin_key=hex_to_bin(key);
		if(bin_key.compare("null")!=0)
		{
			cout<<"binary key: "<<bin_key<<endl;
		}
		
		bin_cipher=hex_to_bin(initial);
		if(bin_cipher.compare("null")!=0)
		{
			cout<<"binary cipher: "<<bin_cipher<<endl;
		}
		
		cipher=des(bin_cipher,bin_key);
		cout<<"Bin Cipher code: "<<cipher<<endl;
		
		cout<<"Cipher: "<<bin_to_hex(cipher)<<endl;
	}
	
}

string hex_to_bin(string ini)
{
	int loop;
	string bin="";
	string value[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	
	for(loop=0;loop<ini.length();loop++)
	{
		switch(ini[loop])
		{
			case '0': bin+=value[0];
				break; 
			case '1': bin+=value[1];
				break;
			case '2': bin+=value[2];
				break;
			case '3': bin+=value[3];
				break;
			case '4': bin+=value[4];
				break;
			case '5': bin+=value[5];
				break;
			case '6': bin+=value[6];
				break;
			case '7': bin+=value[7];
				break;
			case '8': bin+=value[8];
				break;
			case '9': bin+=value[9];
				break;
			case 'A': bin+=value[10];
				break;
			case 'B': bin+=value[11];
				break;
			case 'C': bin+=value[12];
				break;
			case 'D': bin+=value[13];
				break;
			case 'E': bin+=value[14];
				break;
			case 'F': bin+=value[15];
				break;
			default: cout<<"non hex value" ;
					bin="null";
		}
		if(bin.compare("null")==0)
			break;
	}
	return bin;
}

string bin_to_hex(string ini)
{
	int loop;
	string hex="",tmp;
	string value[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	
	for(loop=0;loop<ini.length();loop=loop+4)
	{
		tmp=ini.substr(loop,4);
		
		if(tmp.compare(value[0])==0)
			hex+='0';
		else if(tmp.compare(value[1])==0)
			hex+='1';
		else if(tmp.compare(value[2])==0)
			hex+='2';
		else if(tmp.compare(value[3])==0)
			hex+='3';
		else if(tmp.compare(value[4])==0)
			hex+='4';
		else if(tmp.compare(value[5])==0)
			hex+='5';
		else if(tmp.compare(value[6])==0)
			hex+='6';
		else if(tmp.compare(value[7])==0)
			hex+='7';
		else if(tmp.compare(value[8])==0)
			hex+='8';
		else if(tmp.compare(value[9])==0)
			hex+='9';
		else if(tmp.compare(value[10])==0)
			hex+='A';
		else if(tmp.compare(value[11])==0)
			hex+='B';
		else if(tmp.compare(value[12])==0)
			hex+='C';
		else if(tmp.compare(value[13])==0)
			hex+='D';
		else if(tmp.compare(value[14])==0)
			hex+='E';
		else if(tmp.compare(value[15])==0)
			hex+='F';
		else
			hex="null";
		
		if(hex.compare("null")==0)
			break;
	}
	return hex;
}

string ini_key(string key)
{
	int loop;
	string tmp_key="";
	int perm1[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
	for(loop=0;loop<56;loop++)
		tmp_key+=key[perm1[loop]-1];
    cout<<"tmp_key after permutation: "<<tmp_key<<endl;
	if(tmp_key.length()!=56)
		return "err";
	return tmp_key;
}

string new_key(string key)
{
	int loop,tmpc,tmpd,tmpc1,tmpd1;
	string c=key.substr(0,28);
	string d=key.substr(28,28);
	if(count==0 || count==1 || count==8 || count==15)
	{
		tmpc=c[0];
		tmpd=d[0];
		for(loop=1;loop<28;loop++)
		{
				c[loop-1]=c[loop];
				d[loop-1]=d[loop];
		}
		loop--;
		c[loop]=tmpc;
		d[loop]=tmpd;
		count++;
	}
	else
	{
		tmpc=c[0];
		tmpd=d[0];
		tmpc1=c[1];
		tmpd1=d[1];
		for(loop=2;loop<28;loop+=2)
		{
				c[loop-2]=c[loop];
				c[loop-1]=c[loop+1];
				d[loop-1]=d[loop+1];
				d[loop-2]=d[loop];
		}
		loop=loop-2;
		c[loop]=tmpc;
		d[loop]=tmpd;
		c[loop+1]=tmpc1;
		d[loop+1]=tmpd1;
		count++;
	}
	c=c+d;
	return c;
}

string final_key(string key)
{
	int loop;
	string tmp_key="";
	int perm1[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	for(loop=0;loop<48;loop++)
		tmp_key+=key[perm1[loop]-1];
    cout<<"tmp_key after permutation: "<<tmp_key<<endl;
	if(tmp_key.length()!=48)
		return "err";
	return tmp_key;
}

string ini_cipher(string code)
{
	int loop;
	string plain="";
	int perm1[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	for(loop=0;loop<64;loop++)
		plain+=code[perm1[loop]-1];
    cout<<"plaintext after permutation: "<<plain<<endl;
	if(plain.length()!=64)
		return "err";
	return plain;
}

string des(string code,string key)
{
	int r,c;
	r=c=0;
	string left,right,e_right,tmp_key,tkey[16],scipher;
	string tmp_cipher=ini_cipher(code);
	string value[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	
	int final_cipher[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
	
	int fp[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
	
	int s[8][4][16]={{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
					  {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                      {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
     				  {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
					 {{15,1,8, 14,6,11,3,4,9,7,2,13,12,0,5,10},
      			      {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
      			      {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
     			      {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
					 {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
     			      {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
     			      {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
      			   	  {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
					 {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
     			      {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
     			      {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                      {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
					 {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                      {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
      			      {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                      {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
					 {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
     			      {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
      			      {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
      			      {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
					 {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
     			      {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
      			      {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
      			      {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
					 {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
      			      {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
      			      {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
      			      {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}};
	
	
	int e[]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	tmp_key=ini_key(key);
	if(key.compare("null")!=0)
	{
		cout<<"key after initial 64 to 56 conversion: "<<tmp_key<<endl;
	}
	
	tkey[0]=new_key(tmp_key);
	for(int lp=1;lp<16;lp++)
	{
		cout<<"Count: "<<count<<endl;
		tkey[lp]=new_key(tkey[lp-1]);
	}
	
	for(int i=0;i<16;i++)
	{
		left=tmp_cipher.substr(0,32);
		right=tmp_cipher.substr(32,32);
	
		cout<<"L"<<i<<": "<<left<<" "<<"R"<<i<<": "<<right<<endl;
		tmp_key=final_key(tkey[i]);
		
		cout<<"K"<<(i+1)<<": "<<tmp_key<<endl;
		
		e_right="";
		for(int lp=0;lp<48;lp++)
			e_right+=right[e[lp]-1];
    	cout<<"E(R"<<i<<"): "<<e_right<<endl;
		if(e_right.length()!=48)
			return "err";
		
		tmp_cipher="";
		
		for(int lp=0;lp<48;lp++)
			tmp_cipher+=(char)((tmp_key[lp]^e_right[lp])+48);
			
		cout<<"The XOR of E(R"<<i<<") and K("<<i+1<<"): "<<tmp_cipher<<endl;
		
		int ctr=3,loop=0;
		scipher="";
		
		for(int lp=0;lp<48;lp=lp+6)
		{
			r=(((int)(tmp_cipher[lp+5])-48)*(int)pow(2,0))+(((int)(tmp_cipher[lp])-48)*(int)pow(2,1));
			for(int j=lp+1;j<lp+5;j++)
				c+=((int)(tmp_cipher[j])-48)*(int)pow(2,ctr--);
			cout<<"current row:column :- "<<r<<":"<<c<<endl;
			scipher+=value[s[loop][r][c]];
			loop++;
			r=0;
			c=0;
			ctr=3;
		}		
		cout<<"Plaintext after s boxes: "<<scipher<<endl;
		
		tmp_cipher="";
		
		for(int lp=0;lp<32;lp++)
			tmp_cipher+=scipher[fp[lp]-1];
		
		cout<<"After final permutation round 1 plaintext: "<<tmp_cipher<<endl;
		
		for(int lp=0;lp<32;lp++)
			tmp_cipher[lp]=(char)((tmp_cipher[lp]^left[lp])+48);
		
		tmp_cipher=right+tmp_cipher;
		
		cout<<"After round "<<i+1<<" plaintext is: "<<tmp_cipher<<"\t"<<"Key is: "<<tmp_key<<endl;
		getchar();
	}
	
	left=tmp_cipher.substr(0,32);
    right=tmp_cipher.substr(32,32);
    tmp_cipher=right+left;
    left="";
    cout<<"Round 16 real pliantext: "<<tmp_cipher<<endl;
    cout<<"Applying final permutation:\n";
    for(int i=0;i<64;i++)
    	left+=tmp_cipher[final_cipher[i]-1];
    cout<<"The encrypted binary message: "<<left<<endl;
    return left;
}
