/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Jose Leyba
 * Program to order a sales report receiving an input file
 */
#include <stdio.h>

void swap(float* x, float* y) //given two pointer elements, swap them
{
    float temp = *x; //saves one as a temporary
    *x = *y; //Sets that one to the value of the other
    *y = temp; //Sets the other one to the previous value of the other
}



int main()
{

	char months[13][20] = { "a","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }; //Array of months of the year
    float sales_monthly[12]; //Creates array to save the input file data
    FILE* inputfile; // Looks at our input file
    int i = 0; //Creates number to iterate through the files
    if (inputfile = fopen("inputfile.txt", "r")) //Opens the inputfile in reading mode
    {
        while (fscanf(inputfile, "%f", &sales_monthly[i]) != EOF) //while we have not reached the end of the file, scans and saves the values on the array
        {
            i++; //Augments the index of the array
        }
        fclose(inputfile); //Closes files to avoid problems
        sales_monthly[i] = '\0'; //Saves the last position of the array as \0
    }

    //Output Starts Showing
    printf("Monthly sales report for 2022\n\n");
    printf("Month   Sales\n");
    for (i = 0; sales_monthly[i] != '\0'; i++) //Loops through
    {
    	printf("%s $%.2f\n", months[i+1], sales_monthly[i]); //Prints the sales for each month
    }
    printf("\n\n\n"); //Leaves a space on the code




    //Gets Smaller and Bigger Sales
    float smallest, biggest; //Temporary saves for prices

    smallest = sales_monthly[0]; //starts at January all
    biggest = sales_monthly[0]; //Starts at January all
    int small_month = 0; //Starts at January all
    int big_month = 0; //Starts at January all
    float total = 0; //All the sales we got

    for (i = 0; sales_monthly[i] != '\0'; i++) //Loops through the sales
    {
    	total += sales_monthly[i]; //Sums all the sales
    	if( smallest > sales_monthly[i] ) //Compares if the smallest is still the smaller
        {
    		smallest = sales_monthly[i]; //If it was not, set a new smaller
    		small_month = i; // Saves the index for the month
        }
        if( biggest < sales_monthly[i] ) //Compares if the biggest is still the biggest one
        {
        	biggest = sales_monthly[i]; //If it was not, set a new biggest
        	big_month = i; //Saves the index for the month
        }
    }
    printf("Sales Summary:\n"); //Prints the summary of the sales
    printf("Minimum sales: $%.2f (%s)\n", smallest, months[small_month+1]);
    printf("Maximum sales: $%.2f (%s)\n", biggest, months[big_month+1]);
    printf("Average Sales: $%.2f\n\n\n", total/12);




    //Moving Average
    float average = 0; // To mantain an average
    int start; // Saves a start
    printf("Six-Month Moving Average Report:\n");
    for (i = 0; i< 7; i++ ) //Loops through half the list
    {
    	average = 0; //Resets average after each loop
    	for (int j = 0; j < 6;  j++) //Loops  through half the list again
    	{
    		start = i+j; //Saves the starting point
    		average += sales_monthly[start]; //Does the average of the 6 months

    	}
    	printf("%s - %s $%.2f\n",months[i+1],months[i+6], average/6); //Prints the average
    }
    printf("\n\n\n"); //Leaves a space between the code


    //Code for sort of array
    int min_idx; //Saves minimum index
    char temp [20]; //Temporary for the Months
    for (i = 0; i < 11; i++) //Loops through almost all months
    {
    	min_idx = i; //Set the minimum of unsorted at the last index checked
        for (int j = i + 1; j < 12; j++) //Loop through the indexes not sorted yet
        {
        	if (sales_monthly[j] > sales_monthly[min_idx]) //If it finds something bigger than what's at the start
        	{
        		min_idx = j; // saves it
        	}
        }
    swap(&sales_monthly[min_idx], &sales_monthly[i]); //Swaps (only changes if last is biggest
    strcpy(temp, &months[min_idx+1]); //Sorts the strings (Starts by saving what's on the min index on a temporary
    strcpy(months[min_idx+1], months[i+1]); // Changes what's on i and on the min index (it's the same if it's sorted)
    strcpy(months[i+1],temp); //Copies whatever was on the temp to the new position
    }


    printf("Sales Report (Highest to Lowest):\n");
    for (i = 0; sales_monthly[i] != '\0'; i++) //Loops through
        {
        	printf("%s $%.2f\n",months[i+1], sales_monthly[i]); //Prints the sales for each month
        }
    return 0;



}
