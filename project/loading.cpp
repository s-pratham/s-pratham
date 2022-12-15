#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main()
{
	int n=20,a=0;
	char incomp=' ',comp='/';
	do
	{
		n--;
		a++;
		system("CLS");
		cout<<"\t\tLoading...\n";
		cout<<"\t( ";
		for(int i=0;i<a;i++)
		{
			cout<<comp;
		}
		for(int i=0;i<n;i++)
		{
			cout<<incomp;
		}
		cout<<" )";
		
		cout<<endl;
		this_thread::sleep_for(chrono::milliseconds(90));
	}while(n!=0);
	
	
	return 0;
}
