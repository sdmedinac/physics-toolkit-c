#include <stdio.h>
#include <math.h>
#include "../include/projectile_motion.h"
#include "../include/constants.h"
#include "../include/input_utils.h"

void projectile_motion(Projectile particle)
{
    int selection;
    double launch_angle_rad;

    printf("\nChoose one option\n");
 
    printf("\n(1) Ground Launch\n");
    printf("(2) Elevated Launch\n");
    printf("(3) Horizontal Launch\n");

    selection = read_menu_option("\nSelection: ", 1, 3);

    switch(selection)
    {
        case 1:

            printf("\nGround Launch\n");

            particle.initial_velocity = read_positive_double("\nEnter the initial velocity (m/s): ");

            particle.launch_angle = read_positive_double("Enter the launch angle (degrees): ");
            
            while(particle.launch_angle >= 90){
                printf("\nInvalid angle\n");
                particle.launch_angle = read_positive_double(
                    "Enter an angle greater than zero and less than ninety: ");
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

            particle.initial_height = read_positive_double("\nEnter the initial height (m): ");

            particle.initial_velocity = read_positive_double("Enter the initial velocity (m/s): ");

            particle.launch_angle = read_positive_double("Enter the launch angle (degrees): ");

            while(particle.launch_angle >= 90){
                printf("\nInvalid angle\n");
                particle.launch_angle = read_positive_double(
                    "Enter an angle greater than zero and less than ninety: ");
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

            particle.initial_height = read_positive_double("\nEnter the initial height (m): ");

            particle.initial_velocity = read_positive_double("\nEnter the horizontal velocity (m/s): ");

            particle.vx = particle.initial_velocity;
            particle.vy = 0;

            particle.flight_time = sqrt((2 * particle.initial_height) / GRAVITY);

            particle.range = particle.vx * particle.flight_time;

            printf("\nHorizontal velocity: %.2fm/s\n", particle.vx);

            printf("\nFlight time: %.2fs\n", particle.flight_time);
            printf("Range: %.2fm\n", particle.range);

            break;
    }
}