//======================================================================
//
//        Copyright (C) 2019-2020 yiluzhang    
//        All rights reserved
//
//        filename:usbcan.h
//        description:
//
//        created by yiluzhang at  12/07/2019
//
//======================================================================

#ifndef __USBCAN_H
#define __USBCAN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <ctime>
#include <cstdlib>
#include "unistd.h"

#include "controlcan.h" 

void usbcan_init(void);

#endif
