#include<stdio.h>
#include<math.h>
#include "../include/linear_motion.h"
#include "../include/input_utils.h"

void uniform_linear_motion(Linear_Motion particle)
{
    particle.acceleration = 0; // ULM CONDITION
    int selection;
    printf("\nChoose one option\n");

    printf("\n(1) Calculate Distance\n");
    printf("(2) Calculate Time\n");
    printf("(3) Calculate Velocity\n");
    
    selection = read_menu_option("Selection: ",1, 3);
    
    switch (selection)
    {
    case 1:
        printf("\nCalculate Distance\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Velocity\n");
        printf("Time\n");

        particle.initial_velocity = read_positive_double("\nEnter the velocity (m/s): ");
        
        particle.final_velocity = particle.initial_velocity; // ULM CONDITION

        particle.time = read_positive_double("Enter the time (s): ");
        
        printf("\nVelocity = %.2fm/s\n", particle.initial_velocity);
        printf("Time = %.2fs\n", particle.time);

        particle.distance = particle.initial_velocity * particle.time;
        printf("\nDistance = %.2fm\n", particle.distance);
        
        break;
    case 2:
        
        printf("\nCalculate Time\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Velocity\n");
        printf("Distance\n");
        
        particle.initial_velocity = read_positive_double("\nEnter the velocity (m/s): ");
        
        particle.final_velocity = particle.initial_velocity; // ULM CONDITION
        
        particle.distance = read_positive_double("Enter the distance (m): ");
        
        printf("\nVelocity = %.2fm/s\n", particle.initial_velocity);
        printf("Distance = %.2fm\n", particle.distance);

        particle.time = particle.distance / particle.initial_velocity;
        printf("\nTime = %.2fs\n", particle.time);
        
        break;
    case 3:
        
        printf("\nCalculate Velocity\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Time\n");
        printf("Distance\n");
        
        particle.time = read_positive_double("\nEnter the time (s): ");
        particle.distance = read_positive_double("Enter the distance (m): ");
        
        printf("\nTime = %.2fs\n", particle.time);
        printf("Distance = %.2fm\n", particle.distance);

        particle.initial_velocity = particle.distance / particle.time;
        particle.final_velocity = particle.initial_velocity; // ULM CONDITION
        printf("\nVelocity = %.2fm/s\n", particle.initial_velocity);
        
        break;

    default:
        break;
    }
}

void accelerated_uniform_linear_motion(Linear_Motion particle)
{
    int selection;
    printf("\nChoose one option\n");

    printf("\n(1) Calculate Distance\n");
    printf("(2) Calculate Final Velocity\n");
    printf("(3) Calculate Acceleration\n");
    printf("(4) Calculate Time\n");
    
    selection = read_menu_option("\nSelection: ", 1, 4);
    
    switch (selection)
    {
    case 1:
        
        printf("\nCalculate Distance\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Acceleration\n");
        printf("Initial Velocity\n");
        printf("Time\n");

        particle.acceleration = read_positive_double("\nEnter the acceleration (m/s^2): ");
        particle.initial_velocity = read_positive_double("Enter the initial velocity (m/s): ");
        particle.time = read_positive_double("Enter the time (s): ");
        
        printf("\nAcceleration: %.2fm/s^2\n", particle.acceleration);
        printf("Initial velocity: %.2fm/s\n", particle.initial_velocity);
        printf("Time in movement: %.2fs\n", particle.time);

    
        particle.distance = particle.initial_velocity * particle.time + 1.0/2.0 *particle.acceleration*pow(particle.time, 2);
        printf("\nThe distance is %.2fm\n", particle.distance);
        
        break;
    case 2:
        
        printf("\nCalculate Final Velocity\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Acceleration\n");
        printf("Initial Velocity\n");
        printf("Time\n");

        particle.acceleration = read_positive_double("\nEnter the acceleration (m/s^2): ");
        particle.initial_velocity = read_positive_double("Enter the initial velocity (m/s): ");
        particle.time = read_positive_double("Enter the time (s): ");

        
        printf("\nAcceleration: %.2fm/s^2\n", particle.acceleration);
        printf("Initial velocity: %.2fm/s\n", particle.initial_velocity);
        printf("Time in movement: %.2fs\n", particle.time);

        particle.final_velocity = particle.initial_velocity + particle.acceleration * particle.time;
        printf("\nThe final velocity is: %.2fm/s\n", particle.final_velocity);

        break;
    case 3:
        
        printf("\nCalculate Acceleration\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Final Velocity\n");
        printf("Initial Velocity\n");
        printf("Time\n");

        particle.final_velocity = read_positive_double("\nEnter the final velocity (m/s): ");
        particle.initial_velocity = read_positive_double("Enter the initial velocity (m/s): ");
        particle.time = read_positive_double("Enter the time (s): ");
        
        
        printf("\nFinal velocity: %.2fm/s\n", particle.final_velocity);
        printf("Initial velocity: %.2fm/s\n", particle.initial_velocity);
        printf("Time in movement: %.2fs\n", particle.time);

        particle.acceleration = (particle.final_velocity - particle.initial_velocity) / particle.time;

        printf("\nThe acceleration is: %.2fm/s^2\n", particle.acceleration);

        break;
    case 4:

        printf("\nCalculate Time\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Final Velocity\n");
        printf("Initial Velocity\n");
        printf("Acceleration\n");

        particle.final_velocity = read_positive_double("\nEnter the final velocity (m/s): ");
        particle.initial_velocity = read_positive_double("Enter the initial velocity (m/s): ");
        particle.acceleration = read_positive_double("Enter the acceleration (m/s^2): ");
        

        printf("\nFinal velocity: %.2fm/s\n", particle.final_velocity);
        printf("Initial velocity: %.2fm/s\n", particle.initial_velocity);
        printf("Acceleration: %.2fm/s^2\n", particle.acceleration);

        particle.time = (particle.final_velocity - particle.initial_velocity) / particle.acceleration;
        printf("\nThe time is: %.2fs\n", particle.time);
        
        break;
    default:
        break;
    }
}