// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include <bits/stdc++.h>
using namespace std;

// A class of a single process
class Process
{
public:
	int pid; // Process ID
	int at;	 // Arrival Time
	int bt;	 // Burst Time
	int ft;	 // Finish Time
	int wt;	 // Waiting Time
	int tat; // Turn Around Time
};

/* Comparator to sort according to arrival times */
bool at_comp(Process p1, Process p2)
{
	if (p1.at == p2.at)
		return p1.pid < p2.pid;
	return p1.at < p2.at;
}

/* Comparator to sort according to finish times */
bool ft_comp(Process p1, Process p2)
{
	return p1.ft < p2.ft;
}

// First Come First Serve Algorithm
void fcfs(vector<Process> &process)
{
	int n = process.size();
	int time = 0;
	// Sort vector according to arrival times
	sort(process.begin(), process.end(), at_comp);

	// Run processes
	for (int i = 0; i < n; i++)
	{
		time = max(time, process[i].at);
		process[i].wt = time - process[i].at;
		time += process[i].bt;
		process[i].ft = time;
		process[i].tat = process[i].ft - process[i].at;
	}
	return;
}

/* Print average WT and average TAT */
void printAverage(vector<Process> &process)
{
	int n = process.size();
	double avg_wt = 0.0;
	double avg_tat = 0.0;

	for (auto p : process)
	{
		avg_wt += p.wt;
		avg_tat += p.tat;
	}

	avg_wt /= n;
	avg_tat /= n;
	cout << fixed << setprecision(2);
	cout << avg_wt << " " << avg_tat << endl;

	// Sort vector according to finish times
	sort(process.begin(), process.end(), ft_comp);

	for (int i = 0; i < n; i++)
	{
		cout << "P" << process[i].pid << " ";
	}
	cout << endl;

	return;
}

int main()
{
	// Number of processes
	int n;
	cin >> n;

	// Vector of processes
	vector<Process> process(n);
	for (int i = 0; i < n; i++)
	{
		process[i].pid = i + 1;
		cin >> process[i].at >> process[i].bt;
	}

	// Find WT and TAT for all processes
	fcfs(process);
	// Print average WT and average TAT
	printAverage(process);
}