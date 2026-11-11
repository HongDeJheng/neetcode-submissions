class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canFinish = [&](const int& speed) {
            int time = 0;
            for (const auto& pile : piles) {
                time += pile / speed;
                if (pile % speed != 0) {
                    ++time;
                }

                if (time > h) {
                    return false;
                }
            }

            return time <= h;
        };

        int low = 1, high = 1e9;
        int minSpeed = high;
        while (low < high) {
            int speed = (low + high) / 2;

            if (canFinish(speed)) {
                high = speed;
                minSpeed = min(minSpeed, speed);
            }
            else {
                low = speed + 1;
            }
        }

        return minSpeed;
    }
};
