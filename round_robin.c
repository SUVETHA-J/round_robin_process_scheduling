#include<stdio.h>
int main()
{   int n,ts;
    printf("NUMBER OF PROCESS:");
    scanf("%d",&n);
    printf("\nTime slice:");
    scanf("%d",&ts);
    int at[n],p[n],ct[n],bt[n],tat[n],wt[n];
    int s=0,end=0,i,j=0;
    for(i=0;i<n;i++)
    {   p[i]=-1;
        printf("process:%d\nArrival time:",i+1);
        scanf("%d",&at[i]);
        printf("\nBurst time:");
        scanf("%d",&bt[i]);}
int st[n];
    for(i=0;i<n;i++)
    {st[i]=bt[i];}
   while(s!=n)
    {
        if(p[j]==-1)
        {
            if(at[j]<=end)
            {   if(ts>bt[j])
                {
                    end=end+bt[j];
                    bt[j]=0;
                }
                else
                {end=end+ts;
                    bt[j]=bt[j]-ts;}
              if(bt[j]==0)
              {ct[j]=end;
                  p[j]=0;
                  s++;}}
            else
            {
                end=end+(at[j]-end);
               if(ts>bt[j])
                {
                    end=end+bt[j];
                    bt[j]=0;
                }
                else
                {
                    end=end+ts;
                    bt[j]=bt[j]-ts;
                }

              if(bt[j]==0)
              {   ct[j]=end;
                  p[j]=0;
                  s++;
              }
            }
        }
        j++;
              if(j==n)
              {
                  j=0;
              }


    }
    int tot1=0,tot2=0;
    float avg1,avg2;
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        tot1=tot1+tat[i];
        wt[i]=tat[i]-st[i];
        tot2=tot2+wt[i];
    }
    avg1=(float)tot1/n;
    avg2=(float)tot2/n;

    printf("process\t\tarrival time\t\t burst time\t\t CT\t\tTAT\t\tWT\n");
    for(i=0;i<n;i++)
{
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n",i+1,at[i],st[i],ct[i],tat[i],wt[i]);

}
printf("%f\n%f",avg1,avg2);
}

