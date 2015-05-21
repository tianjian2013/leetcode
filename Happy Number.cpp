#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tri(vector <vector <int > > &input)
{
    int n=input.size();
    vector <int > line=input[0];
    for(int i=1;i<n;i++)
    {
        vector <int > newline;
        newline.push_back(line[0]+input[i][0]);
        for(int j=1;j<i;j++)
        {
            newline.push_back(  max(line[j-1],line[j])+input[i][j]);
        }
        newline.push_back(line[i-1]+input[i][i]);
        swap(line,newline);
    }
    return *max_element(line.begin(),line.end());
    
    
}
int  main()
{
	int n;
    cin>>n;
    if(n<=0) return 0;
    int tmp;
    vector <vector <int > > input;
    for(int i=0;i<n;i++)
    {
        vector <int > line;
        for(int j=0;j<=i;j++)
        {
            cin>>tmp;
            line.push_back(tmp);
        }
        input.push_back(line);
    }
    cout<<tri(input)<<endl;
	return 0;
}