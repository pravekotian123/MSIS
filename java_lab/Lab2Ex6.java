import java.util.Scanner;

public class Lab2Ex6{
    public static void main(String[] args)
    {
        System.out.println("Hey ..Can you answer the riddle below");
        System.out.println("What is seen in the middle of March and April that can’t be seen at the beginning or end of either month");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        int retry_counter  = 0;
        while(retry_counter < 3)
        {
            if(input.equals("R") || input.equals("r"))
            {
                System.out.println("Good ..You're smart");
                break;
            }
            else{
                System.out.println("I'm afraid.. you're wrong");
                
                retry_counter++;
                if(retry_counter == 3)
                {
                    System.out.println("Better luck next time");
                }
                else
                {
                    System.out.println("Give one more try");
                    input = scanner.next();
                }
            }
        }
        

    }
}