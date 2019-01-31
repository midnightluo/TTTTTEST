#include <func.h>

void TimePrint(struct tm *arg)
{
    char week[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char month[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Aug",
        "Sep", "Oct", "Nov", "Dec"};
    printf("%s %s %d %d:%d:%d %d\n", week[arg->tm_wday], month[arg->tm_mon],
           arg->tm_mday, arg->tm_hour + 8, arg->tm_min, arg->tm_sec, arg->tm_year + 1900);
}

void *threadfunc(void *arg)
{
    time_t t;
    struct tm *p;
    p =(struct tm*) malloc(sizeof(struct tm));
    time(&t);
    gmtime_r(&t, p);
    TimePrint(p);
    sleep(5);
    TimePrint(p);
}

int main()
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadfunc,NULL);

    sleep(2);

    time_t t;
    struct tm *m;
    m =(struct tm*)malloc(sizeof(struct tm));
    time(&t);
    gmtime_r(&t, m);
    TimePrint(m);

    pthread_join(pthid, NULL);
    return 0;
}

