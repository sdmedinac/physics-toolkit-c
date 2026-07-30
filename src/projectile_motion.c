#include <stdio.h>
#include <math.h>
#include "../include/projectile_motion.h"
#include "../include/constants.h"

void projectile_motion(Projectile particle)
{
    int selection;
    double launch_angle_rad;

    printf("\nChoose one option\n");

    printf("\n(1) Ground Launch\n");
    printf("(2) Elevated Launch\n");
    printf("(3) Horizontal Launch\n");

    printf("Selection: ");
    scanf("%d", &selection);

    while(selection < 1 || selection > 3){
        printf("Invalid choice, try again: ");
        scanf("%d", &selection);
    }

    switch(selection)
    {
        case 1:

            printf("\nGround Launch\n");

            printf("\nEnter the initial velocity (m/s): ");
            scanf("%lf", &particle.initial_velocity);

            while(particle.initial_velocity <= 0){
                printf("Enter a velocity greater than zero: ");
                scanf("%lf", &particle.initial_velocity);
            }

            printf("Enter the launch angle (degrees): ");
            scanf("%lf", &particle.launch_angle);

            while(particle.launch_angle <= 0 || particle.launch_angle >= 90){
                printf("Enter an angle between 0 and 90 degrees: ");
                scanf("%lf", &particle.launch_angle);
            }
            printf("\nInitial velocity: %.2fm/s\n", particle.initial_velocity);
            printf("Launch angle: %.2fdeg\n", particle.launch_angle);

            launch_angle_rad = particle.launch_angle * (PI / 180.0);

            particle.vx = particle.initial_velocity * cos(launch_angle_rad);
            particle.vy = particle.initial_velocity * sin(launch_angle_rad);

            particle.flight_time = (2 * particle.vy) / GRAVITY;
            particle.max_height = (pow(particle.vy, 2)) / (2 * GRAVITY);
            particle.range = particle.vx * particle.flight_time;

            printf("\nHorizontal velocity: %.2fm/s\n", particle.vx);
            printf("Vertical velocity: %.2fm/s\n", particle.vy);

            printf("\nFlight time: %.2fs\n", particle.flight_time);
            printf("Maximum height: %.2fm\n", particle.max_height);
            printf("Range: %.2fm\n", particle.range);

            break;

        case 2:

            printf("\nElevated Launch\n");

            printf("\nEnter the initial height (m): ");
            scanf("%lf", &particle.initial_height);

            while(particle.initial_height <= 0){
                printf("Enter a height greater than zero: ");
                scanf("%lf", &particle.initial_height);
            }

            printf("Enter the initial velocity (m/s): ");
            scanf("%lf", &particle.initial_velocity);

            while(particle.initial_velocity <= 0){
                printf("Enter a velocity greater than zero: ");
                scanf("%lf", &particle.initial_velocity);
            }

            printf("Enter the launch angle (degrees): ");
            scanf("%lf", &particle.launch_angle);

            while(particle.launch_angle <= 0 || particle.launch_angle >= 90){
                printf("Enter an angle between 0 and 90 degrees: ");
                scanf("%lf", &particle.launch_angle);
            }

            launch_angle_rad = particle.launch_angle * (PI / 180.0);

            particle.vx = particle.initial_velocity * cos(launch_angle_rad);
            particle.vy = particle.initial_velocity * sin(launch_angle_rad);

            particle.flight_time =
            (
                particle.vy +
                sqrt(pow(particle.vy, 2)
                + 2 * GRAVITY * particle.initial_height)
            )
            / GRAVITY;

            particle.max_height =
            particle.initial_height +
            (pow(particle.vy, 2) / (2 * GRAVITY));

            particle.range =
            particle.vx * particle.flight_time;

            printf("\nHorizontal velocity: %.2fm/s\n", particle.vx);
            printf("Vertical velocity: %.2fm/s\n", particle.vy);

            printf("\nFlight time: %.2fs\n", particle.flight_time);
            printf("Maximum height: %.2fm\n", particle.max_height);
            printf("Range: %.2fm\n", particle.range);

            break;

        case 3:

            printf("\nHorizontal Launch\n");

            printf("\nEnter the initial height (m): ");
            scanf("%lf", &particle.initial_height);

            while(particle.initial_height <= 0){
                printf("Enter a height greater than zero: ");
                scanf("%lf", &particle.initial_height);
            }

            printf("Enter the horizontal velocity (m/s): ");
            scanf("%lf", &particle.initial_velocity);

            while(particle.initial_velocity <= 0){
                printf("Enter a velocity greater than zero: ");
                scanf("%lf", &particle.initial_velocity);
            }

            particle.vx = particle.initial_velocity;
            particle.vy = 0;

            particle.flight_time =
            sqrt((2 * particle.initial_height) / GRAVITY);

            particle.range =
            particle.vx * particle.flight_time;

            printf("\nHorizontal velocity: %.2fm/s\n", particle.vx);

            printf("\nFlight time: %.2fs\n", particle.flight_time);
            printf("Range: %.2fm\n", particle.range);

            break;
    }
}