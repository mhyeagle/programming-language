import java.util.concurrent.*;

public class FutureTest {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(5);
        Callable<String> call = new Callable<String>() {
            public String call() throws Exception {
                Thread.sleep(5000);
                return "call func exe end";
            }
        };

        Future<String> task = exec.submit(call);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("in main thread do thing cost 1000 ms");

        while(!task.isDone()) {
            try {
                Thread.sleep(1000);
                System.out.println("wait sub thread for 1000 ms");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        try {
            String str = task.get();
            System.out.println("sub thread return " + str);
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }

        exec.shutdown();
    }
}
