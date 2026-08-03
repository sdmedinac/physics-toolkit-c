#include<stdio.h>
#include "../include/input_utils.h"

double read_positive_double(const char *message)
{
    double value;
    
    printf("%s", message);
 
    while(1){
        
        if(scanf("%lf", &value) == 1 && value > 0){
            return value;
        }

        while(getchar() != '\n');
        printf("Invalid  input. Try again\n");
        printf("%s", message);
    }
}

int read_menu_option(const char *message, int min, int max)
{
    int choice;
    
    printf("%s", message);
    
    while(1){
        
        if(scanf("%d", &choice) == 1 && choice >= min && choice <= max){
            return choice;
        }

        while(getchar() != '\n');
        printf("Invalid input, try again\n");
        printf("Selection: ");
    }
}