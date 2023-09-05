
class Book 
{
    private String name;
    private Author author;
    private double price;
    private int quantity;

    Book(Author author,String name,double price,int quantity)
    {
        this.author = author;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }
    Book(Author author,String name,double price)
    {
        this.author = author;
        this.name = name;
        this.price = price;
        this.quantity = 0;
    }

    public String toString()
    {

        return "\nBook[Name=" + this.name + "," + author + "," + " price =" + this.price + ","+ " quantity = "+this.quantity + "]";
    }
    public String getName()
    {
        return this.name;
    }

    public Author getAuthor()
    {
        return this.author;
    }

    public double getPrice()
    {
        return this.price;
    }

    public void setPrice(double price)
    {
        this.price = price;
    }

    public int getQty()
    {
        return this.quantity;
    }

    public void setQty(int qty)
    {
        this.quantity = qty;
    }

}

public class Ex1
{
    public static void main(String [] args)
    {
        Author author =  new Author("Author1","author1@gmail.com",'M');
        Book book1 = new Book(author,"Biology",25.0);
        assert(book1.getName() == "Biology");
        assert(book1.getAuthor() == author);
        assert(book1.getPrice() == 25.0);
        book1.setPrice(100.0);
        assert(book1.getPrice() == 100.0);
        assert(book1.getQty() == 0);
        book1.setQty(3);
        assert(book1.getQty() == 3);
        System.out.println(book1);
        
    }
}