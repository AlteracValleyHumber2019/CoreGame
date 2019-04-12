// NetworkLibImplementationEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <NetworkLib/UDP_Client.h>
#include <NetworkLib/TCP_Client.h>
#include <NetworkLib/TCP_Server.h>
#include <NetworkLib/UDP_Server.h>
#include <NetworkLib/sha256.h>
#include <NetworkLib/DatabaseConnection.h>
#undef main

using namespace std;

int main(int arg, char* argc[])
{
    std::cout << "Hello World!\n"; 
	TCP_Client client = TCP_Client();
	UDP_Client uclient = UDP_Client();

	bool DBsuccess = true;
	DataBaseConnection dbcon = new DataBaseConnection(DBsuccess);

	if (DBsuccess)
	{
		bool connected = false;
		while (!connected)
		{
			system("CLS");

			cout << "Enter your Username OR Email : ";
			string user;
			cin >> user;


			string pass = "";
			char ch;
			cout << "Enter your Password : ";
			ch = _getch();

			//Character 13 is the enter key
			while (ch != 13) {
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
					ch = _getch();
				}
				else
				{
					if (pass.size() >= 1)
					{
						pass = pass.substr(0, pass.size() - 1);
						cout << "\b \b";
						ch = _getch();
					}
					else
						ch = _getch();
				}
			}

			//We are using SHA256 encryption on the website.
			//TODO: Encrypt the password

			cout << endl;

			//Prints out the query sent to the server for reference purposes
			string query1 = "SELECT * FROM players WHERE (player_name = '" + user + "') OR (player_email = '" + user + "')";
			cout << "Query from the server : " + query1 << endl;
			system("PAUSE");

			MYSQL_RES* res = dbcon.fetchInformation(query1);
			MYSQL_ROW row;

			//row will be FALSE if no result is found
			if (row = mysql_fetch_row(res))
			{
				//We will get only 1 line as a result
				//Data is stored as... ID, name, pass, email
				//TODO: Compare the hashed value
				if (pass == row[2])
				{
					cout << "Connected to the server succesfully under : " + user + " !" << endl;
					connected = true;
				}
				else
					cout << "Incorrect password, try again" << endl;

				//Will retry unless connection is succesful
				system("PAUSE");

			}
			else
			{
				//User not found in database
				cout << "Could not find username or email in the database... ";
				system("PAUSE");
			}


		}

	}
	else
	{
		cout << "Terminating Program, connection not established | Contact an administrator" << endl;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
