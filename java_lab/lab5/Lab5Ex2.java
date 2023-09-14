public class Lab5Ex2
{
    static BasicCalculator calci = null;
    public static void initialize()
    {
        calci = BasicCalculator.initialiseCalci();
    }
    public static int addNumbers(int num1,int num2)
    {
        return calci.put(num1).put(num2).add().read();
    }
    public static int substractNumbers(int num1,int num2)
    {
        return calci.put(num1).put(num2).sub().read();
    }
    public static int mulNumbers(int num1,int num2)
    {
        return calci.put(num1).put(num2).mul().read();
    }
    public static int divNumbers(int num1,int num2)
    {
        return calci.put(num1).put(num2).div().read();
    }
    public static int negateNumber(int num1)
    {
        return calci.put(num1).neg().read();
    }
    public static void main(String [] args)
    {
        initialize();
        assert(addNumbers(1,2) == 3);
        assert(substractNumbers(9,8) == 1);
        assert(mulNumbers(1,-2) == -2);
        assert(divNumbers(10,2) == 5);
        assert(negateNumber(10) == -10);
    }
}