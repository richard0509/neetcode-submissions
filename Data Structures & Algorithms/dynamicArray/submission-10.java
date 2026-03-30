class DynamicArray {
    private int capacity;
    private int length;
    private int[] arr;

    public DynamicArray(int capacity) {
        arr = new int[capacity];
        length = 0;
        this.capacity = capacity;
    }

    public int get(int i) {
        return arr[i];
    }

    public void set(int i, int n) {
        arr[i] = n;
    }

    public void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        arr[length] = n;
        length++;
    }

    public int popback() {
        int num = arr[length - 1];
        length--;
        return num;
    }

    private void resize() {
        int[] newArray = new int[capacity * 2];
        for (int i = 0; i < length; i++) {
            newArray[i] = arr[i];
        }
        capacity *= 2;
        arr = newArray;
    }

    public int getSize() {
        return length;
    }

    public int getCapacity() {
        return capacity;
    }
}
