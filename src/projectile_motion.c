#include<stdio.h>
#include<math.h>
#include "../include/projectile_motion.h"
#include "../include/constants.h"


void projectile_motion(Projectile particle)
{
    double launch_angle_rad;

    printf("Enter the initial velocity in (meters/second): ");
    scanf("%lf", &particle.initial_velocity);
    while(particle.initial_velocity <= 0){
        printf("Error, enter a velocity greater than zero: ");
        scanf("%lf", &particle.initial_velocity);
    }
    
    printf("\nEnter the launch angle in (degrees): ");
    scanf("%lf", &particle.launch_angle);
    while(particle.launch_angle >= 90 || particle.launch_angle <= 0){
        printf("Enter an angle less than ninety degrees: ");
        scanf("%lf", &particle.launch_angle);
    }
    
    launch_angle_rad = particle.launch_angle * (PI/180);

    printf("\nInitial velocity: %.2f m/s\n", particle.initial_velocity);
    printf("Launch angle: %.2f deg\n", particle.launch_angle);
    
    particle.vx = particle.initial_velocity * cos(launch_angle_rad);
    particle.vy = particle.initial_velocity * sin(launch_angle_rad);
    printf("\nHorizontal velocity: %.2fm/s\n", particle.vx);
    printf("Vertical velocity: %.2fm/s\n", particle.vy);

    particle.flight_time = (2 * particle.vy)/(GRAVITY);
    particle.max_height = (pow(particle.vy, 2))/(2 * GRAVITY);
    particle.range = (particle.vx) * (particle.flight_time);

    printf("\nFlight time: %.2fs\n", particle.flight_time);
    printf("Max height: %.2fm\n", particle.max_height);
    printf("Range: %.2fm\n\n", particle.range);
}