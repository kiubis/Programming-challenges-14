#define debug(x) std::cout<<#x<<": "<<x<<"\n";

#include <iostream>
#include <cstdlib>
#include <time.h>

void higher_lower();
void heads_tails();
void carriage(int iSize, int iRand);
void tossSum(int iTails, int iHeads, int iSize);
void no_of_tosses();
void guess_the_toss();

int main() {

	srand(time(NULL));
	int iCho = 0;

	do {
		std::cout << "Type which game would you like to play.\n 1 for higher/lower\n 2 for heads/tails\n 0 to quit\n>>";
		std::cin >> iCho;
		switch (iCho) {
		case 1:
			system("cls");
			higher_lower();
			break;
		case 2:
			system("cls");
			heads_tails();
			break;
		case 0:
			system("cls");
			std::cout << "Thanks for playing!\n";
			break;
		default:
			system("cls");
			std::cout << "Wrong number!\n";
			system("PAUSE");
			system("cls");
			break;
		}
	} while (iCho);

	system("PAUSE");
	return 0;
}

void higher_lower() {

	int iBeg =	 0, 
		iEnd =	 0, 
		iN =	 0, 
		iRand =	 0, 
		iTu=	 0;

	do {
		std::cout << "---Try to guess the number!---\n";
		std::cout << "Type starting parameters:\n";
		std::cout << "Beginning of a interval (integer): ";
		std::cin >> iBeg;
		std::cout << "Ending of a interval (integer): ";
		std::cin >> iEnd;
		std::cout << "Number of tries: ";
		std::cin >> iN;
		if (!(iBeg<iEnd)) {
			system("cls");
			std::cout << "Interval is not valid!\n";
			system("PAUSE");
			system("cls");
		}
		if (iN<1) {
			system("cls");
			std::cout << " Type number of tries higher than 0!\n";
			system("PAUSE");
			system("cls");
		}
	} while (!(iBeg<iEnd) || !(iN>0));
	iRand = ((rand()*rand()) % (iEnd - iBeg)) + iBeg;

	int *iUsed = new int[iN];
	char *cLH =	new char[iN];

	system("cls");
	std::cout << "Let's start! \n";

	do {
		if (iN - iTu == 1)
			std::cout << iN - iTu << " try left\n";
		else
			std::cout << iN - iTu << " tries left\n";
		debug(iRand);
		std::cout << "Interval: <" << iBeg << "," << iEnd << ">\n";
		std::cout << "Guess the number: \n>>: ";
		std::cin >> iUsed[iTu];
		if (iUsed[iTu] == iRand) {
			system("cls");
			std::cout << "Great work! You guessed the number!\n";
		}
		else {
			system("cls");
			if (iUsed[iTu] < iRand) {
				std::cout << "Random number is higher!\n";
				cLH[iTu] = '>';
			}
			else {
				std::cout << "Random number is lower!\n";
				cLH[iTu] = '<';
			}
			std::cout << "Already used numbers: ";
			for (int m = 0; m <= iTu; m++) 
				std::cout << cLH[m]<<iUsed[m] << " ";
			iTu++;
			std::cout << "\n";
		}
	}while((iTu<iN) && (iUsed[iTu]!=iRand));

	if (iUsed[iTu] != iRand)
		std::cout << "Sorry, no tries left... Better luck next time!\n";
	delete []iUsed;
	delete []cLH;

	system("PAUSE");
	system("cls");
}

void heads_tails() {

	int iCho = 0;

	do {
		std::cout << "Which game would you like to play? \n1. Guess the toss. \n2. Count number of tosses.\n0 to go back to main menu.\n>> ";
		std::cin >> iCho;
		switch (iCho) {
		case 1:
			system("cls");
			guess_the_toss();
			break;
		case 2:
			system("cls");
			no_of_tosses();
			break;
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "Wrong number!\n";
			system("pause");
			break;
		}
	} while (iCho);
}

