package app;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class ReadAFile {

    public ReadAFile(String file){
        String path = new File(file).getAbsolutePath();
        String line = null;
        BufferedReader bufferedReader = null;

        try {
            //Open the file
            File csvFile = new File(path);
            FileReader fileReader = new FileReader(csvFile, StandardCharsets.UTF_8);
            bufferedReader = new BufferedReader(fileReader);

            //read till the end of the file
            while ((line = bufferedReader.readLine()) != null) {

                // check the line is not empty
                // break means go ahead with the next while element
                if(line.length() ==0 ) break;

               //split the line read into tokens with the defined separator
                // that is one or more saces/tab ...
               String[] csvLineElements = line.split("\\s+");

               //Check if the first char of first token begins with # and skip
                // if not proceed. You need also to have at least 1 element present
                
              if(csvLineElements[0].charAt(0) != '#' ) {
                  //if there are 6 tokens create the object People
                  if (csvLineElements.length == 6 ) {
                      //ransform the String of the birthdate into LocalDate
                      LocalDate myDate = parsedate(csvLineElements[3]);
                      People pxx = new People(csvLineElements[0], csvLineElements[1],
                              csvLineElements[2], csvLineElements[4], csvLineElements[5],
                              myDate);

                      System.out.println(pxx);
                  } else {
                      // if the number of tokens is not 6
                      System.out.println(" something wrong happened in reading line with :" + line);
                  }
              }
            }
        } catch (IOException e) {
            //if somthing was wrong in reading the file
            System.out.println("Error Occured while parsing csv file.");
            e.printStackTrace();
        }

    }

    /**
     * Method to convert a String into a LocalDate
     * @param s the String contaiting the date
     * @return the LocalDate converted, or now() if an error found
     */
    public LocalDate parsedate(String s){
        LocalDate myDate;
        DateTimeFormatter format =
                DateTimeFormatter.ofPattern("d/M/yyyy");
        try {
            myDate = LocalDate.parse(s, format);
        }catch (DateTimeParseException e){
            myDate = LocalDate.now();
        }
           return myDate;
    }


    public static void main(String[] args) {
        ReadAFile myread = new ReadAFile("src/data/nomi.txt");
    }
}
