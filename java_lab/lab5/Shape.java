
public class Shape
{
    private String color = "red";
    private boolean filled = true;
    Shape()
    {
        this.color ="red";
        this.filled = filled;
    }
    Shape(String color,boolean filled)
    {
        this.color =color;
        this.filled =filled;
    }

    String getColor()
    {
        return this.color;
    }
    void setColor(String color)
    {
        this.color = color;
    }

    boolean IsFilled()
    {
        return this.filled;
    }

    void setFilled(boolean filled)
    {
        this.filled = filled;
    }

    public String toString()
    {
        return " a shape with color = " + this.color + ", fill status = " + this.filled;
    }
}

class Circle extends Shape{
    private double radius;

    Circle()
    {
        super();
        this.radius = 1.0;
    }
    Circle(double radius)
    {
        super();
        this.radius = radius;
    }
    Circle(double radius,String color,boolean filled)
    {
        super(color,filled);
        this.radius = radius;
        
    }

    double getRadius()
    {
        return this.radius;
    }

    void setRadius(double radius)
    {
        this.radius = radius;
    }

    double getArea()
    {
        return 3.14*radius*radius;
    }

    double getParameter()
    {
        return 2*3.14*radius;
    }

    @Override
    public String toString()
    {
        return " A Circle with radius = " + this.radius + " which is subclass of "+ super.toString();
    }
}

class Rectangle extends Shape{
    private double width;
    private double length;
    Rectangle()
    {
        this.width = 1.0;
        this.length = 1.0;
    }
    Rectangle(double width,double length)
    {
        this.width = width;
        this.length = length;
    }
    Rectangle(double width,double length,String color,boolean filled)
    {
        super(color,filled);
        this.width = width;
        this.length = length;
        
    }

    double getWidth()
    {
        return this.width;
    }

    void setWidth(double width)
    {
        this.width = width;
    }

    double getLength()
    {
        return this.length;
    }

    void setLength(double length)
    {
        this.length = length;
    }


    double getArea()
    {
        return this.length * this.width;
    }

    double getParameter()
    {
        return (2*this.length) + (2* this.width);
    }
    @Override
    public String toString()
    {
        return " A Rectange with width = " + this.width + " and length = "+ this.length + " which is subclass of "+ super.toString();
    }
}

class Square extends Rectangle
{
    Square()
    {
        super();
    }
    Square(double side)
    {
        super(side,side);
    }
    Square(double side,String color,boolean filled)
    {
        super(side,side,color,filled);
    }
    double getSide()
    {
        return super.getLength();
    }

    void setSide(double length)
    {
        super.setLength(length);
        super.setWidth(length);
    }
    
    @Override
    void setWidth(double width)
    {
        setSide(width);
    }
    
    @Override
    void setLength(double width)
    {
        setSide(width);
    }
    @Override
    public String toString()
    {
        return " A Square with side = " + super.getLength() + "which is subclass of "+ super.toString();
    }

}