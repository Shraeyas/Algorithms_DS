    #include <bits/stdc++.h>

    
    using namespace std;
    #define MAX 1<<16
    #define MAX2 MAX<<2
     
    int A[MAX];
    struct node{
          int bestleftsum,bestrightsum,sum,bestsum;
          void merge(node &A, node &B){
                sum = A.sum + B.sum;
                bestleftsum = max(A.bestleftsum, A.sum + B.bestleftsum);
                bestrightsum = max(A.bestrightsum + B.sum, B.bestrightsum);
                bestsum = max(max(A.bestsum,B.bestsum),A.bestrightsum+B.bestleftsum);
          }
          void createLeaf(int val){
                sum=bestleftsum=bestrightsum=bestsum=val;
          }
    };
     
    node T[MAX2];
     
    void init(int index, int l,int r)
	{
          if(l==r)
		  {
                T[index].createLeaf(A[l]);
                return;
          }
          
		  else
		  {
                int m = l + (r-l)/2;
                init(2*index,l,m);
                init(2*index+1,m+1,r);
                T[index].merge(T[2*index],T[2*index+1]);
          }
    }
     
    void query(node& res, int l, int r, int u, int v, int index){
          if(u==l && v==r)
		  {
                res=T[index];
                return;
          }
          
          else
		  {
                int m = l + (r-l)/2;
                if(m>=v)
                      query(res,l,m,u,v,2*index);
                else if(m<u)
                      query(res,m+1,r,u,v,2*index+1);
                else{
                      node left,right;
                      query(left,l,m,u,m,2*index);
                      query(right,m+1,r,m+1,v,2*index+1);
                      res.merge(left,right);
                }
          }
    }
    
    
    
    int main() 
	{
          freopen("C:\\Users\\Shraeyas\\Documents\\pg\\pr_ag\\prag_gss1.txt", "r", stdin);
		  
		  ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          int n,t,x,y;
          cin>>n;
          for(int i=0;i<n;i++)
        	cin>>A[i];
          init(1,0,n-1);
          
          //for(int i=1;i<=4*n;i++)
          //cout<<T[i].bestleftsum<<" "<<T[i].bestrightsum<<" "<<T[i].bestsum<<" "<<T[i].sum<<endl;
          
          cin>>t;
          node ans;
          while(t--){
                cin>>x>>y;
                query(ans,0,n-1,x-1,y-1,1);
                cout<<ans.bestsum<<endl;
          }
    	//cout<<"Execution time : "<<tick();
    	//cout<<(1<<16);
          return 0;
    }
     
