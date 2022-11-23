#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <fstream>
using namespace std;

class shopping
{
	private:
	
		int pcode;
		int price;
		int dis;
		string pname;
	
	public:
		void menu(); 
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t________________________________________\n";
	cout<<"\t\t\t\t 									   \n";
	cout<<"\t\t\t\t         SUPER-MARKET Main Menu         \n";
	cout<<"\t\t\t\t 									   \n";
	cout<<"\t\t\t\t________________________________________\n";
	cout<<"\t\t\t\t 									   \n";
	cout<<"\t\t\t\t     1: Administrator   \n";
	cout<<"\t\t\t\t                        \n";
	cout<<"\t\t\t\t     2: Buyer           \n";
	cout<<"\t\t\t\t                        \n";
	cout<<"\t\t\t\t     3: Exit            \n";
	cout<<"\n\t\t\t\t     Select : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
				cout<<"\t\t\t\t________________________________________\n\n";
				cout<<"\t\t\t\t                  Login                 \n\n";
				cout<<"\t\t\t\t     Enter Email  : ";
				cin>>email;
				cout<<"\t\t\t\t     PassWord     : ";
				cin>>password;
				
				if(email=="pps@" && password=="123")
				{
					administrator();
				}
				else 
				{
					cout<<"\t\t\t\t       Invalid Email 0r password        \n\n";
				}
				break;
			}
		case 2:
			{
				buyer();
			}
		case 3:
			{
				exit(0);
			}
		default:
			{
				cout<<"\t\t\t\t     Please select from given option    \n\n";
			}
	}
	goto m;
}

void shopping :: administrator()
{
	m:
	int choice;
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t           Administrator Menu           \n\n";
	cout<<"\t\t\t\t     1: Add the Product    \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\t\t\t\t     2: Modify the Product \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\t\t\t\t     3: Delete the Product \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\t\t\t\t     4: Back to Main Menu  \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\n\t\t\t\t     Select : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: add();
				break;
		case 2: edit();
				break;
		case 3: rem();
				break;
		case 4: menu();
				break;
		default: cout<<"\n\t\t\t\t       Invalid choice      \n";
				break;
	}
	goto m;
} 

void shopping :: buyer()
{
	m:
	int choice;
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t                 BUYER                  \n\n";
	cout<<"\t\t\t\t     1: Buy Product        \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\t\t\t\t     2: Go Back            \n";
	cout<<"\t\t\t\t                           \n";
	cout<<"\n\t\t\t\t     Select : ";
	cin>>choice;
	
	
	switch(choice)
	{
		case 1: receipt();
				break;
		case 2: menu();
				break;
		default: cout<<"\n\t\t\t\t        *Invalid choice      \n";
				break;
	}
	goto m;
}

void shopping :: add()
{
	m:
	fstream data;
	
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t             Add new Product            \n\n";
	cout<<"\t\t\t\t     Product Code         : ";//5-4
	cin>>pcode;
	cout<<"\t\t\t\t     Name of the Product  : ";
	cin>>pname;
	cout<<"\t\t\t\t     Price of the Product : ";
	cin>>price;
	cout<<"\t\t\t\t     Discount on Product  : ";
	cin>>dis;
	if(pcode==-1)
	{
		cout<<"\t\t\t you are moving back to previous menu\n";
		return;
	}
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		// cout<<"************************add () if(!data)";
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else 
	{
		// cout<<"************************ ELSE PART ";
		
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();		
	
		if(token==1)
		{
		cout<<"\t\t\t duplicate item code, please use different item code\n";
		goto m;
		}	
		else
		{
			data.open("database.txt", ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
		}
	}
	cout<<"\t\t\t\t     Record Inserted   \n";
}
void shopping :: edit()
{
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t           Modify the Recored           \n\n";
	cout<<"\t\t\t\t     Product Code         : ";//5-4
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout<<"File not exist!";
	}
	else 
	{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\t\t\t\t     Product New Code     : ";//5-4
				cin>>c;
				cout<<"\t\t\t\t     Name of the Product  : ";
				cin>>n;
				cout<<"\t\t\t\t    Price of the Product : ";
				cin>>p;
				cout<<"\t\t\t\t     Discount on Product  : ";
				cin>>d;

				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\t\t\t\t     Record Edited   \n";
				token++;
			}
			else 
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt" , "database.txt");
		
		if(token==0)
		{
			cout<<"\t\t\t\t       Record Not Found Sorry!!!        \n";
		}
	}
}

void shopping :: rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t             Delete Product             \n\n";
	cout<<"\t\t\t\t        Product Code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout<<"\t\t\t\t           File not exist!            \n";
	}
	else 
	{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\t\t\t\t     Product Delete Succesfully   \n";
				token++;
			}
			else 
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt" , "database.txt");
		
		if(token==0)
		{
			cout<<"\t\t\t\t     Record Not Found Sorry!!!   \n";
		}
	}
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
		
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\tProNo \t\tName \t\tPrice                \n";
	cout<<"\t\t\t\t========================================\n\n";
	
	data>>pcode>>pname>>price>>dis;
	
	while(!data.eof())
	{
		cout<<"\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping :: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	
	cout<<"\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t               --BUY--              \n\n";

	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nEmpty Database";
	}
	else 
	{
		data.close();
		
		list();

		cout<<"\t\t\t\t________________________________________\n\n";
		cout<<"\t\t\t\t            Place the  Order            \n\n";
		cout<<"\t\t\t\t________________________________________\n\n";
		
		do
		{
			m:	
			cout<<"\t\t\t\t________________________________________\n\n";
			cout<<"\t\t\t\t     Enter Product Code     : ";
			cin>>arrc[c];
			cout<<"\t\t\t\t                                          \n";
			cout<<"\t\t\t\t     Enter Product Quantity : ";
			cin>>arrq[c];
			
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\t\t\t\t                                          \n";
					cout<<"\t\t\t\t Duplicate Product Code. Please Try Again!\n";
					goto m;
				}
			}
			c++;
			cout<<"\t\t\t\t    Do you want to buy another product?   \n";
			cout<<"\t\t\t\t    If yes then press 'y' else No 'n' : ";
		  	cin>>choice;
		}
		while(choice=='y' || choice=='Y');
		
		cout<<"\t\t\t\t________________________________________\n\n";
		cout<<"\t\t\t\t                 RECEIPT                \n\n";
		cout<<"\t\t\t\tProNo\tName\tQuality\tPrice\tAmount\tAfter_Discount\n";

		for(int i=0;i<c;i++)
		{
			// cout<<"\nc is "<<c<<"\tarrc[i]:"<<arrc[i]<<"\tarrq[i]:"<<arrq[i]<<"\ti:"<<i<<"\n";
			
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n\t\t\t\t"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
			
			data.close();
		}
	}
	cout<<"\n\t\t\t\t________________________________________\n\n";
	cout<<"\t\t\t\t Total Amount : "<<total<<"\n";
}

int main()
{
	shopping s ;
	s.menu();
}














