 class Main {

    public static void main(String[] args) throws Exception {

       java.io.BufferedReader br = new java.io.BufferedReader(new 
           java.io.InputStreamReader(System.in));

   int t= Integer.parseInt(br.readLine());
    int m,n,j,count;
    long fact;
    while(t!=0)
    {
        String str[] = br.readLine().split(" ");
         m = Integer.parseInt(str[0])-1;
         n = Integer.parseInt(str[1])-1;
   
         fact=1;
         if(n>m/2)
             n= m-n;
         for(j=0;j<n;j++)
         {
             fact*= (m-j);
             fact/= (j+1);
         }
         System.out.println(fact);
          t--;
    }
    
    }
}