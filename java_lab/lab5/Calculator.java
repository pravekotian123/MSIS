public interface Calculator
{
    Calculator put(int n);
    int read();
    Calculator neg();
    Calculator add();
    Calculator sub();
    Calculator mul();
    Calculator div();
    Calculator clear();
    Calculator clearAll();
}

 class BasicCalculator implements Calculator
{
    private int elements[];
    private int index;
    private BasicCalculator()
    {
        elements = new int[2];
        elements[0] = 0;
        elements[1] = 0;
        index = 0;
    }
    public Calculator put(int n)
    {
       elements[index] = n;
       index = (index + 1)%2;
       return this;
    }
    public int read()
    {
        return elements[0];
    }
    public Calculator neg()
    {
        elements[0] = -elements[0];
        return this;
    }
    public Calculator add()
    {
        elements[0] = elements[0] + elements[1] ;
        return this;
    }
    public Calculator sub()
    {
        elements[0] = elements[0] - elements[1] ;
        return this;  
    }
    public Calculator mul()
    {
        elements[0] = elements[0] * elements[1] ;
        return this; 
    }
    public Calculator div()
    {
        if(elements[1] > 0)
        {
             elements[0] = elements[0] / elements[1] ;
        }
        return this; 
    }
    public Calculator clear()
    {
        elements[this.index] = 0;
        if(this.index == 1)
            this.index--;
        return this;
    }
    public Calculator clearAll()
    {
        this.elements[0] = 0;
        this.elements[1] = 0;
        this.index = 0;
        return this;
    }

    public static BasicCalculator initialiseCalci()
    {
        BasicCalculator calci = new BasicCalculator();
        return calci;
    }
}