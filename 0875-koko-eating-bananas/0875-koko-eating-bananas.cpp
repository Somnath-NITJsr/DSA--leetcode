class Solution {
public:
    bool canEat(vector<int>& piles, int time, int& h) {

        long long actual_hours = 0;

        for(int& t: piles) {
            actual_hours += t / time;

            if(t % time != 0) {
                actual_hours++;
            }
        }

        return actual_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l < r) {

            int min_time = l + (r-l)/2;

            if(canEat(piles, min_time, h)) {
                r = min_time;
            } else {
                l = min_time + 1;
            }
        }
        return l;
    }
};