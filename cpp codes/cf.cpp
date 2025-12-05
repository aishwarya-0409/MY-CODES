#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Structure to hold array data and its original index
struct ArrayData {
    vector<int> a;
    int k; // length
    int index;
};

// Function to compare two vectors lexicographically
bool is_lex_smaller(const vector<int>& a, const vector<int>& b) {
    // A smaller size vector is lexicographically smaller only if it's a prefix
    // But in this problem, all candidate final rows will have the same length (L_max)
    
    // Check if the other vector is empty or "infinite" (our initial best)
    if (b.empty()) {
        return true;
    }

    int len = min(a.size(), b.size());
    for (int i = 0; i < len; ++i) {
        if (a[i] < b[i]) {
            return true;
        }
        if (a[i] > b[i]) {
            return false;
        }
    }
    // If one is a prefix of the other (shouldn't happen here as length is L_max)
    // return a.size() < b.size();
    return false; // They are equal
}

void solve() {
    int n;
    cin >> n;

    vector<ArrayData> arrays(n);
    int L_max = 0;

    // 1. Read input and find L_max
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        arrays[i].k = k;
        arrays[i].a.resize(k);
        arrays[i].index = i;
        for (int j = 0; j < k; ++j) {
            cin >> arrays[i].a[j];
        }
        L_max = max(L_max, k);
    }

    // A vector to store the minimum element for column j from all arrays except a_i
    // min_val_others[j] will store min(C_j \ {a_i,j}) where i is the array index
    // The dimensions are [L_max + 1][n]
    // Note: We use 1-based indexing for columns (j=1 to L_max)
    // min_val_others[j][i] is the minimum value in column j from arrays a_m where m != i
    vector<vector<int>> min_val_others(L_max + 1, vector<int>(n, numeric_limits<int>::max()));

    // 2. Pre-compute min_val_others[j][i]
    for (int j = 1; j <= L_max; ++j) {
        // Collect all elements in column j
        vector<pair<int, int>> column_j_elements; // pair: {value, array_index}
        for (int i = 0; i < n; ++i) {
            if (arrays[i].k >= j) {
                column_j_elements.push_back({arrays[i].a[j - 1], i});
            }
        }
        
        if (column_j_elements.empty()) continue;

        // Sort to easily find the minimum (and second minimum)
        sort(column_j_elements.begin(), column_j_elements.end());
        
        int M_j = column_j_elements[0].first;
        int i_star = column_j_elements[0].second;

        // The minimum of C_j \ {a_i,j} is M_j for all i != i_star
        // For i = i_star, the minimum of C_j \ {a_{i^*},j} is the second smallest element (if it exists)
        int M_prime_j = numeric_limits<int>::max();
        if (column_j_elements.size() > 1) {
            // Find the second smallest element that is NOT the current min
            // (Handle cases where multiple arrays have the same minimum value)
            for(size_t idx = 1; idx < column_j_elements.size(); ++idx) {
                if (column_j_elements[idx].first > M_j) {
                    M_prime_j = column_j_elements[idx].first;
                    break;
                }
            }
            // If all elements are equal (e.g., {2, 2, 2}), M_prime_j remains MAX
        }

        // Fill min_val_others[j][i]
        for (int i = 0; i < n; ++i) {
            if (i == i_star) {
                // Array a_{i^*} is on the bottom, we need the minimum from the others
                min_val_others[j][i] = M_prime_j;
            } else {
                // Array a_i is on the bottom (i != i^*), the minimum from the others is M_j
                // This holds even if a_i doesn't contribute to column j, 
                // as long as a_{i^*} is not a_i
                min_val_others[j][i] = M_j;
            }
        }
    }

    // 3. Lexicographical Minimum Search
    vector<int> B_best;
    B_best.reserve(L_max);

    for (int i = 0; i < n; ++i) {
        vector<int> B_current;
        B_current.reserve(L_max);
        
        // Part 1: Elements from a_i (for j <= k_i)
        for (int j = 0; j < arrays[i].k; ++j) {
            B_current.push_back(arrays[i].a[j]);
        }

        // Part 2: Elements that fall into empty cells (for j > k_i)
        for (int j = arrays[i].k + 1; j <= L_max; ++j) {
            int val = min_val_others[j][i];
            if (val != numeric_limits<int>::max()) {
                B_current.push_back(val);
            }
        }
        
        // Note: The resulting bottom row will always have L_max elements IF all columns up to L_max have at least one element.
        // Based on the problem's logic, B_current should be constructed to length L_max, but only non-empty columns matter.
        // If B_current is shorter than L_max, it means some column > k_i was empty in all other arrays.
        
        if (is_lex_smaller(B_current, B_best)) {
            B_best = B_current;
        }
    }

    // 4. Output B_best
    for (size_t i = 0; i < B_best.size(); ++i) {
        cout << B_best[i] << (i == B_best.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}