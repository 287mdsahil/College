#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
  
// structure for message queue 
struct mesg_buffer {
    long value;
    float temp,humidity,pressure,rainfall,rainfallchance; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
    time_t t;
    while(1){
    time(&t);
    // ftok to generate unique key 
    // key = ftok("weather_info", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(94, 0666 | IPC_CREAT); 
    printf("%d",msgid);
  
    // msgrcv to receive message 
    msgrcv(msgid, &message, sizeof(message), 1, 0); 
  
    // display the message 
    printf("Weather Information.\n%s\n------------------------\n",ctime(&t));
    printf("Temperature (C)     : %.3f\n",message.temp);
    printf("Humidity (%%)        : %.3f\n",message.humidity);
    printf("Pressure (mbar)     : %.3f\n",message.pressure); 
    printf("Rainfall (mm)       : %.3f\n",message.rainfall);
    printf("Rainfall chance (%%) : %.3f\n\n",message.rainfallchance);
  
    // to destroy the message queue 
    //msgctl(msgid, IPC_RMID, NULL); 
    sleep(3);
    }
    return 0; 
} 
