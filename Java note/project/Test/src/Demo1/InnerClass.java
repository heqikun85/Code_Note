package Demo1;

public class InnerClass {
    public class Car{
        String carName;
        int carAge;

        Engine e = new Engine();

        public void show(){
            System.out.println(carName);
            System.out.println(e.engineName);
        }

        class Engine{
            String engineName;
            int engineAge;
        }

    }
}
