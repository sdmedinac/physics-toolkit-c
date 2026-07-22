#include<stdio.h>
#include<math.h>
#include "../include/linear_motion.h"

void uniform_linear_motion(Linear_Motion particle)
{
    particle.acceleration = 0; // ULM CONDITION
    printf("\nEnter the velocity in (meters/second): ");
    scanf("%lf", &particle.initial_velocity);
    while(particle.initial_velocity <= 0){
        printf("Enter a velocity greater than zero: ");
        scanf("%lf", &particle.initial_velocity);
    }
    

    particle.final_velocity = particle.initial_velocity; // ULM CONDITION
    
    printf("Enter the time in seconds: ");
    scanf("%lf", &particle.time);
    while(particle.time <= 0){
        printf("Enter a time greater than zero: ");
        scanf("%lf", &particle.time);
    }

    printf("\nInitial velocity: %.2fm/s\n", particle.initial_velocity);
    printf("Time in movement: %.2fs\n", particle.time);

    particle.distance = particle.initial_velocity * particle.time;
    printf("\nThe distance is %.2fm\n", particle.distance);
}

void accelerated_uniform_linear_motion(Linear_Motion particle)
{
    printf("Enter the acceleration in (meters/second ^2): ");
    scanf("%lf", &particle.acceleration);

    while(particle.acceleration <= 0){
        printf("Enter an acceleration greather than zero: ");
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