#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
#define INFO 50
void viewMenu();//prototype of function that display the menu
int enterCustomer(char cust[][INFO], int );//prototype of function that ask the user to enter new customer Information
void viewCustomer(char cust[][INFO], int );//prototype of function that print all Customers Information
int enterVehicle(char vehic[][INFO], int );//prototype of function that ask the user to enter new vehicle Information
void viewVehicle(char vehic[][INFO], int );//prototype of function that print all Vehicles Information
char blank; //global variable
/*---------------------------------------------------------------------------------------------------------*/
int main() //start main
{
    

	int select;
	char Customers[SIZE][INFO];//declaration of 2D array
	char Vehicle[SIZE][INFO];//declaration of 2D array
	int countCust = 0;//initialize countCust
	int countVehic=0;//initialize countVehic
	
	do
	{ //using do-while loop
	
		viewMenu(); //call viewMenu function
		printf("Enter your selected number :");
		scanf("%d", &select);
		
		switch (select)
		{ //start switch
		    
		case 1:
			scanf("%c", &blank); //to ignore the enter key
			countCust=enterCustomer(Customers, countCust); //call enterCustomer function
			break; //breaks out of the switch block and stops the execution
			
		case 2:
			scanf("%c", &blank);
			countVehic = enterVehicle(Vehicle, countVehic); //call enterVehicle function
			break;
			
		case 3:
			viewCustomer(Customers, countCust); //call viewCustomer function
			break;
			
		case 4:
			viewVehicle(Vehicle, countVehic); //call viewVehicle function
			break;
			
		case 5:
		    for(int i=0; i<40; i+=3)
		    {
		        printf("*****");
            }
			printf("\n\t\tApplication Has Been Ends\n");
			printf("\t\t\t Good Bye!");
			exit(0); //to break out of a loop 
			
		default: //run if there is no case match
		    for(int i=0; i<40; i+=3)
		    {
		        printf("-----");
            }
			printf("\nWrong Enter Selected --Try Again-- \n");
			
		} //end of switch
	} while ( select != 5 ); //condition

	return 0;
} //end of main
/*---------------------------------------------------------------------------------------------------------*/
void viewMenu() //function definition that does not return any value
{
	printf("\n"); //new line
    for(int i=0; i<40; i+=3)
    {
        printf("*****");
    }//end for loop
    
	printf("\n\t---------- Car Rental Application ----------\n");
	for(int i=0; i<40; i+=3)
	{
        printf("*****");
    }//end for loop
    
    //display the menu for the user to choose an option
	printf("\n\t1 - To Add A New Customer\n");
	printf("\t2 - To Add A New vehicle\n");
	printf("\t3 - To Print All Customers\' Information\n");
	printf("\t4 - To Print All Vehicles\' Information\n");
	printf("\t5 - To Quit\n");
	
} //end viewMenu function
/*---------------------------------------------------------------------------------------------------------*/
int enterCustomer(char cust[][INFO], int counter) //enterCustomer function definition
{
	for(int i=0; i<40; i+=3)
	{
	    printf("-----");
    }//end for loop
	printf("\nEnter Customer ID: ");
	scanf("%s", cust[counter++]); //read string input from user and increment the counter
	scanf("%c", &blank);
	printf("Enter Customer Name: ");
	fgets(cust[counter++], INFO, stdin);
	size_t length = strlen(cust[counter-1]) - 1;
	
	if (cust[counter-1][length] == '\n')
	{
		cust[counter-1][length] = '\0';
	}
	printf("Enter Customer Phone: ");
	scanf("%s", cust[counter++]);
	
	
	return counter; //return counter
} //end enterCustomer function
/*---------------------------------------------------------------------------------------------------------*/
int enterVehicle(char vehic[][INFO], int counter) //enterVehicle function definition
{
    for(int i=0; i<40; i+=3)
    {
        printf("-----");
    }//end for loop
	printf("\nEnter Model year: ");
	scanf("%s", vehic[counter++]); //read string input from user and increment the counter
	printf("Enter Make: ");
	scanf("%s", vehic[counter++]);
	scanf("%c",&blank);
	printf("Enter Model name: ");
	scanf("%s", vehic[counter++]);
	printf("Enter Model License plate number: ");
	scanf("%s", vehic[counter++]);
	printf("Enter Customer number who is currently renting vehicle: ");
	scanf("%s", vehic[counter++]);
	
	
	return counter; //return counter
} //end enterVehicle function
/*---------------------------------------------------------------------------------------------------------*/
void viewCustomer(char cust[][INFO], int counter) //function definition that does not return any value
{
    for(int i=0; i<40; i+=3)
    {
        printf("-----");
    }//end for loop
    
	printf("\nCustomer Infomration : \n");
    
    //print all Customer Infomration in tabular format
	printf("%s%4s%15s%4s%17s%4s%18s\n","Num","|","Customer ID","|", "Customer Name","|", "Customer Phone");
	
	for (int i = 0; i < counter; i+=3)
	{
		printf("%-6d%-5s%-14s%-5s%-16s%-5s%s\n", (i/3)+1,"|", cust[i],"|", cust[i+1],"|", cust[i+2]);
	}//end for loop
	
	for(int i=0; i<40; i+=3)
	{
	    printf("-----");
	}//end for loop
	
	printf("\n\n");
	
} //end viewCustomer function
/*---------------------------------------------------------------------------------------------------------*/
void viewVehicle(char vehic[][INFO], int counter) //function definition that does not return any value
{
    for(int i=0; i<40; i+=3)
    {
        printf("-----");
    }//end for loop
    
    printf("\nVechiles Infomration : \n");
    
    //print all Vehicles Infomration in tabular format
	printf("%s%4s%14s%4s%9s%11s%14s%4s%24s%4s%19s\n","Num","|","Model year","|","Make","|","Model name","|","License plate number","|","Customer number");
	
	for (int i = 0; i < counter; i+=5)
	{
		printf("%-6d%-5s%-13s%-6s%-14s%-5s%-13s%-5s%-23s%-5s%s\n", (i/5) + 1,"|", vehic[i],"|", vehic[i + 1],"|", vehic[i + 2],"|", vehic[i+3],"|", vehic[i+4]);
	}//end for loop
	
	for(int i=0; i<40; i+=3)
	{
	    printf("-----");
    }//end for loop
    
    printf("\n\n");
    
} //end viewVehicle function