/*
 *
 *      manager.c: Manager program
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void syserror (const char * const str);
void sig_rtmin_handler (int signum, siginfo_t *siginfo, void *context);

int main (int argc, char **argv)
{

    struct sigaction act;

    memset (&act, 0, sizeof (act));

    // set signal handler for SIGRTMIN
    act.sa_sigaction = sig_rtmin_handler;
    act.sa_flags = SA_SIGINFO;

    if (sigaction (SIGRTMIN+1, &act, NULL) == -1)
        syserror ("sigaction");

    // Do important work
    while (1)
        sleep (10); 
}

void sig_rtmin_handler (int signum, siginfo_t *siginfo, void *context)
{
    switch (siginfo -> si_value.sival_int) {
        case '4': write (2, "Four runs scored.\n", 18);
                      break;

        case '6': write (2, "Six runs scored.\n", 17);
                      break;

        case 'W': write (2, "A wicket has fallen.\n", 21);
                      break;

        default:  write (2, "Unclear communication\n", 22);
   
    }
}

void syserror (const char * const str)
{
    perror (str);
    exit (EXIT_FAILURE);
}
