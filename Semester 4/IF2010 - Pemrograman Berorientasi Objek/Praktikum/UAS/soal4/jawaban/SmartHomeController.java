import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.InvocationTargetException;
import java.lang.Class;
import java.util.List;
import java.util.ArrayList;

public class SmartHomeController {
    private SmartHomeController(){}

    public static void printStatus(Object device){
        Class<?> clazz = device.getClass();
        for(Field field : clazz.getDeclaredFields()){
            field.setAccessible(true);
            try{
                Object val = field.get(device);
                System.out.println(field.getName() + " = " + String.valueOf(val));
            } catch (IllegalAccessException | IllegalArgumentException | NullPointerException | ExceptionInInitializerError e){
                System.out.println("FIELD_ACCESS_ERROR");
            }
        }
    }

    public static void printCommands(Object device){
        Class<?> clazz = device.getClass();
        List<String> meths = new ArrayList<String>();
        for(Method meth : clazz.getDeclaredMethods()){
            meth.setAccessible(true);
            meths.add(meth.getName());
        }
        meths.stream().sorted((a, b) -> { return a.compareTo(b); }).forEach(a -> System.out.println(a));
    }

    public static void execute(Object device, String command){
        Class<?> clazz = device.getClass();
        for(Method meth : clazz.getDeclaredMethods()){
            meth.setAccessible(true);
            if(meth.getName().equals(command)){
                try {
                    meth.invoke(device);
                    return;
                } catch (IllegalAccessException | IllegalArgumentException | InvocationTargetException | NullPointerException | ExceptionInInitializerError e){
                    System.out.println("COMMAND_EXECUTION_ERROR");
                    return;
                }
            }
        }
        System.out.println("COMMAND_NOT_FOUND");
    }
}