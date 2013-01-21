    #include <stdio.h>
    int soldiers;
    int moves[222222];
    void read_input(void){
    int i;
    scanf("%d",&soldiers);
    for(i=1;i<=soldiers;i++) scanf("%d",&moves[i]);
    }
    int norm;
    int remain[555555];
    void init_remain(void){
    int i;
    for(norm=1;norm<soldiers;norm*=2);
    for(i=0;i<soldiers;i++) remain[norm+i]=1;
    for(;i<norm;i++) remain[norm+i]=0;
    for(i=norm-1;i>0;i--) remain[i]=remain[2*i]+remain[2*i+1];
    }
    int extract_ith(int i){
    int root=1;
    while(root<norm){
    remain[root]--;
    if(i<=remain[2*root]) root=2*root;
    else{ i-=remain[2*root]; root=2*root+1;}
    }
    remain[root]=0;
    return root-norm+1;
    }
    int rank[222222];
    void find_ranks(void){
    int i;
    init_remain();
    for(i=soldiers;i>0;i--) rank[i]=extract_ith(i-moves[i]);
    }
    void print_ranks(void){
    int i;
    printf("%d",rank[1]);
    for(i=2;i<=soldiers;i++) printf(" %d",rank[i]);
    printf("\n");
    }
    int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
    read_input();
    find_ranks();
    print_ranks();
    }
    return 0;
    } 