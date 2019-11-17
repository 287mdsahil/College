#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
  
// structure for message queue 
struct mesg_buffer {
    long value;
    float temp,humidity,pressure,rainfall,rainfallchance; 
} message; 
  
int main() 
{ 
    srand(time(NULL));
    while(1)
    {
        message.value=1;
        printf("%d",rand());
        key_t key; 
        int msgid; 
    
        // ftok to generate unique key 
        // key = ftok("weather_info", 65); 
    
        // msgget creates a message queue 
        // and returns identifier `
        msgid = msgget(94, 0666 | IPC_CREAT);
        printf("%d",msgid);
        int a=150;
        float x=(float)(rand()%a);
        message.temp=((float)rand()/(float)RAND_MAX)*15.6 + 15.6734;
        a=20;
        message.humidity=x + 72.5964;
        a=50;
        message.pressure=x + 950;
        a=1;
        message.rainfall=x + 8;
        a=75;
        message.rainfallchance=x + 25;
        // msgsnd to send message 
        if(msgsnd(msgid, &message, sizeof(message), 0)==-1)
        {
            perror("Sending Error\n");
        } 
        sleep(1); 
    }
    return 0; 
} 
