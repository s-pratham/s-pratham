#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream mysign("D:/profile/signup.txt",ios::app);
	char name[50],email[50],pass[50],mob[15];
	cout<<"Enter Your name: ";
	cin>>name;
	cout<<"Enter Your Mobile Number: ";
	cin>>mob;
	cout<<"Enter Your email: ";
	cin>>email;
	cout<<"Enter Your Password: ";
	cin>>pass;
	mysign<<name<<" "<<mob<<" "<<email<<" "<<pass<<endl;
	mysign.close();
	
	return 0;
}
