#include<bits/stdc++.h>
using namespace std;
int process_selected[100];
struct process
{
    int pid;
    int allocated_resource[3];
    int req_resource[3];
    int remaining_need[3];
};
int main()
{
    int n;
    struct process p[100];
    int currrent_available[3];
    currrent_available[0]=3;
    currrent_available[1]=3;
    currrent_available[2]=2;
    cout<<"Enter the number of process:"<<endl;
    cin>>n;
    cout<<"Enter the pid,allocated resource, required_resources consecutively:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].pid;
        cin>>p[i].allocated_resource[0];
        cin>>p[i].allocated_resource[1];
        cin>>p[i].allocated_resource[2];
        cin>>p[i].req_resource[0];
        cin>>p[i].req_resource[1];
        cin>>p[i].req_resource[2];
    }
    for(int i=0; i<n; i++)
    {
        p[i].remaining_need[0]=p[i].req_resource[0]-p[i].allocated_resource[0];
        p[i].remaining_need[1]=p[i].req_resource[1]-p[i].allocated_resource[1];
        p[i].remaining_need[2]=p[i].req_resource[2]-p[i].allocated_resource[2];
    }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ; j++)
        {
            if((p[j].remaining_need[0]<=currrent_available[0])&&(p[j].remaining_need[1]<=currrent_available[1])&&(p[j].remaining_need[2]<=currrent_available[2])&&(process_selected[j]!=1))
            {
                process_selected[j]=1;
                currrent_available[0]+=p[j].allocated_resource[0];
                currrent_available[1]+=p[j].allocated_resource[1];
                currrent_available[2]+=p[j].allocated_resource[2];
                cnt++;
                break;
            }
        }
    }
    if(cnt==n)
    {
        cout<<"The Processes are in safe state:"<<endl;
    }
    else
        cout<<"The Processes are not in safe state:"<<endl;
    return 0;
}
