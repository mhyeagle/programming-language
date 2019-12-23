

public class GenericMethodTest {
	public static <E> void printArray(E[] array) {
		for (E element : array)
			System.out.printf("%s", element);
		System.out.println();
	}

	public static void main(String args[]) {
		Integer[] intArray = {1, 2, 3, 4, 5};
		Double[] doubleArray = {1.1, 2.2, 3.3};
		Character[] charArray = {'a', 'b', 'c'};

		printArray(intArray);
		printArray(doubleArray);
		printArray(charArray);
	}
}
