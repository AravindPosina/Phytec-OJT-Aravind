/*
In this sample program, you're demonstrating how the `signal()` function returns the previous signal handler function 
when setting a new one for a specific signal (SIGHUP in this case). You're also raising the SIGHUP signal multiple times 
to see how the different handlers are invoked. 

*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sighup1(int signum) {
    printf("This is HANDLER - I for SIGHUP\n");
}

void sighup2(int signum) {
    printf("This is HANDLER - II for SIGHUP\n");
}

int main() {
    void (*old)(int); 			// Function pointer to store the old signal handler

    signal(SIGHUP, sighup1); 		// Set sighup1 as the handler for SIGHUP
    sleep(3);
    raise(SIGHUP); 			// Raise SIGHUP to trigger sighup1

    old = signal(SIGHUP, sighup2); 	// Set sighup2 as the handler for SIGHUP, store old handler
    sleep(3);
    raise(SIGHUP); 			// Raise SIGHUP to trigger sighup2

    signal(SIGHUP, old); 		// Restore the old handler for SIGHUP
    sleep(3);
    raise(SIGHUP); 			// Raise SIGHUP to trigger the old handler (sighup1)

    signal(SIGHUP, SIG_DFL); 		// Set the default handler for SIGHUP
    sleep(3);
    raise(SIGHUP); 			// Raise SIGHUP to trigger the default handler (terminate the program)

    sleep(100); 			// Sleep to keep the program running for observation

    return 0;
}
