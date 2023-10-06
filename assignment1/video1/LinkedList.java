import java.util.*;

// class ListTest {
//     public static void main(String[] args){
//         LinkedList<Integer> intList = new LinkedList<Integer>();

//         intList.add(45);
//         intList.add(6);
//         intList.add(22);
//         System.out.println(intList);

//     }
// }

class ListTest {
    public static void main(String[] args){
        LinkedList<Integer> intList = new LinkedList<Integer>();
        MyList myList = new MyList();

        intList.add(45);
        intList.add(6);
        intList.add(13);

        myList.add(45);
        myList.add(6);
        myList.add(13);

        System.out.println(intList);
        System.out.println(myList);

    }
}