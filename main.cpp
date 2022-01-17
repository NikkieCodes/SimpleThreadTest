#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <thread>

#pragma warning(disable: 4996)

using namespace std;

class User
{
public:

	string filename;

	void SaveRegister(int id, string username, int age)
	{

		ofstream DataFile("data/" + filename + ".ndev", ios_base::out);

		DataFile << "id: " << id << endl;
		DataFile << "username: " << username << endl;
		DataFile << "age: " << age << endl;

		DataFile.close();
	}
};

class Main
{
public:
	static void RegisterUser()
	{
		User UserObj;
		Files FileObj;

		string userid;
		string userage;
		string name;

		printf("ID: ");
		getline(cin, userid);

		printf("What's your name: ");
		getline(cin, name);

		UserObj.filename = name + "#" + userid;
		string fname = UserObj.filename;

		thread CreateFileThread(FileObj.CreateFile, fname);
		CreateFileThread.join();

		printf("How old are you: ");
		getline(cin, userage);

		UserObj.SaveRegister(stoi(userid), name, stoi(userage));
	}
};

class Files
{
public:
	static void CreateFile(string Fname)
	{
		ofstream NewUserFile("data/" + Fname + ".ndev");
		NewUserFile.close();
	}
};

int main()
{
	Main MainObj;

	string command;

	string Options[2] = { "Add User", "View User"};

	printf("Welcome!\n");
	printf("Please select an option from the menu below: \n");
	
	int x = 0;

	for (int i = 0; i < sizeof(Options) / sizeof(Options[0]); i++)
	{
		x++;

		cout << x << ". " << Options[i] << endl;
	}

	printf(">>> ");
	getline(cin, command);

	if (command == "Add User" || command == "1")
	{
		thread register_user(MainObj.RegisterUser);
		register_user.join();
	}
}