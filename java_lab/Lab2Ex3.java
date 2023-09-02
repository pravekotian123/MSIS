import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
public class Lab2Ex3
{
public static void main(String[] args) {
		Random random  = new Random();
		int total_element = random.nextInt(20);
		int array_of_int[] = new int[total_element];
		System.out.println("Total elements is" + total_element);
		int k_val = 0;
		System.out.println("Array elements are");
		for(int i=0;i<array_of_int.length;i++)
		{
			array_of_int[i] = random.nextInt(50);
			System.out.print(array_of_int[i]+ " ");
		}
		System.out.println();
		Arrays.sort(array_of_int);
		System.out.println("Sorted Array elements are");
		for(int i=0;i<array_of_int.length;i++)
		{
			System.out.print(array_of_int[i]+ " ");
		}
		System.out.println();
		k_val = random.nextInt(10);
		if(k_val > total_element)
		k_val = total_element;
		System.out.println(k_val+"th Largest Element is"+ KthLargestElement(array_of_int,k_val));
		System.out.println(k_val+"th Smallest Element is"+ KthSmallestElement(array_of_int,k_val));

}

static int KthLargestElement(int a[],int k_value)
{
    return a[a.length - k_value];         
}

static int KthSmallestElement(int a[],int k_value)
{
    return a[k_value -1] ;         
}

}