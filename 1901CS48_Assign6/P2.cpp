// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include<bits/stdc++.h>
using namespace std;

struct processes
{
 int arrivalTime;
 int burstTime;
 int newBurstTime;
 int completionTime;
 int processID;
};

bool compare(processes a, processes b)
{
 if(a.arrivalTime < b.arrivalTime)
   return true;

 else if(a.arrivalTime == b.arrivalTime)
   return a.processID < b.processID;

 else
   return false;
}

vector<processes> roundRobin(int n, int tq, vector<processes> v, queue<processes> q)
{
  int time = 0;
  int numberOfProcesses = n;
  int it = 0;

  vector<processes> completion;

  long int totalWaitingTime = 0, totalTurnAroundTime = 0;

  while (numberOfProcesses)
  {
    if (q.empty())
    {
      q.push(v[it]);
      time = v[it].arrivalTime;
      it++;
    }

    processes currentProcess = q.front();
    q.pop();
    int spent = min(currentProcess.newBurstTime, tq);
    currentProcess.newBurstTime -= spent;
    time += spent;
    if (currentProcess.newBurstTime > 0)
    {
      while (it < n && v[it].arrivalTime <= time)
      {
        q.push(v[it]);
        it++;
      }
      q.push(currentProcess);
    }

    else
    {
      currentProcess.completionTime = time;
      completion.push_back(currentProcess);
      numberOfProcesses--;
      totalTurnAroundTime += time - currentProcess.arrivalTime;
      totalWaitingTime += time - currentProcess.arrivalTime - currentProcess.burstTime;

      while (it < n && v[it].arrivalTime <= time)
      {
        q.push(v[it]);
        it++;
      }
    }
  }

  printf("%0.2f %0.2f\n", (float)totalWaitingTime / (float)n, (float)totalTurnAroundTime / (float)n);

  return completion;
}


int main()
{

 int n, tq;
 cin>>n>>tq;

 vector <processes> v;
 queue <processes> q;

 for(int i = 0; i<n ; i++)
 {
   processes process;
   cin>>process.arrivalTime>>process.burstTime;
   process.newBurstTime = process.burstTime;
   process.processID = i+1;
   v.push_back(process);
 }

 sort(v.begin(),v.end(),compare);

 vector<processes> completion = roundRobin(n,tq,v,q);

 for(int i = 0; i<n ; i++)
   cout<<"P"<<completion[i].processID<<" ";
 cout<<endl;

return 0;
}