import java.util.Random;
import java.util.Scanner;

class Employee
{
    int empID;
    String empName;
    String empDestination;
    double empSalary;
    Employee()
    {

    }
    Employee(int id,String name,String destination,double salary)
    {
        this.empID = id;
        this.empName = name;
        this.empDestination = destination;
        this.empSalary = salary;
    }
    public void PrintEmployeeDetails(){
       System.out.println("Employee Name = "+this.empName);
       System.out.println("Employee Id = "+ this.empID);
       System.out.println("Employee Destination = "+this.empDestination);
       System.out.println("Employee Salary = "+this.empSalary);
    }

    public boolean IsEmploteeIdexist(int id)
    {
        if(id == this.empID)
        {
            return true;
        }
        return false;        
    }

    public boolean IsEmploteeNameexist(String name)
    {
        if(name == this.empName)
        {
            return true;
        }
        return false;        
    }

    public boolean SearchDestination(String destination)
    {
        if(destination == this.empDestination)
        {
            return true;
        }
        return false;        
    }

    public void incrementSalary(double hikePercentage)
    {
        this.empSalary += (hikePercentage * this.empSalary)/100;
    }

}


public class Lab3Ex1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of employees");
        int totalSize = sc.nextInt();
        Employee employee1[]= new Employee[totalSize];
        for(int i=0;i<employee1.length;i++)
        {
            Employee tempEmp = new Employee();
            System.out.println("Enter "+ (i+1) + "st Employee Name,Id,Destination,Salary");
            tempEmp.empName = sc.next();
            tempEmp.empID = sc.nextInt();
            tempEmp.empDestination = sc.next();
            tempEmp.empSalary = sc.nextDouble();
            employee1[i] = tempEmp;
        }
        boolean is_exit = false;
        /*test if id exists */
        do{
            System.out.println("Enter one of the option");
            System.out.println("1.Search Employee\n"+"2.Hike salary\n"+"3.Display\n"+"4.Exit");
            int option_entered = sc.nextInt();
            int value = 0;
            boolean search_fail = true;
            switch(option_entered)
            {
                case 1:
                {
                    value = sc.nextInt();
                    for(int i=0;i<employee1.length;i++)
                    {
                        if(employee1[i].IsEmploteeIdexist(value) == true)
                        {
                            System.out.println("Employee detail found");
                            employee1[i].PrintEmployeeDetails();
                            search_fail = false;
                            break;
                        }
                    }
                    if(search_fail == true)
                    {
                        System.out.println("Employee id is invalid");
                    }
                }
                break;
                case 2:
                {
                    System.out.println("Enter id of employee whose salary has to be increased");
                    value = sc.nextInt();
                    search_fail = true;
                    for(int i=0;i<employee1.length;i++)
                    {
                        if(employee1[i].IsEmploteeIdexist(value) == true)
                        {
                            System.out.println("Enter salary percentage");
                            value = sc.nextInt();
                            employee1[i].incrementSalary(value);
                            System.out.println("Updated salary is "+employee1[i].empSalary);
                            search_fail = false;
                            break;
                        }    
                    }
                    if(search_fail == true)
                    {
                        System.out.println("Employee id is invalid");
                    } 
                }
                break;
                case 3:
                System.out.println("Displaying employee deatils");
                for(int i=0;i<employee1.length;i++)
                {
                    employee1[i].PrintEmployeeDetails();
                    System.out.println();
                }
                break;
                case 4:
                is_exit = true;
                System.out.println("Executing exit..");
                System.exit(0);
                break;
                default:
                System.out.println("Invalid input");
                break;

            }
            System.out.println();
        }while(is_exit == false);
        
    }
}