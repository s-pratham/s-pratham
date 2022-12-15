#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int random[50];
	int ran;
	int mran;
	srand(time(NULL));
	for(int i=0;i<50;i++)
	{
		ran=rand()%50;
		random[i]=rand()%10000;
		if(random[ran]>999&&random[ran]<10000)
			mran=random[ran];
	}
	fstream o;
	o.open("D:/project/OTP.txt");
	o<<mran;
	o.close();
	cout<<"\nOTP Generated Successfully...\n";
	return 0;
}
