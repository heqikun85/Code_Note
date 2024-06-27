package StudentSystem;

import java.util.ArrayList;
import java.util.Scanner;

public class App2 {
    public static void main(String[] args) {
        System.out.println("Welcom to the student management system");

        loop: while(true){
            System.out.println("Please select the option: 1. login  2. Sign in  3. Forgot password");
            ArrayList<User> list = new ArrayList<>();
            
            Scanner sc = new Scanner(System.in);
            int op = sc.nextInt();
            switch(op){
                case 1 -> login(list);

                case 2 -> register(list);
                case 3 -> forgotPass(list);
                case 4 -> {
                    System.out.println("Exit");
                    System.exit(0);
                }
                default -> System.out.println("Wrong Input");
            }
        }
    }

    public static void login(ArrayList<User> list){
        System.out.println("login");
    }

    public static void register(ArrayList<User> list){
        Scanner sc = new Scanner(System.in);
        User u = new User();
        while(true){
            System.out.println("Please enter user name"); 
            String name = sc.next(); 
            boolean flag1 = checkUser(name);
            boolean flag2 = varifyUser(list, name);
            if(!flag1){
                System.out.println("this user name isn't allowed");
            }else if(flag2){
                System.out.println("this user name already exist");
            }else{
                u.setName(name);
                System.out.println("user name set");
                break;
            }
        }
        
        System.out.println("Please enter Password");
        String pass = sc.next();
        while(true){
            System.out.println("Please enter Password again");
            String pass2 = sc.next();
            if(pass.equals(pass2)){
                u.setPass(pass);
                System.out.println("Password is set");
                break;
            }else{
                System.out.println("two time password doesn't same");
            }
        }

        while(true){
            System.out.println("Please enter ID number");
            String id = sc.next();
            boolean flag = checkId(id);
            if(flag){
                System.out.println("this id is wrong");
            }else{
                u.setPerson(id);
                System.out.println("id set successful");
                break;
            }
        }

    }

    public static void forgotPass(ArrayList<User> list){
        System.out.println("forgot password");
    }

    public static boolean checkUser(String user){
        int len = user.length();
        int count = 0;

        if(len < 3 || len > 15){
            return false;
        }

        for(int i =0; i<user.length();i++){
            char c = user.charAt(i);
            if(!((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z')||(c >= '0' && c < '9'))){
                return false;
            }
            if(((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z'))){
                count++;
            }
            if(count == user.length()){
                return false;
            }
        }
        return count > 0;
    }
    
    public static boolean varifyUser(ArrayList<User> list, String user){
        for(int i=0; i<list.size(); i++){
            User u = list.get(i);
            String name = u.getName();
            if(user.equals(name)){
                return true;
            }
        }
        return false;
    }

    public static boolean checkId(String id){
        if(id.length() != 18){
            return false;
        }

        boolean f = id.startsWith("0");
        if(f){
            return false;
        }

        for(int i =0; i < id.length() - 1; i++){
            char c = id.charAt(i); 
            if(!(c >= '0' && c <= '9')){
                return false;
            }
        }
        char end = id.charAt(id.length()-1);
        if(!(end == 'x' || end == 'X' || (end >= '0' && end <= '9'))){
            return false;
        }
        return true;
    }

}
