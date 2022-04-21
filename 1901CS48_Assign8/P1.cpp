// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include<bits/stdc++.h>
using namespace std;


bool check(vector<int>sequence, vector<vector<int>>alloc, vector<vector<int>>maxr, vector<int>avail, vector<vector<int>>need)
{
	int n = alloc.size();
	int m = alloc[0].size();
	for(int i=0;i<n;i++)
	{
		int curr = sequence[i]-1;
		for(int j=0;j<m;j++)
		{
			if(avail[j]<need[curr][j]) return false;
		}
		

		for(int j=0;j<m;j++)
		{
			avail[j] += alloc[curr][j];
		}

	}
	return true;
}

signed main()
{
	cout<<"Bankers Algorithm"<<endl<<endl;
	cout<<"Enter the number of processes"<<endl;
	int n;
	cin>>n;
	cout<<"Enter the number of recources"<<endl;
	int m;
	cin>>m;

	assert(n>0 && m>0);

	cout<<"Enter the allocated resources in matrix form. \nA[i][j] will represent how much jth resource is allocated to ith process."<<endl;
	vector<vector<int>>alloc(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>alloc[i][j];
		}
	}
	cout<<"Enter the maximum required resources in matrix form. \nM[i][j] will represent maximum requirement of jth resource ith process."<<endl;
	vector<vector<int>>maxr(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maxr[i][j];
		}
	}
	cout<<"Enter the available amount of every resource."<<endl;
	vector<int>avail(m);
	for(int i=0;i<m;i++)
	{
		cin>>avail[i];
	}
	vector<vector<int>>ans;
	vector<vector<int>>need(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			need[i][j] = maxr[i][j]-alloc[i][j];
		}
	}
	vector<int>sequence(n);
	int factn = 1;
	for(int i=0;i<n;i++) sequence[i] = i+1, factn *= i+1;

	for(int i=0;i<factn;i++)
	{
		if(check(sequence,alloc,maxr,avail,need))
		{
			ans.push_back(sequence);
		}
		next_permutation(sequence.begin(),sequence.end());
	}
	cout<<endl<<endl;
	if(ans.size()==0)
	{
		cout<<"No safe sequence available!"<<endl;
	}
	else
	{
		cout<<"Number of safe sequences available is "<<ans.size()<<endl;
		cout<<"The safe sequences are as follows"<<endl<<endl;
		for(auto g:ans)
		{
			for(auto h:g) cout<<"P"<<h<<" ";
			cout<<endl<<endl;
		}
	}
}