#include <time.h>

#ifndef __LOG_H_
#define __LOG_H_
#define LOGFILE_NAME "./log/ghttp.log"

// ALL -> OFF => 1,2, ..., 8
typedef enum {ALL=1, TRACE, DEBUG, INFO, WARN, ERROR, FATAL, OFF} LOGLEVEL;

void loginit();
void loglog(char * msg);
void logfatal(char *msg);
void logerror(char *msg);
void logwarn(char *msg);
void loginfo(char *msg);
void logdebug(char *msg);
void logtrace(char *msg);
void log_close();
void one_log(char *msg);

#endif
