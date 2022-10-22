import java.util.Scanner;

class Book {
    private int bookId;

    Book() {
        bookId = 0;
    }

    private String bookTitle;
    private int yearOfPublication;
    private String authorName;
    private String publisherName;
    private int numberOfAvailableCopies;
    private int totalCopies;

    Book(int totalCopies) {
        totalCopies = 1000;
    }

    public void setDetails(int id, String title, int year, String author, String publisher, int count) {
        bookId = id;
        bookTitle = title;
        yearOfPublication = year;
        authorName = author;
        publisherName = publisher;
        numberOfAvailableCopies = count;
        totalCopies = count;
    }

    public void getDetails(int bookId) {
        System.out.print("\n");
        System.out.println("Book id:" + bookId);
        System.out.println("Bool tittle:" + bookTitle);
        System.out.println("Year of publication:" + yearOfPublication);
        System.out.println("Name of the author:" + authorName);
        System.out.println("Name of publisher:" + publisherName);
        System.out.println("Number of availabe copies:" + numberOfAvailableCopies);
        System.out.println("Number of total copies:" + totalCopies);
    }

    public void issue(int bookId) {
        if (numberOfAvailableCopies <= 0) {
            System.out.println("No book available.");
        } else {
            System.out.println("Book issued.");
            numberOfAvailableCopies--;
        }
    }

    public void return_book(int bookId) {
        if (totalCopies > numberOfAvailableCopies) {
            System.out.println("Thanks for returning book");
            numberOfAvailableCopies++;
        } else {
            System.out.println("You don't have any book with this book id.Enter correct book id.");
        }
    }

    public int getid() {
        return bookId;
    }

}

public class library {
    public static void main(String args[]) {

        Book[] arr;
        arr = new Book[100];

        for (int i = 0; i < 5; i++) {
            arr[i] = new Book();
        }

        arr[0].setDetails(201, "Algorithm", 2012, "Sumit mishra", "IIITG", 500);
        arr[1].setDetails(202, "Java Theory", 2013, "Manojit Ghosh", "IIITG", 300);
        arr[2].setDetails(203, "maths", 2014, "Frah sultana", "IIITG", 200);
        arr[3].setDetails(204, "Java lab", 2022, "XYZ", "IIITG", 800);
        arr[4].setDetails(205, "Discrete", 2016, "Gautam Kalita", "IIITG", 600);

        Scanner sc = new Scanner(System.in);

        System.out.println("\nEnter 1 for Set Details\n2 for Get Details\n3 for Issue\n4 for Return\n5 for Exit");
        int n = 1;
        int flag;
        while (n != 5) {
            int p = 5;
            flag = 0;
            System.out.print("\nEnter your choice:");
            n = sc.nextInt();

            switch (n) {
                case 1:

                    System.out.println("Set the details of book-");
                    System.out.print("Enter the book id:");
                    int id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter the book title:");
                    String title = sc.nextLine();
                    System.out.print("Enter the publishing year:");
                    int year = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter the author name:");
                    String author = sc.nextLine();
                    System.out.print("Enter the publisher name:");
                    String publisher = sc.nextLine();
                    System.out.print("Enter the number of total copies:");
                    int count = sc.nextInt();
                    arr[p] = new Book();
                    arr[p].setDetails(id, title, year, author, publisher, count);
                    break;
                case 2:
                    System.out.print("Enter the id of book whose details you want:");
                    int b_id = sc.nextInt();
                    for (int j = 0; j < p; j++) {
                        if (arr[j].getid() == b_id) {
                            System.out.println("The details of book is:");
                            arr[j].getDetails(b_id);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        System.out.println("You entered a wrong book id.Try again.");
                    }
                    break;
                case 3:
                    System.out.print("Enter the id of book which you want to issue:");
                    int b__id = sc.nextInt();
                    for (int j = 0; j < p; j++) {
                        if (arr[j].getid() == b__id) {
                            arr[j].issue(b__id);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        System.out.print("You entered a wrong book id.Try again.");
                    }

                    break;

                case 4:
                    System.out.print("Enter the id of book which you want to return:");
                    int bid = sc.nextInt();
                    for (int j = 0; j <p; j++) {
                        if (arr[j].getid() == bid) {
                            arr[j].return_book(bid);
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        System.out.println("You entered a wrong book id.Try again");
                    }

                    break;

                case 5:
                    System.out.println("Thank you for visiting us.");
                    break;

                default:
                    System.out.println("The entered number does not belong to the given options.Try again.");
                    break;
            }
        }
        sc.close();
    }
}