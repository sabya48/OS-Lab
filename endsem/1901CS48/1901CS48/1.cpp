// Name : sabyasachi sarkar
// Roll no:1901CS48

// Question No: 1

#include <bits/stdc++.h>
using namespace std;


int getDistance(int x, int y)
{
    return abs(x - y);
}

int main()
{
    // freopen("input.txt","r",stdin);

    cout << "Enter minimum cyclinder, maximum cyclinder and initial head position." << endl;
    int minCylinder, maxCylinder, ihp;
    cin >> minCylinder >> maxCylinder >> ihp;

    cout << "Enter the number of requests." << endl;
    int numRequests;
    cin >> numRequests;

    vector<int> requests, leftRequests, rightRequests, dhm;
    dhm.push_back(ihp);

    cout << "Enter the requests." << endl;

    for (int i = 0; i < numRequests; i++)
    {
        int request;
        cin >> request;

        if(request == ihp)
            continue;

        if(request <= ihp)
            leftRequests.push_back(request);
        else
            rightRequests.push_back(request);

        requests.push_back(request);
    }

    sort(leftRequests.begin(), leftRequests.end());
    reverse(leftRequests.begin(), leftRequests.end());
    sort(rightRequests.begin(), rightRequests.end());

    if(leftRequests.empty())
        dhm = rightRequests;
    else if(rightRequests.empty())
        dhm = leftRequests;
    else
    {
        int leftmostRequest = leftRequests.back(), rightmostRequest = rightRequests.back();

        if(getDistance(leftmostRequest, ihp) <= getDistance(rightmostRequest, ihp))
        {
            dhm.insert(dhm.end(), leftRequests.begin(), leftRequests.end());
            dhm.insert(dhm.end(), rightRequests.begin(), rightRequests.end());
        }
        else
        {
            dhm.insert(dhm.end(), rightRequests.begin(), rightRequests.end());
            dhm.insert(dhm.end(), leftRequests.begin(), leftRequests.end());
        }
    }

    int seekTime = 0;

    for(int i = 1; i < dhm.size(); ++i)
        seekTime += getDistance(dhm[i], dhm[i-1]);

    cout << "Disk head movement is: ";

    for(int i = 0; i < dhm.size(); ++i)
        cout << dhm[i] << " ";
    cout << endl;

    cout << "Seek time = " << seekTime << endl;
    
    return 0;
}