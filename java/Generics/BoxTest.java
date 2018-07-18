
public class BoxTest<T> {
	private T t;

	public void set(T t) {
		this.t = t;
	}

	public T get() {
		return this.t;
	}

	public static void main(String[] args) {
		BoxTest<Integer> intBox = new BoxTest<Integer>();
		BoxTest<Double> doubleBox = new BoxTest<Double>();
		BoxTest<String> stringBox = new BoxTest<String>();

		intBox.set(10);
		doubleBox.set(10.11);
		stringBox.set("hello");

		System.out.println(intBox.get());
		System.out.println(doubleBox.get());
		System.out.println(stringBox.get());
	}
}
