import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {


    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String splitted[] = bf.readLine().split(" ");

            int n = Integer.parseInt(splitted[0]);
            int m = Integer.parseInt(splitted[1]);
            int k = Integer.parseInt(splitted[2]);

            int intern=0;
            int team = Math.min(n/2, m);

            intern+=(n+m)-team*3;
            while(intern<k){
                intern+=3;
                team--;
            }
            System.out.println(team);

        }catch(IOException e){
            System.out.println(e.toString());
        }
    }
}