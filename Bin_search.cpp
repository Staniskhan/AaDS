#include <iostream>
#include <vector>
using namespace std;

int lower_bound(const vector<int>& a, int x) {
    int low = 0, high = a.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int upper_bound(const vector<int>& a, int x) {
    int low = 0, high = a.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        int l = lower_bound(a, x);
        int r = upper_bound(a, x);
        int b = (l < n && a[l] == x) ? 1 : 0;
        cout << b << " " << l << " " << r << "\n";
    }

    return 0;
}