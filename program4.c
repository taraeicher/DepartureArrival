/*Program Description: Find the closest departure and arrival time for a particular day based on user's desired departure time. Schedule is as follows.
 *	Departure Time Arrival Time
 *	8:a.m          10:16 a.m
 *	9:43 a.m       11:52 a.m
 *	11:19 a.m      1:31 p.m
 *	12:47p.m       3:00 p.m
 *	2:00 p.m       4:08 p.m
 *	3:45 p.m       5:55 p.m
 *	7:00 p.m       9:20 p.m
 *	9:45 p.m       11:58 p.m
 *	If time entered is on the midline between two departure times, default to earlier departure time. Display an error message for invalid entries.
 *Programmer Name: Tara Eicher
 *WSU ID: z847x563
 *Date Completed: 1 October 2012
*/

#include <stdio.h>

   //Assign the departure times to constants, in minutes since midnight.

   const int DEP_TIME1=8*60;
   const int DEP_TIME2=9*60+43;
   const int DEP_TIME3=11*60+19;
   const int DEP_TIME4=12*60+47;
   const int DEP_TIME5=(12+2)*60;
   const int DEP_TIME6=(12+3)*60+45;
   const int DEP_TIME7=(12+7)*60;
   const int DEP_TIME8=(12+9)*60+45;

   //Assign the arrival times to constants, in minutes since midnight.

   const int ARR_TIME1=10*60+16;
   const int ARR_TIME2=11*60+52;
   const int ARR_TIME3=(12+1)*60+31;
   const int ARR_TIME4=(12+3)*60;
   const int ARR_TIME5=(12+4)*60+8;
   const int ARR_TIME6=(12+5)*60+55;
   const int ARR_TIME7=(12+9)*60+20;
   const int ARR_TIME8=(12+11)*60+58;

//Main function

int main(void)
{
   //Use two-dimensional array to hold values. Departure times are stored in first column, arrival times in second.

   int times[8][2];

   times[0][0]=DEP_TIME1;
   times[1][0]=DEP_TIME2;
   times[2][0]=DEP_TIME3;
   times[3][0]=DEP_TIME4;
   times[4][0]=DEP_TIME5;
   times[5][0]=DEP_TIME6;
   times[6][0]=DEP_TIME7;
   times[7][0]=DEP_TIME8;

   times[0][1]=ARR_TIME1;
   times[1][1]=ARR_TIME2;
   times[2][1]=ARR_TIME3;
   times[3][1]=ARR_TIME4;
   times[4][1]=ARR_TIME5;
   times[5][1]=ARR_TIME6;
   times[6][1]=ARR_TIME7;
   times[7][1]=ARR_TIME8;

   //Prompt user for time and store.

   int hours=25,minutes=89,timeEntered=0;
   printf("Enter the desired 24-hour departure time(hh:mm): ");
   scanf("%d:%d",&hours,&minutes);
   timeEntered=hours*60+minutes;

   //Validate that time entered is a proper one. If so, continue with calculations. If not, terminate the program.

   if(hours>=0&&hours<24&&minutes>=0&&minutes<=59)
   {        
      //Locate the first departure time that is later than the time entered.

      int i=0;
      for(;timeEntered>times[i][0];++i)
         ;
     
      //Find and print closest time.

      int depHours=0;
      int depMinutes=0;
      int arrHours=0;
      int arrMinutes=0;

      //If time entered is between two times in the list, compare the differences between time entered and two closest values.

      if(!(i==0||i==8))
      {
         if(times[i][0]-timeEntered<timeEntered-times[i-1][0])
         {
            depHours=times[i][0]/60;
            depMinutes=times[i][0]%60;
            arrHours=times[i][1]/60;
            arrMinutes=times[i][1]%60;
         }  
         else
         {
            depHours=times[i-1][0]/60;
            depMinutes=times[i-1][0]%60;
            arrHours=times[i-1][1]/60;
            arrMinutes=times[i-1][1]%60;
         }
      }

      //If time entered is earlier than earliest time in list, print earliest time in list.

      else if(i==0)
      {
         depHours=times[i][0]/60;
         depMinutes=times[i][0]%60;
         arrHours=times[i][1]/60;
         arrMinutes=times[i][1]%60;
      }

      //If time entered is later than latest time in list, print latest time in list.

      else
      {
         depHours=times[i-1][0]/60;
         depMinutes=times[i-1][0]%60;
         arrHours=times[i-1][1]/60;
         arrMinutes=times[i-1][1]%60;
      }
    
      printf("Closest departure time: %.2d:%.2d\n",depHours,depMinutes);
      printf("Closest arrival time: %.2d:%.2d\n",arrHours,arrMinutes);
   }

   else
     printf("Incorrect time. Please try again.\n");

   return(0);
}
