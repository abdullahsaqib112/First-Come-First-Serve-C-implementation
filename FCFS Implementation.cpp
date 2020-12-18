// C++ program for implementation of FCFS  
// scheduling 

#include<iostream> 
using namespace std;

// Function to find the waiting time for all  
// processes 
void findWaitingTime(int processes[], int size,
    int burstTime[], int waitingTime[])
{
    // waiting time for first process is 0 
    waitingTime[0] = 0;

    // calculating waiting time 
    for (int i = 1; i < size; i++)
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
}

// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int size,
    int burstTime[], int waitingTime[], int tat[])
{
    // calculating turnaround time by adding 
    // burstTime[i] + waitingTime[i] 
    for (int i = 0; i < size; i++)
        tat[i] = burstTime[i] + waitingTime[i];
}

//Function to calculate average time 
void findavgTime(int processes[], int size, int burstTime[])
{
    int waitingTime[5],  tat[5], total_waitingTime = 0, total_tat = 0;

    //Function to find waiting time of all processes 
    findWaitingTime(processes, size, burstTime, waitingTime);

    //Function to find turn around time for all processes 
    findTurnAroundTime(processes, size, burstTime, waitingTime, tat);

    //Display processes along with all details 
    cout << "Processes  " << " Burst time  "
        << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn  
    // around time 
    for (int i = 0; i < size; i++)
    {
        total_waitingTime = total_waitingTime + waitingTime[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << burstTime[i] << "\t    "
            << waitingTime[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "Average waiting time = "
        << (float)total_waitingTime / (float)size;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)size;
}


int main()
{
    //process id's 
    int processes[] = { 0, 1, 2, 3, 4 };
   // int n = sizeof processes / sizeof processes[0];
    const int size = 5;
    //Burst time 
    int  burst_time[] = { 10, 9, 8 , 15, 12 };

    findavgTime(processes, size, burst_time);
    return 0;
}