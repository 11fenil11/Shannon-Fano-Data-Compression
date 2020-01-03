/*
CODER: Fenil Parmar
Vishwakarma Govt Engineering College.
*/



#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<windows.h>
using namespace std;

int actual;
class OP{
	public:
	int freq;
	char ch;
	string codw;
	void getd()
	{
		cout<<"Enter Character:";cin>>ch;
		cout<<"Enter Frequency:";cin>>freq;
		this->codw="";
	}
	void getd(char dh,int preq)
	{
		this->ch=dh;
		this->freq=preq;
		this->codw="";
	}
	
	void display()
	{
		cout<<"Character:"<<ch<<"     Frequency:"<<freq<<endl;
	}
	void cop()
	{
		cout<<"Code of "<<ch<<"="<<codw<<endl;
	}
};
OP pi[127];

class chunks{
	public:
		string b8;
		char d8;
		int i8;
};
chunks cnks[500];
void shan(int s,int e)
{
	if(s<e)
	{
		int sum_1=0,sum_2=0;
		int mind=10000;
		int t=0;
		int diff=0;
		int pt;
		int i,j,k,cmp;
		
		for(cmp=0;cmp<(e-s);cmp++)	
		{

			for(k=s;k<=s+cmp;k++)
			{
				sum_1=sum_1+pi[k].freq;
			}
			for(j=s+cmp+1;j<=e;j++)
			{
				sum_2=sum_2+pi[j].freq;
			}
			diff=abs(sum_2-sum_1);	
			if(diff<=mind)
			{
				mind=diff;
				pt=cmp+s;
			}
			sum_1=0;
			sum_2=0;
		}
			for(i=s;i<=pt;i++)
			{
				pi[i].codw=pi[i].codw+"1";
			}
			cout<<endl;
			for(i=pt+1;i<=e;i++)
			{
				pi[i].codw=pi[i].codw+"0";
			}
			int tmpp=pt;
			shan(tmpp+1,e);
			shan(s,tmpp);
	}
}

void rdfile()
{
	ifstream inFile;
   	char ch; 
	cout<<"Reading file = ab.txt";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	inFile.open("ab.txt");
	if (!inFile)
	{
	  cout << "The input file could not be opened."<<endl;
	  exit(0);
	}
	for(int i=0;i<127;i++)
	{
		cout<<"Char("<<i<<")="<<char(i)<<endl;
		pi[i].getd(char(i),0);
	}
   	ch = inFile.get();
   	while (ch != EOF)
	{
		pi[int(ch)].freq++;
    	ch = inFile.get();
   	}
}

void wtfile(int h)
{
	ifstream inFile;   
	ofstream outfile;	
   	outfile.open("1_Codeword.txt");	
   	
	char ch; 
	cout<<endl;
	cout<<"Reading file = ab.txt"<<endl;
	cout<<"Generating 1_Codeword.txt file";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	inFile.open("ab.txt");
	if (!inFile)
	{
	  cout << "The input file could not be opened."<<endl;
	  exit(0);
	}

   	ch = inFile.get();
   	int i;
	while (ch != EOF)
	{
		i=h;
		while(pi[i].ch!=ch)
		{
			i++;
		}
		outfile<<pi[i].codw;
    	ch = inFile.get();
   	}
   	outfile.close();
   	cout<<"File Generated!"<<endl;
}

int binTOdec(string binaryString)
{  
	int value = 0;
	int indexCounter = 0;
	for(int i=binaryString.length()-1;i>=0;i--)
	{
	    if(binaryString[i]=='1'){
	        value += pow(2, indexCounter);
	    }
    indexCounter++;
	}
	return value;
}


void dcp()
{
	ifstream inFile; 
	ofstream outfile;
	outfile.open("2_compressed.txt");	
	char ch; 
	cout<<"Reading 1_Codeword.txt file"<<endl;
	cout<<"Generating 2_compressed.txt file.";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	inFile.open("1_codeword.txt");
	if (!inFile)
	{
	  cout << "The input file could not be opened."<<endl;
	  exit(0);
	}
   	ch = inFile.get();
   	int i=0,lmt=0;
	cout<<"\tCHAR\tINT\tBINARY\tCint"<<endl;
	while (ch != EOF)
	{
		cnks[i].b8=cnks[i].b8+ch;
		while(cnks[i].b8.length()!=8)
		{
			ch = inFile.get();
			if(ch == EOF)
			{
				lmt++;
				ch = '0';
			}
			cnks[i].b8=cnks[i].b8+ch;	
		}
//		cnks[i].i8 = binTOdec(cnks[i].b8);
//		cnks[i].d8 = char(cnks[i].i8);
		cnks[i].d8 = char(binTOdec(cnks[i].b8));
		cnks[i].i8 = int(cnks[i].d8);
		cout<<"\t"<<cnks[i].d8<<"\t"<<cnks[i].i8<<"\t"<<cnks[i].b8<<"\t"<<int(cnks[i].d8)<<endl;
		outfile<<cnks[i].d8;
		ch = inFile.get();
    	i++;
   	}
   	actual = (i*8)-lmt;
   	outfile.close();
   	cout<<"\nFile 2_compressed.txt Generated!"<<endl;
   	Sleep(100);
}



