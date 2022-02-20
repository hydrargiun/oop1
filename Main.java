import java.io.*;
import java.util.Arrays;
import java.util.Vector;

public class Main { // ооп в мейне лол, гнидятина, больше ооп
    public static int[] Mass;
    public static InputStream inputStream = System.in;
    public static Reader inputStreamReader = new InputStreamReader(inputStream);
    public static BufferedReader bufferedReader = new BufferedReader(inputStreamReader); //госпади ну хуйня

    public static void main(String[] args) throws IOException { // const override  protected long long int бляди на джаве
        //----------почему так все не приятно---------------------//
        System.out.println("Write your array блядь на джаве");
        String Ar = bufferedReader.readLine();
        String[] ArSplited = Ar.split(" ", 0);
        int[] Array = new int[ArSplited.length];
        for (int i = 0; i < ArSplited.length; i++) {
            Array[i] = Integer.parseInt(ArSplited[i]); // 14 строк на ввод масива, красиво
        }
        Main.Mass = Array;
        while (true) {
            String str = Arrays.toString(Mass);
            System.out.println("Current Array - " + str);
            System.out.println("Chose your func: ");
            System.out.println("0. exit");
            System.out.println("1. Удалить нули и после каждого числа, оканчивающего на 3, вставить 9.");
            System.out.println("2. Заменить элемент массива на сумму его соседей, если элемент массива четный и номер его лежит в промежутке от a до b. ");
            System.out.println("3. Удалить промежуток элементов от максимального до минимального");
            String ch = Main.bufferedReader.readLine();
            int choose = Integer.parseInt(ch);
            dialog(choose);
        }

    }

    public static void dialog(int choose) throws IOException {
        switch (choose) {
            case 0 -> System.exit(0);
            case 1 -> Mass = func1(Mass.length, Mass);
            case 2 -> {
                System.out.println("Enter begin");
                String paramOne = bufferedReader.readLine(); //читаем строку с клавиатуры
                int begin = Integer.parseInt(paramOne);
                System.out.println("Enter end");
                String paramTwo = bufferedReader.readLine(); //читаем строку с клавиатуры
                int end = Integer.parseInt(paramTwo);
                Mass = func2(Mass, begin, end);
            }
            case 3 -> Mass = func3(Mass);
        }
    }


    private static int[] func1(int size, int[] arr) {
        int helper = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 0) {
                helper++;
            }
        }
        int[] arrClear = new int[size - helper];
        int ptr = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0) {
                arrClear[ptr] = arr[i];
                ptr++;
            }
        }
        int helper2 = 0;
        for (int i = 0; i < size - helper; i++) {
            if (arrClear[i] % 10 == 3) {
                helper2++;
            }
        }
        int[] arrNine = new int[size - helper + helper2];
        int ptr2 = 0;
        for (int i = 0; i < size - helper; i++) {
            if (arrClear[i] % 10 == 3) {
                arrNine[ptr2] = arrClear[i];
                arrNine[ptr2 + 1] = 9;
                ptr2 = ptr2 + 2;
            } else {
                arrNine[ptr2] = arrClear[i];
                ptr2++;
            }
        }
        return arrNine;
    }

    public static int[] func2(int[] arr, int begin, int end) {
        if (begin >= 0 && end <= arr.length) {
            if (begin == 0) {
                begin++;
            }
            if (end == arr.length)
                end--;

            if (begin % 2 != 0) {
                begin++;
            }
            for (int i = begin; i < end; i = i + 2) {
                arr[i] = arr[i - 1] + arr[i + 1];
            }
        }
        return arr;
    }
    public static int[] func3(int[] arr){
        Pair min = new Pair(arr[0],0);
        Pair max = new Pair(arr[0],0);
        for (int i = 0; i < arr.length; i++){
            if (arr[i] > max.value){
                max.index = i;
                max.value = arr[i];
            }
            if (arr[i] < min.value){
                min.index = i;
                min.value = arr[i];
            }
        }
//        min.index = Math.min(min.index, max.index);
//        max.index = Math.max(min.index, max.index);

        int[] Deteted = new int[arr.length + 1 - (max.index - min.index)];
        if (min.index + 1 >= 0) System.arraycopy(arr, 0, Deteted, 0, min.index + 1);
        int ptr = min.index + 1;
        for (int i = max.index; i < arr.length; i++ ){
            Deteted[ptr] = arr[i];
            ptr++;
        }
        return Deteted;
    }
}
class Pair {
    int value;
    int index;

    public Pair(int val1, int val2) {
        this.index = val1;
        this.value = val2;
    }
}