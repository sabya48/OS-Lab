// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include <bits/stdc++.h>
#define TIME_QUANTUM 1
using namespace std;

// A class of a single process
class Process {
public:
	int pid;	// Process ID
	int at;		// Arrival Time
	int bt;		// Burst Time
	int ft;		// Finish Time
	int wt;		// Waiting Time
	int tat;	// Turn Around Time
	int rt;		// Remaining Time
};

/* Comparator to sort according to arrival times */
bool at_comp(Process p1, Process p2) {
	if (p1.at == p2.at) return p1.pid < p2.pid;
	return p1.at < p2.at;
}

/* Comparator to sort according to finish times */
bool ft_comp(Process p1, Process p2) {
	return p1.ft < p2.ft;
}

/* Operator overloading to sort according to burst times */
struct compareRemainingTime {
	bool operator()(Process* p1, Process* p2) {
		if (p1 -> rt == p2 -> rt) return p1 -> pid > p2 -> pid;
		return p1 -> rt < p2 -> rt;
	}
};

// Longest Remaining Time First Algorithm
void lrtf(vector<Process> &process) {
	int n = process.size();
	int queued = 0;
	int time = 0;

	// Sort vector according to arrival times
	sort(process.begin(), process.end(), at_comp);

	priority_queue<Process*, vector<Process*>, compareRemainingTime> q;

	while (true) {
		// If all finished, break
		if (q.empty() && queued == n) break;

		// If queue is empty, increase time
		if (q.empty()) time = max(time, process[queued].at);

		// Push all processes whose arrival time <= time
		while (time >= process[queued].at && queued < n){
			q.push(&process[queued]);
			queued++;
		}
		
		// Extract shortest remaining burst time process
		Process* p = q.top();
		q.pop();

		// Calculate WT, FT, TAT, RT (Update BT), LET
		time += min(TIME_QUANTUM, p -> rt);
		p -> rt -= min(TIME_QUANTUM, p -> rt);
		if (p -> rt == 0) {
			p -> ft = time;
			p -> tat = p -> ft - p -> at; 
			p -> wt = p -> tat - p -> bt;
		} else q.push(p);
	} 
	
	return;
}

/* Print average WT and average TAT */
void printAverage(vector<Process> &process) {
	int n = process.size();
	double avg_wt = 0.0;
	double avg_tat = 0.0;

	for (auto p: process) {
		avg_wt += p.wt;
		avg_tat += p.tat;
	}

	avg_wt /= n;
	avg_tat /= n;
	cout << fixed << setprecision(2);
	cout << avg_wt << " " << avg_tat << endl;

	// Sort vector according to finish times
	sort(process.begin(), process.end(), ft_comp);

	for (int i = 0; i < n; i++) {
		cout << "P" << process[i].pid << " ";
	}
	cout << endl;

	return;
}

int main() {
	// Number of processes
	int n;
	cin >> n;						

	// Vector of processes
	vector<Process> process(n);
	for (int i = 0; i < n; i++) {
		process[i].pid = i + 1;
		cin >> process[i].at >> process[i].bt;
		process[i].rt = process[i].bt;
	}

	// Find WT and TAT for all processes
	lrtf(process);
	// Print average WT and average TAT
	printAverage(process);
}