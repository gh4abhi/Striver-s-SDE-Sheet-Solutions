// Problem Link - https://www.codingninjas.com/codestudio/problems/795104?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int
// TC - O(N)
// SC - O(N)
bool isValidParenthesis(string str)
{
    stack<char> st;
    for(auto i:str)
    {
        if(st.size()==0 or i=='(' or i=='[' or i=='{')
            st.push(i);
        else
        {
            if(st.top()=='(' and i==')')
                st.pop();
            else if(st.top()=='[' and i==']')
                st.pop();
            else if(st.top()=='{' and i=='}')
                st.pop();
            else
                return false;
        }
    }
    if(st.size()==0)
        return true;
    return false;
}