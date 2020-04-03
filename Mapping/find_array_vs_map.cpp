#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin>>t;

    while (t--){
        int a,cnt=0;
        map<int, int> mp;

        int arr[a];

        for(int i=0;i<t;i++){
            cin>>a;
            arr[a]++; /// no need to map if there is no value

            /*

            mp[a]=i;  ///if value exists
            */
        }

        for(int i=1;i<=t ;i++){
            if(mp.find(i) != mp.end()){  ///if i exists in the map
                cnt++;
            }
        }

    }

}
