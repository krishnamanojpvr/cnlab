import java.util.Scanner;

public class CRC {

    static String data;
    static String generator;
    static String checkValue;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input data and generator polynomial
        System.out.print("Enter data to be transmitted: ");
        data = scanner.nextLine();
        System.out.print("Enter the generator polynomial: ");
        generator = scanner.nextLine();

        // Append zeros to data based on generator length
        String paddedData = data + "0".repeat(generator.length() - 1);
        System.out.println("\nData padded with zeros: " + paddedData);

        // Calculate CRC
        checkValue = calculateCRC(paddedData);
        System.out.println("CRC value: " + checkValue);

        // Append CRC to original data
        String transmittedData = data + checkValue;
        System.out.println("Transmitted data: " + transmittedData);

        // Receiver checks for errors
        System.out.print("\nEnter received data: ");
        String receivedData = scanner.nextLine();
        String remainder = calculateCRC(receivedData);

        if (remainder.contains("1")) {
            System.out.println("Error detected in received data.");
        } else {
            System.out.println("No error detected in received data.");
        }

        scanner.close();
    }

    static String calculateCRC(String input) {
        StringBuilder result = new StringBuilder(input);

        for (int i = 0; i <= input.length() - generator.length(); i++) {
            if (result.charAt(i) == '1') {
                for (int j = 0; j < generator.length(); j++) {
                    result.setCharAt(i + j, result.charAt(i + j) == generator.charAt(j) ? '0' : '1');
                }
            }
        }

        return result.substring(input.length() - (generator.length() - 1));
    }
}