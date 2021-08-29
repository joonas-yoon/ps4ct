import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());
            StringBuilder sb = new StringBuilder();
            for(int i=0;i<n;i++)sb.append('a');
            System.out.println(sb.toString());
        }catch(IOException e){

        }
    }
}