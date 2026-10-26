#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declare global variables including a table structure to hold scheduling
// information
// optional: define a function that finds the maximum of two integers

typedef struct SchedTable
{
    int process_id;
    int arrival_cycle;
    int total_cycles;
    int start_time;
    int end_time;
    int turnaround_time;
    int done;
}SchedTable;

#define MAX_PROCESSES 10

SchedTable table[MAX_PROCESSES];
int total_number_processes;


//***************************************************************
void PRINT_SCHEDULING_TABLE() {
    // declare local variables

    // print table header
    printf("PID    Arrival   Total    Start    End    Turnaround\n");
    printf("--------------------------------------------------\n");
    
    // for each process
    for(int i=0; i<total_number_processes; i++){
        // print the contents (id, arrival time, total_cycles) of each field
        // of the table's index
        // printf("1      0            6\n");
        printf("%d      %d          %d",
        table[i].process_id, table[i].arrival_cycle, table[i].total_cycles);
    
        // if process has been scheduled ("done" field is 1, print other
        // contents (start time, end time, turnaround time)
        if(table[i].done==1){
            printf("       %d        %d       %d",
            table[i].start_time, table[i].end_time, table[i].turnaround_time);
        }
        printf("\n");
    }

    return;
}

//*************************************************************
void option1() {
    // declare local variables
    // int total_number_processes;

    // prompt for total number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &total_number_processes);

    // allocate memory for table to hold process parameters

    // for each process
    for(int i=0; i < total_number_processes; i++){   
        // prompt for arrival time, and total cycle time
        table[i].process_id = i+1;

        printf("Enter arrival cycle for process %d:\n", i+1);
        scanf("%d", &table[i].arrival_cycle);
        
        printf("Enter total cycles for process %d:\n", i+1);
        scanf("%d", &table[i].total_cycles);
    
    }

    // print contents of table
    printf("\n");
    PRINT_SCHEDULING_TABLE();

    return;
}

//*************************************************************
void option2() {
    // declare (and initilize when appropriate) local variables
    int sceduled_processes = 0;
    int current = 0;

    // for each process, reset "done" field to 0
    for(int i=0; i < total_number_processes; i++){
        table[i].done = 0;
    }

    // while there are still processes to schedule
    while(sceduled_processes < total_number_processes){
        // initilize the earliest arrival time to INT_MAX (largest integer
        // value)
        int early_arrival = INT_MAX;
        int earlyIndex;
        
        // for each process not yet scheduled
        for(int i=0; i< total_number_processes; i++){   
            // check if process has earlier arrival time than current
            // earliest and update
            if (table[i].done == 0 && table[i].arrival_cycle < early_arrival){
                early_arrival = table[i].arrival_cycle;
                earlyIndex = i;
            }
        }
        
        // set start time, end time, turnaround time, done fields for
        // unscheduled process with earliest arrival time
        //endtime = start +total
        //turnaround = end - arrival
        if (current < table[earlyIndex].arrival_cycle){
            current = table[earlyIndex].arrival_cycle; 
        }
        table[earlyIndex].start_time = current;
        
        // update current cycle time and increment number of processes
        // scheduled
        table[earlyIndex].end_time = table[earlyIndex].start_time + table[earlyIndex].total_cycles;
        table[earlyIndex].turnaround_time = table[earlyIndex].end_time - table[earlyIndex].arrival_cycle;
        table[earlyIndex].done = 1;

        current = table[earlyIndex].end_time;
        sceduled_processes++;
    }
    // print contents of table
    PRINT_SCHEDULING_TABLE();

    // return;
}

//*************************************************************
void option3() {
    // declare (and initilize when appropriate) local variables

    // for each process, reset "done" field to 0

    // while there are still processes to schedule

    // initilize the lowest total cycle time to INT_MAX (largest integer
    // value)

    // for each process not yet scheduled

    // check if process has lower total cycle time than current
    // lowest and has arrival time less than current cycle time and update

    // set start time, end time, turnaround time, done fields for
    // unscheduled process with lowest (and available) total cycle time

    // update current cycle time and increment number of processes
    // scheduled

    // print contents of table

    // return;
}

//*************************************************************
void option4() {
    // declare (and initilize when appropriate) local variables

    // for each process, reset "done", "total_remaining" and
    // "already_started" fields to 0

    // while there are still processes to schedule

    // initilize the lowest total remaining time to INT_MAX (largest
    // integer value)

    // for each process not yet scheduled

    // check if process has lower total remaining time than current
    // lowest and has arrival time less than current cycle time and update

    // check if process already partially-scheduled

    // if so, set "start time", "already_started" fields of process
    // with lowest (and available) total remaining cycle time

    // set end time, turnaround time of process with lowest (and available)
    // total remaining cycle time

    // decrement total remaining time of process with lowest (and
    // available) total remaining cycle time

    // if remaining time is 0, set done field to 1, increment cycle time
    // and number of scheduled processes

    // print contents of table

    // return;
}

//*************************************************************
void option5() {
    printf("Quitting program");
    // free the schedule table if not NULL

    // return;
}

/* ************************************************************* */

int main() {
    /* declare local vars */
    int userInput;
    int quit = 0;

    /* while user has not chosen to quit */
    while(quit==0){
        /* print menu of options */
        printf("\nBatch Scheduling\n");
        printf("--------------------------------\n");
        printf("1) Enter Parameters\n");
        printf("2) Schedule processes with FIFO algorithm\n");
        printf("3) Schedule processes with SJF algorithm \n");
        printf("4) Schedule processes with SRT algorithm\n");
        printf("5) Quit and free memory\n");
        printf("\n");

        /* prompt for menu selection */
        printf("Enter Selection: ");
        scanf("%d", &userInput);

        /* call appropriate procedure based on choice--use switch statement or
        series of if, else if, else statements */
        switch (userInput)
        {
        case 1:
            // Enter Parameters
            option1();
            break;

        case 2:
            // Schedule processes with FIFO algorithm
            option2();
            break;

        case 3:
            // Schedule processes with SJF algorithm
            option3();
            break;

        case 4:
            // Schedule processes with SRT algorithm
            option4();
            break;
            
        case 5:
            // Quit and free memory
            option5();
            quit = 1;
            break;

        default:
            printf("Pick a listed option");
            break;
        }

    }

    return 1;
} /* end of procedure */
