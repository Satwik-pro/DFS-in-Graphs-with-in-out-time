#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,edges,start,x,y,t=1,i,c=0;
    stack<int>s;
    multimap<int,int>mp;
    map<int,pair<int,int>>io;
    map<int,pair<int,int>>::iterator itr;
    cout<<"Enter number of vertices : ";
    cin>>v;
    for(i=0;i<v;i++)
    io.insert(make_pair(i,make_pair(0,0)));
    vector<int>vt(v);
    vector<int>::iterator it; 
    bool arr[v]={0};
    cout<<"Enter number of edges : ";
    cin>>edges;
    cout<<"Enter the pair of vertices : \n";
    for(i=0;i<edges;i++)
    {
        cin>>x>>y;
        mp.insert(make_pair(x,y));
    }
    cout<<"Enter start edge : ";
    cin>>start;
    cout<<"DFS Traversal  :  ";
    s.push(start);
    arr[start]=1;
    itr=io.find(s.top());
    itr->second.first=t;
    t++;
    vt.clear();
    while(!s.empty() || c!=v)
    {
        c=0;
        bool f=1;
        it=find(vt.begin(),vt.end(),s.top()); 
        if(it == vt.end())
        vt.push_back(s.top());
        for(auto x=mp.find(s.top()); x!=mp.end(); x++)
        {
            if(x->first==s.top() && arr[x->second]==0)
            {
                s.push(x->second);
                itr=io.find(x->second);
                itr->second.first=t;
                t++;
                arr[x->second]=1;
                f=0;
                break;
            }
            else if(x->first != s.top())
            break;
        }
        if(f==1)
        {
            itr=io.find(s.top());
            itr->second.second=t;
            t++;
            s.pop();
        }
        for(i=0;i<v;i++)
        {
            if(arr[i]==1)
            c++;
            else if(s.empty() && arr[i]==0)
            {
                s.push(i);
                arr[i]=1;
                itr=io.find(s.top());
                itr->second.first=t;
                t++;
                break;
            }
        }
    }
    for(auto x : vt)
    {
        cout<<x<<"  ";
        itr=io.find(x);
        cout<<"Entry : "<<itr->second.first<<" / Exit : "<<itr->second.second<<"\n";
    }
    return 0;
}
