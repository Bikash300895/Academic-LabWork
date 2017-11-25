#include <iostream>

using namespace std;

int main()
{

    while(true)
    {
        int M[99][99], R[99]={0}, C[99]={0},n,i,j,I,J,counti,countj;
        cin>>n;
        if(n==0) break;
        for(i=0; i<n; i++)
        {
            R[i]=0;
            for(j=0; j<n; j++)
            {
                cin>>M[i][j];
                R[i]+=M[i][j];
                C[j]+=M[i][j];
            }
        }
        counti=countj=0;
        for(i=0; i<n; i++)
        {
            if(R[i]%2==1)
            {
                counti++;
                I=i;
            }
            if(C[i]%2==1)
            {
                countj++;
                J=i;
            }
            if((counti+countj)>2) break;
        }
        if(counti+countj==0) cout<<"OK"<<endl;
        else if(counti==1 && countj==1) cout<<"Change bit ("<<I+1<<","<<J+1<<")"<<endl;
        else if(counti+countj>0) cout<<"Corrupt"<<endl;
    }

    return 0;
}
