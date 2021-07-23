import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {


    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());
            int numb=2; int k=1;

            //자리수
            /*
                if n<=numb -> k자리수
                n-numb k++ numb*=2

            */
            while(numb<n){
                n-=numb;
                k++;
                numb*=2;
            }

            String ans="";
            numb/=2;
            for(int i=0;i<k;i++){
                if(n<=numb){
                    ans+="4";
                }else {
                    ans+="7";
                    n-=numb;
                }
                numb/=2;
            }
            System.out.println(ans);

        }catch(IOException e){

        }
    }
}