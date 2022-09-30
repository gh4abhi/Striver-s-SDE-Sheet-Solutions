// Problem Link - https://www.codingninjas.com/codestudio/problems/1090543?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

string writeAsYouSpeak(int n) 
{
    if(n==1)
        return "1";
    if(n==2)
        return "11";
    string str = writeAsYouSpeak(n-1);
    string ans = "";
    ll count = 1;
    for(ll i=0;i<str.length();i++)
    {
        if(i==str.length()-1 or str[i]!=str[i+1])
            ans += to_string(count) + str[i], count = 1;
        else
            count++;
    }
    return ans;
}