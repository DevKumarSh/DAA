import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class InvalidReadingException extends Exception {
    InvalidReadingException(String msg) {
        super(msg);
    }
}

public class ElectricityBill extends JFrame implements ActionListener {

    JTextField name, previous, current;
    JTextArea result;
    JButton calculate;

    ElectricityBill() {
        setTitle("Electricity Bill Calculator");
        setSize(400, 400);
        setLayout(new FlowLayout());

        add(new JLabel("Consumer Name:"));
        name = new JTextField(20);
        add(name);

        add(new JLabel("Previous Reading:"));
        previous = new JTextField(20);
        add(previous);

        add(new JLabel("Current Reading:"));
        current = new JTextField(20);
        add(current);

        calculate = new JButton("Calculate Bill");
        add(calculate);

        result = new JTextArea(8, 30);
        add(result);

        calculate.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            String consumer = name.getText();

            int prev = Integer.parseInt(previous.getText());
            int curr = Integer.parseInt(current.getText());

            if (curr < prev) {
                throw new InvalidReadingException(
                    "Current reading cannot be less than previous reading!"
                );
            }

            int units = curr - prev;
            double bill;

            if (units <= 100) {
                bill = units * 2;
            } else if (units <= 200) {
                bill = 100 * 2 + (units - 100) * 3;
            } else {
                bill = 100 * 2 + 100 * 3
                       + (units - 200) * 5;
            }

            result.setText(
                "Consumer Name: " + consumer +
                "\nUnits Consumed: " + units +
                "\nTotal Bill: Rs. " + bill
            );

        } catch (InvalidReadingException ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this,
                "Please enter valid meter readings!");

        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this,
                "Something went wrong!");
        }
    }

    public static void main(String[] args) {
        new ElectricityBill();
    }
}
