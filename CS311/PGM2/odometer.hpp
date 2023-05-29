/*
 AlligatorTaffy
 Program Number: 2                                                           

     Description of the problem:
     This is a odometer class that will create an empty odometer or one with a 
     passed number of miles and gallons of fuel used.
     It will calculate the fuel efficiency in miles per gallon (MPG).

     Pseudo Code:
          Data:
                    m_miles - contains the total miles traveled
                    m_fuel - contains the number of gallons consumed
                    m_mpg - contains the calculated efficiency

          Function:
                    Default Constructor - sets miles, fuel, and mpg to 0 and 
                    calls mpg for miles and gallons consumed
                    Constuctor - accepts passed miles and fuel, sets mpg to 0 
                    and calls mpg for miles and gallons consumed
                    Accessor functions
                         reset_odometer - sets m_miles, m_fuel, m_mpg to 0
                         get_miles - returns the value of m_miles
                         get_fuel - returns the value of m_fuel
                         get_mpg - returns the value of m_mpg
                         add_trip - adds more miles and fuel to current odometer
                         fuel_needed - calculates number of gallons needed based
                                        upon miles given and m_mpg
                    Private member function
                         mpg - calculates the fuel efficiency from m_miles and 
                               m_fuel
                                   Return: Nothing
                                   Input: Nothing

                                   m_mpg = m_miles / m_fuel
*/

class Odometer
{
private:
     float m_miles, m_fuel, m_mpg;
     void mpg();
public:
     Odometer();
     Odometer(float miles, float fuel);
     void reset_odometer();
     float get_miles();
     float get_fuel();
     float get_mpg();
     void add_trip(float miles, float gas);
     float fuel_needed(float miles);
};
