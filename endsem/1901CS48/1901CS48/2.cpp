// Name : Sabyasachi Sarkar
// Roll No: 1901CS48

// Question NO: 2


#include <bits/stdc++.h>
 
using namespace std;
 
int pageFault(int frame_size, int* ref, int len)
{
    
    int* arr = new int[frame_size];
 

    for (int i = 0; i < frame_size; i++) {
        arr[i] = -1;
    }
 
   
    int cnt = 0;
    int start = 0;
    int flag;
    int elm;
 
    for (int i = 0; i < len; i++) {
        elm = ref[i];
        
        flag = 0;
        for (int j = 0; j < frame_size; j++) {
            if (elm == arr[j]) {
                flag = 1;
                break;
            }
        }
       
        if (flag == 0) {
            if (start < frame_size) {
                arr[start] = elm;
                start++;
            }
            else if (start == frame_size) {
                arr[0] = elm;
                start = 1;
            }
            cnt++;
        }
    }

    
    cout << "# page faults for " << frame_size << " frames =";
    cout  << cnt << endl;
    
    return cnt;
}
 
int main()
{
   
    int len;
	    
	printf("Please enter the length of the sequence.\n");
	scanf("%d",&len);
    	int seq[len] ;
    	printf("Please enter the page sequence.\n");
	for(int i=0;i<len;i++)
	{
		scanf("%d",&seq[i]);
	}
	  
	int initial_frame_size ;
	int increased_frame_size ;
	
	printf("Please enter the initial frame size.\n");
	scanf("%d",&initial_frame_size);
 	

    
  
 	printf("Please enter the increased frame size.\n");
	scanf("%d",&increased_frame_size);
	
	int x1=pageFault(initial_frame_size, seq, len);

    	int x2=pageFault(increased_frame_size, seq, len);
 
    if(x1<x2)
    {
        printf("Belady's anomaly detected.\n");
    }
   
 
  
}
