#include <stdio.h>
#include <math.h>

//int ifLeap;

int ifLeap(int NOY){
  if(NOY%400 == 0){
    return 1;
  }
  if(NOY%100 == 0){
    return 0;
  }
  if(NOY%4 == 0){
    return 1;
  }
  return 0;
}


int getStartingDate(int targetYear){
 
  int startingDate = 5;
  int currentYear = 2000;
  if(targetYear > currentYear){
    while(currentYear < targetYear){
      if(ifLeap(currentYear)){
	startingDate = (startingDate + 366) % 7;
      }
      else{
	startingDate = (startingDate + 365) % 7;
      }
      currentYear++;
    }
  }
  else if(targetYear < currentYear){
    while(currentYear >= targetYear){
      if(ifLeap(currentYear)){
	startingDate = -(startingDate - 366) % 7;
      }
      else{
	startingDate = -(startingDate - 365) % 7;
      }
      currentYear--;
    }
  }
  return startingDate;
}



void printCalendar(int NOE){
}

int main(void){
  int numOfYear;
  /*printf("\t\tMONTH CALENDAR\nPlease enter your year for this carlender: -");
  scanf("%d", &numOfYear);
  printf("\t*** CARLENDAR for %d ***\n", numOfYear);*/
  printf("Starting date of 1998 is %d", getStartingDate(1998) );
}
