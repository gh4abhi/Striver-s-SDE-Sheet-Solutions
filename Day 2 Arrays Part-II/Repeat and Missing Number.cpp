// Problrm Link - https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#define ll int

vector<int> Solution::repeatedNumber(const vector<int> &vect) {
    vector<ll> ans;
    vector<ll> A = vect;
    for(ll i=0;i<A.size();i++)
    {
        if(A[abs(A[i])-1]<0)
            ans.push_back(abs(A[i]));
        else
            A[abs(A[i])-1] = -(A[abs(A[i])-1]);
    }
    for(ll i=0;i<A.size();i++)
    {
        if(A[i]>0)
        {
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}
