#include <iostream>
#include <cmath>

/*
1. The world is loaded with
    variables:
        altitude_start, altitude_goal, speed_start, speed_goal, fuel and gravity (depending on altitude and planet_mass);
    constants:
        time_count(0.1 sec), planet_mass;
    (player_inputs):
        thrust,
2. The player chooses one of the scenarios (launch_to_orbit_planet, landing_planet);
    - launch_to_orbit_moon: altitude_start: 0, altitude_goal: 150, speed_start: 0,speed_goal: 50,  fuel: 2000, planet_mass: 1;
    - launch_to_orbit_earth: altitude_start: 0, altitude_goal: 150, speed_start: 0,speed_goal: 50, fuel: 2000, planet_mass: 6;
    - landing_moon: altitude_start: 150, altitude_goal: 0, speed_start: 10,speed_goal: <= 2, fuel: 200, planet_mass: 1;
    - landing_earth: altitude_start: 150, altitude_goal: 0, speed_start: 10,speed_goal: <= 2, fuel: 200, planet_mass: 6;

    The according scenario is loaded;
3. Time starts ticking: every round length is equals time_count;
4. Each round consists of a loop:
    -Check for altitude and speed, 
        if current altitute != goal: 
            1) speed is subtracted from alt (alt from previous round - speed from previous round)
            2) current gravity is calculated (gravity constant at new altitude)
            3) speed is altered by gravity (speed + gravity)
            4) the player chooses the thrust, a check is performed to see if the thrust is acceptable:
                if acceptable, then: 
                    thrust gets subtracted from the fuel (fuel - thrust)
                if not, then:
                    thrust gets limited to a set value or remaining fuel - the lower number gets taken;
                
                after that 1/10 thrust gets subtracted from speed (speed - thrust/10)
            5) repeat;
        if current altitute == goal, speed is checked:
            if speed == goal_speed_range then the player wins;
            else the player loses;
5. The game ends;


  To-Do:

    - speed: should be only positive (V)
    - thrust: check for acceptability (V)
    - altitude_goal: full check -> launch_scenario: >= 150; landing_scenario: >= 0 (V)
    - altitude_start: should not be performed before round_1 (V)
    - gravity: needs altitude adjustement (X)
    - negative altitude in launch scenario needs to be adressed (X)

    - fine tuning the parametes... (XXX)

*/

// Constants
const double time_count = 1;
const double planet_mass_moon = 1; // work in progress...
const double planet_mass_earth = 6; // work in progress...
const double gravity_moon = 1.625; 
const double gravity_earth = 9.81; 



// display
void displayScenarioParameters(double altitude_start, double altitude_goal, double speed_start, double speed_goal, double fuel, double planet_mass, std::string planet) 
{
    std::cout << "\nScenario Parameters:\n";
    std::cout << "Planet: " << planet << "\n";   
    std::cout << "Starting Altitude: " << altitude_start << " meters\n";
    std::cout << "Target Altitude: " << altitude_goal << " meters\n";
    std::cout << "Starting Speed: " << speed_start << " m/s\n";
    std::cout << "Target Speed: " << speed_goal << " m/s\n";
    std::cout << "Fuel: " << fuel << " litres\n";
    std::cout << "Planet Mass: " << planet_mass << "\n";
}

// logic...
void runScenario(double altitude_start, double altitude_goal, double speed_start, double speed_goal, double fuel, double planet_mass, bool launch) 
{
    double altitude = altitude_start;
    double speed = speed_start;

    while ((launch == true && altitude <= altitude_goal) || (launch == false && altitude >= altitude_goal))
    {
        double gravity = (planet_mass == planet_mass_moon) ? gravity_moon : gravity_earth;
        

        double thrust;
        std::cout << "---------------" << std::endl;
        std::cout << "Current altitude: " << altitude << " meters\n";
        std::cout << "Current speed: " << abs(speed) << " m/s\n";
        std::cout << "Fuel left: " << fuel <<  " litres\n";
        std::cout << "Enter thrust: ";
        std::cin >> thrust;
        std::cout << "---------------" << std::endl;

        altitude -= speed;
        speed += gravity * time_count;
        
        if (thrust <= fuel && thrust >= 0) 
        {
            fuel -= thrust;
        } 
        else if(thrust > fuel)
        {
            thrust = fuel;
            fuel -= thrust;
        }
        else 
        {
            thrust = 0;
            fuel -= thrust;
        }

        speed -= (thrust / 3.0) * time_count;
    }

    std::cout << "" << std::endl;
    std::cout << "Current altitude: " << altitude << " meters\n";
    std::cout << "Current speed: " << abs(speed) << " m/s\n";
    std::cout << "Fuel left: " << fuel <<  " litres\n";
    std::cout << "---------------" << std::endl;
    std::cout << "" << std::endl;

    if (launch == true && abs(speed) >= speed_goal) 
    {
        std::cout << "" << std::endl;
        std::cout << "You won!" << std::endl;
    }
    else if (launch == false && abs(speed) <= speed_goal)
    {
        std::cout << "" << std::endl;
        std::cout << "You won!" << std::endl;

    }
    else 
    {
        std::cout << "" << std::endl;
        std::cout << "You've lost!" << std::endl;
    }
}

// programm
int main() 
{
    int scenario;

    std::cout << "" << std::endl;
    std::cout << "       |\n";
    std::cout << "      / \\\n";
    std::cout << "     / _ \\\n";
    std::cout << "    |.o '.|\n";
    std::cout << "    |'._.'|\n";
    std::cout << "    |     |\n";
    std::cout << "  ,'|  |  |  |`.\n";
    std::cout << " /  |  |  |  |  \\\n";
    std::cout << "|,-'--|--'-.| t.r.\n";
    std::cout << "Hello, rocketman! Choose a scenario you wanna fly:\n1. Launch to orbit moon\n2. Launch to orbit earth\n3. Landing on moon\n4. Landing on earth\n";
    std::cout << "" << std::endl;
    std::cin >> scenario;

    double altitude_start, altitude_goal, speed_start, speed_goal, fuel, planet_mass;
    std::string planet;
    bool launch;

    switch (scenario) 
    {
        case 1:
            planet = "moon";
            altitude_start = 0;
            altitude_goal = 5000;
            speed_start = 0;
            speed_goal = 95;
            fuel = 2000;
            planet_mass = planet_mass_moon;
            launch = true;
            break;
        case 2:
            planet = "earth";
            altitude_start = 0;
            altitude_goal = 5000;
            speed_start = 0;
            speed_goal = 95;
            fuel = 2000;
            planet_mass = planet_mass_earth;
            launch = true;
            break;
        case 3:
            planet = "moon";
            altitude_start = 900;
            altitude_goal = 0;
            speed_start = 10;
            speed_goal = 2;
            fuel = 200;
            planet_mass = planet_mass_moon;
            launch = false;
            break;
        case 4:
            planet = "earth";
            altitude_start = 900;
            altitude_goal = 0;
            speed_start = 10;
            speed_goal = 2;
            fuel = 200;
            planet_mass = planet_mass_earth;
            launch = false;
            break;
        default:
            std::cout << "Invalid scenario choice." << std::endl;
            return 0;
    }

    displayScenarioParameters(altitude_start, altitude_goal, speed_start, speed_goal, fuel, planet_mass, planet);
    runScenario(altitude_start, altitude_goal, speed_start, speed_goal, fuel, planet_mass, launch);

    return 0;
}


// if (thrust == 0)
// alt = 0