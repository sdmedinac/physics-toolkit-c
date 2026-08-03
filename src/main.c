#include<stdio.h>
#include "../include/projectile_motion.h"
#include "../include/free_fall.h"
#include "../include/linear_motion.h"
#include "../include/input_utils.h"
char try_again();   

int main(void)
{   
    int option; char again;
    do {
        
        printf("------------------------------\n");
        printf("Welcome to the Physics Toolkit\n");
        printf("------------------------------\n");

        printf("\n");

        printf("Toolkit: \n");
        printf("\n");
        printf("(0) Exit.\n");
        printf("(1) Projectile Motion.\n");
        printf("(2) Free Fall.\n");
        printf("(3) Uniform Linear Motion (ULM).\n");
        printf("(4) Uniformly Accelerated Motion (UAM).\n");
        printf("\n");
        
        option = read_menu_option("Choose one option of the toolkit: ",0 ,4);
        if(option == 0){
            printf("\nExiting Physics Toolkit...\n");
        }
        
        switch (option)
        {
        case 1:
            printf("\n**************************");
            printf("\nProjectile Motion Module: \n");
            printf("**************************\n\n");
            
            Projectile projectile;
            projectile_motion(projectile);
            
            again = try_again();
            break;
        case 2:
            printf("\n**************************");
            printf("\nFree Fall Module: \n");
            printf("**************************\n\n");
            
            Free_Fall rock;
            free_fall(rock);

            again = try_again();
            break;
        case 3:
            printf("\n**************************");
            printf("\nUniform Linear Motion Module: \n");
            printf("**************************\n\n");
            
            Linear_Motion particle;
            uniform_linear_motion(particle);

            again = try_again();
            break;
        case 4:
            printf("\n**************************");
            printf("\nUniformly Accelerated Motion Module: \n");
            printf("**************************\n\n");
            
            Linear_Motion object;
            accelerated_uniform_linear_motion(object);
            
            again = try_again();
            break;
        default:
            
            break;
        }

    } while(again == 'y' || again == 'Y');
    
    return 0;
}

char try_again()
{
    char again;
    printf("Enter 'y' or 'Y' to go back to menu: ");
    scanf(" %c", &again);
    return again;
}