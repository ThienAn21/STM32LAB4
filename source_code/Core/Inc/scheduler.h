/*
 * scheduler.h
 *
 *  Created on: Nov 24, 2023
 *      Author: ASUS TUF GAMING
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "stdint.h"
extern int TICK;

typedef struct {
	// Pointer to the task (must be a ’ void ( void ) ’ function )
	void ( * pTask ) ( void ) ;
	// Delay ( ticks ) until the function will ( next ) be run
	uint32_t Delay ;
	// Interval ( ticks ) between subsequent runs .
	uint32_t Period ;
	// Incremented (by scheduler ) when task i s due to execute
	uint8_t RunMe;
	uint32_t TaskID;
} sTask ;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS] ;

void SCH_Init ( void );
void SCH_Update( void );
unsigned char SCH_Add_Task( void ( * pFunction) ( ) , unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks ( void );
unsigned char SCH_Delete_Task ( const int TASK_INDEX);
void SCH_Go_To_Sleep ();
void SCH_Report_Status ( void );


#endif /* INC_SCHEDULER_H_ */
