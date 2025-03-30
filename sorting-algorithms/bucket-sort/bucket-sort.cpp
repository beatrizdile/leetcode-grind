class Solution {
    public:
        vector<int> bucketSort(vector<int>& arr) {
            int counts[] = {0, 0, 0};

            for (int n: arr) {
                counts[n]++;
            }
        
            int i = 0;
            for (int n = 0; n < 3; n++) {
                for (int j = 0; j < counts[n]; j++) {
                    arr[i] = n;
                    i++;
                }
            }
            return arr;
        }
    };
