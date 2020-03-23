package nikhil;

import java.util.Scanner;

public class pancakescan1 {
    static void flip(int arr[], int i) 
    { 
        int temp, start = 0; 
        while (start < i) { 
            temp = arr[start]; 
            arr[start] = arr[i]; 
            arr[i] = temp; 
            start++; 
            i--; 
        } 
    } 
  
    static int findMax(int arr[], int n) 
    { 
        int mi, i; 
        for (mi = 0, i = 0; i < n; i++) 
            if (arr[i] > arr[mi]) 
                mi = i; 
        return mi; 
    } 
  
    static int pancakeSort(int arr[], int n) 
    { 
    	Scanner sc=new Scanner(System.in);

           
        for (int curr_size = n; curr_size > 1; curr_size--) { 
            int mi = findMax(arr, curr_size); 
            
            if (mi != curr_size - 1) { 
               
                flip(arr, mi); 

  
                 
                flip(arr, curr_size - 1); 

                sc.close();
            } 
        } 
        return 0; 
    } 
  
    static void printArray(int arr[], int arr_size) 
    { 
        for (int i = 0; i < arr_size; i++) 
            System.out.print(arr[i] + " "); 
        System.out.println(""); 
    } 
  
    public static void main(String[] args) 
    { 
        int arr[];
    	Scanner sc=new Scanner(System.in);
    	System.out.println("Enter no of elements");
    	int n=sc.nextInt();
    	arr=new int[n];
    	System.out.println("Enter elements to perform pancake sorting");
    	for(int i=0;i<n;i++)
    	arr[i]=sc.nextInt();
    		pancakeSort(arr, n); 
        System.out.println("Sorted Array:  "); 
        printArray(arr, n);
    	        sc.close();
    } 

}
