class Author
{
    private String name;
    private String email;
    private char gender;
    Author(String name,String email,char gender)
    {
        this.name = name;
        this.email = email;
        this.gender = gender;
    }
    @Override
    String toString()
    {
        return "\n Name=" + this.name + "\n Email=" + this.name + "\n Gender=" + this.gender;
    }

}