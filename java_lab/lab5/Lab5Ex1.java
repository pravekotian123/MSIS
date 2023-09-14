public class Lab5Ex1
{
    
    public static void main(String [] args)
    {
        Circle circle = new Circle(3);
        System.out.println(circle);
        assert(circle.getRadius() == 3);
        Rectangle rectangle = new Rectangle(4,5);
        assert(rectangle.getArea() == 20);
        System.out.println(rectangle);
        Rectangle square = new Square(4);
        assert(square.getArea() == 16);
        System.out.println(square);
    }
}