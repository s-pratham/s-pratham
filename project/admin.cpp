#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<conio.h>
using namespace std;

int qty[100];
int a=1,i;
float price[100];
char pname[50][50];

void getproduct(char* v)//To extract product details from text file
{
	fstream p;
	p.open(v,ios::in);//in is used to open file in read mode
	a=1;
	while(!p.eof())//eof() gives non zero(1) output when end of file is occurs
	{
		p>>pname[a];
		cout<<"\t\t"<<a<<" >> "<<pname[a]<<"\t";
		p>>price[a];
		cout<<price[a]<<endl;
		p>>qty[a];
		a++;
	}
	p.close();
}

void updateproduct(int p,int opr,char* v)
{
	if(opr==1)
	{
		float newprice;
		cout<<"Current Price of Product: "<<price[p]<<endl;
		cout<<"Enter new price to change: ";
		cin>>newprice;
		price[p]=newprice;
		cout<<"\nNew price of product: "<<price[p];
		cout<<"\nPress any key to continue...";
		getch();
	}
	
	else if(opr==2)
	{
		int tempqty,q;
		cout<<"Current quantity of product: "<<qty[p]<<endl;
		cout<<"How many quantity you want to add: ";
		cin>>q;
		tempqty=qty[p];
		qty[p]=tempqty+q;
		cout<<"\nNew quantity of product: "<<qty[p];
		cout<<"\nPress any key to continue...";
		getch();
	}
	
	
	fstream s;
	s.open(v);
	for(i=1;i<a-1;i++)
	{
		s<<pname[i]<<" "<<price[i]<<" "<<qty[i]<<endl;
	}
	s.close();
}

int main()
{
	int ch,op,spro;
	char name[50],mob[15],id[50],pass[50];
	char path1[]="D:/project/Mobile.txt";
	char path2[]="D:/project/TV.txt";
	char path3[]="D:/project/Laptop.txt";
	
	cout<<"Welcome Admin...\n";
	sleep(3);
	do
	{
		system ("CLS");
		cout<<"Menu:\n1)Change price of product\n2)change quantity of product\n3)Display users details\n4)Add a product\n5)Exit from admin mode\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Change price of product\n";
					cout<<"Select Category: \n1)Mobile\t2)TV\n3)Laptop\nEnter selected Category: ";
					cin>>op;
					if(op==1)
					{
						getproduct(path1);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,1,path1);
					}
					else if(op==2)
					{
						getproduct(path2);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,1,path2);
					}
					else if(op==3)
					{
						getproduct(path3);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,1,path3);
					}
					break;
			case 2:cout<<"change quantity of product";
					cout<<"Select Category: \n1)Mobile\t2)TV\n3)Laptop\nEnter selected Category: ";
					cin>>op;
					if(op==1)
					{
						getproduct(path1);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,2,path1);
					}
					else if(op==2)
					{
						getproduct(path2);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,2,path2);
					}
					else if(op==3)
					{
						getproduct(path3);
						cout<<"\nSelect product to change price: ";
						cin>>spro;
						updateproduct(spro,2,path3);
					}
					break;
			case 3:{
				cout<<"Display users details\n";
					fstream user;
					user.open("D:/project/signup.txt");
					cout<<"Name\tMobile\tID\t\tPass\n";
					while(!user.eof())
					{
						user>>name;
						user>>mob;
						user>>id;
						user>>pass;
						cout<<name<<"\t"<<mob<<"\t"<<id<<"\t"<<pass<<endl;
					}
					user.close();
					break;
				}
			case 4:cout<<"Add a product";
					break;
			case 5:cout<<"Exit";
					getch();
					break;
			default:cout<<"Invalid choice...";
					break;
		}
	}while(ch!=5);
	
	return 0;
}
