// CPP program to demonstrate optimal page
// replacement algorithm.
#include <bits/stdc++.h>
using namespace std;

// Function to check whether a page exists
// in a frame or not
bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
	{
		if (fr[i] == key)
		{
			return true;
		}
	}
	return false;
}

// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(vector<int>& pg, vector<int>& fr, int pn, int index)
{
	// Store the index of pages which are going
	// to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) 
	{
		int j;
		for (j = index; j < pn; j++) 
		{
			if (fr[i] == pg[j]) 
			{
				if (j > farthest) 
				{
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future,
		// return it.
		if (j == pn)
		{
			return i;
		}
	}

	// If all of the frames were not in future,
	// return any of them, we return 0. Otherwise
	// we return res.
	return (res == -1) ? 0 : res;
}

void optimalPage(vector<int>& pg, int pn, int fn)
{
	// Create an array for given number of
	// frames and initialize it as empty.
	vector<int> fr;

	// Traverse through page reference array
	// and check for miss and hit.
	int hit = 0;
	for (int i = 0; i < pn; i++) 
	{

		// Page found in a frame : HIT
		if (search(pg[i], fr)) 
		{
			hit++;
			continue;
		}

		// Page not found in a frame : MISS

		// If there is space available in frames.
		if (fr.size() < fn)
		{
			fr.push_back(pg[i]);
		}
		else // Find the page to be replaced. 
		{
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
		for (int i = 0; i < fn; ++i)
		{
			cout << fr[i] << "\t";
		}
		cout << "at time " << i << "\n";
	}
	cout << "No. of hits = " << hit << endl;
	cout << "No. of misses = " << pn - hit << endl;
}

// Driver Function
int main()
{
	int fn, len;
	cin >> fn;
	cout << "Enter the length of page sequence: \n";
	cin >> len;
	vector<int> pg(len);
	for (int i = 0; i < len; ++i)
	{
		cin >> pg[i];
	}
	int pn = len;
	cout << "Best Page Replacement Algorithm: Optimal Algorithm\n\n";
	for (int i = 0; i < fn; ++i)
	{
		cout << "F" << i + 1 << "\t";
	}
	cout << "\n";
	optimalPage(pg, pn, fn);
	return 0;
}