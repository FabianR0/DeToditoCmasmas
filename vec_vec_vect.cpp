#include<iostream>
#include<vector>
using namespace std;
int main()
{
  //Initializing a 3D vector(name = vector_3d )with dimensions (2, 3, 4) and initializing each element with 1
  vector<vector<vector<int>>> vector_3d(1, vector<vector<int>>(9, vector<int>(9, 1)));

  //Printing 3D vector
  for(int i=0;i<vector_3d.size();i++)
  {
    for(int j=0;j<vector_3d[i].size();j++)
    {
      for(int k=0;k<vector_3d[i][j].size();k++)
      {
        cout<<vector_3d[i][j][k]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}
