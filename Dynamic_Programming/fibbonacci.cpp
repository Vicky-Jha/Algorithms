//
//  main.cpp
//  fibbonacci
//
//  Created by Vicky_Jha on 09/04/20.
//  Copyright © 2020 test. All rights reserved.
//

#include <iostream>
using namespace std;
int fib[100];
int fibbo(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else if(fib[n] != 0)
        return fib[n];
    else
        return fib[n] = fibbo(n-1)+ fibbo(n-2);
}

int main(int argc, const char * argv[]) {
    

    int n;
    cin>>n;
    cout<<fibbo(n)<<endl;
    return 0;
}
