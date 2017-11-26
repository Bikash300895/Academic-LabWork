#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream inf("input.txt");
    inf>>n;

    int arrival_time[n];    //stores arrival time
    int burst_time[n];      //stores burst time
    int remaining_time[n];  // remaining execution time
    int finish_time[n];     // time when job i finish


    int total_burst_time = 0;
    // taking input from file
    for(int i=0; i<n; i++)
    {
        inf>>arrival_time[i]>>burst_time[i];
        remaining_time[i] = burst_time[i];

        total_burst_time += burst_time[i];

    }

    // clock
    int current_time = 0;

    while(true)
    {
        int current_short_ex_time = INT_MAX;
        int index = -1;

        // find who to serve
        for(int i=0; i<n; i++)
        {
            if(remaining_time[i]>0 && remaining_time[i] < current_short_ex_time && current_time>= arrival_time[i])
            {
                current_short_ex_time = remaining_time[i];
                index = i;
            }
        }

        // find the time serve
        int next_step_time;
        for(int i=0; i<n; i++)
        {
            if(arrival_time[i] > current_time)
            {
                next_step_time = arrival_time[i];
                break;
            }
        }
        if(current_time>= arrival_time[n-1])
        {
            next_step_time = INT_MAX;
        }

        if(index == -1){
            current_time += next_step_time - current_time;
            continue;
        }

        // serve
        printf("Process %d served from time %d", index, current_time);
        int allowable_ex_time = next_step_time - current_time;
        allowable_ex_time = min(allowable_ex_time, remaining_time[index]);

        remaining_time[index] -= allowable_ex_time;
        current_time += allowable_ex_time;
        if(remaining_time[index] == 0)
        {
            finish_time[index] = current_time;
        }

        printf("to %d\n", current_time);

        bool go_again = false;
        for(int i=0; i<n; i++)
        {
            if(remaining_time[i]>0)
            {
                go_again = true;
            }
        }

        if(!go_again)
        {
            break;
        }
    }

    int waiting_time[n];
    int turnaround_time[n];

    for(int i=0; i<n; i++)
    {
        turnaround_time[i] = finish_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        printf("for %d waiting time: %d, turnaround time: %d\n", i, waiting_time[i], turnaround_time[i]);
    }

    int avg_w=0, avg_t=0;
    for(int i=0; i<n; i++){
        avg_t += turnaround_time[i];
        avg_w += waiting_time[i];
    }
    printf("Average waiting time: %f\n", (avg_w * 1.0)/n);
    printf("Average turnaround time: %f\n", (avg_t * 1.0)/n);
}
