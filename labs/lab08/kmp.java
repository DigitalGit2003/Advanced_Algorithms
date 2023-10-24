public class kmp {

    /**
     * @param patterno
     * @param m
     */
    public static void KMP_Matcher(String pattern, int m)
    {
        int k = 0;
        int pi[] = new int[m];
        pi[0] = 0;
        int count = 0;
        int count1 = 0;
        for(int q = 1; q<m ; q++)
        {
           
            count++;
            while(k>0 && pattern.charAt(k) != pattern.charAt(q))
            {
                k = pi[k-1];
                count++;
                count1++;
                
            }
            if(pattern.charAt(k) == pattern.charAt(q))
            {
                k++;
                
            }
            pi[q]=k;

            
        }
        System.out.print(count + " ");
        System.out.println(count1);
        for(int i = 0; i<m; i++)
        {
            System.out.print(pi[i] + " ");
        }


    }
    public static void main(String[] args) {
        String pattern = "aaaaa";
        int n = pattern.length();
        KMP_Matcher(pattern, n);

    }
    
};
