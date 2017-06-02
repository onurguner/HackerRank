using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string time = Console.ReadLine();
        
        if (time.Contains("AM")) {
            time = time.Replace("AM", "");
            if (time.Substring(0, 2) == "12") {
                time = "00" + time.Substring(2);
            }
        }
        else if (time.Contains("PM")) {
            time = time.Replace("PM", "");
            if (time.Substring(0, 2) != "12") {
                int hour = int.Parse(time.Substring(0, 2)) + 12;
                time = hour.ToString() + time.Substring(2);
            }
        }        
        Console.WriteLine(time);
    }
}