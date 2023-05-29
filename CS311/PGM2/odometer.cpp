/*
 AlligatorTaffy
 Program number: 2
 */

#include "odometer.hpp"

// Default constructor
Odometer::Odometer()
{
     m_miles = m_fuel = m_mpg = 0;
}

// Constructor that sets m_miles and m_fuel
Odometer::Odometer(float miles, float fuel)
{
     m_miles = miles;
     m_fuel = fuel;
     mpg();
}

// Calculates the Fuel Efficiency
void Odometer::mpg()
{
     m_mpg = m_miles/m_fuel;
}

// Accessor function to assign 0 to m_miles, m_fuel, m_mpg
void Odometer::reset_odometer()
{
     m_miles = m_fuel = m_mpg = 0;    
}

// Accessor function to return m_miles
float Odometer::get_miles()
{
     return m_miles;
}

// Accessor function to return m_fuel
float Odometer::get_fuel()
{
     return m_fuel;
}

// Accessor function to return m_mpg
float Odometer::get_mpg()
{
     return m_mpg;
}

// Accessor function to calculate fuel needed given miles
float Odometer::fuel_needed(float miles)
{
     return miles / m_mpg;
}

// Accessor function to add miles and fuel to current odometer
// then find the efficiency
void Odometer::add_trip(float miles, float gas)
{
     m_miles += miles;
     m_fuel += gas;
     mpg();
}
