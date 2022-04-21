#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int, int> page_table, rev_page_table;
set<int> blocked_frames, filled_frames, available_frames;
int p, v, f;
int curr_page, num_ranges, q;
int tot_frames, max_page_lim;

void translate(int log_address)
{
    int tot_frames = (1 << v) / (1 << f);
    int page_no = (log_address >> f);
    cout << "Page no : " << page_no << endl;
    int page_offset = 0;
    for (int i = 0; i < f; i++)
    {
        if (((1 << i) & log_address))
        {
            page_offset += (1 << i);
        }
    }
    if (page_table.find(page_no) == page_table.end())
    {
        cout << "Invalid page number!" << endl;
        return;
    }
    int frame_no = page_table[page_no];
    int phy_address = page_offset + (frame_no << f);
    cout << "The physical address is " << phy_address << endl;
}

void allocate(int process_size)
{
    vector<int> frames_occ;
    int frames_needed = process_size / (1 << f);
    if (frames_needed > available_frames.size())
    {
        cout << "The process exceeds the limit of the memory!" << endl;
        return;
    }
    else
    {
        while (frames_needed != 0)
        {
            int curr_frame = *available_frames.begin();
            available_frames.erase(available_frames.begin());
            frames_needed--;
            filled_frames.insert(curr_frame);
            page_table[curr_page] = curr_frame;
            rev_page_table[curr_frame] = curr_page;
            curr_page++;
            frames_occ.push_back(curr_frame);
        }
    }
    cout << process_size << " bytes has been allocated in frame no ";
    for (int x : frames_occ)
        cout << x << " ";
    cout << endl;
}

void delete_page(int page_no)
{
    if (page_table.find(page_no) == page_table.end())
    {
        cout << "The page is either not allowed to keep any user data or is already deleted!" << endl;
        return;
    }
    int curr_frame = page_table[page_no];
    filled_frames.erase(curr_frame);
    available_frames.insert(curr_frame);
    page_table.erase(curr_frame);
    rev_page_table.erase(page_no);
    cout << "Frame number " << curr_frame << " has been deleted!" << endl;
}

signed main()
{
    cin >> p >> v >> f;
    tot_frames = (1 << (p - f)), max_page_lim = (1 << (v - f));
    cin >> num_ranges;
    for (int i = 0; i < max_page_lim; i++)
    {
        available_frames.insert(i);
    }
    for (int i = 0; i < num_ranges; i++)
    {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
        {
            blocked_frames.insert(j);
            available_frames.erase(j);
        }
    }
    cin >> q;
    while (q--)
    {
        char ch;
        int pres;
        cin >> ch >> pres;
        if (ch == 'a')
        {
            allocate(pres);
        }
        else if (ch == 't')
        {
            translate(pres);
        }
        else
        {
            delete_page(pres);
        }
    }
}