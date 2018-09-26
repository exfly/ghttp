#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.h"
static ssize_t rio_writen(int fd, void *usrbuf, size_t n);

/*全局log文件标识*/
static int logfd;
static LOGLEVEL LOGLEV = INFO;
/*
 * loginit： 初始化打开文件，
 */
/* $start loginit */
void loginit(){
    logfd = open(LOGFILE_NAME, O_WRONLY|O_CREAT|O_APPEND, 777);
}
/* $end loginit */

/*
 * log
 */

/* $start loglog */
static void _loglog(char *level,char * msg){
    char m[8192];
    time_t tmpcal_ptr;
    struct tm *tmp_ptr = NULL;
    time(&tmpcal_ptr);
    tmp_ptr = localtime(&tmpcal_ptr);
    sprintf(m, "[%04d.%02d.%02d %02d:%02d:%02d] [%-5s] | %s", (1900+tmp_ptr->tm_year), (1+tmp_ptr->tm_mon), tmp_ptr->tm_mday, tmp_ptr->tm_hour, tmp_ptr->tm_min, tmp_ptr->tm_sec, level, msg);
    rio_writen(logfd, m, strlen(m));
    rio_writen(logfd, "\n", 1);
    printf("%s\n", m);
}
/* $end loglog */

/* $start loglog */
void loglog(char * msg){
    if (DEBUG >= LOGLEV) {
        _loglog("debug", msg);
    }
}
/* $end loglog */

void logfatal(char *msg){
    if (FATAL >= LOGLEV) {
        _loglog("fatal", msg);
    }
}
void logerror(char *msg){
    if (ERROR >= LOGLEV) {
        _loglog("error", msg);
    }
}
void logwarn(char *msg){
    if ( WARN >= LOGLEV) {
        _loglog("warn", msg);
    }
}
void loginfo(char *msg){
    if (INFO >= LOGLEV) {
        _loglog("info", msg);
    }
}
void logdebug(char *msg){
    if (DEBUG >= LOGLEV) {
        _loglog("debug", msg);
    }
}
void logtrace(char *msg){
    if (TRACE >= LOGLEV) {
        _loglog("trace", msg);
    }
}

/* $start log_close */
void log_close(){
    close(logfd);
}
/* $end log_close */

/*
 * rio_writen - Robustly write n bytes (unbuffered)
 */
/* $begin rio_writen */
static ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0) {
	if ((nwritten = write(fd, bufp, nleft)) <= 0) {
	    if (errno == EINTR)  /* Interrupted by sig handler return */
		nwritten = 0;    /* and call write() again */
	    else
		return -1;       /* errno set by write() */
	}
	nleft -= nwritten;
	bufp += nwritten;
    }
    return n;
}
/* $end rio_writen */

void one_log(char *msg){
    loginit();
    loglog(msg);
    log_close();
}
