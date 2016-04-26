class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int index = 0;
        bool flag = false;
        while (index < intervals.size()) {
            if (newInterval.start > intervals[index].end) {
                result.push_back(intervals[index]);
            } else { 
                if (newInterval.end < intervals[index].start) {
                    if (!flag) {
                        result.push_back(newInterval);
                        flag = true;
                    }
                    result.push_back(intervals[index]);
                } else {
                    newInterval.start = newInterval.start < intervals[index].start ? newInterval.start : intervals[index].start;
                    newInterval.end = newInterval.end > intervals[index].end ? newInterval.end : intervals[index].end;
                } 
            }
            ++index;
        }
        if (intervals.size() == 0 || newInterval.end > intervals[index - 1].start) {
            result.push_back(newInterval);
        }
        return result;
    }
};
