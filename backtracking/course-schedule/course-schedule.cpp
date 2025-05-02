class Solution {
    public:
        bool dfs(set<int>& currentCourses, map<int, vector<int>>& courseDependencies, int currentCourse, map<int, bool>& cache) {        
            if (cache.count(currentCourse) != 0)
                return cache[currentCourse];
    
            if (currentCourses.count(currentCourse) != 0)
                return false;
    
            if (courseDependencies.count(currentCourse) == 0) {
                currentCourses.erase(currentCourse);
                cache[currentCourse] = true;
                return true;
            }
    
            currentCourses.insert(currentCourse);
            for (auto nextCourse : courseDependencies[currentCourse]) {
                if (!dfs(currentCourses, courseDependencies, nextCourse, cache)) {
                    return false;
                }
            }
            currentCourses.erase(currentCourse);
            cache[currentCourse] = true;
    
            return true;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            if (prerequisites.empty())
                return true;
    
            map<int, vector<int>> courseDependencies;
            for (int i = 0; i < prerequisites.size(); i++)
                courseDependencies[prerequisites[i][0]].push_back(prerequisites[i][1]);
    
            map<int, bool> cache;
            for (auto course : courseDependencies) {
                set<int> currentCourses;
                if (!dfs(currentCourses, courseDependencies, course.first, cache))
                    return false;
            }
    
            return true;
        }
    };
    