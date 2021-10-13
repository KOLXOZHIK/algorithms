//Problem source - https://leetcode.com/problems/3sum/` 
//given array of integers, find indices of three elements of the array which add up 0
//Author: KOLXOZHIK

#include <unordered_map>
#include <utility> //for pair and make_pair
#include <vector>
#include <iostream>

using namespace std;

pair<int,int> find_two_sum(const vector<int>& v, const unordered_map<int,int>& umap, int skip, int target_val)
/**
 * @param v - input vector of integer values
 * @param umap - input map of values of elements of vector v
 * @param skip - index to skip
 * @param target_val - input target value for the sum of two elements
 * @return - a pair of indices in the input vector v which add up to the target_value
*/
{
    pair<int,int> res = make_pair(-1,-1);
    auto n = v.size();
    for(int i =0; i < n; i++)
    {
       if(i==skip)
	   continue;
       if(umap.find(target_val-v[i]) != umap.end() && umap.at(target_val-v[i]) != i && umap.at(target_val-v[i]) != skip) 
       {
	   res.first = i;
	   res.second = umap.at(target_val-v[i]);
	   break;
       } 
    }
    return res;
}

tuple<int, int, int> find_3sum(const vector<int>& v)
/**
 * @param v - input vector of integer values
 * @return - a tuple of three indices i1, i2, i3 such that v[i1]+v[i2]+v[i3] = 0
 *
*/
{
    tuple<int, int, int> res = {-1,-1,-1};
    unordered_map<int,int> umap;
    auto n = v.size();
    if(n<3)
        return res;
    for(int i =0; i < n; i++)
    {
        umap[v[i]] = i;
    }
    for(int i=0; i<n; i++)
    {
	auto target_val = -v[i];
	pair<int,int> p = find_two_sum(v, umap, i, target_val);
        if(p.first >= 0 && p.first != i && p.second != i)
	{
	   get<0>(res)=i;
	   get<1>(res)=p.first;
	   get<2>(res)=p.second;
	   return res;
	}
    }
    return res;   	
}

int main(int argc, char** argv)
{
    vector<int> a{-1,0,1,2,-1,-4};
    tuple<int,int,int> t = find_3sum(a);
    if(get<0>(t) <0)
       cout << "No two elements add up to target value\n";
    else
    {
       cout << "Indices:";
       cout << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << endl;
       cout << "Elements:";
       cout << a[get<0>(t)] << "," << a[get<1>(t)] << "," << a[get<2>(t)] << endl; 
    }
}
