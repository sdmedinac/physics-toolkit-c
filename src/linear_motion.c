#include<stdio.h>
#include<math.h>
#include "../include/linear_motion.h"

void uniform_linear_motion(Linear_Motion particle)
{
    particle.acceleration = 0; // ULM CONDITION
    int selection;
    printf("\nChoose one option\n");

    printf("\n(1) Calculate Distance\n");
    printf("(2) Calculate Time\n");
    printf("(3) Calculate Velocity\n");
    printf("Selection: ");
    scanf("%d", &selection);

    while(selection < 1 || selection > 3){
        printf("Invalid choice, try again: ");
        scanf("%d", &selection);
    }
    
    switch (selection)
    {
    case 1:
        printf("\nCalculate Distance\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Velocity\n");
        printf("Time\n");

        printf("\nEnter the velocity in (meters/second): "); 
        scanf("%lf", &particle.initial_velocity);
        
        while(particle.initial_velocity <= 0){
            printf("Enter a velocity greater than zero: "); 
            scanf("%lf", &particle.initial_velocity);
        }
        
        particle.final_velocity = particle.initial_velocity; // ULM CONDITION

        printf("Enter the time in (seconds): ");
        scanf("%lf", &particle.time);
        
        while(particle.time <= 0){
            printf("Enter a time greater than zero: "); 
            scanf("%lf", &particle.time);
        }

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
        
        printf("\nEnter the velocity in (meters/second): "); 
        scanf("%lf", &particle.initial_velocity);
        
        while(particle.initial_velocity <= 0){
            printf("Enter a velocity greater than zero: "); 
            scanf("%lf", &particle.initial_velocity);
        }
        
        particle.final_velocity = particle.initial_velocity; // ULM CONDITION
        
        printf("\nEnter the distance in (meters): ");
        scanf("%lf", &particle.distance);
        
        while(particle.distance <= 0){
            printf("Enter a distance greater than zero: "); 
            scanf("%lf", &particle.distance);
        }

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
        
        printf("Enter the time in (seconds): ");
        scanf("%lf", &particle.time);
        
        while(particle.time <= 0){
            printf("Enter a time greater than zero: "); 
            scanf("%lf", &particle.time);
        }

        printf("Enter the distance in (meters): ");
        scanf("%lf", &particle.distance);
        
        while(particle.distance <= 0){
            printf("Enter a distance greater than zero: "); 
            scanf("%lf", &particle.distance);
        }

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
    printf("Selection: ");
    scanf("%d", &selection);

    while(selection < 1 || selection > 4){
        printf("Invalid choice, try again: ");
        scanf("%d", &selection);
    }

    switch (selection)
    {
    case 1:
        
        printf("\nCalculate Distance\n");
        
        printf("\nKNOWN VARIABLES:\n");
        printf("Acceleration\n");
        printf("Initial Velocity\n");
        printf("Time\n");

        printf("\nEnter the acceleration in (meters/second ^2): ");
        scanf("%lf", &particle.acceleration);

        while(particle.acceleration <= 0){
        printf("Enter an acceleration greater than zero: ");
        scanf("%lf", &particle.acceleration);
        }

        printf("Enter the initial velocity in (meters/second): ");
        scanf("%lf", &particle.initial_velocity);

        while(particle.initial_velocity < 0){
        printf("Enter zero or a initial velocity greater than zero: ");
        scanf("%lf", &particle.initial_velocity);
        }

        printf("Enter the time in seconds: ");
        scanf("%lf", &particle.time);
        while(particle.time <= 0){
        printf("Enter a time greater than zero: ");
        scanf("%lf", &particle.time);
        }

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

        printf("\nEnter the acceleration in (meters/second ^2): ");
        scanf("%lf", &particle.acceleration);

        while(particle.acceleration <= 0){
            printf("Enter an acceleration greater than zero: ");
            scanf("%lf", &particle.acceleration);
        }

        printf("Enter the initial velocity in (meters/second): ");
        scanf("%lf", &particle.initial_velocity);

        while(particle.initial_velocity < 0){
            printf("Enter zero or a initial velocity greater than zero: ");
            scanf("%lf", &particle.initial_velocity);
        }

        printf("Enter the time in seconds: ");
        scanf("%lf", &particle.time);
        while(particle.time <= 0){
            printf("Enter a time greater than zero: ");
            scanf("%lf", &particle.time);
        }

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

        printf("\nEnter the final velocity in (meters/second): ");
        scanf("%lf", &particle.final_velocity);

        while(particle.final_velocity < 0){
            printf("Enter zero or a initial velocity greater than zero: ");
            scanf("%lf", &particle.final_velocity);
        }

        printf("Enter the initial velocity in (meters/second): ");
        scanf("%lf", &particle.initial_velocity);

        while(particle.initial_velocity < 0){
            printf("Enter zero or a initial velocity greater than zero: ");
            scanf("%lf", &particle.initial_velocity);
        }
        
        printf("Enter the time in seconds: ");
        scanf("%lf", &particle.time);
        while(particle.time <= 0){
            printf("Enter a time greater than zero: ");
            scanf("%lf", &particle.time);
        }

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

        printf("\nEnter the final velocity in (meters/second): ");
        scanf("%lf", &particle.final_velocity);

        while(particle.final_velocity < 0){
            printf("Enter zero or a initial velocity greater than zero: ");
            scanf("%lf", &particle.final_velocity);
        }

        printf("Enter the initial velocity in (meters/second): ");
        scanf("%lf", &particle.initial_velocity);

        while(particle.initial_velocity < 0){
            printf("Enter zero or a initial velocity greater than zero: ");
            scanf("%lf", &particle.initial_velocity);
        }

        printf("Enter the acceleration in (meters/second ^2): ");
        scanf("%lf", &particle.acceleration);

        while(particle.acceleration <= 0){
            printf("Enter an acceleration greater than zero: ");
            scanf("%lf", &particle.acceleration);
        }
        
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