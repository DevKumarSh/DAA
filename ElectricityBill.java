import javax.swing.*;
import java.awt.event.*;

class InvalidReadingException extends Exception {
    InvalidReadingException(String msg) {
        super(msg);
    }
}

public class ElectricityBill extends JFrame implements ActionListener {

    JLabel l1, l2, l3;
    JTextField t1, t2, t3;
    JButton b1;
    JTextArea result;

    ElectricityBill() {

        setTitle("Electricity Bill Calculator");
        setSize(400, 450);
        setLayout(null);

        l1 = new JLabel("Consumer Name:");
        l1.setBounds(30, 30, 120, 30);
        add(l1);

        t1 = new JTextField();
        t1.setBounds(160, 30, 180, 30);
        add(t1);

        l2 = new JLabel("Previous Reading:");
        l2.setBounds(30, 80, 120, 30);
        add(l2);

        t2 = new JTextField();
        t2.setBounds(160, 80, 180, 30);
        add(t2);

        l3 = new JLabel("Current Reading:");
        l3.setBounds(30, 130, 120, 30);
        add(l3);

        t3 = new JTextField();
        t3.setBounds(160, 130, 180, 30);
        add(t3);

        b1 = new JButton("Calculate Bill");
        b1.setBounds(120, 180, 150, 35);
        add(b1);

        result = new JTextArea();
        result.setBounds(30, 230, 310, 150);
        add(result);

        b1.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

        try {
            String name = t1.getText();

            int prev = Integer.parseInt(t2.getText());
            int curr = Integer.parseInt(t3.getText());

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
                "Consumer Name: " + name +
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
