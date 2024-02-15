/*
*  The process creates a signal mask
*  and sets it using sigprocmask()
*  after sometime changes its mask to the old one
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    sigset_t newset, oldset;
    
    sigemptyset(&newset); // Initialize an empty signal set.
    sigaddset(&newset, SIGINT); // Add SIGINT to the signal set.
    
    sigprocmask(SIG_SETMASK, &newset, &oldset); // Set the new signal mask and store the old one.
    
    int i = 0;
    for (i = 1; i <= 10; i++) {
        printf("I am masking SIGINT for 10 seconds!\n");
        sleep(1);
    }
    
    sigprocmask(SIG_SETMASK, &oldset, NULL); // Restore the old signal mask.
    
    for (i = 1; i <= 10; i++) {
        printf("Now I am having the old sigset without any mask\n");
        sleep(1);
    }
    
    return 0;
}