void fina()
{
	ifstream inFile;   // input file
	ofstream outfile;	//output file
   	
	outfile.open("3_BinaryOfCompressed.txt");	
   	
	char ch; 
	cout<<"Reading file = 2_Compressed.txt"<<endl;
	cout<<"Generating 3_BinaryOfCompressed.txt file.";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	inFile.open("2_compressed.txt");
	if (!inFile)
	{
	  cout << "The input file could not be opened."<<endl;
	  exit(0);
	}
   	ch = inFile.get();
   	int i=0;
   	cout<<"Results In 3_BinaryOfCompressed"<<endl;
   	cout<<"Character\tBinary"<<endl;
	
	while(ch != EOF)
	{
		while (ch != EOF)
		{
	      	cout <<"\t"<< ch<<"\t"<<int(ch)<<"\t";
			bitset<8> bin_x(ch);
			outfile<<bin_x;
			cout<<"binary ="<<bin_x<<endl;
			ch = inFile.get();
			cout<<"CHAR"<<ch<<"\t"<<int(ch)<<"\t\t";
		}
		
	   	ch = inFile.get();
	}

   	
	cout<<"\nGenerated 3_BinaryOfCompressed.txt file!"<<endl;
   	Sleep(1000);
   	outfile.close();
	
}

void las(int h)
{
	ifstream inFile;
	ofstream outfile;
	
	inFile.open("3_BinaryOfCompressed.txt");
	outfile.open("4_Finalizedfile.txt");
	cout<<"Reading file = 3_BinaryOfCompressed.txt"<<endl;
	cout<<"Generating 4_Finalizedfile.txt file.";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	if(!inFile)
	{
		cout << "The input file could not be opened."<<endl;
	  	exit(0);
	}
	char ch;
	ch = inFile.get();
	string str="";
	for(int i=0;i<actual;i++)
	{
		str=str+ch;
		for(int k=h;k<127;k++)
		{
			if(pi[k].codw==str)
			{
				outfile<<pi[k].ch;
				str="";
			}
		}
		ch = inFile.get();
	}
	outfile.close();
	cout<<"\nGenerated 4_Finalizedfile.txt file!"<<endl;
	
}

void deta()
{
	ifstream iff;
	
	iff.open("ab.txt"); //enter Your input file path with name
	iff >> std::noskipws;
	char ch;
	int siz=0;
	while(iff>>ch)
	{
		siz++;
	}
	cout<<"\n\tFile Name\t|\tSize";
	cout<<"\n\t ab.txt||\t"<<siz<<"bytes";
	iff.close();
	iff >> std::noskipws;	
	iff.open("2_compressed.txt"); //enter Your input file path with name
	siz=0;
	while(iff>>ch)
	{
		siz++;
	}
	cout<<"\n\t2_compressed.txt||\t"<<siz<<"bytes";
	iff.close();
}

int main()
{
	int i,j,k,n;
	int sum_1=0,sum_2=0;
	int mind=10000;
	int t=0;
	int diff=0;
	int pt;
	n=127;
	rdfile();

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(pi[j].freq>pi[j+1].freq)
			{
				OP tmp;
				tmp=pi[j];
				pi[j]=pi[j+1];
				pi[j+1]=tmp;
			}
		}
	}
	int h;
	for(i=0;i<n;i++)
	{
		if(pi[i].freq!=0)
		{
			h=i;	
			break;
		}
	}

	for(i=h;i<n;i++)
	{
		cout<<i;
		pi[i].display();
	}	

	shan(h,n-1);
	ofstream codfile;//codeword file
	codfile.open("codfile.txt");
	
	for(i=h;i<n;i++)
	{
		codfile<<pi[i].ch<<" ||  Freq="<<pi[i].freq<<"  ||   Codeword="<<pi[i].codw<<endl;
		pi[i].cop();
	}
	codfile.close();
	wtfile(h);
	dcp();
	cout<<"ACTUAL==================================================="<<actual<<endl;
	fina();
	las(h);
	deta();
	return 0;
}
