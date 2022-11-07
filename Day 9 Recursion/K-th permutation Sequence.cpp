// Problem Link - https://www.codingninjas.com/codestudio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

string kthPermutation(int n, int k) {
    vector<ll> vect;
    ll fact = 1;
    for(ll i=1;i<n;i++)
        fact*=i, vect.push_back(i);
    vect.push_back(n);
    k-=1;
    string ans = "";
    while(1)
    {
        ans += to_string(vect[k/fact]);
        vect.erase(vect.begin()+k/fact);
        if(vect.size()==0)
            break;
        k = k%fact;
        fact = fact/vect.size();
    }
    return ans;
}
