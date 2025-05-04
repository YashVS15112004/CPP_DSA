#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
 int sum=1, i=1, n=ratings.size();
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]) {
                peak++;
                sum+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]) {
                down++;
                sum+=down;
                i++;
            }
            down++;
            if(down>peak) sum+=(down-peak);
        }
        return sum;
}
int main()
{
    vector<int> ratings = {1,0,2};
    cout<<candy(ratings);
}