#include <stdio.h>
#include "log.h"

int main(){
    loginit();
    loglog("hello!");
    logfatal("fatal");
    logerror("error");
    logwarn("warn");
    loginfo("info");
    logdebug("debug");
    logtrace("trace");
    log_close();
}
