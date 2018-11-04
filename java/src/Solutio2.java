import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * Exercise 1-1
 */
public class Solutio2 {

	public static void main(String[] args) {
		int[] array1 = {1,2,3,4,4};
		int[] array2 = {3,1,4,1,5,9,2,6,5,3,5,8,9,3,9};
		int[] array3 = {1,1,1,1};
		showNonDuplicateArray(array1);
		showNonDuplicateArray(array2);
		showNonDuplicateArray(array3);
	}
	
	/*
	 * Remove duplicate elements in an array
	 * and print it in the standard output
	 * @param a the input array
	 */
	public static void showNonDuplicateArray(int[] a) {
		List<Integer>num=new ArrayList<>();
		for(int i=0;i<a.length;i++)
		{num.add(a[i]);}
		Set<Integer>num1=new HashSet<>();
		num1.addAll(num);
		System.out.println(num1);
		
		}

}
