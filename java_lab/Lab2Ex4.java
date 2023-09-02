import java.util.Random;
import java.util.Arrays;

public class Lab2Ex4
{
	public static void main(String[] args)
	{
        Random random  = new Random();
		int total_element = random.nextInt(20);
		int array_of_int[] = new int[total_element];
		System.out.println("Total elements is" + total_element);
		int average_value = 0;
		long sum = 0;
		System.out.println("Array elements are");
		for(int i=0;i<array_of_int.length;i++)
		{
			array_of_int[i] = random.nextInt(50);
			sum += array_of_int[i]; 
			System.out.print(array_of_int[i]+ " ");
		}
		System.out.println();
		average_value = (int)sum/array_of_int.length;
		Arrays.sort(array_of_int);
		for(int i=0;i<array_of_int.length;i++)
		{
			if(array_of_int[i] >average_value)
			{
				System.out.print(array_of_int[i]+ " ");
			}
		}
		System.out.println();
		
	}
}