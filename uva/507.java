import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<>();
    while (scanner.hasNext()) {
      Integer current = scanner.nextInt();
      if (current == -999999) {
        BigInteger max = BigInteger.valueOf(current);
        BigInteger prod = BigInteger.valueOf(0);

        for (int i = 0; i < list.size(); i++) {
          prod = BigInteger.valueOf(1);
          for (int j = i; j < list.size(); j++) {
            prod = prod.multiply(BigInteger.valueOf(list.get(j)));
          }
          if (prod.compareTo(max) >= 1) {
            max = prod;
          }
        }
        System.out.println(max.toString());
        list.clear();
      } else {
        list.add(current);
      }
    }
  }
}
