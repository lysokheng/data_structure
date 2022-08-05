//Define a data item having some data, and key based on which search is to be conducted in hashtable.
public class DataItem {
   private int key;
   private int data;

   public DataItem(int key, int data) {
      this.key = key;
      this.data = data;
   }

   public int getKey() {
      return key;
   }

   public int getData() {
      return data;
   }
}