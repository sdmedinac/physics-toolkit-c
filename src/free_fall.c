#include<stdio.h>
#include<math.h>
#include "../include/free_fall.h"
#include "../include/constants.h"

void free_fall(Free_Fall particle)
{    
    particle.initial_velocity = 0; // for the version (1)
    printf("Enter initial hight in (meters): ");
    scanf("%lf", &particle.initial_height);
    
    while(particle.initial_height <= 0){
        printf("Enter a hight greater than zero: ");
        scanf("%lf", &particle.initial_height);
    }
    
    particle.distance = particle.initial_height;

    particle.time = sqrt((2 * particle.initial_height)/(GRAVITY));
    particle.final_velocity = -sqrt(2*GRAVITY*particle.initial_height);

    printf("\nTime of fall: %.2fs\n", particle.time);
    printf("Final velocity: %.2fm/s\n", particle.final_velocity);
    printf("Distance: %.2fm\n", particle.distance);    
}