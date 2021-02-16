#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include "check.h"

int x[5] = {1,2,3,4,5};

void allocate()
{
    int i;
    int *p;
    for(i =1 ; i<1000000 ; i++)
    {
        if (func(i)) {
            p = malloc(500 * sizeof(int));
            free(p);
        }
    }
}

void allocate1()
{
    int i;
    int *p;
    for (i=1 ; i<10000 ; i++)
    {
        p = malloc(1000 * sizeof(int));
        if(i & 1)
            free (p);
    }
}

void allocate2()
{
    int i;
    int *p;
    for (i=1 ; i<300000 ; i++)
    {
        p = malloc(10000 * sizeof(int));
        free (p);
    }
}

double calc_time_diff_ms(struct timeval end, struct timeval start) {
    double integer_part = (double )(end.tv_sec - start.tv_sec);
    double decimal_part = (double )(end.tv_usec - start.tv_usec);
    if (decimal_part < 0) {
        decimal_part += 1000000;
        integer_part -= 1;
    }
    return integer_part* 1000 + decimal_part/1000;
}

int main(int argc, char const *argv[]) {
    int i;
    int *p;

    struct rusage start_usage, end_usage;
    getrusage(RUSAGE_SELF, &start_usage);
    printf("Executing the code ......\n");


    allocate();

    for (i=0 ; i<10000 ; i++)
    {
        p = malloc(1000 * sizeof(int));
        free (p);
    }
    getrusage(RUSAGE_SELF, &end_usage);

    printf("Program execution successfull\n");
    printf("User time: %lfms\n", calc_time_diff_ms(end_usage.ru_utime, start_usage.ru_utime));
    printf("System time: %lfms\n", calc_time_diff_ms(end_usage.ru_stime, start_usage.ru_stime));
    printf("Max resident set size: %ldKB\n", end_usage.ru_maxrss);
    printf("Signal received: %ld\n", end_usage.ru_nsignals);
    printf("Voluntary context switches: %ld\n", end_usage.ru_nvcsw);
    printf("Involuntary context switches: %ld\n", end_usage.ru_nivcsw);
    return 0;
}
