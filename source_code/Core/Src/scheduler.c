/*
 * scheduler.c
 *
 *  Created on: Nov 28, 2023
 *      Author: ASUS TUF GAMING
 */
#include "scheduler.h"
int TICK = 10;

void SCH_Init ( void ){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}
void SCH_Update( void ){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].pTask != 0){
			SCH_tasks_G[i].Delay--;
			if(SCH_tasks_G[i].Delay == 0){
				SCH_tasks_G[i].RunMe += 1;
				if(SCH_tasks_G[i].Period > 0){
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}
			}
		}
	}
}
unsigned char SCH_Add_Task( void ( * pFunction) ( ) , unsigned int DELAY, unsigned int PERIOD){
	int i;
	for(i = 0; i<SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].pTask == 0) break;
	}
	if(i == SCH_MAX_TASKS){
		//too many tasks
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[i].pTask = pFunction;
	SCH_tasks_G[i].Delay = DELAY/TICK;
	SCH_tasks_G[i].Period = PERIOD/TICK;
	SCH_tasks_G[i].RunMe = 0;

	return i;
}
void SCH_Dispatch_Tasks ( void ){
	for(int i = 0; i<SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			//run task
			(*SCH_tasks_G[i].pTask) ();
			SCH_tasks_G[i].RunMe--;

			if(SCH_tasks_G[i].Period <= 0){
				SCH_Delete_Task(i);
			}
		}
	}
}
unsigned char SCH_Delete_Task ( const int TASK_INDEX){
	unsigned char return_code;
	if(SCH_tasks_G[TASK_INDEX].pTask == 0){
		return_code = 'F';
	}
	else {
		return_code = 'T';
	}

	SCH_tasks_G[TASK_INDEX].pTask = 0;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return return_code;
}
void SCH_Go_To_Sleep ();
void SCH_Report_Status ( void );
