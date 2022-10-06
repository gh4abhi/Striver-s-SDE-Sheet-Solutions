// Problem Link - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<ll> st;
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(i);
                ans.push_back(1);
                continue;
            }
            while(st.size() and price[st.top()]<=price[i])
                st.pop();
            if(st.size())
                ans.push_back(i-st.top());
            else
                ans.push_back(i+1);
            st.push(i);
        }
        return ans;
    }
};