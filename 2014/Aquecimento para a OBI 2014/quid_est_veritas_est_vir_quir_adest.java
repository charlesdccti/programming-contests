import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        BigInteger A, d, m;
        int len, i, j;
        String str;
        int[] ascii = new int[26];
        
        m = new BigInteger("1000000007");
        
        while(sc.hasNext()){
            str = sc.next();
            len = str.length();
            
            A = BigInteger.ONE;
            for(i=len; i>1; i--){
                A = A.multiply(BigInteger.valueOf(i));
            }
            
            for(i=0; i<26; i++)
                ascii[i] = 0;
            
            for(i=0; i<len; i++){
                ascii[(int)str.charAt(i)-(int)'A']++;
            }
            
            for(i=0; i<26; i++){
                if(ascii[i] > 1){
                    d = BigInteger.ONE;
                    for(j=ascii[i]; j>1; j--){
                        d = d.multiply(BigInteger.valueOf(j));
                    }
                    
                    A = A.divide(d);
                }
            }
            
            System.out.println(A.mod(m));
        }
    }
}