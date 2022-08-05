public class HashTable {

   private DataItem[] hashArray;
   private int size;
   private DataItem dummyItem;

   public HashTable(int size) {
      this.size = size;
      hashArray = new DataItem[size];
      dummyItem = new DataItem(-1, -1);
   }

   public void display() {
      for (int i = 0; i < size; i++) {
         if (hashArray[i] != null)
            System.out.print(" ("
                  + hashArray[i].getKey() + ","
                  + hashArray[i].getData() + ") ");
         else
            System.out.print(" ~~ ");
      }
      System.out.println("");
   }

   // Define a hashing method to compute the hash code of the key of the data item.
   public int hashCode(int key) {
      return key % size;
   }

   // Whenever an element is to be searched. Compute the hash code of the key
   // passed and locate the element using that hashcode as index in the array. Use
   // linear probing to get element ahead if element not found at computed hash
   // code.
   public DataItem search(int key) {
      // get the hash
      int hashIndex = hashCode(key);
      // move in array until an empty
      while (hashArray[hashIndex] != null) {
         if (hashArray[hashIndex].getKey() == key)
            return hashArray[hashIndex];
         // go to next cell
         ++hashIndex;
         // wrap around the table
         hashIndex %= size;
      }
      return null;
   }

   // Whenever an element is to be inserted. Compute the hash code of the key
   // passed and locate the index using that hashcode as index in the array. Use
   // linear probing for empty location if an element is found at computed hash
   // code.
   public void insert(DataItem item) {
      int key = item.getKey();

      // get the hash
      int hashIndex = hashCode(key);

      // move in array until an empty or deleted cell
      while (hashArray[hashIndex] != null
            && hashArray[hashIndex].getKey() != -1) {
         // go to next cell
         ++hashIndex;
         // wrap around the table
         hashIndex %= size;
      }

      hashArray[hashIndex] = item;
   }

   // Whenever an element is to be deleted. Compute the hash code of the key passed
   // and locate the index using that hashcode as index in the array. Use linear
   // probing to get element ahead if an element is not found at computed hash
   // code. When found, store a dummy item there to keep performance of hashtable
   // intact.
   public DataItem delete(DataItem item) {
      int key = item.getKey();

      // get the hash
      int hashIndex = hashCode(key);

      // move in array until an empty
      while (hashArray[hashIndex] != null) {
         if (hashArray[hashIndex].getKey() == key) {
            DataItem temp = hashArray[hashIndex];
            // assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
         }
         // go to next cell
         ++hashIndex;
         // wrap around the table
         hashIndex %= size;
      }
      return null;
   }
}