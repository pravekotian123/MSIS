import java.util.Scanner;
class Stack
{
    int array_of_elements[];
    int top_index;
    int stack_size;
    Stack(int maximum_elements)
    {
        this.stack_size = maximum_elements;
        this.array_of_elements = new int[maximum_elements];
        this.top_index = -1;
    }
    boolean PushData(int data)
    {
        boolean return_value = false;
        if(this.top_index < (this.stack_size-1))
        {
            this.array_of_elements[++top_index] = data;
            return_value = true;
        }
        return return_value;
    }

    boolean IsStackEmpty()
    {
        boolean return_value = false;
        if(this.top_index == -1)
        {
            return_value = true;
        }
        return return_value;
    }

    int GetTopElement()
    {
        int return_value = 0;
        if(this.top_index != -1)
        {
            return_value = this.array_of_elements[top_index];
        }
        return return_value;
    }

    boolean PopData()
    {
        boolean return_value = false;
        if(this.top_index != -1)
        {
            this.top_index--;
            return_value = true;
        }
        return return_value;
    }
    boolean DisplayData()
    {
        boolean return_value = false;
        if(this.top_index != -1)
        {
            for(int i=0;i<=this.top_index;i++)
            {
                System.out.print(this.array_of_elements[i]+ " ");
            }
            System.out.println(" ");
            return_value = true;
        }
        return return_value;
    }
}

public class Lab3Ex3
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int max_size = 10;
        Stack new_stack  = null;
        boolean stack_created = false;
        do{
        System.out.println("1.Create New stack 2.Push  3. Pop 4.Display 5. Empty");
        int entered_option = sc.nextInt();
        
        
        switch(entered_option)
        {
            case 1:
            {
                if(stack_created == false)
                {
                    new_stack = new Stack(max_size);
                    System.out.println("New stack creation successful");
                    stack_created = true;
                }
                else
                {
                    System.out.println("Stack already exists");
                }
            }
            break;
            case 2:
            {
                if(new_stack != null)
                {
                    System.out.println("Entered Integer Data to be pushed");
                    int data_val = sc.nextInt();
                    if(new_stack.PushData(data_val) == false)
                    {
                        System.out.println("Stack already filled for max limit");
                    }
                }
                else{
                     System.out.println("Stack not created");
                }

            }
            break;
            case 3:
            {
                if(new_stack != null)
                {
                    if(new_stack.IsStackEmpty() == false)
                    {
                        new_stack.PopData();
                    }
                    else{
                        System.out.println("Stack is empty");
                    }
                }
                else{
                     System.out.println("Stack not created");
                }
            }
                break;
            case 4:
            {
                if(new_stack != null)
                {
                    if(new_stack.DisplayData() == false)
                    {
                        System.out.println("No data found");
                    }
                }
                else{
                     System.out.println("Stack not created");
                }
            }
                break;
            case 5:
            {
                if(new_stack != null)
                {
                    while(new_stack.IsStackEmpty() == false)
                    {
                        new_stack.PopData();
                    }
                }
                else{
                     System.out.println("Stack not created");
                }
            }
                break;
            default:
            System.out.println("Invalid entry");
            break;
                        
        }
        System.out.println();
        }while(true);
    }
}