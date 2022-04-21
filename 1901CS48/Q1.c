// NAME: SABYASACHI SARKAR
// ROLL NO: 1901CS48
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

FILE *gnuplotPipe;
int THM[4], TST[4];

char *algorithm[] = {"FCFS", "SCAN", "CSCAN", "SSTF"};

// ORDER AND DISK REQUESTED
typedef struct Request
{
    int idx;
    int req;
} Request;

//  Q-SORT ACCORDING TO DISK REQUESTED
int compare(const void *a, const void *b)
{
    Request A = *((Request *)a);
    Request B = *((Request *)b);
    return (A.req - B.req);
}

// Q-SORT ACCORDING TO INDEX NUMBER
int compare_idx(const void *a, const void *b)
{
    Request A = *((Request *)a);
    Request B = *((Request *)b);
    return (A.idx - B.idx);
}

void gen_plot(int Y[], int size, int plot_num)
{
    FILE *plotdata = fopen(algorithm[plot_num], "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(plotdata, "%d %d\n", i + 1, Y[i]);
        THM[plot_num] += Y[i];
    }
    TST[plot_num] = THM[plot_num] * 5;

    fprintf(gnuplotPipe, "set title \"%s Disk Scheduling\"\nset terminal qt %d\n", algorithm[plot_num], plot_num);
    fprintf(gnuplotPipe, "plot \"%s\" with linespoints linestyle 1 \n", algorithm[plot_num]);
    printf("\n%s Disk Scheduling\nTotal Head Movement = %d\nTotal Seek Time = %d ms\n", algorithm[plot_num], THM[plot_num], TST[plot_num]);

    fclose(plotdata);
    return;
}

// FCFS DISK SCHEDULING
void fcfs(int n_cyc, int head_pos, int n_req, Request disk[])
{
    int head_movement[n_req];

    for (int i = 0; i < n_req; i++)
    {
        head_movement[i] = abs(head_pos - disk[i].req);
        head_pos = disk[i].req;
    }

    gen_plot(head_movement, n_req, 0);
    return;
}

// SCAN DISK SHEDULING
void scan(int n_cyc, int head_pos, int n_req, Request disk[])
{
    int start = -1, idx;
    int head_movement[n_req];

    qsort(disk, n_req, sizeof(Request), compare);

    // Forward movement from the current position
    for (int i = 0; i < n_req; i++)
    {
        if (disk[i].req >= head_pos)
        {
            if (start == -1)
                start = i;
            idx = disk[i].idx;
            head_movement[idx] = disk[i].req - head_pos;
            head_pos = disk[i].req;
        }
    }

    head_pos = n_cyc - 1;
    // Reverse movement from end
    for (int i = start - 1; i >= 0; i--)
    {
        if (disk[i].req <= head_pos)
        {
            idx = disk[i].idx;
            head_movement[idx] = head_pos - disk[i].req;
            head_pos = disk[i].req;
        }
    }

    qsort(disk, n_req, sizeof(Request), compare_idx);

    gen_plot(head_movement, n_req, 1);
}

// CSAN DISK SCHEDULING
void cscan(int n_cyc, int head_pos, int n_req, Request disk[])
{
    int start = -1, idx;
    int head_movement[n_req];

    qsort(disk, n_req, sizeof(Request), compare);

    // Forward movement from the current position
    for (int i = 0; i < n_req; i++)
    {
        if (disk[i].req >= head_pos)
        {
            if (start == -1)
                start = i;
            idx = disk[i].idx;
            head_movement[idx] = disk[i].req - head_pos;
            head_pos = disk[i].req;
        }
    }

    // Return to beginning and then forward movement from beginning
    head_pos = 0;
    for (int i = 0; i < start; i++)
    {
        if (disk[i].req >= head_pos)
        {
            idx = disk[i].idx;
            head_movement[idx] = disk[i].req - head_pos;
            head_pos = disk[i].req;
        }
    }

    qsort(disk, n_req, sizeof(Request), compare_idx);

    gen_plot(head_movement, n_req, 2);
}

// SSTF DISK SCHEDULING
void sstf(int n_cyc, int head_pos, int n_req, Request disk[])
{
    int serviced = 0;
    int head_movement[n_req];

    while (serviced < n_req)
    {
        int min_idx = -1;
        for (int i = 0; i < n_req; i++)
        {
            if (min_idx == -1 || abs(disk[i].req - head_pos) < abs(disk[min_idx].req - head_pos))
                min_idx = i;
        }
        int idx = disk[min_idx].idx;
        head_movement[idx] = abs(disk[min_idx].req - head_pos);
        head_pos = disk[min_idx].req;
        disk[min_idx].req = INT_MAX;
        serviced++;
    }

    gen_plot(head_movement, n_req, 3);
}

// PRINTING THE  SORTED ORDER OF PERFORMANCE ALGORITHM
void print_sorted()
{
    int count = 0;
    printf("\nSorted order of algorithms:\n");
    while (count < 4)
    {
        int min_idx = 0;
        for (int i = 0; i < 4; i++)
        {
            if (THM[i] < THM[min_idx])
                min_idx = i;
        }
        printf("%s ", algorithm[min_idx]);
        THM[min_idx] = INT_MAX;
        count++;
    }
    printf("\n");
}

int main()
{
    int n_cyl, head_pos, n_req;

    printf("Enter Number of Cylinders: ");
    scanf("%d", &n_cyl);

    printf("Enter the head position: ");
    scanf("%d", &head_pos);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n_req);

    Request disk[n_req];
    printf("Enter the requests: \n");
    for (int i = 0; i < n_req; i++)
    {
        scanf("%d", &disk[i].req);
        disk[i].idx = i;
    }

    gnuplotPipe = popen("gnuplot -p", "w");
    fprintf(gnuplotPipe, "set style line 1 \\\n\tlinecolor rgb '#0060ad' \\\n\tlinetype 1 linewidth 2 \\\n\tpointtype 7 pointsize 1.5\nset title font \",15\"\nset xlabel \"Request Number\"\\\n\tfont \",12\"\nset ylabel \"Head Movement\"\\\n\tfont \",12\"\n");

    fcfs(n_cyl, head_pos, n_req, disk);
    scan(n_cyl, head_pos, n_req, disk);
    cscan(n_cyl, head_pos, n_req, disk);
    sstf(n_cyl, head_pos, n_req, disk);

    print_sorted();

    fclose(gnuplotPipe);
}