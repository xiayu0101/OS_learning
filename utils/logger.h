#ifndef APP_PUBLIC_LOGGER_H__
#define APP_PUBLIC_LOGGER_H__
#include "stdio.h"

#define __DEBUG

#ifdef __DEBUG
#define DEBUG(format, ...) printf(format,##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

enum LOG_LEVEL{
    LOG_LEVEL_OFF = 0,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_ALL
};

#define log_fatal(level,format,...) do { \
    if(level>= LOG_LEVEL_FATAL)          \
        DEBUG("[FATAL @ func:%s FILE:%s LINE:%d] " format "\n", \
        __func__,__FILE__,__LINE__,##__VA_ARGS__);\
}while(0)

#define log_err(level,format,...) do { \
    if(level>= LOG_LEVEL_ERR)          \
        DEBUG("[ERR @ func:%s FILE:%s LINE:%d] " format "\n", \
        __func__,__FILE__,__LINE__,##__VA_ARGS__);\
}while(0)

#define log_warn(level,format,...) do { \
    if(level>= LOG_LEVEL_WARN)          \
        DEBUG("[WARN @ func:%s FILE:%s LINE:%d] " format "\n", \
        __func__,__FILE__,__LINE__,##__VA_ARGS__);\
}while(0)

#define log_info(level,format,...) do { \
    if(level>= LOG_LEVEL_INFO)          \
        DEBUG("[INFO @ func:%s FILE:%s LINE:%d] " format "\n", \
        __func__,__FILE__,__LINE__,##__VA_ARGS__);\
}while(0)

#define log_debug(level,format,...) do { \
    if(level>= LOG_LEVEL_ALL)          \
        DEBUG("[DEBUG @ func:%s FILE:%s LINE:%d] " format "\n", \
        __func__,__FILE__,__LINE__,##__VA_ARGS__);\
}while(0)

#endif


