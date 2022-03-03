#ifndef __LOGGING_H
#define __LOGGING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define STR_LEN 200
char* logPath = "logfile.txt";

void initializeLogFile();
void log(char* logInfo);

#endif
