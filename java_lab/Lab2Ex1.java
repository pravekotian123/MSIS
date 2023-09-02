import java.util.Scanner;
import java.util.Arrays;

public class Lab2Ex1
{
	public static void main(String[] args)
	{
		System.out.println("Enter array size");
		Scanner element = new Scanner(System.in);
		int array_of_int[] = new int[element.nextInt()];
		Boolean duplicate_found = false;
		System.out.println("Enter space sperated array elements");
		for(int i=0;i<array_of_int.length;i++)
		{
			array_of_int[i] = element.nextInt();
		}
		Arrays.sort(array_of_int);
		System.out.println("Duplicate elements are");
        for(int i=0;i<(array_of_int.length-1);i++)
        {
        	for(int j=i+1;j<array_of_int.length;j++)
        	{

        		if(duplicate_found ==  true)
        		{
        			if(array_of_int[i] != array_of_int[j])
        			{
        				i = j;
        				break;
        			}
        		}
        		else
        		{
	        		if(array_of_int[i] == array_of_int[j])
	        		{
	        			System.out.println(array_of_int[i]);
	        			duplicate_found = true;
	        		}
        		}
        	}
        }     
	}
}