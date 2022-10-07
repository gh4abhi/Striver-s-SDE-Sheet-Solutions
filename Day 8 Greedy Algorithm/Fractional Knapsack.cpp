// Problem Link - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
struct Item{
    int value;
    int weight;
};
*/
#define ll int

bool cmp(struct Item &a, struct Item &b)
{
    return (a.value*1.0)/a.weight > (b.value*1.0)/b.weight;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double ans = 0;
        ll w = 0;
        for(ll i=0;i<n;i++)
        {
            if(w+arr[i].weight<=W)
                w += arr[i].weight, ans += arr[i].value;
            else
            {
                ans += (W-w)*((arr[i].value*1.0)/arr[i].weight);
                break;
            }
        }
        return ans;
    }
};