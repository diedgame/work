import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * Exercise 1-1
 */
public class Solution1 {

	public static void main(String[] args) {
		int[] array1 = {1,2,3,4,5};
		int[] array2 = {3,1,4,1,5,9,2,6};
		
		showReversedArray(array1);
		showReversedArray(array2);
	}
	
	/*
	 * Reverse an array and print it in the standard output
	 * @param a the input array
	 */
	public static void showReversedArray(int[] a) {
		List<Integer>num=new ArrayList<>();
		for(int i=a.length-1;i>=0;i--)
		{num.add(a[i]);}
	System.out.println(num);
		
		
	
	
	
	
	
	}
}
