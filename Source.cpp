#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<conio.h>
using namespace std;
vector <string> name;
vector <string> phoneNumber;
vector <string> address;
void list();
void addContact();
void deleteContact();
void search();
void editAContact();
int menu()
{
	system("cls");
	cout << "###########  CONTACT MANAGEMENT SYSTEM  ###########" << endl << endl << endl;
	cout << "       MAIN MENU" << endl;
	cout << "------------------------" << endl;
	
	cout << "1. List of contacts" << endl;
	cout << "2. Add a new contact" << endl;
	cout << "3. Delete a contact" << endl;
	cout << "4. Search a contact" << endl;
	cout << "5. Edit a contact" << endl;
	cout << "6. Exit a program" << endl;
	cout << "------------------------" << endl;
	cout << "Enter a number: ";
	int n;
	cin >> n;
	while (n < 1 || n>6)
	{
		cout << "invalid command try again: ";
		cin >> n;
	}
	switch (n) //chosing what to do in Menu
	{
	
	case 1:
		system("cls");
		list();//if input is 1 goto list of contacts
		break;
	case 2:
		system("cls");
		addContact(); //if input is 2 add contact
		break;
	case 3:
		system("cls");
		deleteContact(); //if input is 3 delete a contact
		break;
	case 4:
		system("cls");
		search(); // if input is 4 go to search
	case 5:
		system("cls");
		editAContact();
	case 6:
		return 0;
		
		
	}
	
}
void list()
{
	// my list of contacts is sorten in alphabet order so I used bubble sorting
	string temp; // temporary string for changind places

  
	if (name.size() == 0)
	{
		cout << "Your list is empty: ";
	}
	else
	{
		// sorting bubble sort,i agree that it is not the best sorting, but anyways it works
		for (int i = 0; i < name.size() - 1; i++)
		{
			for (int j = 0; j < name.size() - i - 1; j++)
			{
				if (name[j] > name[j + 1]) {
					// changes element places
					temp = name[j];
					name[j] = name[j + 1];
					name[j + 1] = temp;
					temp = phoneNumber[j];
					phoneNumber[j] = phoneNumber[j + 1];
					phoneNumber[j + 1] = temp;
					temp = address[j];
					address[j] = address[j + 1];
					address[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < name.size(); i++)
		{
			cout <<i+1<<". "<< name[i]<<endl; 
		}
		cout << "------------------------" << endl;
		cout << "press 0 to go to MAIN MENU" << endl;
		cout << "press any number to see a contact details";
		int b;
		cin >> b;
		while (b < 0 || b > name.size()) //validation check
		{
			cout << "invalid command try again: ";
			cin >> b;
		}
		if (b == 0) //goes to menu
		{
			system("cls");
			menu();
		}
		else //prints more info about person
		{
			system("cls");
			cout <<"Name: "<<name[b-1]<<endl;
			cout << "Phone number: " << phoneNumber[b-1] << endl;
			cout << "Address: " << address[b-1] << endl;
			cout << "------------------------" << endl;
			cout << "press 0 to go to MAIN MENU" << endl;
			cout << "press 1 to go to contacts list" << endl;
			
			int d;//command variable
			cin >> d;
			while ( d < 0 || d>1 )
			{
				cout << "invalid command try again: ";
				cin >> d;
			}
			if (d==0) // goes to menu
			{
				system("cls");
				menu();
			}
			else // goes to contacts list
			{
				system("cls");
				list();
			}
		}
	}
	cout << endl;
	cout<< "------------------------" << endl;
	cout << "press 0 to go to MAIN MENU" << endl;
	int a; //controll number
	cin >> a;
	if (a == 0)
	{
		system("cls");
		menu();
	}
	while (a != 0) //validation check
	{
		cout << "invalid command try again: ";
		cin >> a;
		if (a==0)
		{
			system("cls");
			menu();
		}
		break;
	}
	

}
void addContact()
{
	string a;//name to put into list
	cout << "Enter a name: ";
	cin >> a;
	for (int i = 0; i < a.size(); i++)//validation check for name
	{
		if (a[i] < 'A' || (a[i] > 'Z' && a[i] < 'a') || a[i]>'z')
		{
			cout << "you entered invalid name, please try again: ";
			cin >> a;
			i = 0;

		}
	}
	name.push_back(a);
	cout << endl;
	cout << "Enter a phone number: ";
	string b;//phone number
	cin >> b;
	for (int i = 0; i < b.size(); i++)//validation check for phone number
	{
		if (b[i]<'0' || b[i]>'9')
		{
			cout << "you entered invalid phone number, please try again: ";
			cin >> b;
			i = 0;

		}
	}
	phoneNumber.push_back(b);
	string c;//address. There is no validation check for address because it can contain numbers and letters also
	cout << "Enter an address: ";
	cin >> c;
	address.push_back(c);
	cout << "Your name has been added successfully!" << endl;
	cout<< "------------------------" << endl;
	cout << "press 0 to go to MAIN MENU" << endl;
	int e;//validation check
	cin >> e;
	if (e == 0)
	{
		system("cls");
		menu();
	}
	while (e != 0)
	{
		cout<<"invalid command try again: ";
		cin >> e;
		if (e == 0)
		{
			system("cls");
			menu();
		}
	}
}
void deleteContact()
{
	if (name.size() == 0)
	{
		cout << "Your list is empty: ";
	}
	else
	{
		cout << "Enter a name that you want to delete: ";
		string deleteName;
		cin >> deleteName;
		for (int i = 0; i < name.size(); i++) //loop to find match 
		{
			if (deleteName == name[i])
			{
				name.erase(name.begin() + i);
				address.erase(address.begin() + i);
				phoneNumber.erase(phoneNumber.begin() + i);
				cout << "Contact has been deleted successfully!" << endl;
			}
		}
		cout << "------------------------" << endl;
		cout << "press 0 to go to MAIN MENU" << endl;
		int e;//validation check
		cin >> e;
		if (e == 0)
		{
			system("cls");
			menu();
		}
		while (e != 0)
		{
			cout << "invalid command try again: ";
			cin >> e;
			if (e == 0)
			{
				system("cls");
				menu();
			}
		}
	}
}
void search()
{
	cout << "enter a name which you want to find: ";
	string searchName;
	cin >> searchName;
	bool f = 0;//bool to check wether name was found or not
	for (int i = 0; i < name.size(); i++) // loop to find match 
	{
		if (searchName == name[i])
		{
			f = 1;//if name was found we change condition of bool to true
			system("cls");
			cout << "Your name was found!" << endl;
			cout <<"Name: "<< name[i]<<endl;
			cout << "Number: " << phoneNumber[i]<<endl;
			cout << "address: " << address[i] << endl;
			break;
		}
	}
	if (f == 0)
	{
		cout << "Unfortunately we could not find your name in list"<<endl;
	}
	cout << "------------------------" << endl;
	cout << "press 0 to go to MAIN MENU" << endl;
	int e;//validation check
	cin >> e;
	if (e == 0)
	{
		system("cls");
		menu();
	}
	while (e != 0)
	{
		cout << "invalid command try again: ";
		cin >> e;
		if (e == 0)
		{
			system("cls");
			menu();
		}
	}
}
void editAContact()
{
	cout << "write a name that you want to edit: ";
	string a;
	cin >> a;
	for (int i = 0; i < name.size(); i++)
	{
		if (a == name[i])
		{
			cout << "Contact was found!"<<endl;
			cout << "------------------------" << endl;
			cout << "If you want to change a name press 1"<<endl;
			cout << "If you want to change number press 2"<<endl;
			cout << "If you want to change address press 3" << endl;
			
			int a;
			cin >> a;
			string newName;
			string newNumber;
			string newAddress;
			switch (a)
			{
			case 1: system("cls");
				cout << "Enter a new name: ";
				
				cin >> newName;
				for (int i = 0; i < newName.size(); i++)//validation check for name
				{
					if (newName[i] < 'A' || (newName[i] > 'Z' && newName[i] < 'a') || newName[i]>'z')
					{
						cout << "you entered invalid name, please try again: ";
						cin >> newName;
						i = 0;

					}
				}
				name[i] = newName;
				cout << endl;
				cout << "Name was edited succesfully!"<<endl;
				cout << "Press any key to continue" << endl;
				_getch();
				menu();
				break;
			case 2: system("cls");
				cout << "Enter a new phone number: ";
				
				cin >> newNumber;
				for (int i = 0; i < newNumber.size(); i++)//validation check for phone number
				{
					if (newNumber[i] < '0' || newNumber[i]>'9')
					{
						cout << "you entered invalid phone number, please try again: ";
						cin >> newNumber;
						i = 0;

					}
				}
				phoneNumber[i] = newNumber;
				cout << "Name was edited succesfully!" << endl;
				cout << "Press any key to continue" << endl;
				_getch();
				menu();
				break;

			case 3:
				system("cls");
				cout << "Enter a new address: ";

				cin >> newAddress;
				phoneNumber[i] = newNumber;
				cout << "Address was edited succesfully!" << endl;
				cout << "Press any key to continue" << endl;
				_getch();
				menu();
				break;
			}
			
		}
	}
	cout << "Name was not found! Press any key to continue";
	_getch();
	menu();

}

int main()
{
	system("Color 17");
	menu();
	system("pause");
	return 0;
}