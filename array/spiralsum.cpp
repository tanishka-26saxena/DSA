#include<iostream>
#include<vector>
using namespace std;
void spiralsum(vector<vector<int>>& vec)
{
    vector<int> ans;
    int row=vec.size();
    int col=vec[0].size();

    int count=0;
    int total=row*col;

    int startingrow=0;
    int startingcol=0;
    int endingrow=row-1;
    int endingcol=col-1;

    while(count<total)
    {
        //print starting row
        for(int index=startingcol; index<=endingcol && count<total;index++)
        {
            ans.push_back(vec[startingrow][index]);
            count++;
        }
        startingrow++;

        //print ending column
        for(int index=startingrow; index<=endingrow && count<total;index++)
        {
            ans.push_back(vec[index][endingcol]);
            count++;
        }
        endingcol--;

        //print ending row
        for(int index=endingcol;index>=startingcol && count<total; index--)
        {
            ans.push_back(vec[endingrow][index]);
            count++;
        }
        endingrow--;

        //print starting column
        for(int index=endingrow; index>=startingrow && count<total; index--)
        {
            ans.push_back(vec[index][startingcol]);
            count++;
        }
        startingcol++;

        
    }
    cout<<"spiral array is\n";
    for(int i=0;i<total;i++)
    {
        cout<<ans[i]<<" ";
    }

}
int main()
{
    cout<<"enter length of row\n";
    int r;
    cin>>r;
    cout<<"enter length of column\n";
    int c;
    cin>>c;
    cout<<"enter array\n";
    vector<vector<int>> v;
    for(int i=0;i<r;i++)
    {
        vector<int>row;
        for(int j=0;j<c;j++)
        {
            int ele;
            cin>>ele;
            row.push_back(ele);
        }
        v.push_back(row);

    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    spiralsum(v);
    return 0;
}