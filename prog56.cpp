#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval& lhs, const Interval& rhs)
{
    if (lhs.start < rhs.start)
        return true;
    else if (rhs.start < lhs.start)
        return false;
    else
        return lhs.end < rhs.end;
}

vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    if (intervals.size() <=0 ) return result;

    sort(intervals.begin(),intervals.end(),compare);
    Interval running{intervals[0]};
    for (int i=1; i<intervals.size();++i)
    {
        if (running.end < intervals[i].start)
        {
            result.push_back(running);
            running=intervals[i];
        }
        else
        {
            running.end = (running.end>intervals[i].end)?
                            running.end : intervals[i].end;
        }
    }
    result.push_back(running);
    return result;
}

void printInterval(Interval& interval)
{
    cout << "["<<interval.start << ","<< interval.end <<"]";
}

void printIntervals(vector<Interval>& intervals)
{
    for (auto x : intervals)
    {
        printInterval(x);
        cout << " ";
    }
    cout << endl;
}

int main()
{
    vector<Interval> intervals;
    Interval i1{1,4};
    Interval i2{0,2};
    Interval i3{3,5};
    Interval i4{4,18};
    intervals.push_back(i4);
    intervals.push_back(i3);
    intervals.push_back(i2);
    intervals.push_back(i1);
    printIntervals(intervals);
    auto newIntervals=merge(intervals);
    printIntervals(newIntervals);
    return 0;
}



