import java.util.Random;
public class Lab2Ex5
{
    public static void main(String[] args)
    {
        Random random_number = new Random();
        int total_element = random_number.nextInt(10)+1;
        int array_of_elements[] = new int[total_element];
        for(int i=0;i<array_of_elements.length;i++)
        {
            array_of_elements[i] = random_number.nextInt(100)-50;
            System.out.print(array_of_elements[i]+ " ");
        }
        System.out.println();
        for(int i=0;i<array_of_elements.length;i++)
        {
            if(array_of_elements[i] < 0)
            {
               int temp = array_of_elements[i];
               for(int j=i;(j>0);j--)
               { 
                    array_of_elements[j] = array_of_elements[j-1];
               }
               array_of_elements[0] = temp;
            }
        }
        for(int i=0;i<array_of_elements.length;i++)
        {
            System.out.print(array_of_elements[i]+ " ");
        }
    }
}