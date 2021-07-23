import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {


    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());
            String splitted[];
            int max[] = new int[5];
            int now[] = new int[5];

            int a,b;
           for(int i=0;i<n;i++){
               splitted=bf.readLine().split(" ");
               a=Integer.parseInt(splitted[0])-1;
               b=Integer.parseInt(splitted[1])-1;
               for(int j=0;j<5;j++){
                   if(j==a||j==b){
                       now[j]++;
                       if(max[j]<now[j])max[j]=now[j];
                   }else{
                       now[j]=0;
                   }
               }
           }

           int ans_max=0,ans_grade=0;

            for(int j=0;j<5;j++){
                if(max[j]>ans_max){
                    ans_max=max[j];
                    ans_grade=j;
                }
            }
            System.out.println(ans_max+" "+(ans_grade+1));
        }catch(IOException e){

        }
    }
}