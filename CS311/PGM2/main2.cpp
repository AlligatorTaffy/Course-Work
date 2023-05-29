/*
 AlligatorTaffy
 Program Number: 2

     Description of the Problem:
     We are testing the Odometer class to determine if it is working correctly.
     Are are testing all of the variables and functiion defined in the class
     with arbitrary numbers as followed below.  Each case is identified below
     in sequence.

     Pseudo Code:
          In a test case, we test the following in this order:
          -Test creation of the odometer class
          -Output m_miles using get_miles function
          -Output m_fuel using get_fuel function
          -Output m_mpg using the get_mpg function
          -Test fuel_needed function with arbitrary value
          -Test add_trip by adding abritrary values to m_miles and m_fuel
          -Check add_trip by outputting new m_miles
          -Check add_trip by outputting new m_fuel
          -Check add_trip by outputting new m_mpg
          -Test fuel_needed using new m_miles and m_mpg
          -Test reset_odometer and then outputting cleared m_miles, m_fuel, m_mpg
     
*/

#include <iostream>
#include "odometer.hpp"
using namespace std;

int main()
{
     // Initializing Odometer for Test 1
     Odometer test1;
     
     // Outputting all of the initial variables of the test1 Odometer class.
     // This tests the get_miles, get_fuel, get_mpg, and mpg functions.
     cout << "Test 1: Default Constructor with 0 in all values" << endl;
     cout << "\t\tMiles Driven: " << test1.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test1.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test1.get_mpg() << endl;
    
     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test1.fuel_needed(200) << endl;

     // Testing add_trip by adding 120 miles to m_miles, 4 gallons to m_fuel,
     // then recalculating m_mpg by calling the mpg function.
     cout << "\tTesting Adding 120 miles and 4 gallons consumed to odometer" << endl;
     test1.add_trip(120,4);
     cout << "\t\tMiles Driven: " << test1.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test1.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test1.get_mpg() << endl;

     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test1.fuel_needed(200) << endl;
    
     // Tests the reset_odometer function and then tests the new values against
     // get_miles, get_fuel, get_mpg, mpg, and fuel_needed functions.
     cout << "\tTesting the Reset of the Odometer" << endl;
     test1.reset_odometer();
     cout << "\t\tMiles Driven: " << test1.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test1.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test1.get_mpg() << endl;
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test1.fuel_needed(200) << endl;
     cout << endl;



     // Initializing Odometer for Test 2
     Odometer test2(320,11);

     // Outputting all of the initial variables of the test1 Odometer class.
     // This tests the get_miles, get_fuel, get_mpg, and mpg functions.
     cout << "Test 2: Overloaded Constructor with 320 Miles Driven and 11 Gallons of Fuel Consumed" << endl;
     cout << "\t\tMiles Driven: " << test2.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test2.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test2.get_mpg() << endl;

     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test2.fuel_needed(200) << endl;

     // Testing add_trip by adding 120 miles to m_miles, 4 gallons to m_fuel,
     // then recalculating m_mpg by calling the mpg function.
     cout << "\tTesting Adding 120 miles and 4 gallons consumed to odometer" << endl;
     test2.add_trip(120,4);
     cout << "\t\tMiles Driven: " << test2.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test2.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test2.get_mpg() << endl;

     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test2.fuel_needed(200) << endl;

     // Tests the reset_odometer function and then tests the new values against
     // get_miles, get_fuel, get_mpg, mpg, and fuel_needed functions.
     cout << "\tTesting the Reset of the Odometer" << endl;
     test2.reset_odometer();
     cout << "\t\tMiles Driven: " << test2.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test2.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test2.get_mpg() << endl;
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test2.fuel_needed(200) << endl;
     cout << endl;



     // Initializing Odometer for Test 3
     Odometer test3(256.7,9.67);

     // Outputting all of the initial variables of the test1 Odometer class.
     // This tests the get_miles, get_fuel, get_mpg, and mpg functions.     
     cout << "Test 3: Overloaded Constructor with 256.7 Miles Driven and 9.67 Gallons of Fuel Consumed" << endl;
     cout << "\t\tMiles Driven: " << test3.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test3.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test3.get_mpg() << endl;

     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test3.fuel_needed(200) << endl;

     // Testing add_trip by adding 120 miles to m_miles, 4 gallons to m_fuel,
     // then recalculating m_mpg by calling the mpg function.
     cout << "\tTesting Adding 120 miles and 4 gallons consumed to odometer" << endl;
     test3.add_trip(120,4);
     cout << "\t\tMiles Driven: " << test3.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test3.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test3.get_mpg() << endl;

     // Testing the fuel_needed function with an arbitrary value of 200 miles
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test3.fuel_needed(200) << endl;

     // Tests the reset_odometer function and then tests the new values against
     // get_miles, get_fuel, get_mpg, mpg, and fuel_needed functions.
     cout << "\tTesting the Reset of the Odometer" << endl;
     test3.reset_odometer();
     cout << "\t\tMiles Driven: " << test3.get_miles() << endl;
     cout << "\t\tFuel Consumed (Gallons): " << test3.get_fuel() << endl;
     cout << "\t\tEfficiency (MPG): " << test3.get_mpg() << endl;
     cout << "\tTesting Number Of Gallons Needed to Drive 200 Miles Based on Efficiency" << endl;
     cout << "\t\tFuel Needed in Gallons: " << test3.fuel_needed(200) << endl;
     cout << endl;

     return 0;
}
