/*
 * File:   main.c
 * Author: philip
 *
 * Created on 24 April 2018, 16:57
 */

#include "config.h"
#include "send_spi_byte.h"
#include "write_command.h"
#include "init_ports.h"
#include "config_oled.h"
//#include "clear_oled.h"
void main(void) 
{
    init_ports();
    config_oled();
    //clear_oled();
    while(1)
    {
        if(SWIP == 1)
        {
            DIAGNOSTIC_LED = 1;
        }
        if(SWIP == 0)
        {
            DIAGNOSTIC_LED = 0;
        }
        
       
    }
}
