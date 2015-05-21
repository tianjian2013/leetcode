#include "globe.h"

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 bool cmp(Interval &i1,Interval &i2)
 {
     return i1.start<i2.start;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> ret;
        Interval tmp=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start>tmp.end )
            {
                ret.push_back(tmp);
                tmp=intervals[i];
            }
            else
            {
                if(intervals[i].end>tmp.end )
                  tmp.end=intervals[i].end ;
            }
        }
        return ret;
        
    }
};

void main()
{

}