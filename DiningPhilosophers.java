import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class DiningPhilosophers {
    private int numPhilosophers;
    private Lock[] forks;
    private Condition[] conditions;

    public DiningPhilosophers(int numPhilosophers) {
        this.numPhilosophers = numPhilosophers;
        this.forks = new Lock[numPhilosophers];
        this.conditions = new Condition[numPhilosophers];

        for (int i = 0; i < numPhilosophers; i++) {
            forks[i] = new ReentrantLock();
            conditions[i] = forks[i].newCondition();
        }
    }

    public void pickForks(int philosopherId) {
        int leftFork = philosopherId;
        int rightFork = (philosopherId + 1) % numPhilosophers;

        forks[leftFork].lock();
        forks[rightFork].lock();
    }

    public void releaseForks(int philosopherId) {
        int leftFork = philosopherId;
        int rightFork = (philosopherId + 1) % numPhilosophers;

        forks[leftFork].unlock();
        forks[rightFork].unlock();
    }

    public void dine(int philosopherId) {
        while (true) {
            System.out.println("Philosopher " + philosopherId + " is thinking.");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Philosopher " + philosopherId + " is hungry.");
            pickForks(philosopherId);

            System.out.println("Philosopher " + philosopherId + " is eating.");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            releaseForks(philosopherId);
        }
    }

    public static void main(String[] args) {
        int numPhilosophers = 5;
        DiningPhilosophers diningTable = new DiningPhilosophers(numPhilosophers);
        Thread[] philosophers = new Thread[numPhilosophers];

        for (int i = 0; i < numPhilosophers; i++) {
            final int philosopherId = i;
            philosophers[i] = new Thread(() -> diningTable.dine(philosopherId));
        }

        for (Thread philosopher : philosophers) {
            philosopher.start();
        }
    }
}
