class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> canTake;
        vector<int> indegree(numCourses);

        for (const auto& prereq : prerequisites) {
            canTake[prereq.back()].push_back(prereq.front());
            ++indegree[prereq.front()];
        }

        queue<int> q;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            auto course = q.front();
            q.pop();

            order.push_back(course);

            for (auto nextCourse : canTake[course]) {
                if (--indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>{};
    }
};
