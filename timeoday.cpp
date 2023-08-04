#include <windows.h>
#include <time.h>
#include <dos.h>


int gettimeofday(struct timeval * tp, struct timezone * tzp)
{
    SYSTEMTIME      systime;

    if (tp) {
        struct tm       tmrec;
        time_t          theTime = time(NULL);


        tmrec = *localtime(&theTime);
        tp->tv_sec = mktime(&tmrec);
        GetLocalTime(&systime); /* system time */

        tp->tv_usec = systime.wMilliseconds * 1000;
    }
    return 0;
}
