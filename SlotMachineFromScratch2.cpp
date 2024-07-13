#include <iostream>
#include <windows.h>
#include <vector>
#include <string.h>
#include <random>
#include <ctime>
#include <limits>
#include <cstddef>
#include <sstream>
//22 Different letters

#undef max
std::vector<char> LReel = { 'A','C','A','A','C','G','G','G','F','C','F','F','D','E','E','E','D','D','D','K','K','K' };
std::vector<char> CReel = { 'K','K','E','K','E','F','F','F','G','E','G','G','D','C','C','C','D','D','D','A','A','A' };
std::vector<char> RReel = { 'D','D','F','D','F','F','E','E','G','E','G','G','D','K','K','K','A','A','A','C','C','C' };
int choice;
void insertCredits();
int credits;
void menuCredits();
int win;
void spinOne();
void spinTwo();
void spinThree();
void spinFour(); 
//bool IsNumber();
using namespace std;
//Check to see if string is number.
bool IsNumber(string W)
{
	for (int i = 0; i < W.length(); i++)
		if (isdigit(W[i]) == false)
			return false;
	return true;
}
void menuCredits()
{
	bool correctChoice = false;
	while (!correctChoice)
	{
		cout << "You have " << credits << " credits." << endl;
		cout << "How much would you like to bet?" << endl;
		cout << "1)50" << endl;
		cout << "2)100" << endl;
		cout << "3)150" << endl;
		cout << "4)200" << endl;
		bool WhileNotANumber = false;
		while (!WhileNotANumber)
		{
			bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			cin >> choice;
			if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
			{
				bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				WhileNotANumber = true;

			}
			else
			{
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Error!! Enter a number 1 through 4 and don't enter letters." << std::endl;
			}
		}
		switch (choice)
		{
		case 1:
			system("cls");
			correctChoice = true;
			credits -= 50;
			spinOne();
			PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 2:
			system("cls");
			correctChoice = true;
			credits -= 100;
			spinTwo();
			PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 3:
			system("cls");
			correctChoice = true;
			credits -= 150;
			spinThree();
			PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		case 4:
			system("cls");
			correctChoice = true;
			credits -= 200;
			spinFour();
			PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
			break;
		default:
			cout << "ERROR!! Enter a number 1 through 4 and don't enter letters...." << endl;
			correctChoice = false;
			break;
		}

	}


}
int main()
{

	srand((unsigned int)time(NULL));
	insertCredits();
	menuCredits();
	system("PAUSE");
	return 0;
}

