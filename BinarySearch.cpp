using namespace std;
#include<cmath>
#include <iostream>
#include <algorithm>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include <map>
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
priority_queue<int> heap;
vector<pair<string, int>> output;

// Binary_search implementation
bool Binary_search(int arr[], int n, int k)
{
    int l =0, r = n-1 ;
    while (l<= r)
    {
        int mid = (l+r) /2 ; // l + (r-l) /2 ;
        if (arr[mid] == k ) return true ;
        else
        {
            if (arr[mid] < k ) return l = mid+1 ;
            else r = mid-1 ;
        }
    }
    return false ;

}
int find_lower(vector<int>& v, int x) {
    int l = -1, r = v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] > x) r = m;
        else l = m;
    }
    return l;
}

int find_upper(vector<int>& v, int x) {
    int l = -1, r = v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] < x) l = m;
        else r = m;
    }
    return r;
}
int main()
{
    // 1.Binary search over array or vector
    int n,  k ;
    cin >> n >> k ;
    int arr[n] ;
    for (int i =0 ; i < n ; i++)cin >> arr[i] ;

    sort (arr,arr+n) ;
    // built in Functions
    //1.binarySearch
    //print value
    cout<< *binary_search(arr, arr+n, k) <<endl ;
    // print position
    cout<< binary_search(arr, arr+n, k) <<endl  ;
    //2.lower_bound
    //print value
    cout<< *lower_bound(arr, arr+n, k)<<endl  ;
    // print position
    cout<< lower_bound(arr, arr+n, k) - arr<<endl  ;
    //2.upper_bound
    //print value
    cout<< *upper_bound(arr, arr+n, k)<<endl  ;
    // print position
    cout<< upper_bound(arr, arr+n, k) - arr <<endl ;
    //================================================

    vector <int> v ;
    int num ;
    for (int i =0 ; i < n ; i++)
    {
        cin >> num ;
        v.push_back(num) ;

    }
    sort (v.begin(), v.end() ) ;
    // built in Functions
    //1.binarySearch
    //print value
    cout<< binary_search(v.begin(), v.end(), k)<<endl  ;
    // print position
    cout<< binary_search(v.begin(), v.end(), k)<<endl  ;
    //2.lower_bound
    //print value
    cout<< *lower_bound(v.begin(), v.end(), k)<<endl  ;
    // print position
    cout<< lower_bound(v.begin(), v.end(), k) - v.begin() <<endl;
    //2.upper_bound
    //print value
    cout<< *upper_bound(v.begin(), v.end(), k)<<endl  ;
    // print position
    cout<< upper_bound(v.begin(), v.end(), k) - v.begin() <<endl ;

    //==================================================================
    // Upper_bound and Lower_bound with set and map
    set <int> s ;
    for(int i =0 ; i < n ; i++)
    {
        cin >> num ;
        s.insert(num) ;
    }
    cout << *s.upper_bound(k) <<endl ;
    cout << *s.lower_bound(k) <<endl;

     map<int , int> mp ;
    for(int i =0 ; i < n ; i++)
    {
        cin >> num ;
        mp[num]++ ;
    }
    cout << (*mp.upper_bound(k)).first <<endl ;
    cout << (*mp.lower_bound(k)).first <<endl;

    //=========================================================================
}
