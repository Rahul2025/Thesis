public class Main {
    public static void main(String[] args)throws java.lang.Exception
    {
        java.io.InputStreamReader inp =  new java.io.InputStreamReader (System.in) ;
        java.io.BufferedReader br =  new java.io.BufferedReader(inp) ;
        int t ; 
        int[] dict1 = new int[26] ;
        char c,d ;
        
        int[] dict2 = new int[26] ;
        t = Integer.parseInt(br.readLine()) ;
        int count = 0 ;
        String[] strings ;
        String s1,s2 ;
        boolean[] results =  new boolean[t] ;
        while(count<t)
        {
            strings = br.readLine().split(" ") ;
            s1=strings[0] ;
            s2=strings[1] ;
           if(s1.length() != s2.length())
           {
               results[count]=false ;
           }
           else
           { 
             
            for(int i=0 ; i<26;i++)
             {
               dict1[i]= 0 ;
               dict2[i]=0 ;
              }
            
            for(int i=0 ; i<s1.length();i++)
            {
                c  = s1.charAt(i) ;
                d = s2.charAt(i) ;
                dict1[(int)c-97] = dict1[(int)c-97]+1 ;
                dict2[(int)d-97] = dict2[(int)d-97]+1 ;
            }
            boolean flag = true ;
            for(int i=0;i<26;i++)
            {
                if(dict1[i]!=dict2[i])
                {
                    flag = false ;
                    break ; 
                }
            }
            results[count]=flag ;
           }
          count++ ;  
        }
       for(int i=0 ; i<t ; i++)
       {
           if(results[i]==true)
           {
               System.out.println("YES") ;
               
           }
           else {
               System.out.println("NO") ;
           }
       }
    }
}