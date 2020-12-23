class Solution {
public:
    vector<int> arr;
    int findParent(int x)
    {
        if(arr[x] < 0)
            return x;
        else
        {
            int y= x;
            while(arr[x] > 0)
                x=arr[x];
            arr[y] = x;
        }
        return x;
    }
    void Union(int p1 , int p2)
    {
        if(arr[p1] <= arr[p2])
        {
            arr[p2] = p1;
            arr[p1] = arr[p1] -2;
        }
        else
        {
            arr[p1] = p2;
            arr[p2] = arr[p2] -2;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        arr.resize(edges.size()+1,-1);
        arr[0] = 0;
        vector<int> res(2);
        for (int i=0; i<edges.size(); i++)
        {
            for(int j=0; j<1;j++)
            {
                int p1 = findParent(edges[i][j]);
                int p2 = findParent(edges[i][j+1]);
                if(p1 == p2)
                {
                    res[0]= edges[i][j];
                    res[1] = edges[i][j+1];
                }
                else
                    Union(p1,p2);
            }
        }
        return res;
    }
};
