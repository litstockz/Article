//随机数生成库
// Copyright (c) 2018 by litstockz.
// All Rights Reserved.
// See More in (https://github.com/litstockz)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//随机化
void Randomize()
{
  srand((int)time(0));
}

//生成指定范围内的随机整数
int GenerateRandomNumber(int low, int high)
{
  double _d;
  if(low > high)
  {
    cout << "GenerateRandomNumber:Make sure low <= high." << '\n';
    exit(1);
  }
  _d=(double)rand()/((double)RAND_MAX+1.0);
  return(low+(int)(_d*(high-low +1)));
}

//生成指定范围内的随机实数
double GenerateRandomReal(double low,double high)
{
  double _d;
  if(low>high)
  {
    cout << "GenerateRandomReal:Make sure low <= high." << '\n';
    exit(2);
  }
  _d=(double)rand()/(double)RAND_MAX;
  return(low+_d*(high-low));
}

/**
 * for test
 * 单独测试库的所有函数
 * 联合测试
 */

int main()
{
  int i;
  Randomize();
  for(i=0;i<8;i++)
  {
    int t=GenerateRandomNumber(10,99);
    cout << t << ';';
  }
  cout<<endl;
  for(i=0;i<8;i++)
  {
    double d=GenerateRandomReal(10.0,99.0);
    cout << d << ';';
  }
  cout<<endl;
}
