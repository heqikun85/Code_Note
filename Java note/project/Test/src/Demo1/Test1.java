package Demo1;

public class Test1 {
    public static void main(String[] args) {
        Person p = new Person("Uncle John", 60);
        Animal a = new Dog ("blue", 11);
        p.keepPet(a, "beef bone");
        p.keepPet(a,"sea base");
    }
}

class Animal{
    private String color;
    private int age;

    public Animal() {
    }

    public Animal(String color, int age) {
        this.color = color;
        this.age = age;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void eat(String something){
        System.out.println("animal is eating");

    }
}




class Person{
    private int age;
    private String name;

/*    public void keepPet(Dog dog, String something){
        System.out.println("年龄为"+age+"岁的"+name+"养了一只"+dog.getColor()+"颜色的"+dog.getAge()+"岁的狗");
        dog.eat(something);
    }
    public void keepPet(Cat cat, String something){
        System.out.println("年龄为"+age+"岁的"+name+"养了一只"+cat.getColor()+"颜色的"+cat.getAge()+"岁的猫");
        cat.eat(something);
    }*/

    public void keepPet(Animal a, String something){
        if(a instanceof Dog d){
            System.out.println("年龄为"+age+"岁的"+name+"养了一只"+d.getColor()+"颜色的"+d.getAge()+"岁的dog");
            d.eat(something);
        }else if(a instanceof Cat c){
            System.out.println("年龄为"+age+"岁的"+name+"养了一只"+c.getColor()+"颜色的"+c.getAge()+"岁的cat");
            c.eat(something);
        }else{
            System.out.println("not this kind animal");
        }
    }

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}

class Dog extends Animal{
    public Dog() {
    }

    public Dog(String color, int age) {
        super(color, age);
    }
    @Override
    public void eat(String something) {
        System.out.println(getAge() + "岁的"+ getColor() +"颜色的狗两只前腿死死的抱住"+something+"猛吃");
    }

    public void lookHome(){
        System.out.println("dog is looking home now");
    }

}

class Cat extends Animal {
    public Cat() {
    }

    public Cat(String color, int age) {
        super(color, age);
    }
    @Override
    public void eat(String something) {
        System.out.println(getAge()+"岁的"+getColor()+"颜色的猫眯着眼睛侧着头吃"+something);
    }
    public void catchMouse(){

    }


}
