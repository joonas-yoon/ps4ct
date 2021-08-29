import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());
            int numb[] = new int[500000];
            String splitted[] = bf.readLine().split(" ");
            int target;
            int max=0;
            for(String s : splitted) {
            	target=Integer.parseInt(s);
            	numb[target]++;
            	if(numb[target]>max)max=numb[target];
            }
            System.out.println(max);
        }catch(IOException e){

        }
    }
}