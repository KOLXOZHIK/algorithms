//Problem source - https://leetcode.com/problems/two-sum/
//given array of integers, find indices of two elements of the array which add up to target value
//Author: KOLXOZHIK

#include <unordered_map>
#include <utility> //for pair and make_pair
#include <vector>
#include <iostream>

using namespace std;

pair<int,int> find_two_sum(const vector<int>& v, int target_val)
/**
 * @param v - input vector of integer values
 * @param target_val - input target value for the sum of two values
 * @return - a pair of indices in the input vector v which add up to the some
*/
{
    pair<int,int> res = make_pair(-1,-1);
    unordered_map<int,int> umap;
    auto n = v.size();
    for(int i =0; i < n; i++)
    {
        umap[v[i]] = i;
    }
    for(int i =0; i < n; i++)
    {
       if(umap.find(target_val-v[i]) != umap.end()) 
       {
	   res.first = i;
	   res.second = umap[target_val-v[i]];
	   break;
       } 
    }
    return res;
}

int main(int argc, char** argv)
{
    vector<int> a{2,7,11,15};
    int target = 9;
    pair<int,int> p = find_two_sum(a, target);
    if(p.first <0)
       cout << "No two elements add up to target value\n";
    else
    {
       cout << "Indices:";
       cout << p.first << "," << p.second << " Elements:" << a[p.first] << "," << a[p.second] << endl;
       cout << "Target value=" << target << endl;
    }
}
