#include <iostream>

/*
1. the world is loaded with variables: altitude_start, altitude_goal, speed_start, speed_goal and fuel; constants: time_count(0.1 sec), gravity (depending on altitude and planet_mass);
2. the player chooses one of the scenarios (launch_to_orbit_planet, landing_planet);
    - launch_to_orbit_moon: altitude_start: 0, altitude_goal: 150, speed_start: 0,speed_goal: 50,  fuel: 2000, planet_mass: 1;
    - launch_to_orbit_earth: altitude_start: 0, altitude_goal: 150, speed_start: 0,speed_goal: 50, fuel: 2000, planet_mass: 6;
    - landing_moon: altitude_start: 150, altitude_goal: 0, speed_start: 10,speed_goal: <= 2, fuel: 200, planet_mass: 1;
    - landing_earth: altitude_start: 150, altitude_goal: 0, speed_start: 10,speed_goal: <= 2, fuel: 200, planet_mass: 6;
3. time starts ticking: every round is equals time_count;
4. Each round has a loop: 
    1) speed is subtracted from alt (alt from previous round - speed from previous round)
    2) current gravity is calculated (gravity constant at new altitude)
    3) speed is altered by gravity (speed + gravity)
    4) the player shooses the thrust, it gets subtracted from the fuel (fuel - thrust)
                                   1/10 gets subtracted from speed (speed - thrust/10)



*/
