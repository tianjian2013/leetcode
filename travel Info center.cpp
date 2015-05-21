#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector < vector <int > >  &ref,vector <bool> &fcity,int city) //breadth-first search
{
	if(fcity[city]) return 0;

	vector <int > color(fcity.size(),0);  //status of a city , not visited(0) ,being visited(1), have been visited(2) 
	color[city]=1;
	vector <int > dist(fcity.size(),0);   //distance between the input city and other cities 
	dist[city]=0;

	queue<int> qe;     // use a queue to visit all cities 
	qe.push(city);

	
	while(qe.size())   
	{
		int k=qe.front();
		qe.pop();
                int num=ref[k].size();
		for(int i=0;i<num;i++) //visit  Adjacency cities of the kth city
		{
   			if(color[ref[k][i] ]==0 ) //if a city is not visited ,visit it 
			{
				color[ref[k][i] ]=1;  
				qe.push(ref[k][i] );
				dist[ref[k][i]]=dist[k]+1; //add the distance 
				if(fcity[ref[k][i]]) 
					return dist[ref[k][i]]; // find the result ,return it 
			}
			color[k]=2;
		}

	}
	return -1; // can not find a festive city,error
}


int main()
{
	int n,m;
	cin>>n>>m;
	if(n<2||n>100000||m<1||m>100000) 
	{
		cout<<"m should be in the range of [1,100000] and n [2,100000]"<<endl;
		return 0;
	}
	vector < vector <int > >  ref(n); // Adjacency list of the input graph 
	vector <bool> fcity(n,false);     //store the state of a city, festive city or not 
	fcity[0]=true;                    // only the city No.1 is festive city at the beginning 
	for(int i=0;i<n-1;i++)            // build the Adjacency list 
	{
		int p,q;
		cin>>p>>q;                 // for a faster execution ,do not examine the input 
		ref[p-1].push_back(q-1);
		ref[q-1].push_back(p-1);
	}
	for(int i=0;i<m;i++)
	{
		int flag,city;
		cin>>flag>>city;
		if(flag==1)   // announce a new festive city
		{
			fcity[city-1]=true;
		}
		if(flag==2)  //find and print the shortest distance 
		{
			cout<<bfs(ref,fcity,city-1)<<endl; 
		}
	}

	return 0;
}