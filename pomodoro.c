#include <stdio.h>
#include <time.h>
#include <unistd.h>

void timer(){

     printf("Enter the desired number of minutes you would like to study for:\n");
     int timeSelect=0;
     scanf("%d", &timeSelect); //take the ammount of time user would like the timer to go for
     if(timeSelect<1){
     printf("Selected time must be atleast 1 minute"); 
}

timeSelect*=60;  // to take the user input and make it a minute
 
      while(timeSelect>0){
       printf("time left is: %d seconds \n", timeSelect);
       sleep(1);
       timeSelect--;       


}
printf("  | Study time is done!s|\n ");
printf("   --------------------");
}

void Break(){

}
      
void taskTimer(){

}


int main (){

timer();

return 0;
}
