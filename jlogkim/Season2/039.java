import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void add(HashMap<Integer, Long> map, int key){
        if(map.containsKey(key)){
            map.put(key, map.get(key)+1);
        }else{
            map.put(key, 1L);
        }
    }

    public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(bf.readLine());

            HashMap<Integer, Long> a_sum = new HashMap<>();
            HashMap<Integer, Long> b_sum = new HashMap<>();

            int a_length = Integer.parseInt(bf.readLine());
            int a_arr[] = new int[a_length];
            String splitted[] = bf.readLine().split(" ");
            int a_subsum[] = new int[a_length];
            for(int i=0;i<a_length;i++){
                a_arr[i]=Integer.parseInt(splitted[i]);
                a_subsum[i]=a_arr[i];
                add(a_sum,a_subsum[i]);
            }

            int b_length = Integer.parseInt(bf.readLine());
            int b_arr[] = new int[b_length];
            splitted = bf.readLine().split(" ");
            int b_subsum[] = new int[b_length];

            for(int i=0;i<b_length;i++){
                b_arr[i]=Integer.parseInt(splitted[i]);
                b_subsum[i]=b_arr[i];
                add(b_sum,b_subsum[i]);
            }

            for(int l=2;l<=a_length;l++){
                for(int idx=(a_length-1);idx>=(l-1);idx--) {
                    a_subsum[idx]=a_subsum[idx-1]+a_arr[idx];
                    add(a_sum,a_subsum[idx]);
                }
            }
            for(int l=2;l<=b_length;l++){
                for(int idx=(b_length-1);idx>=(l-1);idx--) {
                    b_subsum[idx]=b_subsum[idx-1]+b_arr[idx];
                    add(b_sum,b_subsum[idx]);
                }
            }
            long ans=0;

            for(Integer key: a_sum.keySet()){
                if(b_sum.containsKey(n-key)){
                    ans+=(b_sum.get(n-key)*a_sum.get(key));
                }
            }
            System.out.println(ans);

        }catch(IOException e){

        }
    }
}