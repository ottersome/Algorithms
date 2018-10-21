#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1000001
using namespace std;
vectior<long long> isPrime(MAX,true);
vector<long long> prime;//we store all prime numbers from 1 to n ;
vector<long long> spf;
void manipulated_sieve(int n){
    isPrime[0] = isPrime[1] = false;//both 0 and 1 are KNOWN not to beprime
    for(long long int i =2; i<N;i++){
        if(isprime[i]){
            prime.push_back(i);
            SPF[i] = i;
        }
        for(long long int j=0; j < (int) prime.size() && i*prime[j] < N && prime[j] <= spf[i];j++){
            j < (int)prime.size() && 
        }
    }
}
int main(){

    int n;
    printf("Please input your n:");
    cin >>n;
    cout<<endl;


    return 0;
}
