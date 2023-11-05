#include <iostream>

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

*/
