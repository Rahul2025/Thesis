#include<stdio.h>
#include<math.h>
typedef struct point
{
    int x,y;
};
double diff(point pt1,point pt2)
{

    double diff=((pt2.x-pt1.x)*(pt2.x-pt1.x))+((pt2.y-pt1.y)*(pt2.y-pt1.y));
    return sqrt(diff);
}
int main()
{
    int test,ans;double diff1,diff2,diff3,range=0.0f;

    point chef,head,sous;
    scanf("%d",&test);
    while(test--)
    {
        ans=1;
        scanf("%lf",&range);
        scanf("%d %d",&chef.x,&chef.y);
        scanf("%d %d",&head.x,&head.y);
        scanf("%d %d",&sous.x,&sous.y);
        diff1=diff(head,chef);
        diff2=diff(sous,chef);
        diff3=diff(head,sous);
        //printf("\t%.5lf %.5lf\n",diff1,diff2);
        if((diff1>range&&diff2>range)||(diff1>range&&diff3>range)||(diff2>range&&diff3>range))
        ans=0;

        if(ans)
        printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
