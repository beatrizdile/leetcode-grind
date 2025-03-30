// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    public:
        void divide(vector<Pair>& pairs, int start, int end) {
            if (start >= end)
                return ;
            
            int pivot = conquer(pairs, start, end);
            divide(pairs, start, pivot - 1);
            divide(pairs, pivot + 1, end);
        }
    
        int conquer(vector<Pair>& pairs, int start, int end) {
            int i = start - 1;
            for (int j = start; j <= end; j++) {
                if (pairs[j].key < pairs[end].key) {
                    i++;
                    swap(pairs[j], pairs[i]);
                }
            }
            i++;
            swap(pairs[end], pairs[i]);
    
            return i;
        }
    
        vector<Pair> quickSort(vector<Pair>& pairs) {
            divide(pairs, 0, pairs.size() - 1);
            return pairs;
        }
    };
    