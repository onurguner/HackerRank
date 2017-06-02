using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        int N = Convert.ToInt32(Console.ReadLine());        
        List<string> table = new List<string>();
        for (int i=0; i<N; i++)
            table.Add(Console.ReadLine()); 
        int q = Convert.ToInt32(Console.ReadLine());
        for (int j=0; j<q; j++) {
            string str = Console.ReadLine();
            int c = table.FindAll(s => s == str).Count;
            Console.WriteLine(c);
        }
    }
}