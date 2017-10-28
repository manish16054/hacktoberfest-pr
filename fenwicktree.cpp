#include <bits/stdc++.h>

using namespace std;

int ft[int(1e5+5)];

int zeroes(int n)
{
	int count=0;
	while(n)
	{
		if(n%10==0)
			count++;
		n/=10;
	}
	return count;
}
int getsum(int index)
{
	int sum=0;
	index++;
	while(index)
	{
		sum += ft[index];
		index -= index & (-index);
	}
	return sum;
}
void update(int n, int index, int val)
{
	index++;
	while(index <= n)
	{
		ft[index] += val;
		index += index & (-index);	
	}
}
int build(int arr[], int n)
{
	// int ft[n+1];
	memset(ft, 0, sizeof ft);
	for(int i=0; i<n; i++)
		update(n, i, arr[i]);
	for(int i=1; i<=n; i++)
		cout<<ft[i]<<' ';
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; cin>>arr[i++]);
	// int isum[n];
	// for(int i=0; i<n; i++)
	// {
		// isum[i] = zeroes(arr[i]);
	// }
	// for(int i=0; i<n; i++)
		// cout<<isum[i]<<' ';
	// cout<<'\n';
	build(arr, n);
	cout<<'\n';
	// cout<<getsum(2);
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		--l; --r;
		int ans = getsum(r)-getsum(l);
		cout<<ans;
	}
	
	// int sum[1000001]={0};
	// sum[0] = isum[0];
	// for(int i=1; i<n; i++)
		// sum[i] = (isum[i]+sum[i-1]);
	// cout<<'\n';
	// for(int i=0; i<n; cout<<sum[i++]<<' ');
}