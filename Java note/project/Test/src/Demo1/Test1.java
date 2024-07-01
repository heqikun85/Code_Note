package Demo1;

public class Test1 {
    public static void main(String[] args) {
        Animal a = new Dog();
        System.out.println(a.name);
    }
}

class Animal{
    String name = "Animal";
    public void show(){
        System.out.println("Animal --- show method");
    }
}

class Dog extends Animal{
    String name = "Dog";
    @Override
    public void show(){
        System.out.println("Dog --- show method");
    }
}

class Cat extends Animal{
    String name = "Cat";
    @Override
    public void show(){
        System.out.println("Cat --- show method");
    }
}
