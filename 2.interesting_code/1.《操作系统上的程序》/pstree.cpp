#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"
#include "dirent.h"
#include "logger.h"
#include "sys/types.h"
bool opt_p = false,opt_n = false,opt_V = false;
static enum LOG_LEVEL logger = LOG_LEVEL_ALL;

void parseOpt(int argc,char *argv[]){
    for(int i = 0;i < argc;i++){
        assert(argv[i]);
        if(!strcmp(argv[i],"-p")){
            opt_p = true;
            continue;
        }else if(!strcmp(argv[i],"-n")){
            opt_n = true;
            continue;
        }else if(!strcmp(argv[i],"-V")){
            opt_V = true;
            continue;
        }
    }
    assert(!argv[argc]);
}

void setProcessInfo(){
    DIR *dp = opendir("/proc");
    if(!dp){
        log_err(logger,"Can't open /proc");
        exit(1);
    }
    struct dirent *entry;
    while((entry= readdir(dp))!=NULL){

    }

}
int main(int argc,char* argv[]){
    // 1.parse argv
    parseOpt(argc,argv);
    if(opt_V){
        log_info(logger,"version 1.0");
        exit(0);
    }

    // 2.save all process index
    setProcessInfo();


    // 3.get all process's parent

    // 4.construct tree and sort by argv

    // 5.print tree in terminal
    return 0;
}


