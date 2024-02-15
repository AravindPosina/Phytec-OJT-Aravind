/*

    scorer.c: signal the manager when a batsman hits a 4 or 
              a 6, or, when a wicket falls

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void syserror (const char * const str);
//int get_option (void);

int main (int argc, char **argv)
{
    int option;

    if (argc != 2) {
        printf ("Usage: scorer manager-pid\n");
	exit (1);
    }

    pid_t manager_pid = atoi (argv [1]);

    while (1) {
        printf ("Action: \n");
	printf ("\t1\tBatsman hit 4\n");
	printf ("\t2\tBatsman hit 6\n");
	printf ("\t3\tWicket falls\n\n");
	printf ("\t0\tQuit\n\n\n");
	printf ("Enter action: ");
	scanf ("%d", &option);
	if (option == 0)
	    break;
	if (option >= 1 && option <= 3) {
	    // send signal
	    union sigval sigval;
	    switch (option) {
                case 1: sigval.sival_int = '4';
			break;

                case 2: sigval.sival_int = '6';
			break;

                case 3: sigval.sival_int = 'W';
			break;
	    }
	    if (sigqueue (manager_pid, SIGRTMIN+1, sigval) == -1)
                syserror ("sigqueue");
        }
	else
	    printf ("Illegal option, try again\n\n");
    }
}

void syserror (const char * const str)
{
    perror (str);
    exit (EXIT_FAILURE);
}
