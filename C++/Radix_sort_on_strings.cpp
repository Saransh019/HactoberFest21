// Exact problem Statement:

// Percy is a math nerd who loves to play around with numbers. One day he came across a problem that given an input
// array A[ ] of some finite size with elements A[i] ∈ [1, 10^6 ] , return the sorted version of the array. Being the nerd he
// was, he found the problem to be quite easy and boring. Upon thinking, he came up with a challenging tweak- what if
// the elements of the array A were not that small.
// He modified the range of elements to A[i]∈ [1, 10^1,000,000] & then attempted to solve the problem. He realised that he
// won’t be able to solve it alone by himself & asks for your help. Being his best friend you decided to code for him

#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long int ll;


string removeZero(string str)
{
    int i = 0;
    while (str[i] == '0')
    i++;
    str.erase(0, i);
    return str;
}

void countingSort(int arr[], int n,int x,string a[])
{
    string output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = a[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
         a[i] = output[i];
}


void radix(string a[],int d, int n, int l[]){
    int k=10;
    int c[k]={0};
    for(int x=d-1;x>=0;x--){
        for(int i=0;i<n;i++){
            c[i]=a[i][x]-'0';
        }
        countingSort(c,n,x,a);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<removeZero(a[i])<<endl;
    }
}

int main(){
    int n,k,i;
    cin>>n;
    string t;
    string arr[n];
    int l[n];
    int m=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
        int k = arr[i].length();
        l[i]=k;
        m=max(k,m);
    }


        for(i=0;i<n;i++)
    {
       t=arr[i];
       string r="";
       k=t.length();
       r.append(m-k,'0');
       t=r+t;
       arr[i]=t;
    }
    radix(arr,m,n,l);

    return 0;
}
