#include<stdio.h>
#include<math.h>
#include "../include/free_fall.h"
#include "../include/constants.h"
#include "../include/input_utils.h"

void free_fall(Free_Fall particle)
{    
    int selection;
    printf("\nChoose one option\n");

    printf("\n(1) Released From Rest\n");
    printf("(2) Initial Downward Velocity\n");
    printf("(3) Initial Upward Velocity\n");

    selection = read_menu_option("\nSelection: ", 1, 3);
    
    switch (selection)
    {
    case 1:
        
        printf("\nReleased From Rest\n");

        particle.initial_velocity = 0; // Released from rest
        particle.initial_height = read_positive_double("\nEnter initial height (m): ");
        printf("\nInitial height: %.2fm\n", particle.initial_height);
    
        particle.distance = particle.initial_height;

        particle.time = sqrt((2 * particle.initial_height)/(GRAVITY));
        particle.final_velocity = -sqrt(2*GRAVITY*particle.initial_height);

        printf("\nTime of fall: %.2fs\n", particle.time);
        printf("Final velocity: %.2fm/s\n", particle.final_velocity);
        printf("Distance: %.2fm\n", particle.distance);

        break;
    case 2:

        printf("\nInitial Downward Velocity\n");

        particle.initial_height = read_positive_double("\nEnter initial height (m): ");
        particle.initial_velocity = read_positive_double("Enter the initial downward velocity in (m/s): ");

        printf("\nInitial height: %.2fm\n", particle.initial_height);
        printf("Initial downward velocity: %.2fm/s\n", particle.initial_velocity);

        particle.distance = particle.initial_height;
        particle.final_velocity = sqrt(pow(particle.initial_velocity, 2) + 2*GRAVITY*particle.initial_height);
        particle.time = (particle.final_velocity - particle.initial_velocity) / GRAVITY;
        
        printf("\nTime of fall: %.2fs\n", particle.time);
        printf("Final velocity: %.2fm/s\n", (-1) * particle.final_velocity);
        printf("Distance: %.2fm\n", particle.distance);

        break;
    case 3:

        double t_up;
        double h_max;
        int choice;
        
        printf("\nInitial Upward Velocity\n");

        particle.initial_velocity = read_positive_double("\nEnter the initial upward velocity in (m/s): ");

        printf("\nLaunch location\n");
        printf("(1) Ground level\n");
        printf("(2) Elevated position\n");
        choice = read_menu_option("\nSelection: ", 1, 2);

        if(choice == 1){
            
            particle.initial_height = 0;
            printf("\nInitial upward velocity: %.2fm/s\n", particle.initial_velocity);
            printf("Launched from the ground, initial height: %.2fm\n", particle.initial_height);

            t_up = particle.initial_velocity / GRAVITY;
            h_max = (pow(particle.initial_velocity, 2))/(2*GRAVITY);
            particle.time = (2*particle.initial_velocity) / GRAVITY;
            particle.final_velocity = (-1) * particle.initial_velocity;

            printf("\nTime To Maximum Height: %.2fs\n", t_up);
            printf("Maximum height: %.2fm\n", h_max);
            printf("Total Flight Time: %.2fs\n", particle.time);
            printf("Impact Velocity: %.2fm/s\n", particle.final_velocity);
        }
        else if(choice == 2){
            
            particle.initial_height = read_positive_double("\nEnter initial height (m): ");

            printf("\nInitial upward velocity: %.2fm/s\n", particle.initial_velocity);
            printf("Initial height: %.2fm\n", particle.initial_height);

            t_up = particle.initial_velocity / GRAVITY;
            h_max = (pow(particle.initial_velocity, 2))/(2*GRAVITY) + particle.initial_height;
            particle.time = (2*particle.initial_velocity + sqrt(4*pow(particle.initial_velocity, 2) + 8*GRAVITY*particle.initial_height)) / (2*GRAVITY);
            particle.final_velocity = particle.initial_velocity - GRAVITY*particle.time;

            printf("\nTime To Maximum Height: %.2fs\n", t_up);
            printf("Maximum height: %.2fm\n", h_max);
            printf("Total Flight Time: %.2fs\n", particle.time);
            printf("Impact Velocity: %.2fm/s\n", particle.final_velocity);
        }

        break;
    default:
        break;
    }
}