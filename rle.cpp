#include "rle.h"
#include<string>
using namespace std;
// Constructor
rle::rle(int gamma): gamma(gamma){}
int power(int x,int y)
{
	int ans=1;
	for(int i=0;i<y;i++)
	{
		ans=ans*x;
	}
	return ans;

}
// Convert integer to gamma-bit binary string
string rle::f(int i)
{ 
 	int A[gamma];
 	string x;
 	string l;
 	string j;
 	for(int k=0;k<gamma;k++)
	{
		l=l+to_string(1);
	}
	for(int k=0;k<gamma;k++)
	{
		j=j+to_string(0);
	}
 	if(i<=(power(2,gamma)-1))
	{
		for(int j=1;j<=gamma;j++)
		{
			
			A[gamma-j]=i%2;
			i=i/2;
		}
		for(int k=0;k<gamma;k++)
		{
			x=x+to_string(A[k]);
		}
	}
	else
	{
		int n=i/(power(2,gamma)-1);
		for(int m=0;m<n;m++)
		{
			x=x+l;
			x=x+j;
		}
		i=i%(power(2,gamma)-1);
		x=x+rle().f(i);
	}
	
	
	return x; 
}

// Convert gamma-bit binary string to integer
int rle::g(string i)
{ 
	int bin=0;
	int l=i.size();
	if(l==gamma)
	{
		for(int k=0;k<gamma;k++)
		{
			bin=bin+power(2,k)*(i[gamma-k-1]-'0');
		}
	}
	else
	{
		int full=0;
		for(int k=0;k<gamma;k++)
		{
			full=full+power(2,k)*('1'-'0');
		}
		int no=(l-4)/8;
		bin=bin+full*no;
		string ne;
		for(int k=0;k<gamma;k++)
		{
			ne+=to_string(i[l-gamma+k]-'0');
		}
		bin=bin+rle().g(ne);
	}
	return bin;
}

// Compress the input file
string rle::compress(string input_string)
{ 
	string out;
	out+=to_string(input_string[0]-'0');
	int l=input_string.size();
	int count=1;
	for(int i=0;i<l-1;i++)
	{
		if(input_string[i]-'0'==input_string[i+1]-'0')
		{
			count++;
		}
		else
		{
			out=out+rle().f(count);
			count=1;
		}	
	}	
	out=out+rle().f(count);
	return out;
}

string rle::decompress(string input_string)
{
	int l=input_string.size();
	string ori;
	string m;
	char zee;
	// ori+=to_string(input_string[0]-'0');
	zee=input_string[0];
	if(zee=='0'){m+='1';}
	else{m+='0';}
	int check=0;
	// check0 print zee else print m
	string sub;
	int jtk=0;
	while(jtk<l-gamma+1)
	{
		for(int k=jtk;k<gamma+jtk;k++)
		{
			sub+= to_string(input_string[k+1]-'0');
		}
		if(rle().g(sub)<=(power(2,gamma)-1))
		{
			if(check==0)
			{
				check=1;
				for(int h=0;h<rle().g(sub);h++)
				{
					ori+=zee;
				}
				
			}
			else
			{
				check=0;
				for(int h=0;h<rle().g(sub);h++)
				{
					ori+=m;
				}
				
			}
		}
		sub="";
		jtk=jtk+4;
	}
	return ori;
}