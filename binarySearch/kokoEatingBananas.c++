class Solution {
public:
    // Brute Force - try every bananas-per-hour rate from 1 to max(piles)
    // Time: O(nm) - Time Limit Exceeded
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles[i] - how many bananas in pile
        // h - hours
        // koko can decide her bananas per hour eating speed
        // EACH hour she can choose a pile and eat k bananas from the pile
        // if the pile has less than k bananas she eats all of them and will not eat any more
        // return the minimum amount of bananas she has to eat per hour to eat all the bananas before the guards come back


        int maxB = *max_element(piles.begin(), piles.end());

       
        for (int eating = 1; eating <= maxB; eating++) {
            int k = 0;
            for (int i = 0; i < piles.size(); i++) {
                k += ceil((double)piles[i]/eating);
                if (k > h) {
                    break;
                }
            }   
            if (k <= h) {
                return eating;
            }     
        }
        return -1;
    }

    // Binary Search
    // Time: O(n*logm)
    // Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles[i] - how many bananas in pile
        // h - hours
        // koko can decide her bananas per hour eating speed
        // EACH hour she can choose a pile and eat k bananas from the pile
        // if the pile has less than k bananaa she eats all of them and will not eat any more
        // return the minimum amount of bananas she has to eat per hour to eat all the bananas before the guards come back

        int left = 1, right = *max_element(piles.begin(), piles.end());
        int k = INT_MAX;
        while (left <= right) {
            int speed = (left+right)/2;
            int hourSpent = 0;
            for (int i = 0; i < piles.size(); ++i) {
                hourSpent +=  piles[i] / speed + (piles[i] % speed != 0);
                if (hourSpent > h) {
                    left = speed+1;
                    break;
                }
            }   
            if (hourSpent <= h) {
                right = speed-1;
                k = min(speed, k);
            }     
        }
        return k;
    }
};