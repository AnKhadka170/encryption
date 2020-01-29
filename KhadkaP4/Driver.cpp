// Name: Anu Khadka
// Email ID: akhadka@cnm.edu
// Program Name: Project4

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>


using namespace std;

// Defining Prototypes

void Header();
int GetCodeInteger();
string AskForString();
string AskForEncryptedMessage();
string Encoder(int Key, string SecretMessage);
string Decoder(int Key, string CodedMessage);


int main()
{
	char Choice = 'y';
	int CodingChoice;
	string SecretMessage, CodedMessage;
	string SecretMessage1, CodedMessage1;
	string EncryptedMsg, DecryptedMsg;

	Header(); // display function is called to print infos in console

	//To get a random number based on local time//
	srand((unsigned)time(NULL));


	do // if user wants to go another round
	{

		int CodeKey = GetCodeInteger(); // assiging the key value from the function to CodeKey varaibale

		//Asking the user whether he wants to encode or decode the message

		cout << endl << " Do you want to Encode or Decode a secret message?" << endl;
		cout << endl << "Choose either (1) or (2) as 0ptions" << endl << "1) Enter 1 for Encryption.";
		cout << endl << "2) Enter 2 for Decryption." << endl;
		cout << endl << "You have choosen : ";
		cin >> CodingChoice;
		cin.ignore();

		if (CodingChoice == 1)//encode choice
		{
			cout << endl << "Great!! You want your Secret Message to : Encrypt ";
			cout << endl << "Encryption is in Process...." << endl;
			EncryptedMsg = Encoder(CodeKey, SecretMessage); // encrypted function is called for encoding
		}

		else if (CodingChoice == 2) // Decode the choice
		{
			cout << endl << "Great!! You want your Secret Message to : Decrypt ";
			cout << endl << "Decryption is in Process......" << endl;
			CodedMessage = AskForEncryptedMessage();
			DecryptedMsg = Decoder(CodeKey, CodedMessage);

		}

		else // if the user choses the option other than the valid options 1 and 2.
		{

			cout << endl << "You have choosen an invalid option. Please try again";
			cout << endl << "Do you want to Encode or Decode a secret message?" << endl;
			cout << endl << "Choose either(1) or (2) as options";
			cout << endl << "1) Enter 1 for Encryption.";
			cout << endl << "2) Enter 2 for Decryption." << endl;
			cout << endl << "You have choosen : ";
			cin >> CodingChoice;
		}
		cout << endl << "\nDo you want to do another round?(Y/N) : "; // if user wants to go for another round
		cin >> Choice;
		cin.ignore();

	} while (Choice == 'y');

	if (Choice == 'n') // if user wants to exit the program
	{
		cout << endl << "You are exiting this program.";
		cout << " See you soon. Have a good day." << endl;
	}

	return 0;
}

void Header()
{
	cout << "***************************************************************************************************************" << endl;
	cout << "Name : Anu Khadka" << endl;
	cout << "Program Title : KhadkaP4" << endl;
	cout << "File Name : Driver.cpp" << endl;
	cout << "Program Objective : Coding for Encrytption and Decryption " << endl;
	cout << "***************************************************************************************************************" << endl;

}

int GetCodeInteger() //function to get the key number for either encryption or decryption
{
	int Key;
	string CodedMessage, SecretMessage;
	char MyChoice;
	int Comp_Key, User_Key;    //Variables Declaration


	//Providing choice to user to input a code integer or have it randomly determined by the program

	cout << endl << "Do you want computer to generate a random key for you? (Y/N) : ";
	cin >> MyChoice;
	cin.ignore();

	if (MyChoice == 'y') // for computer generated key value which changes with time
	{
		cout << endl << "You have opted for computer's choice of key" << endl;
		Comp_Key = rand() % 35 + 1;
		cout << "Computer has choosen " << Comp_Key << " as a key number." << endl;
		Key = Comp_Key; //Assigning computer choosen key value to another variable called Key

	}

	else if (MyChoice == 'n') // if the user wants to put his own key value
	{
		cout << endl << "You have opted for User's Choice key number." << endl;
		cout << "Choose the key number (Number must be between 1 and 35) : ";
		cin >> User_Key;
		Key = User_Key; //Assigning User'key value to another variable called Key

		cout << endl << "You have choosen " << User_Key << " as a key number." << endl;
	}
	else // if user chosses neither of the given option, loop runs again
	{
		cout << endl << "You have choosen an invalid option. Please try again";
		cout << endl << "Do you want computer to generate a random key for you? (Y/N) : ";
		cin >> MyChoice;
		cin.ignore();
	}


	return Key;
}

string AskForString() //ask for the message to be encoded
{
	string SecretMessage;

	cout << endl << "Enter the secret message you want to encode:" << endl;
	cout << "Secret Message : ";
	getline(cin, SecretMessage);


	return SecretMessage;


}

string AskForEncryptedMessage() // ask for the encrypted message to be decoded
{
	string CodedMessage;

	cout << endl << "Enter the coded message you want to decode" << endl;;
	cout << "Coded Message : ";
	getline(cin, CodedMessage);




	return CodedMessage;

}

string Encoder(int Key, string SecretMessage) //Function for Encryption
{
	string EncryptedMsg;
	int x = 0;
	char temp[50];
	SecretMessage = AskForString(); // ask for string function is called and stored as SecretMessage
	cout << endl << "Secret Message = " << SecretMessage;
	cout << endl << "Encryption Key : " << Key;

	cout << endl << "Hence, Your Encrypted Message : ";

	while (SecretMessage[x] != '\0') //loop runs till each character os the string exists

	{

		if (int(SecretMessage[x]) + Key < 32) //to test whether each character is in uppercase or lowercase
		{
			EncryptedMsg = ((int(SecretMessage[x]) + Key) + 127) - 32; //for uppercase alphabets

		}
		else
		{
			EncryptedMsg = (int(SecretMessage[x]) + Key); // for lowercase alphabets

		}
		cout << EncryptedMsg;
		x++;
	}



	cin.ignore();
	return EncryptedMsg;

}

string Decoder(int Key, string CodedMessage) // decoding function
{
	string DecryptedMsg;
	int x = 0;

	cout << endl << "Coded Message = " << CodedMessage;
	cout << endl << "Decryption Key : " << Key;

	cout << endl << "Hence, Your Decrypted Message : ";

	while (CodedMessage[x] != '\0')

	{

		if (int(CodedMessage[x]) - Key < 32) ///to test whether each character is in uppercase or lowercase

			DecryptedMsg = ((int(CodedMessage[x]) - Key) + 127) - 32; //For Uppercase Alphabets

		else

			DecryptedMsg = (int(CodedMessage[x]) - Key); //For lowercase Alphabets

		cout << DecryptedMsg;

		x++;
	}

	return DecryptedMsg;

}

