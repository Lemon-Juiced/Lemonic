#pragma once
#include "lcomp_structs.h"

char *removePath(const char *filename);
int isValidLemonicFile(const char *filename);
void setOutputFileName(int argc, char *argv[], ProgamInfo *programInfo);
