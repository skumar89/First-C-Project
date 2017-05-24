/* Assignment 1          IPC144                                     Sarthak Kumar (022-265-144)  */


#include <stdio.h>

int main ()

{

//Declare Constants
        const float basicfee = 35.00;
        const float regularrate = 1.10;
        const float latefee = 2.00;
        const float averageuse = .95;

//Declare Variables
        float unpaidbalance;
        float total = basicfee;

        int previousreading;
        int currentreading;
        int chargeablereading;
        int conservative;
        int lastqtr;

//User Instructions
        printf("This program calculates a water bill based on the demand charge ($%.2f) and a $%.2f per cubic meter use charge.\n\n", basicfee, regularrate);
        printf("A $%.2f surcharge is added to accounts with an unpaid balance.\n\n", latefee);
        printf("If you live in a conservation district, a conservation area rate will apply.\n\n");
        printf("Not meeting the coservations guidelines will result in an overuse charge of 2.0 times the regular rate.\n\n");
        printf("Enter an unpaid balance, previous, current meter readings and weather you lve in a conservation district on separate lines after the prompts.\n\n");

//User Input
        printf("Enter unpaid balance ($): ");
        scanf("%f", &unpaidbalance);

        printf("Enter previous meter reading: ");
        scanf("%d", &previousreading);
        printf("Enter current meter reading: ");
        scanf("%d", &currentreading);

        printf("Do you live in a conservation district (enter 0 for no and 1 for yes): ");
        scanf("%d", &conservative);

//Calculating Charges and Total
        chargeablereading = (currentreading - previousreading);

        total = total + unpaidbalance;

//Conservation district
        if (conservative)
        {
         printf("Since you live in a conservation district, you are required to use no more than 95.0%% of the amount of water you used in the same quarter last year in order to qualify for the rate of $%.2f per cubic meter.\n\n", regularrate);

        printf("Enter amount of water used in the same quarter last year: ");
        scanf("%d", &lastqtr);

        printf("\n");

        if (chargeablereading > (lastqtr * averageuse))
                {
                total = total + (chargeablereading*regularrate*2);
                printf("Use charge is at 2.00 times normal rate since use of %d units exceeds 95.0%% of last year's %d unit use.\n", chargeablereading, lastqtr);
                }
        else{
                total = total + (chargeablereading*regularrate);
                }
           }

//No conservation district
        else{
                total = total + (chargeablereading*regularrate);
            }

   printf("\n");

//Late Fees checker
        if(unpaidbalance > 0)
                {
                total = total + latefee;
                printf("Bill include $%.2f late charge on unpaid balance of $%.2f\n\n",latefee, unpaidbalance);
                }

        printf("Total Due = $%.2f\n", total);



return 0;
