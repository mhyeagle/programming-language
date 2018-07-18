import java.util.List;
import java.util.ArrayList;

public class WildCardTest {
    public static void main(String[] args) {
        List<Integer> intList = new ArrayList<Integer>();
        List<String> stringList = new ArrayList<String>();

        intList.add(1);
        intList.add(2);
        stringList.add("hello");
        stringList.add("world");

        printData(intList);
        //printData(stringList);
    }

    public static void printData(List<? extends Number> list) {
        for (Number element : list) {
            System.out.println(element);
        }
    }
}
