class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> prereqs(numCourses);

        for (auto &pre : prerequisites) {
            ++indegree[pre.back()];
            prereqs[pre.front()].push_back(pre.back());
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finishes = 0;
        while (!q.empty()) {
            auto course = q.front();
            q.pop();
            ++finishes;

            for (auto nextCourse : prereqs[course]) {
                if (--indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return finishes == numCourses;
    }
};
