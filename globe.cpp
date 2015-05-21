#include "globe.h"
void showvector(vector<int>  input)
{
	for(size_t i=0;i<input.size();i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
}


/*********************
Solution sl;
	vector<int> m1;
	m1.push_back(1);
	m1.push_back(2);



	vector<int> m0;
	m0.push_back(-1);

	vector<int> m1;
	m1.push_back(2);
	m1.push_back(3);

	vector<int> m2;
	m1.push_back(1);
	m1.push_back(-1);
	m1.push_back(-1);

	vector<vector<int> > input;
	input.push_back(m0);
	input.push_back(m1);
	input.push_back(m2);


/*********************/