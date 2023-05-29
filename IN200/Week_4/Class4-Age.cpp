//	In Class assignment #4

#include <iostream> 
using namespace std ;

int main () {
	float yearDays = 365.25 ;
	int monthDays = 30 ;
	float totalDays = 0 ;
	float userYearsOld = 28, userMonthsOld = 11 ;

	cout << "Hey there how many YEARS old are you?\n" ;
	cin >> userYearsOld ;
	cout << "Now how many MONTHS on top of that?\n" ;
	cin >> userMonthsOld ;
	totalDays = (userYearsOld * yearDays) + (userMonthsOld * monthDays) ;
	cout << "Total Days Alive :" << totalDays << "\n" ;


	return 0 ;
}
