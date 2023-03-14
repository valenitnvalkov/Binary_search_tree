#include<stdio.h>
#include<string.h>

struct companyDetails
{
	char companyName[35];	
	int numOfWorkers;	
};
 
struct worker
{
	char name[15];			
	char middleName[15];	
	char surname[15];	
	char EGN[11];			
	int workPeriod;		
	int workDaysInAMonth;	
	float moneyPerDay[25];
};
 
 void input(struct worker* currentWorker);
 double salary(struct worker* currentWorker);
 void output(struct worker* currentWorker);

void input(struct worker* currentWorker)			
{
	printf("\nEnter your first name: "); 
	scanf("%s", currentWorker->name, 14);			
	printf("Enter your middle name: ");
	scanf("%s", currentWorker->middleName, 14);
	printf("Enter your last name: ");
	scanf("%s", currentWorker->surname, 14);		
	printf("Enter your EGN: ");
	scanf("%s", currentWorker->EGN, 10);			
	printf("Enter how many years you have worked: ");
	scanf("%d", &currentWorker->workPeriod);		
	printf("Enter how many days in a month you work: ");
	scanf("%d", &currentWorker->workDaysInAMonth);		
	for (int i = 0; i < currentWorker->workDaysInAMonth; i++) 
	{
		printf("Enter your daily salary: ");
		do
		{
			scanf("%f", &currentWorker->moneyPerDay[i]);
		} while (currentWorker->moneyPerDay[i] < 0);
	}
	printf("\n");
}
 
double salary(struct worker* currentWorker) 
{
	double sum = 0; 
	for (int i = 0; i < currentWorker->workDaysInAMonth; i++)
	{
		sum += currentWorker->moneyPerDay[i];
	}
	sum += (currentWorker->workPeriod * 0.015 * sum); 
	sum *= 0.75; 
	return sum; 
}
 
void output(struct worker* currentWorker) 
{
	printf("%s %s %s\n", currentWorker->name, currentWorker->middleName, currentWorker->surname);
	printf("%.2lf\n", salary(currentWorker));
}
 
int main()
{
	struct companyDetails detailsOfTheCompany;
	struct worker allWorkers[100];						
    printf("WEELCOME TO THE MENU! Please follow the instructions.\n");
	printf("\nEnter the company name: ");
	scanf("%s", detailsOfTheCompany.companyName, 34); 
	printf("Enter the number of workers: ");
	scanf("%d", &detailsOfTheCompany.numOfWorkers);	
	for (int i = 0; i < detailsOfTheCompany.numOfWorkers; i++)
	{
		input(&allWorkers[i]); 
	}
	int inputByUser = -2;
	printf("\n1. To see the salary for particular worker (press 1)\n");
	printf("2. To see the salary for every worker (press 2)\n");
	printf("3. To exit (press 3)\n");
	scanf("%d", &inputByUser);
	while (inputByUser != 3)
	{
		if (inputByUser == 1)
		{
			char particularWorkerEGN[11];
			printf("Enter the person's EGN: ");
			scanf("%s", particularWorkerEGN, 10);
			for (int i = 0; i < detailsOfTheCompany.numOfWorkers; i++)
			{
				if (strcmp(allWorkers[i].EGN, particularWorkerEGN) == 0)
				{
					printf("The salary of the person is: %.2lf\n", salary(&allWorkers[i]));
					printf("\n");
				}
			}
		}
		else if (inputByUser == 2)
		{
			for (int i = 0; i < detailsOfTheCompany.numOfWorkers; i++)
				output(&allWorkers[i]);
		}
		printf("\nTo see the salary for particular worker (press 1)\n");
		printf("To see the salary for every worker (press 2)\n");
		printf("To exit (press 3)\n");
		scanf("%d", &inputByUser);
	}
	return 0;
}
