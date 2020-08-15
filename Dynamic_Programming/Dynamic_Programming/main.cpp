//
//  main.cpp
//  Dynamic_Programming
//
//  Created by Vicky_Jha on 08/04/20.
//  Copyright © 2020 test. All rights reserved.
//

#include <iostream>
using namespace std;
int facto[100];
int fact(int n)
{
    memset(facto, 0, sizeof(facto));
    
    if(n == 1)
        return 1;
    else if(facto[n] != 0)
        return facto[n];
    else
        return facto[n] = n*fact(n-1);
}

int main(int argc, const char * argv[]) {

    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    
    return 0;
}


//INF 9 7 3 2 INF INF INF INF INF INF INF
//INF INF INF INF INF 4 2 1 INF INF INF INF
//INF INF INF INF INF 2 7 INF INF INF INF INF
//INF INF INF INF INF INF INF 11 INF INF INF INF
//INF INF INF INF INF INF 11 8 INF INF INF INF
//INF INF INF INF INF INF INF INF 6 5 INF INF
//INF INF INF INF INF INF INF INF 4 3 INF INF
//INF INF INF INF INF INF INF INF INF 5 6 INF
//INF INF INF INF INF INF INF INF INF INF INF 4
//INF INF INF INF INF INF INF INF INF INF INF 2
//INF INF INF INF INF INF INF INF INF INF INF 5
//INF INF INF INF INF INF INF INF INF INF INF INF
