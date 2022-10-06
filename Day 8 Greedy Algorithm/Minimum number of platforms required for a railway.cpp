// Problem Link - https://www.codingninjas.com/codestudio/problems/799400?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    ll plat = 1;
    ll ans = 1;
    ll i=1,j=0;
    while(i<n and j<n)
    {
        if(at[i]<=dt[j])
            i++,plat+=1;
        else
            plat-=1,j++;
        ans = max(ans,plat);
    }
    return ans;
}