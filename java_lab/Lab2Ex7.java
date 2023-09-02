public class Lab2Ex7
{
    public static void main(String[] args)
    {
        int count = 1;
        for(int i=0;(count<92);i++)
        {
            for(int j=0;(j<=i)&&(count<92);j++)
            {
                System.out.print((count++)+" ");
            }
            System.out.println();
        }
        
        System.out.println();     
        count = 1;
        for(int i=0;(count<16);i++)
        {
            for(int j=0;(j<=i)&&(count<16);j++)
            {
                System.out.print(((i+j+1)%2)+" ");
                count++;
            }
            System.out.println();
        }
        System.out.println();
    }
}