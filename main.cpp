#include <iostream>
#include <cstdlib>
#include <time.h>

int main(){

srand(time(NULL));
int iN=0;
char cLetter=0;
std::cout << "How many letters should your name have?: ";
std::cin >> iN;
std::cout << "Your name is: ";
cLetter=rand()%26+65;
std::cout << cLetter;
for(int i=2; i<=iN; i++){
	cLetter=rand()%26+97;
	std::cout << cLetter;
}
std::cout<<"\n";
return 0;
}
