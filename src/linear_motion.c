#include<stdio.h>
#include<math.h>
#include "../include/linear_motion.h"

void uniform_linear_motion(Linear_Motion particle)
{
    particle.acceleration = 0; // ULM CONDITION
    int selection;
    printf("\nKNOWN DATA: \n");
    
    printf("\n*********\n");
    printf("REMAINDER\n");
    printf("*********\n");
   
    printf("\nYou must know at least two of this three quantities to solve the problem:\n");

    printf("\nVelocity\n");
    printf("Time\n");
    printf("Distance\n");

    printf("\nEnter (1) if you know the velocity and time\n");
    printf("Enter (2) if you know the velocity and the distance\n");
    printf("Enter (3) if you know the time and the distance\n");
    printf("Selection: ");
    scanf("%d", &selection);

    while(selection != 1 && selection != 2 && selection != 3){
        printf("Invalid choice, try again: ");
        scanf("%d", &selection);
    }

    if(selection == 1){
        
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
    }
    else if(selection == 2){
        
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
    }
    else if(selection == 3){
        
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
    }    
}

void accelerated_uniform_linear_motion(Linear_Motion particle)
{
    printf("Enter the acceleration in (meters/second ^2): ");
    scanf("%lf", &particle.acceleration);

    while(particle.acceleration <= 0){
        printf("Enter an acceleration greater than zero: ");
        scanf("%lf", &particle.acceleration);
    }

    printf("Enter the initial velocity in (meters/second): ");
    scanf("%lf", &particle.initial_velocity);

    while(particle.initial_velocity < 0){
        printf("Enter zero or a velocity greater than zero: ");
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
}