#include<bits/stdc++.h>
using namespace std;

void print(vector<char> v)
{
    for(int i=0;i<v.size();i++)
    cout<<v[i];

    //v.clear();

    cout<<endl;
}

void generate(string s,vector<char> v,int ind)
{
    if(v.size()>=0)
    {
        print(v);
        if(ind==s.size())
        return;
    }

    for(int i=ind;i<s.size();i++)
    {
        v.push_back(s[i]);
        generate(s,v,i+1);
        v.pop_back();
    }
    return;

}



int main()
{
    string s;
    cin>>s;

    vector<char> v;

    generate(s,v,0);
    return 0;
}