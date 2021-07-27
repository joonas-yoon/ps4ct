import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {


    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());

            String str = bf.readLine();
            String prefix,postfix,inside;

            if(n<=25){
                System.out.println(str);
            }else{
                prefix=str.substring(0,11);
                postfix=str.substring(n-11,n);
                inside=str.substring(11,n-11);
                int idx=inside.indexOf('.');
                if(idx!=-1&&idx!=(inside.length()-1)){
                    prefix=prefix.substring(0,9);
                    postfix=postfix.substring(1);
                    inside="......";
                }else{
                    inside="...";
                }
                System.out.println(prefix+inside+postfix);
            }



        }catch(IOException e){

        }
    }
}