// Name : Sabyasachi Sarkar
// Roll NO: 1901CS48

// Question No: 3


#include<bits/stdc++.h>
using namespace std;
float solve(float a, float b, float c, float d, float e)
{
	float ans1 = a*(c+d)+(1-a)*(b*(c+2*d)+(1-b)*(c+2*d+e));
	return ans1;
}
int main()
{
	float tlb_hr, pgt_hr,tlb_ac,mm_ac,pg_st;
	cout<<"TLB hit ratio"<<endl;
	cin>>tlb_hr;
	cout<<"Page table hit Ratio: "<<endl;
	cin>>pgt_hr;
	cout<<"TLB access time(ns) "<<endl;
	cin>>tlb_ac;
	cout<<" Main memory acces time(ns)"<<endl;
	cin>>mm_ac;
	cout<<"Page Fault service time(ns)"<<endl;
	cin>>pg_st;

	float ans = solve(tlb_hr,pgt_hr ,tlb_ac, mm_ac,pg_st);
	cout<<"Effecrtfive memory accesss time: "<<ans<<endl;
	return 0;
}