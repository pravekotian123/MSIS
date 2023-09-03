import java.util.Scanner;

class Book
{
    String author;
    String title;
    double price;
    String publisher;
    int copies;
    Book(String author,String title,double price,String publisher,int copies)
    {
        this.author = author;
        this.title = title;
        this.price = price;
        this.publisher = publisher;
        this.copies = copies;
    }
    void PrintBookDetail()
    {
        System.out.println("Book name = "+this.author+" Book title = "+this.title + " Book price = "+this.price + " Book publisher = "+this.publisher);
    }
    boolean DispatchBook(int copies)
    {
        boolean return_value = false;
        if(this.copies >= copies)
        {
            this.copies -= copies;
            return_value = true;
        }
        return return_value;
    }
    boolean IsCopyAvailable(int required_copies)
    {
        boolean return_value  = false;
        if((this.copies >= required_copies) && (this.copies > 0))
        {
            return_value = true;
        }
        return return_value;
    }

    String GetBookTitle()
    {
        return this.title;
    }

    String GetBookAuthor()
    {
        return this.author;
    }

    double GetBookPrice()
    {
        return this.price;
    }
}

public class Lab3Ex2
{

    public static void main(String [] args)
    {
        Book book_array[] = new Book[5];
        book_array[0] = new Book("Author1","Physics",100,"Fincher",10);
        book_array[1] = new Book("Author2","Chemistry",500,"Floyd",1);
        book_array[2] = new Book("Author3","Maths",100,"Dark",3);
        book_array[3] = new Book("Author4","Biology",10000,"Aa",8);
        book_array[4] = new Book("Razavi","Analog",10000,"World",8);
        Scanner sc = new Scanner(System.in);
 
        
        do{
            System.out.println("Enter author name and title of book");
            String author = sc.next();
            String title = sc.next();
            for(int i=0;i <5;i++)
            {
                if(author.equals(book_array[i].GetBookAuthor()) && title.equals(book_array[i].GetBookTitle()))
                {
                    System.out.println("Book details found");
                    book_array[i].PrintBookDetail();
                    System.out.println("Enter number of copies");
                    int copies = sc.nextInt();
                    if(book_array[i].IsCopyAvailable(copies) == true)
                    {
                        System.out.println("Total cost = "+(book_array[i].GetBookPrice() * (double)copies));
                        System.out.println("Enter y to confirm booking");
                        String confirm_msg = sc.next();
                        if(confirm_msg.equals("y") || confirm_msg.equals("Y"))
                        {
                            book_array[i].DispatchBook(copies);
                            System.out.println("Booking successful");

                        }
                    }
                    else{
                        System.out.println("Required copies not in stock");
                    }
                }
            }
            System.out.println(" ");
        }while(true);
        
    }
}