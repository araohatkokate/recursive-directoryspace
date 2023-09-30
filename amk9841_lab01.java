//Name - Araohat Kokate
//Net ID - 1001829841
//Language version - openjdk 11.0.20
//OS used - Windows 11

import java.io.File;

public class amk9841_lab01 
{
    //recursive function to go through the directories and add file size
    public static long calculateTotalSize(File directory)
    {
        long totalSize = 0;

        if (directory.isDirectory()) 
        {
            File[] files = directory.listFiles();
            if (files != null) 
            {
                for (File file : files) 
                {
                    totalSize += calculateTotalSize(file);
                }
            }
        } 
        //if it is just a file, the size gets added to the variable
        else if (directory.isFile()) {
            totalSize += directory.length();
        }

        return totalSize;
    }

    public static void main(String[] args) 
    {
        String currentDirectoryPath = ".";
        File currentDirectory = new File(currentDirectoryPath);
        long totalSize = calculateTotalSize(currentDirectory);

        System.out.println("Total size : " + totalSize + " bytes");
    }
}
