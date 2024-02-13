#include<bits/stdc++.h>
using namespace std;
int que_completed[100];
struct process
{
    int pid;
    int arrival_time;
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
bool compareBurst(process p1,process p2)
{
    return p1.burst_time<p2.burst_time;
}
bool compareID(process p1,process p2)
{
    return p1.pid<p2.pid;
}
int main()
{
    freopen("input2(sjf).txt","r",stdin);
    freopen("output2(sjf).txt","w",stdout);
    int n;
    int index_;
    int i;
    struct process p[100];
    struct process temp[100];

    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilization;
    float throughput;

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_burst_time=0;
    cout<<"Enter The Number of Processes:"<<endl;
    cin>>n;
    cout<<"Enter The ProcessId ,arrival_time ,burst_time consecutively"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].pid;
        cin>>p[i].arrival_time;
        cin>>p[i].burst_time;
    }
    int current_time;
    for(current_time=0; current_time<1000; current_time++)
    {
        i=0;
        for(int j=0; j<n; j++)
        {
            if((current_time>=p[j].arrival_time)&&(que_completed[j]==0))
            {
                temp[i]=p[j];
                i++;
            }
        }
        if(i==0)
        {

        }
        else
        {
            if(i==1)
            {
            }
            else
            {
                sort(temp,temp+i,compareBurst);
            }
            index_=temp[0].pid;
            que_completed[index_-1]=1;
            p[index_-1].start_time=current_time;
            p[index_-1].completion_time=p[index_-1].start_time+p[index_-1].burst_time;
            p[index_-1].turnaround_time=p[index_-1].completion_time-p[index_-1].arrival_time;
            p[index_-1].waiting_time=p[index_-1].turnaround_time-p[index_-1].burst_time;
            p[index_-1].response_time=p[index_-1].start_time-p[index_-1].arrival_time;
            current_time=current_time+p[index_-1].burst_time;
            current_time--;

            total_turnaround_time+=p[index_-1].turnaround_time;
            total_waiting_time+=p[index_-1].waiting_time;
            total_response_time+=p[index_-1].response_time;
            total_burst_time+=p[index_-1].burst_time;
        }
    }
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
