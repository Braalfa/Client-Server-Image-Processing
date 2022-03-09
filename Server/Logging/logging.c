#include "logging.h"
char* logPath = "logfile.txt";


char* getCurrentTimeAsString(char* currentTime);


void initializeLogFile(){
    FILE *file;
    file = fopen(logPath, "w");
    if (file == NULL) {
        return;
    }
    fprintf(file, "");
    fclose(file);

}


void logString(char* logInfo){
    FILE *file;
    file = fopen(logPath, "a+");
    if (file == NULL) {
        return;
    }
    char logLine[STR_LEN];
    char currentTime[STR_LEN];
    getCurrentTimeAsString(currentTime);
    sprintf(logLine, "[%s] %s\n", currentTime, logInfo);
    fprintf(file, logLine);
    fclose(file);
    printf("%s",logLine);
}

char* getCurrentTimeAsString(char* currentTime)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(currentTime, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  return currentTime;
}