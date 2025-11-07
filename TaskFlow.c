#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define maxNumberOfNotes 100
#define maxNoteLength 500
#define maxNumberOfPlans 100
#define maxPlanLength 500

int choice;

char notes[maxNumberOfNotes][maxNoteLength]; 
int count = 0; 

char plans[maxNumberOfPlans][maxPlanLength];
char planDates[maxNumberOfPlans][11]; 
int planCount = 0;

void addNote() {
 if (count >= maxNumberOfNotes) {
    printf("Too many notes! Delete one first \n");
return;
}
printf("Enter your note: ");
scanf(" %[^\n]", notes[count]);
count++;
printf("Added note!\n");
}

void showNotes() {
if (count == 0) {
printf("No notes saved \n");
return;
}

printf("Your notes:\n");

for (int i = 0; i < count; i++) {
printf("%d: %s\n", i + 1, notes[i]);
  }
}

void deleteNote() {
    
int deleteNumber;

showNotes();

printf("Enter the note number to delete: ");
scanf("%d", &deleteNumber);
if (deleteNumber < 1 || deleteNumber > count) {
printf("Invalid number \n");
return;
} 

for (int i = deleteNumber - 1; i < count - 1; i++) {
strcpy(notes[i], notes[i + 1]);
}

count--;

printf("Note deleted \n");
}

void show() {
    
 
system("clear");
while(1) {
printf("                                    \n");
printf(" #    #  ####  ##### ######  ####   \n");
printf(" ##   # #    #   #   #      #       \n");
printf(" # #  # #    #   #   #####   ####   \n");
printf(" #  # # #    #   #   #           #  \n");
printf(" #   ## #    #   #   #      #    #  \n");
printf(" #    #  ####    #   ######  ####   \n");
printf("=============================================================\n");
printf("1  Add Note\n");
printf("2  Show Notes\n");
printf("3  Delete Note\n");
printf("0  Exit\n");
printf("Choose: ");

scanf("%d", &choice);

switch (choice) {

case 1: 
addNote(); 
break;

case 2: 
showNotes(); 
break;

case 3: 
deleteNote(); 
break;

case 0:

printf("exiting\n"); 
 return; 

default: printf("choose a number listed in the menu\n");
 }
}


}

void timer(){
printf(" #####                                                   \n");
printf(" #     #  ####  #    #  ####  #####   ####  #####   ####  \n");
printf(" #     # #    # ##  ## #    # #    # #    # #    # #    # \n");
printf(" ######  #    # # ## # #    # #    # #    # #    # #    # \n");
printf(" #       #    # #    # #    # #    # #    # #####  #    # \n");
printf(" #       #    # #    # #    # #    # #    # #   #  #    # \n");
printf(" #        ####  #    #  ####  #####   ####  #    #  ####  \n");
printf("=============================================================\n\n");
printf("Enter the desired time to study (hrs mins seconds) eg: 00 10 00 for 10 mins\n");

int hours;
int minutes; 
int seconds;

scanf("%d %d %d", &hours, &minutes, &seconds);

if(hours <0 || minutes<0 || seconds< 0 || minutes>= 60 || seconds>= 60){
  printf("please submit a valid time\n"); 
   return;
}

int combinedTime = hours * 3600 + minutes * 60 + seconds;


while(combinedTime >= 0){

 int hrs = combinedTime / 3600;
 int mins = (combinedTime % 3600) / 60;
 int secs = combinedTime % 60;

printf("\rTime left: %02d:%02d:%02d", hrs, mins, secs);
     fflush(stdout);
     sleep(1);     
     combinedTime--; 
 
}

    printf("\nstudy completed\n");
    
    system("aplay /home/s8460409/Downloads/67560^alarma.wav");

    
}

void taskTimer(){
    char choice;
    while(1){
  timer();
  
     printf("Do you want to start another session? y/n (y = yes, n = no): ");  
     scanf(" %c", &choice);
        if(choice == 'n'){
            printf("Good bye /n");
         
            break;
        }
    }
}

void addPlan() {
if (planCount >= maxNumberOfPlans) {
printf("Too many plans, Delete one .\n");
return;
    }

printf("what is  your plan?: ");
scanf(" %[^\n]", plans[planCount]);
printf("Enter the date (YYYY-MM-DD): ");
scanf("%s", planDates[planCount]);
 
planCount++;
 
printf("your plan has been added. \n");
}

