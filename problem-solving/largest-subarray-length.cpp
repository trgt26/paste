#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int INF = 1e9 + 7;

// Segment Tree to find the minimum index in a range of values
std::vector<int> tree;
int N_seg;

void update(int idx, int val, int n) {
    idx += n;
    tree[idx] = std::min(tree[idx], val);
    for (; idx > 1; idx /= 2) {
        tree[idx / 2] = std::min(tree[idx], tree[idx ^ 1]);
    }
}

int query(int l, int r, int n) { // query on interval [l, r)
    int res = INF;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = std::min(res, tree[l++]);
        if (r & 1) res = std::min(res, tree[--r]);
    }
    return res;
}

// Main function to find the largest subarray length
int largestSubarraySumLessThanK(const std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;

    // 1. Calculate prefix sums
    std::vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    // 2. Coordinate Compression
    std::map<long long, int> val_map;
    for (long long p : prefix_sum) {
        val_map[p] = 0;
        val_map[p - k] = 0;
    }
    int compressed_idx = 0;
    for (auto const& [val, ignore] : val_map) {
        val_map[val] = compressed_idx++;
    }
    
    // 3. Initialize Segment Tree
    N_seg = val_map.size();
    tree.assign(2 * N_seg, INF);

    int max_len = 0;
    
    // 4. Iterate through prefix sums
    for (int i = 0; i < n + 1; ++i) {
        // We need P[j] > P[i] - k
        // Find compressed index for P[i] - k
        auto it = val_map.upper_bound(prefix_sum[i] - k);
        if (it != val_map.end()) {
            int l = it->second;
            int r = N_seg;
            // Query for minimum index j in the value range
            int min_j = query(l, r, N_seg);
            if (min_j < i) {
                max_len = std::max(max_len, i - min_j);
            }
        }
        
        // Update segment tree with current P[i] and its index i
        update(val_map[prefix_sum[i]], i, N_seg);
    }

    return max_len;
}

int main() {
    std::vector<int> nums = {2, -3, 5, -1, 4, -8, 6};
    int k = 5;
    int result = largestSubarraySumLessThanK(nums, k);
    // Expected: Subarray [2, -3, 5, -1] has sum 3 and length 4.
    std::cout << "Largest length of subarray with sum less than " << k << " is: " << result << std::endl; // Output: 4

    std::vector<int> nums2 = {10, -5, 1};
    int k2 = 5;
    result = largestSubarraySumLessThanK(nums2, k2);
    // Expected: Subarray [-5, 1] has sum -4 and length 2.
    std::cout << "Largest length of subarray with sum less than " << k2 << " is: " << result << std::endl; // Output: 2
    
    return 0;
}