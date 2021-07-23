import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

class Solution {
    public int solution(int N, int number) {
			HashSet<Integer> set = new HashSet<>();
			HashMap<Integer,LinkedList<Integer>> numb = new HashMap<Integer,LinkedList<Integer>>();
			
			int count=0;
			boolean found=false;
			int times=0;
			LinkedList<Integer> a;
			LinkedList<Integer> b;
			Iterator<Integer> aiter;
			Iterator<Integer> biter;
			//Iterator<Integer> iter;
			int anumb;
			int bnumb;
			int imt;
			
 			while(!found) {
				count++;
				times=times*10+1;
				//numb.containsKey(count);
				LinkedList<Integer> nlist = new LinkedList<Integer>();
				nlist.add(times*N);
				set.add(times*N);
				for(int i=count-1;(2*i)>=count;i--) {
					a = numb.get(i);
					b = numb.get(count-i);
					aiter = a.iterator();
					while(aiter.hasNext()) {
						anumb=aiter.next();
						biter = b.iterator();
						while(biter.hasNext()){
							bnumb=biter.next();
							if(!set.contains(anumb+bnumb)) {
								nlist.add(anumb+bnumb);
								set.add(anumb+bnumb);
							}
							if(!set.contains(anumb*bnumb)) {
								nlist.add(anumb*bnumb);
								set.add(anumb*bnumb);
							}
							if(anumb<bnumb) {
								imt=anumb;
								anumb=bnumb;
								bnumb=imt;
							}
							if(!set.contains(anumb-bnumb)&&(anumb!=bnumb)) {
								nlist.add(anumb-bnumb);
								set.add(anumb-bnumb);
							}
							if(!set.contains(anumb/bnumb)) {
								nlist.add(anumb/bnumb);
								set.add(anumb/bnumb);
							}
						}
					}
				}
				numb.put(count, nlist);
				if(set.contains(number)) {
					found=true;
					break; 
				}
				if(count>=8)break;
			}
 			if(!found)count=-1;
			return count;
    }
}