void showPlans() {
if (planCount == 0) {
printf("you have made no plans.\n");
    return;
}
printf("Your plans: \n");
int i;
for (i= 0; i < planCount; i++) {
 
printf("%d: %s on %s\n", i + 1, plans[i], planDates[i]);
 
}
}

void deletePlan() {

int planToDelete;

showPlans();
printf("Enter the plan number that you want to delete: ");
scanf("%d", &planToDelete);
   
 if (planToDelete < 1 || planToDelete > planCount) {
  
  printf("Invalid number.\n");
   
  return;   
 }

for (int i = planToDelete - 1; i < planCount - 1; i++) {
    
 strcpy(plans[i], plans[i + 1]);
   strcpy(planDates[i], planDates[i + 1]);
    
}

 planCount--;
 printf("Plan deleted.\n");
}

void dayPlanner(){
  while(1){
system("clear");
 
printf("                                                                          \n");
printf(" #####    ##   #   #    #####  #        ##   #    # #    # ###### #####   \n");
printf(" #    #  #  #   # #     #    # #       #  #  ##   # ##   # #      #    #  \n");
printf(" #    # #    #   #      #    # #      #    # # #  # # #  # #####  #    #  \n");
printf(" #    # ######   #      #####  #      ###### #  # # #  # # #      #####   \n");
printf(" #    # #    #   #      #      #      #    # #   ## #   ## #      #   #   \n");
printf(" #####  #    #   #      #      ###### #    # #    # #    # ###### #    #  \n");
printf("                                                                          \n");
printf("========================================================================================\n");
printf("1  Add plan\n");
printf("2  See plans\n");
printf("3  Delete plan\n");
printf("0  Exit\n\n");
printf("enter your choice: ");
 
scanf("%d", &choice);

switch (choice) {
            
 case 1:
   addPlan();              
  break;
            
 case 2:
  showPlans();
 break;
 
 case 3:
  deletePlan();
 break;
            
 case 0:
     return; 
 default:
     printf("not a valid input, Please select a number from the menu.\n");
        }
  }
    }



void TuiPrint(){
system("clear");
 
    printf("===================================================================================================================\n\n");
    printf(" _________  ________  ________  ___  __            ________ ___       ________  ___       __      \n");
    printf("|\\___   ___\\\\   __  \\|\\   ____\\|\\  \\|\\  \\         |\\  _____\\\\  \\     |\\   __  \\|\\  \\     |\\  \\    \n");
    printf("\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|_       \\ \\  \\__/\\ \\  \\    \\ \\  \\|\\  \\ \\  \\    \\ \\  \\   \n");
    printf("     \\ \\  \\ \\ \\   __  \\ \\_____  \\ \\   ___  \\       \\ \\   __\\\\ \\  \\    \\ \\  \\\\\\  \\ \\  \\  __\\ \\  \\  \n");
    printf("      \\ \\  \\ \\ \\  \\ \\  \\|____|\\  \\ \\  \\\\ \\  \\       \\ \\  \\_| \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\|\\__\\_\\  \\ \n");
    printf("       \\ \\__\\ \\ \\__\\ \\__\\____\\_\\  \\ \\__\\\\ \\__\\       \\ \\__\\   \\ \\_______\\ \\_______\\ \\____________\\\n");
    printf("        \\|__|  \\|__|\\|__|\\_________\\|__| \\|__|        \\|__|    \\|_______|\\|_______|\\|____________|\n");
    printf("                        \\|_________|                                                              \n");
    printf("                                                                                                  \n\n");
    printf("===================================================================================================================\n");
    printf("| 1. Pomodoro Timer                                                                                                |\n");
    printf("| 2. Notes                                                                                                         |\n");
    printf("| 3. Day Planner                                                                                                   |\n");
    printf("| 0. Exit                                                                                                          |\n");
    printf("===================================================================================================================\n\n");
    printf("Choose an option: ");



}

void UserInput(){

scanf("%d", &choice);

switch (choice) {
case 1:
taskTimer();
break;
case 2:
 show();
break;
case 3:
dayPlanner();
break;
case 0:
exit(0);
break;
}
}

int main(){

     while(1){
     TuiPrint();
     UserInput();
}
    return 0;
}
