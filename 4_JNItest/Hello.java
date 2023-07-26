public class Hello{

    static {
        System.loadLibrary("Hello");
    }

    public native void sayHello();

    public static void main(String[] args){
        new Hello().sayHello();
        
    }

}