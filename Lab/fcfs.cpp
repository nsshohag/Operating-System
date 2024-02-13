#include<bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int arrival_time;
    int priority;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};
bool compareArrival(process p1,process p2)
{
    return p1.arrival_time<p2.arrival_time;
}
bool compareID(process p1,process p2)
{
    return p1.pid<p2.pid;
}
int main()
{
    freopen("input2(fcfs).txt","r",stdin);
    freopen("output2(fcfs).txt","w",stdout);
    int n;
    struct process p[100];

    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilization;
    float throughput;

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    int total_burst_time=0;

    cout<<"Enter The Number of Processes:"<<endl;
    cin>>n;
    cout<<"Enter The ProcessId ,priority ,arrival_time ,burst_time consecutively"<<endl;
    ///input
    for(int i=0; i<n; i++)
    {
        cin>>p[i].pid;
        cin>>p[i].priority;
        cin>>p[i].arrival_time;
        cin>>p[i].burst_time;
    }
    ///sort the records by arrival_time
    sort(p,p+n,compareArrival);

    for(int i=0; i<n; i++)
    {
        p[i].start_time=(i==0)? p[i].arrival_time:max(p[i-1].completion_time,p[i].arrival_time);
        p[i].completion_time=p[i].start_time+p[i].burst_time;
        p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
        p[i].response_time=p[i].start_time-p[i].arrival_time;

        total_turnaround_time+=p[i].turnaround_time;
        total_waiting_time+=p[i].waiting_time;
        total_response_time+=p[i].response_time;
        total_burst_time+=p[i].burst_time;
    }
    ///sort the records by ID
    sort(p,p+n,compareID);
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t";
        cout<<p[i].arrival_time<<"\t";
        cout<<p[i].burst_time<<"\t";
        cout<<p[i].start_time<<"\t";
        cout<<p[i].completion_time<<"\t";
        cout<<p[i].turnaround_time<<"\t";
        cout<<p[i].waiting_time<<"\t";
        cout<<p[i].response_time<<"\t";
        cout<<endl;
    }

    avg_turnaround_time=(float)total_turnaround_time/n;
    avg_waiting_time=(float)total_waiting_time/n;
    avg_response_time=(float)total_waiting_time/n;
    cpu_utilization=(float)total_burst_time/(float)p[n-1].completion_time*100;
    throughput=(float)n/(p[n-1].completion_time-p[0].arrival_time);

    cout<<"Average TurnAroundTime= "<<avg_turnaround_time<<endl;
    cout<<"Average WaitingTime= "<<avg_waiting_time<<endl;
    cout<<"Average ResponseTime= "<<avg_response_time<<endl;
    cout<<"CPU Utilization: "<<cpu_utilization<<"%"<<endl;
    cout<<"Throughput: "<<throughput<<endl;

    return 0;
}
