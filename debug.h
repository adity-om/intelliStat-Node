/*
 * @Author: aditya om 
 * @Date: 2022-02-04 20:20:05 
 * @Last Modified by:   aditya om
 * @Last Modified time: 2022-02-04 20:20:05 
 */

#ifndef __DEBUG_H

    #define __DEBUG_H
    
    #define ENABLE_DEBUG /*Delete this line in order to DISABLE DEBUGGING*/
    #define DEBUG_PORT Serial

    #define TEXTIFY(A) #A
    #define ESCAPEQUOTE(A) TEXTIFY(A)

    #ifdef ENABLE_DEBUG

        #ifndef DEBUG_PORT
            #define DEBUG_PORT Serial1
        #endif

        #define DEBUG DEBUG_PORT

        #define DBUGS               Serial
        #define DEBUG_BEGIN(speed)  DEBUG_PORT.begin(speed)

        #define DBUGF(format, ...)  DEBUG_PORT.printf(format "\n", ##__VA_ARGS__)
        #define DBUG(...)           DEBUG_PORT.print(__VA_ARGS__)
        #define DBUGLN(...)         DEBUG_PORT.println(__VA_ARGS__)
        #define DBUGVAR(x, ...)     do { DEBUG_PORT.print(ESCAPEQUOTE(x) " = "); DEBUG_PORT.println(x, ##__VA_ARGS__); } while (false)

    #else

        #define DEBUG_BEGIN(speed)
        #define DBUGF(...)
        #define DBUG(...)
        #define DBUGLN(...)
        #define DBUGVAR(...)

    #endif // DEBUG

#endif // __DEBUG_H
