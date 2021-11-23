//
//  SignalsSending.c
//  Alarm simulation using fork, sleep, and signal functions
//
//  Created by ryan knapp on 11/20/21.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// The signal handler is called when the process receives a signal
void sigalrm()
{
printf("\n");
printf("Ding!\n");
printf("Done.\n");
exit(0);
}

int main(int argc, char *argv[])
{

//checks if sleep time is passed as argument
if (argc != 2) {
printf("please type an integer in seconds for the sleep time\n");
exit(1);
}

// converting string to integer
int timeSleeping = atoi(argv[1]);

printf("Alarm app starting\n");

//forking the new process
if (fork() == 0) {
printf("Waiting for alarm to sound......\n");
printf("|%d second pause|\n", timeSleeping);

// Sleeps for the time requested
sleep(timeSleeping);

//getppid gets the process id, kill used to send signal to parent process
kill(getppid(), SIGALRM);

} else {
    
signal(SIGALRM, sigalrm);

    //infinitely waits for signal
    while (1) {}
}
}
