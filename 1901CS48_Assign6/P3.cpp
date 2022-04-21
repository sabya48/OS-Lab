// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include <bits/stdc++.h>
using namespace std;

struct processes
{
    int arrivalTime;
    int burstTime;
    int newburstTime;
    int priority;
    int completionTime;
    int processID;
};

struct compareSet
{
    bool operator()(processes a, processes b)
    {
        if (a.priority != b.priority)
            return a.priority < b.priority;
        else if (a.priority == b.priority)
        {
            if(a.arrivalTime != b.arrivalTime)
                return a.arrivalTime < b.arrivalTime;
            else
                return a.processID < b.processID;
        }
    }
};

bool compare(processes a, processes b)
{
    if (a.arrivalTime < b.arrivalTime)
        return true;
    else if (a.arrivalTime == b.arrivalTime)
        return a.processID < b.processID;
    else
        return false;
}

vector<processes> priorityNonPreemptive(int n, int tq, vector<processes> v, set<processes, compareSet> s)
{
    int time = 0;
    int numberOfProcesses = n;
    int it = 0;
    vector<processes> completion;
    long int totalWaitingTime = 0, totalTurnAroundTime = 0;
    while (numberOfProcesses)
    {
        if (s.empty())
        {
            s.insert(v[it]);
            time = v[it].arrivalTime;
            it++;
        }
        processes currentProcess = *s.begin();
        s.erase(currentProcess);

        time += currentProcess.newburstTime;
        currentProcess.newburstTime = 0;

        currentProcess.completionTime = time;
        completion.push_back(currentProcess);
        numberOfProcesses--;
        totalTurnAroundTime = totalTurnAroundTime + (time - currentProcess.arrivalTime);
        totalWaitingTime = totalWaitingTime + (time - currentProcess.arrivalTime - currentProcess.burstTime);
        while (it < n && v[it].arrivalTime <= time)
        {
            s.insert(v[it]);
            it++;
        }
    }

    printf("%0.2f %0.2f\n", (float)totalWaitingTime / (float)n, (float)totalTurnAroundTime / (float)n);

    return completion;
}

int main()
{
    int n, tq;
    cin >> n;
    vector<processes> v;
    set<processes, compareSet> s;

    for (int i = 0; i < n; i++)
    {
        processes process;
        cin >> process.arrivalTime >> process.burstTime >> process.priority;
        process.newburstTime = process.burstTime;
        process.processID = i + 1;
        v.push_back(process);
    }

    sort(v.begin(), v.end(), compare);
    
    vector<processes> completion = priorityNonPreemptive(n, tq, v, s);

    for (int i = 0; i < n; i++)
        cout << "P" << completion[i].processID << " ";
    cout << endl;

    return 0;
}