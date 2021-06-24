// https://codeforces.com/blog/entry/11080
// https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

// for ordered multiset: just use ordered set but pairs as the elements

int main () {
    oset ose;

    ose.insert(X); ose.find(X); ose.end(); ose.erase(X); // same as set probably
    ose.order_of_key(X) // find number of elements strictly less than X in ose
    ose.find_by_order(k) // find k-th largest elements of X (0-indexing)
}