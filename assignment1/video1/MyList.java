class MyList {
    class Node {
        int value;
        Node next;
    }

    Node head;

    void add(int newvalue){
        Node newnode = new Node();
        newnode.value = newvalue;
        newnode.next = head;
        head = newnode;
    }

    public String toString(){
        Node tmp = head;
        String result = "[";
        while(tmp != null){
            result = result + Integer.toString(tmp.value) + " - ";
            tmp = tmp.next;
        }
        result = result + "]";
        return result;
    }
}