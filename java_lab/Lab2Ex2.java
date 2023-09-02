import java.util.Scanner;
public class Lab2Ex2
{
	static int number_of_years = 0;
	static int number_of_days = 0;
	public static void main(String[] args)
	{
		char response_value;
		do
		{
			System.out.println("Enter minute to be converted to year");
			Scanner sc = new Scanner(System.in);
			long minute=sc.nextLong();

            CalculateYearsAndDays(minute);
			System.out.println("Number_of_years "+ number_of_years );
			System.out.println("Number_of_days "+ number_of_days );
			System.out.println("Would like like to continue");
			System.out.println("Press y to yes");
			Scanner response = new Scanner(System.in);
			response_value = response.next().charAt(0);
			}while(response_value == 'y');
	}

	static void CalculateYearsAndDays(long minute)
	{
		number_of_days =(int) minute/(60 * 24);
		number_of_years =(int) number_of_days/365;
	}
}