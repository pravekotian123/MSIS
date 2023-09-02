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
    void PrintBookDetail(void)
    {
        System.out.println("Book name = "+this.author," Book title = "+this.title + " Book price = "+this.price + " Book publisher = "+this.publisher)
    }
    int DispatchBook(int copies)
    {
        int return_value = -1;
        if(this.copies >= copies)
        {
            this.copies -= copies;
            return_value = 0;
        }
        return return_value;
    }
}

Class Lab3Ex2
{

    public static void main(String [] args)
    {
        
    }
}