void insertCredits()
{
	bool WhileNotANumber = false;
	cout << "Please enter the amount of credits you would like to use." << endl;
	cout << "It has to be greater then 50 or equal to 50 credits." << endl;
	while (!WhileNotANumber)
	{
		cin >> credits;
		if (credits < 50)
		{
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Error!! Enter a number greater then or equal 50 and do not enter letters." << std::endl;
			cin >> credits;
		}
		if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
		{
			WhileNotANumber = true;
			bool SlotWin = PlaySound(TEXT("InsertCoin.wav"), NULL, SND_ASYNC);
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Error!! Enter a number greater then 50 and do not enter letters." << std::endl;
			cin >> credits;
		}
	}
}
void spinOne()
{
	
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	

	
		do
		{
				cout << "You have " << credits << " credits." << endl;
				if (credits -= 50)
				{	
				    bool SlotWin1 = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);	
				}
				int mini = rand() % 101;
				int minor = rand() % 151;
				int major = rand() % 201;
				cout << "Here is the mini bonus count." << mini << endl;
				cout << "Here is the minor bonus count." << minor << endl;
				cout << "Here is the major bonus count." << major << endl;
				if (mini >= 100)
				{
					cout << "YOU WON!!!! The MINI!" << endl;
					cout << "You have won 10000 credits" << endl;
					bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
					credits += 10000;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (minor >= 150)
				{
					cout << "YOU WON!!!! The MINOR!" << endl;
					cout << "You have won 100,000 credits." << endl;
					bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
					credits += 100000;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (major >= 200)
				{
					cout << "YOU WON!!!! The MAJOR!" << endl;
					cout << "You have won 1,000,000 credits" << endl;
					bool BigSlotWin = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
					credits += 1000000;
					cout << "You now have " << credits << " credits." << endl;
				}
				std::size_t number = distribution(generator);
				std::size_t number2 = distribution2(generator2);
				std::size_t number3 = distribution3(generator3);
				std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
			
				if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
				{
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					cout << "YOU WON!!!!" << endl;
					credits += 75;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
				{
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					cout << "YOU WON!!!!" << endl;
					credits += 10;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 2000;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 1500;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 1750;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 25;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 1550;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 75;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 10;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 50;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 50;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 50;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 50;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 1000;
					cout << "You now have " << credits << " credits." << endl;
				}
				else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
				{
					cout << "YOU WON!!!!" << endl;
					bool SlotWin1 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
					credits += 50;
					cout << "You now have " << credits << " credits." << endl;
				}
			       
					if (Play)
					{
						bool PressedChoice = false;
						while (!PressedChoice)
						{
							string yesOrNo = "";
							cout << "Would you like to play again? y/n? Please type Y or N..." << endl;
							cin >> yesOrNo;
							if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
							{
								bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
								PressedChoice = true;
							}
						    else
						    {
						    	std::cin.clear();
						    	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
						    	std::cout << "Enter Y or N.." << std::endl;
						    	cin >> yesOrNo;
								if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
								{
									bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
									PressedChoice = true;
								}
								if (yesOrNo == "y")
								{
									Play = true;
									bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
								}
								else if (yesOrNo == "n")
								{
									Play = false;
									PressedChoice = true;
									bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
								}
								
						    }
							if (yesOrNo == "y")
							{
								Play = true;
								bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
							}
							else if (yesOrNo == "n")
							{
								Play = false;
								PressedChoice = true;
								bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
							}
							if (credits <= 0)
							{
								cout << "YOU LOSE!! YOU HAVE NO MORE CREDITS!!!" << endl;
								Play = false;
								bool ButtonPress = PlaySound(TEXT("YouLose.wav"), NULL, SND_ASYNC);
							}
						}
					}
				
		} while (Play);
	
}
void spinTwo()
{

	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	do
	{
		cout << "You have " << credits << " credits." << endl;
		if (credits -= 100)
		{
			bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "Here is the mini bonus count." << mini << endl;
		cout << "Here is the minor bonus count." << minor << endl;
		cout << "Here is the major bonus count." << major << endl;
		if (mini >= 100)
		{
			cout << "YOU WON!!!! The MINI!" << endl;
			cout << "You have won 10,000 credits!" << endl;
			bool BigSlotWin2 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "You now have 10,000 credits." << endl;
		}
		else if (minor >= 150)
		{
			cout << "YOU WON!!!! The MINOR!" << endl;
			cout << "You have won 100,000 credits" << endl;
			bool BigSlotWin2 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (major >= 200)
		{
			cout << "YOU WON!!!! The MAJOR!" << endl;
			cout << "You have won 1,000,000 credits" << endl;
			bool BigSlotWin2 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "You now have " << credits << " credits." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution2(generator2);
		std::size_t number3 = distribution3(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
		
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 175;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 10;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 3000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
		
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2500;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			cout << "YOU WON!!!!" << endl;
		
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2750;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2500;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
		
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 125;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 1550;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 175;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 110;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin2 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "Would you like to play again? y/n? Please type Y or N..." << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Enter Y or N.." << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y")
					{
						Play = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y")
				{
					Play = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "YOU LOSE!! YOU HAVE NO MORE CREDITS!!!" << endl;
					Play = false;
					bool ButtonPress = PlaySound(TEXT("YouLose.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}
void spinThree()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	do
	{
		
		cout << "You have " << credits << " credits." << endl;
		if (credits -= 150)
		{
			bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "Here is the mini bonus count." << mini << endl;
		cout << "Here is the minor bonus count." << minor << endl;
		cout << "Here is the major bonus count." << major << endl;
		if (mini >= 100)
		{
			bool BigSlotWin3 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			cout << "YOU WON!!!! The MINI!" << endl;
			cout << "You have won 10,000  credits" << endl;
			credits += 10000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (minor >= 150)
		{
			bool BigSlotWin3 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			cout << "YOU WON!!!! The MINOR!" << endl;
			cout << "You have won 100000 credits" << endl;
			credits += 100000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (major >= 200)
		{
			cout << "YOU WON!!!! The MAJOR!" << endl;
			bool BigSlotWin3 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			cout << "You have won 1,000,000 credits" << endl;
			credits += 1000000;
			cout << "You now have " << credits << " credits." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution2(generator2);
		std::size_t number3 = distribution3(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;

		
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 190;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 20;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 3000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2500;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2750;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 125;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 1550;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 175;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 110;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin3 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "Would you like to play again? y/n? Please type Y or N..." << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Enter Y or N.." << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y")
					{
						Play = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}

				}
				if (yesOrNo == "y")
				{
					Play = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "YOU LOSE!! YOU HAVE NO MORE CREDITS!!!" << endl;
					Play = false;
					bool ButtonPress = PlaySound(TEXT("YouLose.wav"), NULL, SND_ASYNC);
				}
			}
		}
	
	} while (Play);
}
void spinFour()
{
	bool Play = true;
	std::mt19937 generator(std::random_device{}());
	std::mt19937 generator2(std::random_device{}());
	std::mt19937 generator3(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, LReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution2(0, CReel.size() - 1);
	std::uniform_int_distribution<std::size_t> distribution3(0, RReel.size() - 1);
	do
	{
		cout << "You have " << credits << " credits." << endl;
		if (credits -= 200)
		{
			PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
		}
		int mini = rand() % 101;
		int minor = rand() % 151;
		int major = rand() % 201;
		cout << "Here is the mini bonus count." << mini << endl;
		cout << "Here is the minor bonus count." << minor << endl;
		cout << "Here is the major bonus count." << major << endl;
		if (mini >= 100)
		{
			cout << "YOU WON!!!! The MINI!" << endl;
			cout << "You have won 10,000  credits" << endl;
			bool BigSlotWin4 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 10000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (minor >= 150)
		{
			cout << "YOU WON!!!! The MAJOR!" << endl;
			cout << "You have won 100,000  credits" << endl;
			bool BigSlotWin4 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 100000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (major >= 200)
		{
			cout << "YOU WON!!!! The MAJOR!" << endl;
			cout << "You have won 1,000,000 credits" << endl;
			bool BigSlotWin4 = PlaySound(TEXT("BigWinSlotMachineSound.wav"), NULL, SND_ASYNC);
			credits += 1000000;
			cout << "You now have " << credits << " credits." << endl;
		}
		std::size_t number = distribution(generator);
		std::size_t number2 = distribution2(generator2);
		std::size_t number3 = distribution3(generator3);
		std::cout << LReel[number] << CReel[number2] << RReel[number3] << std::endl;
		if (LReel[number] == 'D' && CReel[number2] == 'D' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 275;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 20;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 3500;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 3000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'G')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 3000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 125;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2550;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 175;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'F' && CReel[number2] == 'F' && RReel[number3] == 'E')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 110;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'A' && CReel[number2] == 'A' && RReel[number3] == 'K')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'G' && CReel[number2] == 'G' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'E' && CReel[number2] == 'E' && RReel[number3] == 'F')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'A')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'K' && CReel[number2] == 'K' && RReel[number3] == 'C')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 2000;
			cout << "You now have " << credits << " credits." << endl;
		}
		else if (LReel[number] == 'C' && CReel[number2] == 'C' && RReel[number3] == 'D')
		{
			cout << "YOU WON!!!!" << endl;
			bool SlotWin4 = PlaySound(TEXT("SlotMachineWin.wav"), NULL, SND_ASYNC);
			credits += 150;
			cout << "You now have " << credits << " credits." << endl;
		}
		
		if (Play)
		{
			bool PressedChoice = false;
			while (!PressedChoice)
			{
				string yesOrNo = "";
				cout << "Would you like to play again? y/n? Please type Y or N..." << endl;
				cin >> yesOrNo;
				if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
				{
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					PressedChoice = true;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cout << "Enter Y or N.." << std::endl;
					cin >> yesOrNo;
					if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n', !IsNumber(yesOrNo), yesOrNo.size() <= 1))
					{
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
						PressedChoice = true;
					}
					if (yesOrNo == "y")
					{
						Play = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
					else if (yesOrNo == "n")
					{
						Play = false;
						PressedChoice = true;
						bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
					}
				}
				if (yesOrNo == "y")
				{
					Play = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				else if (yesOrNo == "n")
				{
					Play = false;
					PressedChoice = true;
					bool ButtonPress = PlaySound(TEXT("ButtonPress.wav"), NULL, SND_ASYNC);
				}
				if (credits <= 0)
				{
					cout << "YOU LOSE!! YOU HAVE NO MORE CREDITS!!!" << endl;
					Play = false;
					bool ButtonPress = PlaySound(TEXT("YouLose.wav"), NULL, SND_ASYNC);
				}
			}
		}
	} while (Play);
}

