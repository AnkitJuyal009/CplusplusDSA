
#include<iostream>
#include <vector>
#include <algorithm>

// In this question we sort the intervals using compareIntervals(). the vector is sorted through second element of vector.
// Then we just check if the index pos of second element is greater than the ith pos of first element, if its true then we just find the max and min of index and i positions.
//else we just increment index and put value of index to the ith position.

//TC => O(nlogn)

using namespace std;

struct Interval {
     int first, second;
};

bool compareIntervals(Interval i1, Interval i2) {

    return (i1.second < i2.second);
}

void mergeIntervals( vector<Interval>& v, int len) {
    
    if(len <= 0) {
        return;
    }

    sort(v.begin(), v.end(), compareIntervals);

    for(auto it : v) {
        cout<<it.first<<it.second<<'\n';
    }
    
    int index = 0;

    for (int i=1; i<len; i++)
    {
        if (v[index].second >=  v[i].first) {
            v[index].second = max(v[index].second, v[i].second);
            v[index].first = min(v[index].first, v[i].first);
        }
        else {
            index++;
            v[index] = v[i];
        }
    }

    cout << "\n The Merged Intervals are: ";

    for (int i = 0; i <= index; ++i) {

        cout << "[" << v.at(i).first << " " << v.at(i).second << "]" << '\n';
    }
}


int main() {

    vector<Interval> intervals = {{2,4},{6,8},{1,3},{7,10}};

    int n = intervals.size();

    mergeIntervals(intervals, n);
}

