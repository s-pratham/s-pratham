#include<iostream>
#include<fstream>//file handling
#include<unistd.h>//sleep();
#include<iomanip>//setw();
#include<string>//strcmp();
#include<conio.h>//getch();
using namespace std;
int i,j=0;
class shop
{
	public:
		int qty[50];
		float price[50];
		char pname[50][50];
		
		
		void getproduct(char* v)//To extract product details from text file
		{
			fstream p;
			p.open(v,ios::in);//in is used to open file in read mode
			int a=1;
			while(!p.eof())//eof() gives non zero(1) output when end of file is occurs
			{
				p>>pname[a];
				cout<<"\t\t"<<a<<" >> "<<left<<setw(65)<<pname[a];
				p>>price[a];
				cout<<price[a]<<endl;
				p>>qty[a];
				a++;
			}
			p.close();
		}
		
		
		
};
class cart
{
	public:
		string cart[50];
		float cprice[50];
		float total;
		int cqty[50];
		void addcart(string name,float price,int quantity)//product is getting added into the cart
		{
			j++;
			cart[j]=name;
			cprice[j]=price;
			cqty[j]=quantity;
		}
		void showcart()//displaying the products in cart
		{
			for(i=1;i<=j;i++)
			{
				cout<<left<<setw(55)<<cart[i]<<cprice[i]<<"\t"<<cqty[i]<<endl;
			}
		}
		float buycart()//Calculating total of products in cart
		{
			float temp;
			for(i=1;i<=j;i++)
			{
				
				temp=cprice[i]*cqty[i];
				total=total+temp;
			}
			return total;
		}
		void printcartbill(string bname,string bmob,float t)//displaying cart bill
		{
			cout<<"================================================================================";
			cout<<endl<<"\t\t\t\t\tBill\n";
			cout<<"================================================================================\n";	
			float total=t;
			cout<<"Item\t\t\t\tPrice\tQuantity\n";
			for(i=1;i<=j;i++)
			{
				cout<<cart[i]<<"\t"<<cprice[i]<<"\t"<<cqty[i]<<endl;
			}
			cout<<"Total: "<<total;
			cout<<"\nBuyer's Name: "<<bname<<"\nMobile: "<<bmob<<endl;
			j=0;
		}
};
void getaddress(char* eid)//getting the address from file of a specific user
{
	fstream myadd;
	myadd.open("D:/profile/address.txt");
	char address[100],checkid[50];
	int z=0;
	do
	{
		myadd>>checkid;
		myadd>>address;
		if(strcmp(checkid,eid)==0)
			z=1;
	}while(z!=1);
	cout<<address;
}
/*void addaddress(string id)
{
	ofstream myadd("D:/profile/address.txt",ios::app);
	char address[100];
	cout<<"Enter Your address: ";
	cin>>address;
	myadd<<id<<" "<<address<<endl;
	myadd.close();
}*/
float getbill(string name,float price,int quantity)//calculating total price of a purchased product
{
	float total;
	total=price*quantity;
	return total;
}
void printbill(string name,float price,int quantity,string bname,string bmob)//displaying purchased product's bill
{
	cout<<"================================================================================";
	cout<<endl<<"\t\t\t\t\tBill\n";
	cout<<"================================================================================\n";	
	float total;
	total=price*quantity;
	cout<<"Item\t\t\t\tPrice\tQuantity\n";
	cout<<name<<"\t"<<price<<"\t"<<quantity<<endl;
	cout<<"Total: "<<total;
	cout<<"\nBuyer's Name: "<<bname<<"\nMobile: "<<bmob<<endl;
}
int main()
{
	shop a[5];
	cart b;
	float pay,cpay;
	int ch,op,f,end,ops,pch,bch,bop,addqty,buyqty;
	char mch;
	char oname[50],omob[15],oid[50],opass[50];
	char id[50],pass[50];
	char path1[]="D:/profile/Snacks.txt";
	char path2[]="D:/profile/Beverages.txt";
	char path3[]="D:/profile/Dairy.txt";
	char path4[]="D:/profile/Care.txt";
	
	string upiid,upipin,card;
	string category[5];
	category[1]="Snacks";
	category[2]="Beverages";
	category[3]="Dairy Products";
	category[4]="Personal Care";
	
	cout<<">>>>>>>>>>>>>>>>>>>>>>>> Welcome <<<<<<<<<<<<<<<<<<<<<";
	sleep(3);//sleeps for 3 second
	
	open:system ("CLS");
	cout<<"\t\t\t\t||``````````````````````````````````````````````||";
	cout<<"\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\t\tS: Sign up\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\t\tL: Log in\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\t\tE: Exit\t\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t  \t\tWhat to do: ";
	cin>>mch;
	switch(mch)
	{
		case 's':
		case 'S':{cout<<"\n\t\t\t\t::~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~::\n\t\t\t\t::\t\t\tSignup\t\t\t::\n";
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
				cout<<"\nThanks for sign up\nPress any key to continue...";
				getch();
				goto main;
			}//jump to case lable -fpermissive error(contents of this case is visible to other cases)
		case 'l':
		case 'L':{cout<<"\n\t\t\t\t::~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~::\n\t\t\t\t::\t\t\tLogin\t\t\t::";
				log:fstream omysign;
				omysign.open("D:/profile/signup.txt");
				cout<<"\n\n\t\t\t\t\tEnter Email: ";
				cin>>id;
				cout<<"\n\n\t\t\t\t\tEnter Password: ";
				cin>>pass;
				do
				{
					omysign>>oname;
					omysign>>omob;
	
					omysign>>oid;
					omysign>>opass;
					
					end=omysign.eof();
					if(f==0 && end!=0)
					{
						cout<<"\n\n\t\t\t\t\tEnter Correct email and password...";
						goto log;
					}
					
					if((strcmp(oid,id)!=0) || (strcmp(opass,pass)!=0))
					{
						f=0;
					}
					else if((strcmp(oid,id)==0) && (strcmp(opass,pass)==0))
						f=1;
					
					
				}while(f==0);
				omysign.close();
				cout<<"\n\n\t\t\t\t\t\tLogin Successfully...\n\n\t\t\t\t\t\tPress any key to continue...\n\t\t\t\t::~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~::";
				
				getch();
				goto main;
			}
		case 'e':
		case 'E':cout<<"exit";
				goto exit;
				
		default:printf("\nEnter Correct Charecter...");
				break;
	}
	
	
	
	main:system ("CLS");
	do
	{
		cout<<"=====================================================================================================================\n";
		cout<<"\t\t\t\t\t\t\tMenu: \n";
		cout<<"=====================================================================================================================\n";
		cout<<"\n\t\t\t\t\t\t1)Profile\n\n\t\t\t\t\t\t2)Cart\n\n\t\t\t\t\t\t3)Categories\n\n\t\t\t\t\t\t4)Log out\n\n\t\t\t\t\t\tEnter Your Choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:system ("CLS");
					cout<<"\t\t\t\t\t\tProfile\n\t\t\t\t _______________________________________________\n\t\t\t\t|\t\t\t\t\t\t|";
					cout<<"\n\t\t\t\t|\tName: "<<oname<<"\t\t\t\t|"<<endl<<"\t\t\t\t|\tMobile: "<<omob<<"\t\t\t|"<<endl<<"\t\t\t\t|\tEmail: "<<oid<<"\t\t|"<<endl<<"\t\t\t\t|\tAddress: ";	
					getaddress(oid);
					cout<<"\t|\n\t\t\t\t|_______________________________________________|"<<endl;
					cout<<"\n\t\t\t\tEnter 9 to go to menu  or  0 to exit: ";
					cin>>op;
					if(op==9)
					{
						goto main;
					}
					else if(op==0)
					{
						ch=4;
					}
					break;
			case 2: cart:system ("CLS");
					cout<<left<<setw(55)<<"Cart\nProduct"<<"   Price  Quantity\n";
					b.showcart();
					
					cout<<"\nPress 1 to buy all products in cart\nEnter 9 to go to menu or 0 to exit";
					cin>>op;
					if(op==9)
					{
						goto main;
					}
					else if(op==0)
					{
						ch=4;
					}
					else if(op==1)
					{
						cpay=b.buycart();
						if(cpay>0)
							goto buy;
						else if(cpay==0)
							cout<<"Cart is empty\nPress any key to continue...";
						getch();
					}
					break;
			case 3:do
					{
						category:system ("CLS");
						cout<<"Shop by Categories\n";
						cout << left << setw(20) << "1)Snacks" << setw(20) << "2)Beverages" << '\n';
						cout << left << setw(20) << "3)Dairy Products" << setw(20) << "4)Personal Care" << '\n';
						cout<<"Enter 9 to go to menu\tor\t0 to exit";
						cout<<"\nEnter your choice:";
						cin>>op;
						if(op==9)
						{
							goto main;
						}
						else if(op==0)
							ch=4;
									do
									{
										
										system ("CLS");
										cout<<"\t\t\t\t\t\t"<<category[op]<<endl;
										cout<<left<<setw(65)<<"\n\t\t\tProducts"<<"Price\n";
										if(op==1)
											a[op].getproduct(path1);
										else if(op==2)
											a[op].getproduct(path2);
										else if(op==3)
											a[op].getproduct(path3);
										else if(op==4)
											a[op].getproduct(path4);
										cout<<"\nChoose a product: (Enter 99 to go to menu  or  0 to exit)";
										cin>>pch;
										if(pch==99)
											goto category;
										else if(pch==0)
											goto exit;
										else if(a[op].qty[pch]>0)
										{
											product:system ("CLS");
											cout<<"Name: "<<a[op].pname[pch]<<"\nprice"<<a[op].price[pch];
											cout<<"\nProduct is in stock...";
											cout<<"\n1)Add to cart\n2)Buy Now\n(Enter 9 to go to menu  or  0 to exit)\nEnter choice:";
											cin>>bch;
											if(bch==1)
											{
												cout<<"How much quantity of product you want to add to cart: ";
												cin>>addqty;
												b.addcart(a[op].pname[pch],a[op].price[pch],addqty);
											}
											
											else if(bch==2)
											{
												cout<<"\nHow much quantity you want to buy: ";
												cin>>buyqty;
												pay=getbill(a[op].pname[pch],a[op].price[pch],buyqty);
												buy:do
												{
													cout<<"\nBuying options:-\n1)UPI\n2)Debit/Credit Cards\n3)Cash on Delivery\nPress 0 to cancle buying\nEnter your choice:";
													cin>>bop;
													if(bop==0 && pay>0)
														goto product;
													else if(bop==0 && cpay>0)
														goto cart;
													switch(bop)
													{
														case 1:cout<<"UPI";
																if(pay>0)
																	cout<<"\nAmount to pay: "<<pay;
																else if(cpay>0)
																	cout<<"\nAmount to pay: "<<cpay;
																cout<<"\nEnter UPI id: ";
																cin>>upiid;
																cout<<"\nEnter UPI PIN: ";
																cin>>upipin;
																cout<<"\nProcessing Payment...";
																sleep(5);
																cout<<"\n\nPayment Successful!\n";
																cout<<"Press any key to Print Bill...";
																getch();
																system("CLS");
																if(pay>0)
																{
																	printbill(a[op].pname[pch],a[op].price[pch],buyqty,oname,omob);
																	pay=0;
																}
																else if(cpay>0)
																{
																	b.printcartbill(oname,omob,cpay);
																	cpay=0;
																}
																cout<<"Press any key to continue...";
																getch();
																goto main;
																break;
														case 2:cout<<"Cards";
																cout<<"Enter Card Details: ";
																cin>>card;
																cout<<"\nProcessing Payment...";
																sleep(5);
																cout<<"\n\nPayment Successful!\n";
																cout<<"Press any key to Print Bill...";
																getch();
																system("CLS");
																if(pay>0)
																{
																	printbill(a[op].pname[pch],a[op].price[pch],buyqty,oname,omob);
																	pay=0;
																}
																else if(cpay>0)
																{
																	b.printcartbill(oname,omob,cpay);
																	cpay=0;
																}
																cout<<"Press any key to continue...";
																getch();
																goto main;
																break;
														case 3:cout<<"Cash on Delivery\nProduct Shipped...";
																cout<<"Press any key to Print Bill...";
																getch();
																system("CLS");
																if(pay>0)
																{
																	printbill(a[op].pname[pch],a[op].price[pch],buyqty,oname,omob);
																	pay=0;
																}
																else if(cpay>0)
																{
																	b.printcartbill(oname,omob,cpay);
																	cpay=0;
																}
																cout<<"\nPress any key to continue...";
																getch();
																goto main;
																break;
														default:cout<<"\nInvalid option";
																break;
													}
													
												}while(bop!=0);
											}
											else if(bch==0)
												goto exit;
											
											
										}
										
										else
										{
											cout<<"\nProduct is out of stock...";
										}
										cout<<"\nPress any key to continue...";
										getch();
									}while(pch!=9 || pch!=0);
									
					}while(op!=0 || op!=9);
					break;
			case 4:system ("CLS");
					cout<<"Log out!";
					goto open;
			default:
					cout<<"Invalid Choice!";
					break;
					
		}
		
	}while(ch!=4);
	
	exit:system ("CLS");
	cout<<"-----------X-----------Exit------------X------------";
	
	return 0;
}
