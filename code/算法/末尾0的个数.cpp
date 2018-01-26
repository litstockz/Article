// Copyright (c) 2018 by litstockz.
// All Rights Reserved.
// See More in (https://github.com/litstockz)


/**
 * 输入一个正整数n,求n!(即阶乘)末尾有多少个0？
 * 输入描述:输入为一行，n(1 ≤ n ≤ 1000)
 * 输出描述:输出一个整数,即题目所求
 */

//问题可简化为小于等于n的数中有多少个数是5的倍数
 #include <iostream>
 using namespace std;
 int main()
 {
     int n,cnt=0;
     cin>>n;
     while(n/=5)
     {
         cnt+=n;
     }
     cout<<cnt<<endl;
     return 0;
 }