void guess_the_toss() {
	int iN = 0,
		iRand = 0,
		iScore = 0,
		iAll = 0;
	char cGue,
		cLast[10];

	for (int i = 0; i < 10; i++)
		cLast[i] = ' ';

	do {
		std::cout << "How many tries do you want?\n>> ";
		std::cin >> iN;
		if (iN < 1) {
			std::cout << "Wrong number!";
			system("pause");
			system("cls");
		}
	} while (iN < 1);
	system("cls");
	std::cout << "Let's start!";
	do{
		if (cLast[0] != ' ') {
			std::cout << "Last results (max 10):\n";
			for (int i = 0; i < 10; i++)
				std::cout << cLast[i] << " ";
		}
	std::cout << "\n" << iN - iAll << " turns left. \n";
	if (iScore == 1)
		std::cout << "So far, you have been right once\n";
	if (iScore > 2)
		std::cout << "So far, you have been " << iScore << " times right.\n";
	std::cout << "Type H for Heads or T for Tails\n>> ";
	std::cin >> cGue;
	iRand = rand()*rand() % 2;
	if (cGue == 'H' || cGue == 'h' || cGue == 'T' || cGue == 't') {
		iAll++;
		for (int i = 9; i > 0; i--)
			cLast[i] = cLast[i - 1];
		switch (iRand) {
		case 0:
			cLast[0] = 'H';
			if (cGue == 'H' || cGue == 'h') {
				iScore++;
				std::cout << "You guessed right!\n";
			}
			else
				std::cout << "You guessed wrong...\n";
			break;
		case 1:
			cLast[0] = 'T';
			if (cGue == 'T' || cGue == 't') {
				iScore++;
				std::cout << "You guessed right!\n";
			}
			else
				std::cout << "You guessed wrong...\n";
			break;
		}
	}
	else
		std::cout << "Wrong letter!";
	system("pause");
	system("cls");
	} while (iAll < iN);
	system("cls");
	std::cout << "Your score is " << iScore << "/" << iN << "\n";
	if ((double)iScore / (double)iN > 0.8)
		std::cout << "Pretty nice!";
	else if ((double)iScore / (double)iN > 0.5)
		std::cout << "Good score!";
	else
		std::cout << "Better luck next time!";
	std::cout << "\n";
	system("pause");
	system("cls");
}


void no_of_tosses(){
		int iN = 0,
			iRand = 0,
			iTails = 0,
			iHeads = 0;
		char cDec;

	do {
		std::cout << "Type a number of coin tosses: ";
		std::cin >> iN;
		std::cout << "Show every toss? [Y/N]: ";
		std::cin >> cDec;
		if (iN < 1) {
			system("clc");
			std::cout << "Wrong number of coin tosses!";
			system("pause");
			system("clc");
		}
		if (!(cDec == 'y' || cDec == 'Y' || cDec == 'N' || cDec == 'n')) {
			system("clc");
			std::cout << "Wrong letter!";
			system("pause");
			system("clc");
		}

	} while (iN < 1 || iN>99999 || !(cDec == 'y' || cDec == 'Y' || cDec == 'N' || cDec == 'n'));

	std::cout << "Heads--|--Tails\n";

	if (cDec == 'y' || cDec == 'Y') {
		for (int k = 0; k < iN; k++) {
			iRand = rand()*rand() % 2;
			carriage(15, iRand);
			if (iRand)
				iTails++;
			else
				iHeads++;
		}	
	}
	else {
		for (int k = 0; k < iN; k++) {
			iRand = rand()*rand() % 2;
			if (iRand)
				iTails++;
			else
				iHeads++;
		}
	}
	for (int i = 1; i <= 15; i++)
		std::cout << "=";
	tossSum(iHeads, iTails, 15);
	system("pause");
	system("cls");
}

void carriage(int iSize, int iRand) {
	int iStart = 2;
	char *iLin = new char[iSize];
	for (int k = 0; k < iSize; k++)
		iLin[k] = ' ';
	if (!iRand)
		iLin[iStart] = 0xf;
	else
		iLin[iStart + iSize - 5] = 0xf;
	iLin[iSize / 2] = '|';
	for (int k = 0; k < iSize; k++)
		std::wcout << iLin[k];
	std::cout << "\n";
	delete []iLin;
}

void tossSum(int iHeads, int iTails, int iSize) {
	int iHpos = 2,
		iTpos = iSize - 5 + iHpos;
	bool bFT = false,
	 	 bFH = false;

	for (int k = 10; k <= 1000; k *= 100) {
		if (iTails / k)
			iTpos--;
		if (iHeads / k)
			iHpos--;
	}

	char *cSho = new char[iSize];

	for (int i = 0; i < iSize; i++)
		cSho[i] = ' ';
	for (int i = 5; i < iSize - 5; i++)
		cSho[i] = '-';

	cSho[iSize / 2] = '|';

	for (int i = 10000; i >= 1; i /= 10) {
		if (iTails / i || bFT) {
			cSho[iTpos] = ( iTails % (i * 10) ) / i + 48;
			iTpos++;
			bFT = true;
		}
		if (iHeads / i || bFH) {
			cSho[iHpos] = ( iHeads % (i * 10) ) / i + 48;
			iHpos++;
			bFH = true;
		}
	}
	for (int i = 0; i < iSize; i++)
		std::cout << cSho[i];
	std::cout << "\n";

	delete []cSho;
}
