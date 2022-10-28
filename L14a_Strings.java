import java.util.ArrayList;
import java.util.Arrays;

public class L14a_Strings {


    public static void main(String[] args) {
        //Pretty printing
        float a = 1.234566f;
        System.out.printf("Formatted no is %.3f", a);// printf is used not println

        System.out.printf("Pie:%.2f", Math.PI);
        System.out.println();
        System.out.printf("Hello my name is %s and my name is %s", "Ankit", "cool");
        System.out.println();

        /*
        There are many format specifiers we can use. Here are some common ones:

                %c - Character
                %d - Decimal number (base 10)
                %e - Exponential floating-point number
                %f - Floating-point number
                %i - Integer (base 10)
                %o - Octal number (base 8)
                %s - String
                %u - Unsigned decimal (integer) number
                %x - Hexadecimal number (base 16)
                %t - Date/time
                %n - Newline
                */

        // Operators and cancatenation

        System.out.println('a' + 'b');//Adding two char will add their ASCII value
        System.out.println("a" + "b");//Adding two strings will do cancatenation
        System.out.println((char) ('a' + 3));

        System.out.println("a" + 1);
        // this is same as after a few steps: "a" + "1"
        // integer will be converted to Integer that will call toString()

        System.out.println("Kunal" + new ArrayList<>());
        System.out.println("Kunal" + new Integer(56));
        String ans = new Integer(56) + "" + new ArrayList<>();
        System.out.println(ans);
        //Watch vedio from 48:00 to understand things above
        //Watch vedio from 49:00 to know more about string cancatenation operator and an important rule too


        System.out.println("a" + 'b');

        //String Builder in java and its methods

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            char ch = (char) ('a' + i);
            builder.append(ch);
            //The java. lang. StringBuilder. append(String str) method appends the specified string to this character sequence. The characters of the String argument are appended, in order, increasing the length of this sequence by the length of the argument.
        }
        System.out.println(builder.toString());
        builder.reverse();
        System.out.println(builder);

        //Array methods
        //We have to import import java.util.Arrays;for using array methods
        String name = "Kunal Kushwaha Hello World";
        System.out.println(Arrays.toString(name.toCharArray()));
        System.out.println(name.toLowerCase());
        System.out.println(name);
        System.out.println(name.indexOf('a'));
        System.out.println("     Kunal   ".strip());
        System.out.println(Arrays.toString(name.split(" ")));


        //Pallindrome
        String s = "abc";
        System.out.println(pallindrome1(s));
        System.out.println(isPalindrome( s));

    }

    static String pallindrome1(String str) {
        //reversing string using stringbuilder
        StringBuilder sb = new StringBuilder(str);
        // IMPORTANT

        // sb.reverse();//It means the whole sb is pointing towards Sb.reverse ,
        // We have commented above code because we are have use sb.reverse in if statement too , if we dont comment it here then it will reverse string again and leads to same strings

        System.out.println(sb.toString());//Checking value of sb before using sb.reverse
        //Two StringBuilder objects are never equal. We Use .toString() to get the string representation for both the objects and then use .equals() to compare the objects. This way equals() method from the String class gets invoked that compares the string value of the objects instead of comparing the memory location.
        //https://www.javacodeexamples.com/compare-two-stringbuilder-objects-or-stringbuffer-equals/2234
        if (sb.toString().equals(sb.reverse().toString()))// here we have to use sb first and sb.reverse in equalsto as if we use sb.reverse first then it means sb will be reversed and point towards revesed one and hence both will be equal always
        // since we have used sb.reverse() above, hence sb will reversed and poiint towards reversed one, we have verified it by printing sb before and after using sb.reverse in if-else loop
        {
            System.out.println(sb.toString());
            return "Pallindrome";
        } else {
            System.out.println(sb.toString());
            return "notPalli";
        }
    }

    //2nd Method3
    static boolean isPalindrome(String str) {
        if (str == null || str.length() == 0) {
            return true;
        }
        str = str.toLowerCase();
        for (int i = 0; i <= str.length() / 2; i++) {
            char start = str.charAt(i);
            char end = str.charAt(str.length() - 1 - i);

            if (start != end) {
                return false;
            }
        }
        return true;
    }
}


         

